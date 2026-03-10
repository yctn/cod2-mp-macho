SECTIONS
{
    /* Dynamic linker stuff first */
    . = SIZEOF_HEADERS;
    .interp : { *(.interp) }
    .hash : { *(.hash) }
    .gnu.hash : { *(.gnu.hash) }
    .dynsym : { *(.dynsym) }
    .dynstr : { *(.dynstr) }
    .gnu.version : { *(.gnu.version) }
    .gnu.version_r : { *(.gnu.version_r) }
    .rel.dyn : { *(.rel.dyn) }
    .rel.plt : { *(.rel.plt) }
    .init : { *(.init) }
    .plt : { *(.plt*) }
    .fini : { *(.fini) }

    /* Code at normal address */
    . = 0x08048000;
    .text : { *(.text .text.*) }

    /* Original strings section at original address */
    . = 0x00215000;
    .rodata.str : {
        strings.o(.rodata .rodata.*)
    }

    /* Original rodata at original address */
    . = 0x002edb00;
    .rodata.orig : {
        rodata.o(.rodata .rodata.*)
    }

    /* Original data */
    . = 0x00308000;
    .data.orig : {
        data.o(.data .data.*)
    }

    /* Original BSS */
    . = 0x00334700;
    .bss.orig (NOLOAD) : {
        bss.o(.bss COMMON)
        bss.o(COMMON)
    }

    /* Everything else goes after the original BSS end */
    . = 0x01960000;
    .rodata : { *(.rodata .rodata.*) }
    .eh_frame : { *(.eh_frame) }
    .eh_frame_hdr : { *(.eh_frame_hdr) }
    .data : { *(.data .data.*) }
    .got : { *(.got) }
    .got.plt : { *(.got.plt) }
    .dynamic : { *(.dynamic) }
    .bss (NOLOAD) : { *(.bss COMMON) *(COMMON) }
}
