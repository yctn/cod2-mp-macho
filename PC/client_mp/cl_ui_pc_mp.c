/* Decompiled from: cl_ui_pc_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_ui_pc_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Extern declarations for called functions */
extern qboolean NET_StringToAdr(const char *s, netadr_t *a);
extern qboolean NET_CompareAdr(netadr_t a, netadr_t b);
extern const char *NET_AdrToString(netadr_t a);
extern int NET_CompareAdrSigned(netadr_t *a, netadr_t *b);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void Com_Memcpy(void *dst, const void *src, int size);
extern int FS_SV_FOpenFileRead(const char *filename, fileHandle_t *fp);
extern fileHandle_t FS_SV_FOpenFileWrite(const char *filename);
extern int FS_Read(void *buffer, int len, fileHandle_t h);
extern int FS_Write(const void *buffer, int len, fileHandle_t h);
extern void FS_FCloseFile(fileHandle_t h);
extern int CL_SortGlobalServers(void);

extern const char str_002b6980[]; /* "servercache.dat" */

/*
 * The global at 0x195ecac is a pointer to a clientStatic_t structure.
 * We access it as a byte pointer and use offsets for fields that don't
 * match the struct definition exactly (globalServers is actually a large array).
 *
 * Key offsets within clientStatic_t (via byte pointer):
 *   0x4540  - numglobalservers (int)
 *   0x4544  - globalServers[20000] (serverInfo_t array)
 *   0x29c644 - numfavoriteservers (int)
 *   0x29c648 - favoriteServers[128] (serverInfo_t array)
 */
extern byte *cls_ptr_195ecac; /* 0x195ecac - pointer to clientStatic_t */

#define CLS (*(byte **)&cls_ptr_195ecac)

#define CLS_NUMFAVORITESERVERS(base) (*(int *)((base) + 0x29c644))
#define CLS_FAVORITESERVERS(base) ((serverInfo_t *)((base) + 0x29c648))

#define CLS_NUMGLOBALSERVERS(base) (*(int *)((base) + 0x4540))
#define CLS_GLOBALSERVERS(base) ((serverInfo_t *)((base) + 0x4544))

#define CLS_NUMLOCALSERVERS(base) (*(int *)((base) + 0x138))
#define CLS_LOCALSERVERS(base) ((serverInfo_t *)((base) + 0x13c))

#define MAX_FAVORITESERVERS 128
#define MAX_GLOBALSERVERS 20000

int LAN_AddServer(int source, const char *name, const char *address);
int LAN_RemoveServer(int source, const char *addr);
int LAN_GetServerAddressString(int source, int n, char *buf, int buflen);
int LAN_LoadCachedServers(void);
int LAN_SaveServersToCache(void);

/* line 25 */
int LAN_AddServer(int source, const char *name, const char *address)
{
    netadr_t adr;
    int i;
    byte *base;
    serverInfo_t *servers;
    int *count;

    if (source != 2) {
        return -1;
    }

    base = CLS;
    if (CLS_NUMFAVORITESERVERS(base) > 127) {
        return -1;
    }

    if (!NET_StringToAdr(address, &adr)) {
        return -2;
    }

    count = &CLS_NUMFAVORITESERVERS(base);
    servers = CLS_FAVORITESERVERS(base);

    if (*count > 0) {
        for (i = 0; i < *count; i++) {
            if (NET_CompareAdr(servers[i].adr, adr)) {
                if (*count <= i) {
                    break;
                }
                return 0;
            }
        }
    }

    /* Add the new server at the end */
    servers[*count].adr = adr;
    I_strncpyz(servers[*count].hostName, name, 32);
    servers[*count].dirty = 1;
    *count += 1;
    return 1;
}

/* line 76 */
int LAN_RemoveServer(int source, const char *addr)
{
    netadr_t comp;
    int i;
    int j;
    byte *base;
    serverInfo_t *servers;
    int *count;

    if (source != 2) {
        return 0;
    }

    NET_StringToAdr(addr, &comp);

    base = CLS;
    count = &CLS_NUMFAVORITESERVERS(base);
    servers = CLS_FAVORITESERVERS(base);

    if (*count <= 0) {
        return 0;
    }

    for (i = 0; i < *count; i++) {
        if (NET_CompareAdr(servers[i].adr, comp)) {
            /* Found the server, remove it by shifting entries down */
            if (i < *count - 1) {
                for (j = i; j < *count - 1; j++) {
                    Com_Memcpy(&servers[j], &servers[j + 1], sizeof(serverInfo_t));
                }
            }
            *count -= 1;
            return 0;
        }
    }

    return 0;
}

/* line 120 */
int LAN_GetServerAddressString(int source, int n, char *buf, int buflen)
{
    byte *base;
    netadr_t adr;

    switch (source) {
    case 0:
        if ((unsigned int)n > 127) {
            break;
        }
        base = CLS;
        adr = CLS_LOCALSERVERS(base)[n].adr;
        I_strncpyz(buf, NET_AdrToString(adr), buflen);
        return 0;

    case 1:
        if (n < 0) {
            break;
        }
        base = CLS;
        if (n >= CLS_NUMGLOBALSERVERS(base)) {
            break;
        }
        adr = CLS_GLOBALSERVERS(base)[n].adr;
        I_strncpyz(buf, NET_AdrToString(adr), buflen);
        return 0;

    case 2:
        if ((unsigned int)n > 127) {
            break;
        }
        base = CLS;
        adr = CLS_FAVORITESERVERS(base)[n].adr;
        I_strncpyz(buf, NET_AdrToString(adr), buflen);
        return 0;
    }

    *buf = '\0';
    return 0;
}

/* line 196 */
int LAN_LoadCachedServers(void)
{
    fileHandle_t fileIn;
    int version;
    int size;
    int success;
    byte *base;

    if (!FS_SV_FOpenFileRead(str_002b6980, &fileIn)) {
        base = CLS;
        CLS_NUMGLOBALSERVERS(base) = 0;
        CLS_NUMFAVORITESERVERS(base) = 0;
        return 0;
    }

    success = 0;

    /* Read version */
    if (FS_Read(&version, 4, fileIn) != 4) {
        goto done;
    }
    if (version != 1) {
        goto done;
    }

    base = CLS;

    /* Read numglobalservers */
    if (FS_Read(&CLS_NUMGLOBALSERVERS(base), 4, fileIn) != 4) {
        goto done;
    }
    if ((unsigned int)CLS_NUMGLOBALSERVERS(base) > 19999) {
        goto done;
    }

    /* Read numfavoriteservers */
    if (FS_Read(&CLS_NUMFAVORITESERVERS(base), 4, fileIn) != 4) {
        goto done;
    }
    if ((unsigned int)CLS_NUMFAVORITESERVERS(base) > 127) {
        goto done;
    }

    /* Read size and validate */
    if (FS_Read(&size, 4, fileIn) != 4) {
        goto done;
    }
    if (size != 0x298100) {
        goto done;
    }

    /* Read global servers data */
    if (FS_Read(CLS_GLOBALSERVERS(base), 0x298100, fileIn) != 0x298100) {
        goto done;
    }

    /* Read favorite servers data */
    if (FS_Read(CLS_FAVORITESERVERS(base), 0x4400, fileIn) != 0x4400) {
        goto done;
    }

    success = 1;

done:
    FS_FCloseFile(fileIn);
    if (!success) {
        base = CLS;
        CLS_NUMGLOBALSERVERS(base) = 0;
        CLS_NUMFAVORITESERVERS(base) = 0;
    } else {
        CL_SortGlobalServers();
    }

    return 0;
}

/* line 224 */
int LAN_SaveServersToCache(void)
{
    fileHandle_t fileOut;
    int version;
    int size;
    byte *base;
    int d;
    serverInfo_t *servers;

    fileOut = FS_SV_FOpenFileWrite(str_002b6980);
    if (!fileOut) {
        return 0;
    }

    version = 1;
    FS_Write(&version, 4, fileOut);

    base = CLS;
    servers = CLS_GLOBALSERVERS(base);

    /*
     * Clean up the global server list before saving:
     * - Remove servers with requestCount > 2 (stale/unresponsive)
     * - Remove duplicate adjacent addresses (requestCount <= 2)
     * Removal is done by replacing the entry with the last entry in the list.
     */
    d = CLS_NUMGLOBALSERVERS(base) - 1;
    while (d >= 0) {
        if (servers[d].requestCount > 2) {
            /* Stale server: remove by copying last entry over it */
            CLS_NUMGLOBALSERVERS(base) -= 1;
            memcpy(&servers[d], &servers[CLS_NUMGLOBALSERVERS(base)], sizeof(serverInfo_t));
            d--;
            continue;
        }
        /* requestCount <= 2: check for duplicate with previous entry */
        if (d == 0) {
            break;
        }
        if (NET_CompareAdrSigned(&servers[d].adr, &servers[d - 1].adr) == 0) {
            /* Duplicate address: remove */
            CLS_NUMGLOBALSERVERS(base) -= 1;
            memcpy(&servers[d], &servers[CLS_NUMGLOBALSERVERS(base)], sizeof(serverInfo_t));
            d--;
            continue;
        }
        /* Unique server, keep it */
        d--;
        base = CLS;
        servers = CLS_GLOBALSERVERS(base);
    }

    CL_SortGlobalServers();

    base = CLS;

    /* Write numglobalservers */
    FS_Write(&CLS_NUMGLOBALSERVERS(base), 4, fileOut);

    /* Write numfavoriteservers */
    FS_Write(&CLS_NUMFAVORITESERVERS(base), 4, fileOut);

    /* Write size of global servers data */
    size = 0x298100;
    FS_Write(&size, 4, fileOut);

    /* Write global servers data */
    FS_Write(CLS_GLOBALSERVERS(base), 0x298100, fileOut);

    /* Write favorite servers data */
    FS_Write(CLS_FAVORITESERVERS(base), 0x4400, fileOut);

    FS_FCloseFile(fileOut);

    return 0;
}
