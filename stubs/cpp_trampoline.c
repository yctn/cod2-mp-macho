/* Converted from stubs/cpp_trampoline.S */
/* Mac Mach-O triple-underscore → Linux ELF double-underscore trampolines */
#include <stddef.h>

extern void __cxa_allocate_exception(void);
extern void __cxa_begin_catch(void);
extern void __cxa_end_catch(void);
extern void __cxa_rethrow(void);
extern void __cxa_throw(void);
extern void _Unwind_Resume(void);
extern void _ZdaPv(void);
extern void _ZdlPv(void);
extern void _Znaj(void);
extern void _Znwj(void);
extern void _ZN9__gnu_cxx18__exchange_and_addEPVii(void);
extern void _ZNKSs4findEPKcjj(void);
extern void _ZNKSs7compareEPKc(void);
extern void _ZNSs12_M_leak_hardEv(void);
extern void _ZNSs4_Rep10_M_destroyERKSaIcE(void);
extern void _ZNSs6appendEPKcj(void);
extern void _ZNSs6appendERKSs(void);
extern void _ZNSs6assignEPKcj(void);
extern void _ZNSs6assignERKSs(void);
extern void _ZNSs7replaceEjjPKcj(void);
extern void _ZNSs7reserveEj(void);
extern void _ZNSs9_M_mutateEjjj(void);
extern void _ZNSsC1EPKcRKSaIcE(void);
extern void _ZNSsC1ERKSs(void);
extern void _ZNSsC1ERKSsjj(void);
extern void _ZNSsD1Ev(void);
extern void _ZNSt15_List_node_base4hookEPS_(void);
extern void _ZNSt15_List_node_base6unhookEv(void);
extern void _ZSt17__throw_bad_allocv(void);
extern void _ZSt20__throw_length_errorPKc(void);
extern void _ZSt20__throw_out_of_rangePKc(void);
extern void _ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base(void);
extern void _ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base(void);
extern void _ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_(void);
extern void _ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_(void);

void ___cxa_allocate_exception(void) { __cxa_allocate_exception(); }
void ___cxa_begin_catch(void) { __cxa_begin_catch(); }
void ___cxa_end_catch(void) { __cxa_end_catch(); }
void ___cxa_rethrow(void) { __cxa_rethrow(); }
void ___cxa_throw(void) { __cxa_throw(); }
void __Unwind_Resume(void) { _Unwind_Resume(); }
void __ZdaPv(void) { _ZdaPv(); }
void __ZdlPv(void) { _ZdlPv(); }
void __Znam(void) { _Znaj(); }
void __Znwm(void) { _Znwj(); }
void __ZN9__gnu_cxx18__exchange_and_addEPVii(void) { _ZN9__gnu_cxx18__exchange_and_addEPVii(); }
void __ZNKSs4findEPKcmm(void) { _ZNKSs4findEPKcjj(); }
void __ZNKSs7compareEPKc(void) { _ZNKSs7compareEPKc(); }
void __ZNSs12_M_leak_hardEv(void) { _ZNSs12_M_leak_hardEv(); }
void __ZNSs4_Rep10_M_destroyERKSaIcE(void) { _ZNSs4_Rep10_M_destroyERKSaIcE(); }
void __ZNSs6appendEPKcm(void) { _ZNSs6appendEPKcj(); }
void __ZNSs6appendERKSs(void) { _ZNSs6appendERKSs(); }
void __ZNSs6assignEPKcm(void) { _ZNSs6assignEPKcj(); }
void __ZNSs6assignERKSs(void) { _ZNSs6assignERKSs(); }
void __ZNSs7replaceEmmPKcm(void) { _ZNSs7replaceEjjPKcj(); }
void __ZNSs7reserveEm(void) { _ZNSs7reserveEj(); }
void __ZNSs9_M_mutateEmmm(void) { _ZNSs9_M_mutateEjjj(); }
void __ZNSsC1EPKcRKSaIcE(void) { _ZNSsC1EPKcRKSaIcE(); }
void __ZNSsC1ERKSs(void) { _ZNSsC1ERKSs(); }
void __ZNSsC1ERKSsmm(void) { _ZNSsC1ERKSsjj(); }
void __ZNSsD1Ev(void) { _ZNSsD1Ev(); }
void __ZNSt15_List_node_base4hookEPS_(void) { _ZNSt15_List_node_base4hookEPS_(); }
void __ZNSt15_List_node_base6unhookEv(void) { _ZNSt15_List_node_base6unhookEv(); }
void __ZSt17__throw_bad_allocv(void) { _ZSt17__throw_bad_allocv(); }
void __ZSt20__throw_length_errorPKc(void) { _ZSt20__throw_length_errorPKc(); }
void __ZSt20__throw_out_of_rangePKc(void) { _ZSt20__throw_out_of_rangePKc(); }
void __ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base(void) { _ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base(); }
void __ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base(void) { _ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base(); }
void __ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_(void) { _ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_(); }
void __ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_(void) { _ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_(); }

/* dynamic_cast: all casts in this codebase are valid downcasts — return source ptr */
void *___dynamic_cast(void *obj, ...) { return obj; }

int __ZNSs4_Rep11_S_terminalE = 0;
extern void _ZNSs4_Rep20_S_empty_rep_storageE(void);
void * const __ZNSs4_Rep20_S_empty_rep_storageE = (void *)(uintptr_t)_ZNSs4_Rep20_S_empty_rep_storageE;
static char __ZTIl[16] = {0};
