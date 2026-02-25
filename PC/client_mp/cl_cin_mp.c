/* Converted to C from ASM: cl_cin_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_cin_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern e_status ROQ_StopCinematicFromHandle(int handle);
extern e_status ROQ_RunCinematicFromHandle(int handle);
extern int ROQ_PlayCinematic(const char *arg, int x, int y, int w, int h, int systemBits);
extern long int ROQ_SetExtentsFromHandle(int handle, int x, int y, int w, int h);
extern long int ROQ_DrawCinematicFromHandle(int handle);
extern long int ROQ_PlayCinematic_f(void);
extern long int ROQ_DrawCinematic(void);
extern long int ROQ_RunCinematic(void);
extern long int ROQ_StopCinematic(void);
extern long int ROQ_UploadCinematicFromHandle(int handle);
extern long int ROQ_CloseAllVideos(void);

e_status CIN_StopCinematic(int handle)
{
    return ROQ_StopCinematicFromHandle(handle);
}

e_status CIN_RunCinematic(int handle)
{
    return ROQ_RunCinematicFromHandle(handle);
}

int CIN_PlayCinematic(const char *arg, int x, int y, int w, int h, int systemBits)
{
    return ROQ_PlayCinematic(arg, x, y, w, h, systemBits);
}

long int CIN_SetExtents(int handle, int x, int y, int w, int h)
{
    return ROQ_SetExtentsFromHandle(handle, x, y, w, h);
}

long int CIN_DrawCinematic(int handle)
{
    return ROQ_DrawCinematicFromHandle(handle);
}

long int CL_PlayCinematic_f(void)
{
    return ROQ_PlayCinematic_f();
}

long int SCR_DrawCinematic(void)
{
    return ROQ_DrawCinematic();
}

long int SCR_RunCinematic(void)
{
    return ROQ_RunCinematic();
}

long int SCR_StopCinematic(void)
{
    return ROQ_StopCinematic();
}

long int CIN_UploadCinematic(int handle)
{
    return ROQ_UploadCinematicFromHandle(handle);
}

long int CIN_CloseAllVideos(void)
{
    return ROQ_CloseAllVideos();
}
