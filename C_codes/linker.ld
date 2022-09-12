Memory {
    flash(RX) : ORGIN = 0x08000000 LENGTH = 128K
    SRAM(RWX) : ORGIN = 0x20000000 LENGTH = 20K
   
}
SECTIONS{
    .text: {
        *(.vectors*)
        *(.text*)
        *(.rodata)
		_E_TEXT = . ;
    }> flash
    
    .data : {
        _S_DATA = . ;

		*(.data)
		.= ALIGN(4);
		_E_DATA =. ;

    } sram AT> flash
    
	.bss {
	_S_bss = .;
        *(.bss)
	_E_bss = .;
    }
    
    
    
    
}