/* ASM dump from: scr_yacc.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_yacc.c */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <unistd.h>

/* Original includes (from N_BINCL debug info):
 *   #include ".\script\scr_lex.h"
 */

extern int yychar; /* 0x0 */
extern stype_t yylval; /* 0x0 */
extern int yynerrs; /* 0x0 */
extern int yyleng; /* 0x0 */
extern FILE *yyin; /* 0x0 */
extern FILE *yyout; /* 0x0 */
extern char *yytext; /* 0x0 */
extern sval_t yaccResult; /* yaccResult - BSS */
extern unsigned int g_out_pos; /* g_out_pos - BSS */
extern unsigned int g_sourcePos; /* g_sourcePos - BSS */
extern unsigned char g_parse_user; /* g_parse_user - BSS */
extern sval_t g_dummyVal; /* g_dummyVal - BSS */
extern const unsigned char yytranslate[];
extern const unsigned char yyr1[];
extern const unsigned char yyr2[];
extern const unsigned char yydefact[];
extern const unsigned char yydefgoto[];
extern const unsigned char yypact[];
extern const unsigned char yypgoto[];
extern const unsigned char yytable[];
extern const unsigned char yycheck[];
extern YY_BUFFER_STATE yy_current_buffer; /* yy_current_buffer - BSS */
extern char yy_hold_char; /* yy_hold_char - BSS */
extern int yy_n_chars; /* yy_n_chars - BSS */
extern char *yy_c_buf_p; /* yy_c_buf_p - BSS */
extern int yy_init; /* yy_init */
extern int yy_start; /* yy_start - BSS */
extern int yy_did_buffer_switch_on_eof; /* yy_did_buffer_switch_on_eof - BSS */
extern const unsigned char yy_accept[];
extern const unsigned char yy_ec[];
extern const unsigned char yy_meta[];
extern const unsigned char yy_base[];
extern const unsigned char yy_def[];
extern const unsigned char yy_nxt[];
extern const unsigned char yy_chk[];
extern yy_state_type yy_last_accepting_state; /* yy_last_accepting_state - BSS */
extern char *yy_last_accepting_cpos; /* yy_last_accepting_cpos - BSS */
extern char ch_buf[]; /* ch_buf - BSS */

__attribute__((used, aligned(4)))
int yy_init_storage[6] __asm__("yy_init") = {
    1, 0, 0, 0, 0, 0,
}; /* 0x311468 */

#define yy_init (yy_init_storage[0])

YY_BUFFER_STATE yy_create_buffer(FILE *file, int size);
int yyparse(void);
void ScriptParse(sval_t *parseData, int user);

/* line 1838 */
YY_BUFFER_STATE yy_create_buffer(FILE *file, int size)
{
    YY_BUFFER_STATE b;
    char *buf;

    b = (YY_BUFFER_STATE)malloc(0x28);
    if (!b) {
        fprintf(stderr, "%s\n", "fatal flex scanner internal error--no action found");
        exit(2);
    }

    b->yy_buf_size = size;

    buf = (char *)malloc(size + 2);
    b->yy_ch_buf = buf;
    if (!buf) {
        fprintf(stderr, "%s\n", "fatal flex scanner internal error--no action found");
        exit(2);
    }

    b->yy_is_our_buffer = 1;
    b->yy_n_chars = 0;
    buf[0] = 0;
    buf[1] = 0;
    b->yy_buf_pos = buf;
    b->yy_at_bol = 1;
    b->yy_buffer_status = 0;

    if (b == yy_current_buffer) {
        yy_n_chars = 0;
        yy_c_buf_p = buf;
        yytext = buf;
        yyin = b->yy_input_file;
        yy_hold_char = 0;
    }

    b->yy_input_file = file;
    b->yy_fill_buffer = 1;

    if (file && isatty(fileno(file)) > 0) {
        b->yy_is_interactive = 1;
    } else {
        b->yy_is_interactive = 0;
    }

    return b;
}

/* line 463 */
#include "yyparse_impl.h"
