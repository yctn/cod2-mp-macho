#ifndef _\SCRIPT\SCR_LEX_H_H
#define _\SCRIPT\SCR_LEX_H_H

/* Reconstructed from: .\script\scr_lex.h */
/* Types attributed via N_BINCL cross-reference */

struct stype_t;
union sval_u;

struct stype_t {
    sval_t val;
    unsigned int pos;
};

union sval_u {
    int type;
    unsigned int stringValue;
    unsigned int idValue;
    float floatValue;
    int intValue;
    int node;
    unsigned int sourcePosValue;
    const char *codePosValue;
    const char *debugString;
    scr_block_s *block;
};

#endif /* _\SCRIPT\SCR_LEX_H_H */
