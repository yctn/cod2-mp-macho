/* yyparse_impl.h - C implementation of yyparse for Emscripten builds */
/* Auto-converted from x86 ASM: combined yylex+yyparse */

/* Forward declarations */
extern unsigned int node0(int type);
extern unsigned int node1(int type, unsigned int val1);
extern unsigned int node1_(int val1);
extern unsigned int node2(int type, unsigned int val1, unsigned int val2);
extern unsigned int node2_(unsigned int val1, unsigned int val2);
extern unsigned int node3(int type, unsigned int val1, unsigned int val2, unsigned int val3);
extern unsigned int node4(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4);
extern unsigned int node5(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5);
extern unsigned int node6(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5, unsigned int val6);
extern unsigned int node7(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5, unsigned int val6, unsigned int val7);
extern unsigned int node8(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5, unsigned int val6, unsigned int val7, unsigned int val8);
extern unsigned int node_pos(unsigned int pos);
extern unsigned int linked_list_end(unsigned int val);
extern unsigned int prepend_node(unsigned int val1, unsigned int val2);
extern unsigned int append_node(unsigned int val1, unsigned int val2);
extern void CompileError(unsigned int sourcePos, const char *msg, ...);
extern unsigned int SL_ConvertToLowercase(unsigned int stringValue, unsigned int user, int type);
extern unsigned int SL_GetString_(const char *str, unsigned int user, int type);
extern unsigned int SL_GetStringOfLen(const char *str, unsigned int user, unsigned int len, int type);
extern int Scr_ScanFile(char *buf, int max_size);
extern void *imp_scrCompilePub;

/* Cast YACC table arrays to short pointers - they are really short arrays despite char decl */
#define YYPACT(i) ((const short *)yypact)[(i)]
#define YYTABLE(i) ((const short *)yytable)[(i)]
#define YYCHECK(i) ((const short *)yycheck)[(i)]
#define YYR1(i) ((const short *)yyr1)[(i)]
#define YYR2(i) ((const short *)yyr2)[(i)]
#define YYDEFACT(i) ((const short *)yydefact)[(i)]
#define YYDEFGOTO(i) ((const short *)yydefgoto)[(i)]
#define YYPGOTO(i) ((const short *)yypgoto)[(i)]
#define YYTRANSLATE(i) ((const signed char *)yytranslate)[(i)]
#define YY_ACCEPT_VAL(i) ((const short *)yy_accept)[(i)]
#define YY_EC_VAL(i) ((const unsigned char *)yy_ec)[(i) * 4]
#define YY_META_VAL(i) ((const unsigned char *)yy_meta)[(i) * 4]
#define YY_BASE(i) ((const short *)yy_base)[(i)]
#define YY_DEF(i) ((const short *)yy_def)[(i)]
#define YY_NXT(i) ((const short *)yy_nxt)[(i)]
#define YY_CHK(i) ((const short *)yy_chk)[(i)]

/* Process string escape sequences (\\n, \\t, \\r) */
static char *yyparse_unescape(char *dst, const char *src, int len)
{
    char *out = dst;
    while (len > 0) {
        if (*src == '\\') {
            if (len == 1) break;
            char next = src[1];
            if (next == 'n') *out++ = '\n';
            else if (next == 't') *out++ = '\t';
            else if (next == 'r') *out++ = '\r';
            else *out++ = next;
            len -= 2;
            src += 2;
        } else {
            *out++ = *src++;
            len--;
        }
    }
    return out;
}

/*
 * Inline yylex: flex DFA scanner embedded in yyparse.
 * string_buf is a 0x2000-byte buffer on yyparse's stack for string token unescaping.
 * Returns the token value, sets yychar/yylval as side effects.
 */
static int yyparse_yylex(char *string_buf)
{
    int yy_act;
    char *yy_bp; /* base pointer for current token */

    /* yy_init check */
    if (yy_init) {
        yy_init = 0;
        if (!yy_start) yy_start = 1;
        if (!yyin) yyin = stdin;
        if (!yyout) yyout = stdout;
        if (!yy_current_buffer) {
            yy_current_buffer = yy_create_buffer(yyin, 0x4000);
        }
        /* Load buffer state */
        {
            struct yy_buffer_state *b = (struct yy_buffer_state *)yy_current_buffer;
            yy_n_chars = b->yy_n_chars;
            yy_c_buf_p = b->yy_buf_pos;
            yytext = yy_c_buf_p;
            yyin = b->yy_input_file;
            yy_hold_char = *yy_c_buf_p;
        }
    }

restart_scan:
    yy_bp = yy_c_buf_p;
    *yy_bp = yy_hold_char;

    {
        int yy_current_state = yy_start;
        char *yy_cp = yy_bp;

        /* DFA loop */
        for (;;) {
            unsigned char yy_c = YY_EC_VAL((unsigned char)*yy_cp);
            if (YY_ACCEPT_VAL(yy_current_state)) {
                yy_last_accepting_state = yy_current_state;
                yy_last_accepting_cpos = yy_cp;
            }
            {
                int idx = YY_BASE(yy_current_state) + yy_c;
                while (YY_CHK(idx) != yy_current_state) {
                    yy_current_state = YY_DEF(yy_current_state);
                    if (yy_current_state > 0xff) {
                        yy_c = YY_META_VAL(yy_c);
                    }
                    idx = YY_BASE(yy_current_state) + yy_c;
                }
                yy_current_state = YY_NXT(idx);
            }
            yy_cp++;
            if (YY_BASE(yy_current_state) == 0x1af) break;
        }

        /* Find action */
        yy_act = YY_ACCEPT_VAL(yy_current_state);
        if (yy_act == 0) {
            yy_cp = yy_last_accepting_cpos;
            yy_act = YY_ACCEPT_VAL(yy_last_accepting_state);
        }

        /* Set up yytext/yyleng */
        yytext = yy_bp;
        yyleng = (int)(yy_cp - yy_bp);
        yy_hold_char = *yy_cp;
        *yy_cp = '\0';
        yy_c_buf_p = yy_cp;

        /* Execute action based on yy_act */
        if ((unsigned int)yy_act > 0x61) {
            /* Default: echo to output (fatal error in this grammar) */
            fprintf(stderr, "%s\n", (const char *)str_00228d88);
            exit(2);
        }

        /* Lex action dispatch */
        /* Most actions: update g_out_pos, set yylval.pos = g_sourcePos = old g_out_pos, return token */
        switch (yy_act) {
        case 0: /* ECHO (backup) */
            *yy_cp = yy_hold_char;
            yy_cp = yy_last_accepting_cpos;
            yy_current_state = yy_last_accepting_state;
            yy_act = YY_ACCEPT_VAL(yy_current_state);
            /* Set yytext etc and re-dispatch - simplified: */
            yytext = yy_bp;
            yyleng = (int)(yy_cp - yy_bp);
            yy_hold_char = *yy_cp;
            *yy_cp = '\0';
            yy_c_buf_p = yy_cp;
            goto restart_scan;
        case 1: /* comment / whitespace: skip, continue scanning */
            { unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng; }
            goto restart_scan;
        case 2: /* switch to INITIAL state (end of dev comment) */
            { unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng; }
            yy_start = 3;
            goto restart_scan;
        case 3: case 4: case 5:
            { unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng; }
            goto restart_scan;
        case 6: /* switch to DEV_COMMENT state */
            { unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng; }
            yy_start = 5;
            goto restart_scan;
        case 7: /* single-quoted string */
        {
            unsigned int p = g_out_pos;
            yylval.pos = p; g_sourcePos = p;
            int slen = yyleng;
            g_out_pos = p + slen;
            /* Strip quotes: skip first char, reduce length by 2 */
            slen -= 2;
            const char *src = yytext + 1;
            if (slen > 0x1fff) {
                CompileError(p, (const char *)str_00217bfc, src);
                return 0x101;
            }
            char *end = yyparse_unescape(string_buf, src, slen);
            *end = '\0';
            yylval.val.node = (int)SL_GetString_(string_buf, (unsigned int)(unsigned char)g_parse_user, 0xd);
            return 0x103;
        }
        case 8: /* double-quoted string */
        {
            unsigned int p = g_out_pos;
            yylval.pos = p; g_sourcePos = p;
            int slen = yyleng;
            g_out_pos = p + slen;
            /* Strip quotes: skip first 2 chars, reduce length by 3 */
            slen -= 3;
            const char *src = yytext + 2;
            if (slen > 0x1fff) {
                CompileError(p, (const char *)str_00217bfc, src);
                return 0x101;
            }
            char *end = yyparse_unescape(string_buf, src, slen);
            *end = '\0';
            yylval.val.node = (int)SL_GetString_(string_buf, (unsigned int)(unsigned char)g_parse_user, 0xd);
            return 0x104;
        }
        case 9: /* token 0x105 */
        case 10: /* token 0x106 */
        case 11: /* token 0x107 */
        case 12: /* token 0x108 */
        case 13: /* token 0x109 */
        case 14: /* token 0x10a */
        case 15: /* token 0x10b */
        case 16: /* token 0x10c */
        case 17: /* token 0x10d */
        case 18: /* token 0x10e */
        case 19: /* token 0x10f */
        case 20: /* token 0x110 */
        case 21: /* token 0x111 */
        case 22: /* token 0x112 */
        case 23: /* token 0x113 */
        case 24: /* token 0x114 */
        case 25: /* token 0x115 */
        case 26: /* token 0x116 */
        case 27: /* token 0x117 */
        case 28: /* token 0x118 */
        case 29: /* token 0x119 */
        case 30: /* token 0x11a */
        case 31: /* token 0x11b */
        case 32: /* token 0x11c */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            return 0x105 + (yy_act - 9);
        }
        case 33: /* token 0x11d (line 132) */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            return 0x11d;
        }
        case 34: /* token 0x11e (line 133) */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            return 0x11e;
        }
        case 35: /* integer: sscanf "%d", token 0x11f (line 134) */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            sscanf(yytext, "%d", &yylval.val.intValue);
            return 0x11f;
        }
        case 36: /* float: sscanf "%f", token 0x120 (line 135) */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            sscanf(yytext, "%f", &yylval.val.floatValue);
            return 0x120;
        }
        case 37: /* token 0x121 (line 136) - mapped from reversed line order */
        case 38: /* token 0x122 (line 137) */
        case 39: /* token 0x123 (line 138) */
        case 40: /* token 0x124 (line 139) */
        case 41: /* token 0x125 (line 140) */
        case 42: /* token 0x126 (line 141) - note: out of sequence in ASM */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            /* These map to tokens based on jump table order */
            static const int token_map_37_42[] = { 0x121, 0x122, 0x123, 0x124, 0x125, 0x126 };
            /* Actually, looking at the ASM more carefully, the jump table entries at indices 37-42
             * map to specific labels. Let me trace them from the second jump table. */
            /* From the ASM labels:
             * case 37: 0x122 (line 136->137)
             * case 38: 0x121 (line 137->line 136)
             * Actually the mapping is complex. Let me use the line numbers from ASM comments. */
            /* The jump table indices map:
             * 37 = line 137, token 0x121
             * 38 = line 136, token 0x122
             * 39 = line 139, token 0x123
             * 40 = line 138, token 0x126
             * 41 = line 140, token 0x125
             * 42 = line 141, token 0x124 */
            {
                static const int tmap[] = { 0x121, 0x122, 0x123, 0x126, 0x125, 0x124 };
                return tmap[yy_act - 37];
            }
        }
        case 43: /* token 0x127 */
        case 44: /* token 0x128 */
        case 45: /* token 0x129 */
        case 46: /* token 0x12a */
        case 47: /* token 0x12b */
        case 48: /* token 0x12c */
        case 49: /* token 0x12d */
        case 50: /* token 0x12e */
        case 51: /* token 0x12f */
        case 52: /* token 0x130 */
        case 53: /* token 0x131 */
        case 54: /* token 0x132 */
        case 55: /* token 0x133 */
        case 56: /* token 0x134 */
        case 57: /* token 0x135 */
        case 58: /* token 0x136 */
        case 59: /* token 0x137 */
        case 60: /* token 0x138 */
        case 61: /* token 0x139 */
        case 62: /* token 0x13a */
        case 63: /* token 0x13b */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            return 0x127 + (yy_act - 43);
        }
        case 64: /* token 0x13c (line 163) */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            return 0x13c;
        }
        case 65: /* token 0x13d */
        case 66: /* token 0x13e */
        case 67: /* token 0x13f */
        case 68: /* token 0x140 */
        case 69: /* token 0x141 */
        case 70: /* token 0x142 */
        case 71: /* token 0x143 */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            return 0x13d + (yy_act - 65);
        }
        case 72: /* token 0x144: SL_GetStringOfLen token (line 170) - identifier/path */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p;
            int slen = yyleng;
            g_out_pos = p + slen;
            yylval.val.node = (int)SL_GetStringOfLen(yytext, 0, (unsigned int)(slen + 1), 0xd);
            return 0x144;
        }
        case 73: /* token 0x145 */
        case 74: /* token 0x146 */
        case 75: /* token 0x147 */
        case 76: /* token 0x148 */
        case 77: /* token 0x149 */
        case 78: /* token 0x14a */
        case 79: /* token 0x14b */
        case 80: /* token 0x14c */
        case 81: /* token 0x14d */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            return 0x145 + (yy_act - 73);
        }
        case 82: /* token 0x14e */
        case 83: /* token 0x14f */
        case 84: /* token 0x150 */
        case 85: /* token 0x151 */
        case 86: /* token 0x152 */
        case 87: /* token 0x153 */
        case 88: /* token 0x154 */
        case 89: /* token 0x155 */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            return 0x14e + (yy_act - 82);
        }
        case 90: /* token 0x156 (line 188) */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
            return 0x156;
        }
        case 91: /* SL_GetStringOfLen identifier: token 0x102 (line 189) */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p;
            int slen = yyleng;
            g_out_pos = p + slen;
            yylval.val.node = (int)SL_GetStringOfLen(yytext, 0, (unsigned int)(slen + 1), 0xd);
            return 0x102;
        }
        case 92: /* bad token error: CompileError (line 192) */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p;
            g_out_pos = p + yyleng;
            CompileError(p, (const char *)str_00228d14, yytext);
            return 0x101;
        }
        case 93: /* ECHO: fwrite to yyout (line 193) */
        {
            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p;
            int slen = yyleng;
            g_out_pos = p + slen;
            fwrite(yytext, (size_t)slen, 1, yyout);
            goto restart_scan;
        }
        case 94: /* end-of-buffer */
        case 95:
        case 96:
        case 97:
            /* These are EOF/end-of-buffer actions.
             * In the original ASM, these handle buffer switching, refilling, etc.
             * For the Emscripten port, we handle EOF by returning 0. */
        {
            /* Compute amount to push back */
            int num_to_read;
            int offset;
            struct yy_buffer_state *b;

            /* Restore yy_hold_char */
            *yy_c_buf_p = yy_hold_char;

            /* Check if we need more input */
            offset = (int)(yy_c_buf_p - yytext) - 1;
            b = (struct yy_buffer_state *)yy_current_buffer;

            if (b->yy_buffer_status == 0) {
                yy_n_chars = b->yy_n_chars;
                b->yy_input_file = yyin;
                b->yy_buffer_status = 1;
            }

            /* Try to read more */
            {
                char *dest = b->yy_ch_buf;
                int n_to_copy = (int)(yy_c_buf_p - yytext);
                /* Move unmatched chars to beginning of buffer */
                if (n_to_copy > 0) {
                    char *src2 = yytext;
                    int i;
                    for (i = 0; i < n_to_copy - 1; i++) {
                        dest[i] = src2[i];
                    }
                }

                /* Calculate how much room we have */
                num_to_read = b->yy_buf_size - (n_to_copy - 1);

                /* Keep doubling buffer if too small */
                while (num_to_read <= 0) {
                    int buf_offset = (int)(yy_c_buf_p - b->yy_ch_buf);
                    if (b->yy_is_our_buffer) {
                        int new_size = b->yy_buf_size * 2;
                        if (new_size <= 0) {
                            new_size = b->yy_buf_size + (b->yy_buf_size >> 3);
                        }
                        b->yy_buf_size = new_size;
                    } else {
                        b->yy_ch_buf = NULL;
                    }
                    b->yy_ch_buf = (char *)realloc(b->yy_ch_buf, (size_t)(b->yy_buf_size + 2));
                    if (!b->yy_ch_buf) {
                        fprintf(stderr, "%s\n", (const char *)str_00228d5c);
                        exit(2);
                    }
                    yy_c_buf_p = b->yy_ch_buf + buf_offset;
                    num_to_read = b->yy_buf_size - (n_to_copy - 1);
                }

                if (num_to_read > 0x2001) num_to_read = 0x2000;

                if (b->yy_buffer_status == 2) {
                    yy_n_chars = 0;
                    b->yy_n_chars = 0;
                } else {
                    yy_n_chars = Scr_ScanFile(b->yy_ch_buf + (n_to_copy - 1), num_to_read);
                    b->yy_n_chars = yy_n_chars;
                }

                if (yy_n_chars == 0) {
                    if (n_to_copy - 1 == 0) {
                        /* True EOF */
                        /* Handle EOF: check if switching buffers */
                        /* For CoD2 scripting: just wrap up */
                        yy_did_buffer_switch_on_eof = 0;
                        yy_c_buf_p = yytext;
                        /* Return EOF token */
                        yy_act = (yy_start - 1) / 2 + 0x5f;
                        {
                            unsigned int p = g_out_pos; yylval.pos = p; g_sourcePos = p; g_out_pos = p + yyleng;
                        }
                        return yy_act;
                    } else {
                        b->yy_buffer_status = 2;
                    }
                }

                yy_n_chars += n_to_copy - 1;
                b->yy_ch_buf[yy_n_chars] = '\0';
                b->yy_ch_buf[yy_n_chars + 1] = '\0';
                yytext = b->yy_ch_buf;
                yy_c_buf_p = yytext + offset;
                goto restart_scan;
            }
        }
        default:
            /* Return 0 for unhandled actions */
            return 0;
        }
    }
}

int yyparse(void)
{
    short yyssa[200];
    stype_t yyvsa[200];
    char string_buf[0x2000];

    short *yyss = yyssa;
    stype_t *yyvs = yyvsa;
    short *yyssp = yyssa - 1;
    stype_t *yyvsp = yyvsa;
    int yystacksize = 200;
    int yystate = 0;
    int yyerrstatus = 0;
    int yyn;
    int yylen;
    stype_t yyval;

    yynerrs = 0;
    yychar = -2;

yysetstate:
    yyssp++;
    *yyssp = (short)yystate;

    if (yyssp >= yyss + yystacksize - 1) {
        int size = (int)(yyssp - yyss);
        if (yystacksize > 9999) goto yyoverflow;
        yystacksize *= 2;
        if (yystacksize > 10000) yystacksize = 10000;
        short *new_yyss = (short *)__builtin_alloca(yystacksize * sizeof(short));
        memcpy(new_yyss, yyss, (size + 1) * sizeof(short));
        stype_t *new_yyvs = (stype_t *)__builtin_alloca(yystacksize * sizeof(stype_t));
        memcpy(new_yyvs, yyvs, (size + 1) * sizeof(stype_t));
        yyssp = new_yyss + size;
        yyvsp = new_yyvs + size;
        if (yyssp >= new_yyss + yystacksize - 1) goto yyoverflow;
        yyss = new_yyss;
        yyvs = new_yyvs;
    }

    /* Look up action */
    {
        short pact_val = YYPACT(yystate);
        if (pact_val == (short)0x8000) goto yydefault;

        if (yychar == -2) {
            yychar = yyparse_yylex(string_buf);
        }

        int yytoken;
        if (yychar <= 0) { yychar = 0; yytoken = 0; }
        else if (yychar > 0x157) { yytoken = 0x74; }
        else { yytoken = YYTRANSLATE(yychar); }

        yyn = yytoken + (int)pact_val;
        if ((unsigned int)yyn > 0x520 || YYCHECK(yyn) != yytoken) goto yydefault;

        {
            short table_val = YYTABLE(yyn);
            int n = (int)table_val;
            if (n < 0) {
                if (table_val == (short)0x8000) goto yyerrlab;
                yyn = -n;
                goto yyreduce;
            }
            if (table_val == 0) goto yyerrlab;
            if (table_val == 0xff) return 0;

            /* Shift */
            if (yychar != 0) yychar = -2;
            yyvsp++;
            *yyvsp = yylval;
            if (yyerrstatus > 0) yyerrstatus--;
            yystate = n;
            goto yysetstate;
        }
    }

yydefault:
    {
        short defact_val = YYDEFACT(yystate);
        yyn = (int)defact_val;
        if (defact_val == 0) goto yyerrlab;
    }

yyreduce:
    yylen = (int)YYR2(yyn);
    if (yylen > 0) {
        yyval = yyvsp[1 - yylen];
    }

    if ((unsigned int)yyn > 0x82) goto yy_post_reduce;

    switch (yyn) {
    case 0: break;
    case 1:
        yaccResult.node = (int)node2_(yyvsp[-1].val.node, yyvsp[0].val.node);
        break;
    case 2:
        yaccResult.node = (int)node1(0x41, yyvsp[0].val.node);
        break;
    case 3:
        yaccResult.node = (int)node1(0x52, yyvsp[0].val.node);
        break;
    case 4:
        yaccResult.node = (int)node1(0x52, yyvsp[0].val.node);
        break;
    case 5:
        yyval.val.node = (int)node2(6, yyvsp[0].val.node, node_pos(yyvsp[0].pos));
        break;
    case 6: { unsigned int p1=node_pos(yyvsp[-2].pos), p2=node_pos(yyvsp[0].pos), p3=node_pos(yyvsp[-1].pos);
        yyval.val.node=(int)node5(0x2f,yyvsp[-2].val.node,yyvsp[0].val.node,p3,p2,p1); yyval.pos=yyvsp[-2].pos; break; }
    case 7: { unsigned int p1=node_pos(yyvsp[-2].pos), p2=node_pos(yyvsp[0].pos), p3=node_pos(yyvsp[-1].pos);
        yyval.val.node=(int)node5(0x30,yyvsp[-2].val.node,yyvsp[0].val.node,p3,p2,p1); yyval.pos=yyvsp[-2].pos; break; }
    case 8:  { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x66),p); yyval.pos=yyvsp[-1].pos; break; }
    case 9:  { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x67),p); yyval.pos=yyvsp[-1].pos; break; }
    case 10: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x68),p); yyval.pos=yyvsp[-1].pos; break; }
    case 11: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x69),p); yyval.pos=yyvsp[-1].pos; break; }
    case 12: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x6a),p); yyval.pos=yyvsp[-1].pos; break; }
    case 13: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x6b),p); yyval.pos=yyvsp[-1].pos; break; }
    case 14: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x6c),p); yyval.pos=yyvsp[-1].pos; break; }
    case 15: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x6d),p); yyval.pos=yyvsp[-1].pos; break; }
    case 16: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x6e),p); yyval.pos=yyvsp[-1].pos; break; }
    case 17: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x6f),p); yyval.pos=yyvsp[-1].pos; break; }
    case 18: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x70),p); yyval.pos=yyvsp[-1].pos; break; }
    case 19: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x71),p); yyval.pos=yyvsp[-1].pos; break; }
    case 20: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x72),p); yyval.pos=yyvsp[-1].pos; break; }
    case 21: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x73),p); yyval.pos=yyvsp[-1].pos; break; }
    case 22: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x74),p); yyval.pos=yyvsp[-1].pos; break; }
    case 23: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x31,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x75),p); yyval.pos=yyvsp[-1].pos; break; }
    case 24: yyval.val.node=(int)node2(0x32,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 25: yyval.val.node=(int)node2(0x33,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 26: yyval.val.node=(int)node1(0x41,yyvsp[0].val.node); break;
    case 27: yyval.val.node=(int)node0(0); break;
    case 28: yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd); yyval.val.node=yyvsp[0].val.node; break;
    case 29: yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd); yyval.val.node=yyvsp[0].val.node; break;
    case 30: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)node3(0x15,yyvsp[-2].val.node,yyvsp[0].val.node,node_pos(yyvsp[-1].pos));
        *(int*)((char*)imp_scrCompilePub+4)+=1; break; }
    case 31: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)node2(0x14,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break; }
    case 32: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)node3(0x15,yyvsp[-2].val.node,yyvsp[0].val.node,node_pos(yyvsp[-1].pos));
        yyval.pos=yyvsp[-1].pos; *(int*)((char*)imp_scrCompilePub+4)+=1; break; }
    case 33: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)node2(0x14,yyvsp[0].val.node,node_pos(yyvsp[-1].pos)); break; }
    case 34: yyval.val.node=(int)node2(0x12,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 35: yyval.val.node=(int)node2(0x16,yyvsp[-2].val.node,node_pos(yyvsp[-1].pos)); break;
    case 36: yyval.val.node=(int)node2(0x1a,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 37: { yyval.val.node=(int)node3(0x1e,yyvsp[0].val.node,node_pos(yyvsp[-1].pos),node_pos(yyvsp[0].pos)); yyval.pos=yyvsp[0].pos; break; }
    case 38: { yyval.val.node=(int)node3(0x17,yyvsp[-3].val.node,yyvsp[-1].val.node,node_pos(yyvsp[-2].pos)); yyval.pos=yyvsp[-2].pos; break; }
    case 39: { unsigned int p1=node_pos(yyvsp[-2].pos),p2=node_pos(yyvsp[-3].pos);
        yyval.val.node=(int)node5(0x18,yyvsp[-4].val.node,yyvsp[-3].val.node,yyvsp[-1].val.node,p2,p1); yyval.pos=yyvsp[-2].pos; break; }
    case 40: yyval.val.node=(int)node2(0x2e,yyvsp[-1].val.node,node_pos(yyvsp[-1].pos)); break;
    case 41: yyval.val.node=(int)node2(7,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 42: yyval.val.node=(int)node2(8,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 43: yyval.val.node=(int)node2(9,yyvsp[0].val.node,node_pos(yyvsp[-1].pos)); break;
    case 44: yyval.val.node=(int)node2(0xa,yyvsp[0].val.node,node_pos(yyvsp[-1].pos)); break;
    case 45: yyval.val.node=(int)node2(0xb,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 46: yyval.val.node=(int)node2(0xc,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 47: yyval.val.node=(int)node1(0x13,yyvsp[0].val.node); break;
    case 48: yyval.val.node=(int)node2(0x11,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 49: yyval.val.node=(int)node1(0x1f,node_pos(yyvsp[0].pos)); break;
    case 50: yyval.val.node=(int)node1(0x20,node_pos(yyvsp[0].pos)); break;
    case 51: yyval.val.node=(int)node1(0x22,node_pos(yyvsp[0].pos)); break;
    case 52: yyval.val.node=(int)node1(0x23,node_pos(yyvsp[0].pos)); break;
    case 53: yyval.val.node=(int)node1(0x24,node_pos(yyvsp[0].pos)); break;
    case 54: { yyval.val.node=(int)node2(0x34,yyvsp[-1].val.node,node_pos(yyvsp[-1].pos)); yyval.pos=yyvsp[0].pos; break; }
    case 55: yyval.val.node=(int)node2(0x12,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break;
    case 56: yyval.val.node=(int)node1(0x42,node_pos(yyvsp[-1].pos)); break;
    case 57: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)node2(0x43,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break; }
    case 58: yyval.val.node=(int)node1(0x48,node_pos(yyvsp[0].pos)); break;
    case 59: yyval.val.node=(int)node1(0x49,node_pos(yyvsp[0].pos)); break;
    case 60: yyval.val.node=(int)node1(0x4a,node_pos(yyvsp[0].pos)); break;
    case 61: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)node3(0xf,yyvsp[-2].val.node,yyvsp[0].val.node,node_pos(yyvsp[-1].pos)); yyval.pos=yyvsp[0].pos; break; }
    case 62: { unsigned int p1=node_pos(yyvsp[-1].pos),p2=node_pos(yyvsp[-2].pos);
        yyval.val.node=(int)node4(0xd,yyvsp[-3].val.node,yyvsp[-1].val.node,p2,p1); yyval.pos=yyvsp[-1].pos; break; }
    case 63: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)node2(4,yyvsp[0].val.node,node_pos(yyvsp[0].pos)); break; }
    case 64: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)node2(0x4f,yyvsp[0].val.node,node_pos(yyvsp[-1].pos)); break; }
    case 65: { yyval.val.node=(int)node2(0x35,yyvsp[-2].val.node,node_pos(yyvsp[-1].pos)); yyval.pos=yyvsp[0].pos; break; }
    case 66: { unsigned int p1=node_pos(yyvsp[0].pos),p2=node_pos(yyvsp[-1].pos);
        yyval.val.node=(int)node4(2,yyvsp[-2].val.node,yyvsp[0].val.node,p2,p1); break; }
    case 67: yyval.val.node=(int)node2(0x1b,yyvsp[0].val.node,node_pos(yyvsp[-1].pos)); break;
    case 68: yyval.val.node=(int)node1(0x1c,node_pos(yyvsp[0].pos)); break;
    case 69: { unsigned int p1=node_pos(yyvsp[-1].pos),p2=node_pos(yyvsp[0].pos);
        yyval.val.node=(int)node3(0x1d,yyvsp[0].val.node,p2,p1); break; }
    case 70: yyval.val.node=(int)node2(0x29,yyvsp[-1].val.node,node_pos(yyvsp[-1].pos)); break;
    case 71: yyval.val.node=(int)node2(0x2a,yyvsp[-1].val.node,node_pos(yyvsp[-1].pos)); break;
    case 72: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x66),p); break; }
    case 73: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x67),p); break; }
    case 74: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x68),p); break; }
    case 75: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x6f),p); break; }
    case 76: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x70),p); break; }
    case 77: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x71),p); break; }
    case 78: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x72),p); break; }
    case 79: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x73),p); break; }
    case 80: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x74),p); break; }
    case 81: { unsigned int p=node_pos(yyvsp[-1].pos); yyval.val.node=(int)node4(0x2b,yyvsp[-2].val.node,yyvsp[0].val.node,node1_(0x75),p); break; }
    case 82: { unsigned int p1=node_pos(yyvsp[-2].pos),p2=node_pos(yyvsp[-3].pos);
        yyval.val.node=(int)node4(0x37,yyvsp[-4].val.node,yyvsp[-1].val.node,p2,p1); break; }
    case 83: { unsigned int p1=node_pos(yyvsp[-2].pos),p2=node_pos(yyvsp[-3].pos);
        yyval.val.node=(int)node4(0x38,yyvsp[-4].val.node,yyvsp[-1].val.node,p2,p1); break; }
    case 84: yyval.val.node=(int)node1(0x39,node_pos(yyvsp[0].pos)); break;
    case 85: { unsigned int p1=node_pos(yyvsp[-2].pos),p2=node_pos(yyvsp[-3].pos);
        yyval.val.node=(int)node4(0x3a,yyvsp[-4].val.node,yyvsp[-1].val.node,p2,p1); break; }
    case 86: { unsigned int p1=node_pos(yyvsp[-1].pos),p2=node_pos(yyvsp[-3].pos);
        yyval.val.node=(int)node4(0x3b,yyvsp[-4].val.node,yyvsp[-1].val.node,p2,p1); break; }
    case 87: yyval.val.node=(int)node1(0x3f,node_pos(yyvsp[0].pos)); break;
    case 88: yyval.val.node=(int)node1(0x40,node_pos(yyvsp[0].pos)); break;
    case 89: yyval.val.node=(int)node1(0x4b,node_pos(yyvsp[0].pos)); break;
    case 90: yyval.val.node=(int)node2(0x4c,yyvsp[-1].val.node,node_pos(yyvsp[-2].pos)); break;
    case 91: yyval.val.node=(int)node2(0x4d,yyvsp[-1].val.node,node_pos(yyvsp[-2].pos)); break;
    case 92: yyval.val.node=(int)node1(0x19,yyvsp[0].val.node); break;
    case 93: break;
    case 94: yyval.val.node=(int)node0(0); break;
    case 95: case 96: break;
    case 97: { unsigned int p1=node_pos(yyvsp[0].pos),p2=node_pos(yyvsp[-1].pos);
        yyval.val.node=(int)node3(0x2c,yyvsp[-1].val.node,p2,p1); break; }
    case 98: { yyval.val.node=(int)node4(0x25,yyvsp[-2].val.node,yyvsp[0].val.node,node_pos(yyvsp[-1].pos),g_dummyVal.node); break; }
    case 99: { unsigned int p1=node_pos(yyvsp[-1].pos),p2=node_pos(yyvsp[-3].pos);
        yyval.val.node=(int)node7(0x26,yyvsp[-4].val.node,yyvsp[-2].val.node,yyvsp[0].val.node,p2,p1,g_dummyVal.node,g_dummyVal.node); break; }
    case 100: { unsigned int p1=node_pos(yyvsp[-3].pos),p2=node_pos(yyvsp[-1].pos);
        yyval.val.node=(int)node5(0x27,yyvsp[-2].val.node,yyvsp[0].val.node,p2,p1,g_dummyVal.node); break; }
    case 101: { unsigned int p1=node_pos(yyvsp[-6].pos),p2=node_pos(yyvsp[-3].pos);
        yyval.val.node=(int)node8(0x28,yyvsp[-5].val.node,yyvsp[-4].val.node,yyvsp[-2].val.node,yyvsp[0].val.node,p2,p1,g_dummyVal.node,g_dummyVal.node); break; }
    case 102: { yyval.val.node=(int)node3(0x3c,yyvsp[-4].val.node,yyvsp[-1].val.node,node_pos(yyvsp[-3].pos)); break; }
    case 103: { yyval.val.node=(int)node3(0x2d,yyvsp[-1].val.node,node_pos(yyvsp[-1].pos),g_dummyVal.node); break; }
    case 104: yyval.val.node=(int)node0(0); break;
    case 105: { yyval.val.node=(int)node3(0x3d,yyvsp[-1].val.node,node_pos(yyvsp[-1].pos),g_dummyVal.node); break; }
    case 106: { yyval.val.node=(int)node2(0x3e,node_pos(yyvsp[-1].pos),g_dummyVal.node); break; }
    case 107: break;
    case 108: yyval.val.node=(int)append_node(yyvsp[-1].val.node,yyvsp[0].val.node); break;
    case 109: yyval.val.node=(int)linked_list_end(node0(0)); break;
    case 110: { unsigned int n=node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos)); yyval.val.node=(int)prepend_node(n,yyvsp[-2].val.node); break; }
    case 111: { unsigned int n=node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos)); yyval.val.node=(int)prepend_node(n,node0(0)); break; }
    case 112: yyval.val.node=(int)node0(0); break;
    case 113: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)append_node(yyvsp[-2].val.node,node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos))); break; }
    case 114: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)append_node(linked_list_end(node0(0)),node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos))); break; }
    case 115: yyval.val.node=(int)linked_list_end(node0(0)); break;
    case 116: { yyvsp[0].val.node=(int)SL_ConvertToLowercase(yyvsp[0].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        yyval.val.node=(int)append_node(yyvsp[-2].val.node,node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos))); break; }
    case 117: { unsigned int n=node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos));
        yyval.val.node=(int)append_node(linked_list_end(node0(0)),n); break; }
    case 118: { unsigned int n=node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos));
        yyval.val.node=(int)append_node(yyvsp[-2].val.node,n); break; }
    case 119: { unsigned int n=node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos));
        yyval.val.node=(int)append_node(linked_list_end(node0(0)),n); break; }
    case 120: { unsigned int n=node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos));
        yyval.val.node=(int)prepend_node(n,yyvsp[-2].val.node); break; }
    case 121: { unsigned int n=node2_(yyvsp[0].val.node,node_pos(yyvsp[0].pos));
        yyval.val.node=(int)prepend_node(n,node0(0)); break; }
    case 122: { yyvsp[-6].val.node=(int)SL_ConvertToLowercase(yyvsp[-6].val.node,(unsigned int)(unsigned char)g_parse_user,0xd);
        unsigned int p1=node_pos(yyvsp[0].pos),p2=node_pos(yyvsp[-6].pos);
        yyval.val.node=(int)node6(0x44,yyvsp[-6].val.node,yyvsp[-4].val.node,yyvsp[-1].val.node,p2,p1,g_dummyVal.node); break; }
    case 123: { unsigned int p1=node_pos(yyvsp[-1].pos),p2=node_pos(yyvsp[-3].pos);
        yyval.val.node=(int)node3(0x47,yyvsp[-2].val.node,p2,p1); break; }
    case 124: yyval.val.node=(int)node1(0x45,node_pos(yyvsp[0].pos)); break;
    case 125: yyval.val.node=(int)node1(0x46,node_pos(yyvsp[0].pos)); break;
    case 126: yyval.val.node=(int)append_node(yyvsp[-1].val.node,yyvsp[0].val.node); break;
    case 127: yyval.val.node=(int)linked_list_end(node0(0)); break;
    case 128: { yyval.val.node=(int)node2(0x55,yyvsp[0].val.node,node_pos(yyvsp[-1].pos));
        *(int*)((char*)imp_scrCompilePub+4)+=1; break; }
    case 129: yyval.val.node=(int)append_node(yyvsp[-2].val.node,yyvsp[-1].val.node); break;
    case 130: yyval.val.node=(int)linked_list_end(node0(0)); break;
    default: break;
    }

yy_post_reduce:
    yyvsp -= yylen;
    yyssp -= yylen;
    yyvsp++;
    yyvsp->val = yyval.val;
    yyvsp->pos = yyval.pos;

    { int r1=(int)YYR1(yyn)-0x5a; int pg=(int)YYPGOTO(r1); int st=(int)*yyssp; int idx=pg+st;
      if((unsigned)idx<=0x520 && YYCHECK(idx)==st) yystate=(int)YYTABLE(idx);
      else yystate=(int)YYDEFGOTO(r1);
      goto yysetstate; }

yyerrlab:
    if (yyerrstatus == 0) {
        yynerrs++;
        if (yychar == 0) CompileError(g_sourcePos,(const char*)str_00228ce8);
        else if (yychar == 0x101) { /* fall through */ }
        else CompileError(g_sourcePos,(const char*)str_00228d08);
    }
    if (yyerrstatus == 3) {
        if (yychar == 0) return 1;
        yychar = -2;
    }
    for (;;) {
        short pv = YYPACT(*yyssp);
        if (pv != (short)0x8000) {
            int idx = (int)pv + 1;
            if ((unsigned)idx <= 0x520 && YYCHECK(idx) == 1) {
                short tv = YYTABLE(idx);
                int n = (int)tv;
                if (n < 0) { if (tv != (short)0x8000) { yyn=-n; yyerrstatus=3; goto yyreduce; } }
                else if (tv == 0) { }
                else if (tv == 0xff) return 0;
                else { yyvsp++; *yyvsp=yylval; yystate=n; yyerrstatus=3; goto yysetstate; }
            }
        }
        if (yyssp == yyss) return 1;
        yyvsp--; yystate=(int)*(yyssp-1); yyssp--;
    }

yyoverflow:
    { int ch=yychar;
      if(ch==0) CompileError(g_sourcePos,(const char*)str_00228ce8);
      else if(ch==0x101) { }
      else CompileError(g_sourcePos,(const char*)str_00228d08);
      return 2; }
}
