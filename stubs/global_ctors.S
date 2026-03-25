/* Register C++ global constructors in .init_array */
/* These were originally in __mod_init_func in the Mach-O binary */

.section .init_array,"aw",@init_array

.long GLOBAL__I__ZN7COpenGL7sOpenGLE
