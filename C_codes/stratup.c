
#include <stdint.h>


void Defualt_Handler (void){
	
	Reset_Handler();
}

void NMI_Handler __attribute__ ((weak,alias,("Defualt_Handler")));
void H_fault_Handler  __attribute__ ((weak,alias,("Defualt_Handler")));


uint32_t vectors[] __attribute__((section(".vectors"))) ={
(uint32_t) 0x20001000,
(uint32_t) &Reset_Handler,
(uint32_t) &NMI_Handler,
(uint32_t) &H_fault_Handler,

};

extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;



void Reset_Handler (){
 
		// copy data section from flash to ram 
			unsigned int Data_size =  (unsigned char*) &_E_DATA - (unsigned char*) &_S_DATA;
			unsigned char* P_src = (unsigned char*) &_E_TEXT;
			unsigned char* P_dst = (unsigned char*) &_S_DATA;
			
			for (int i =0; i < Data_size; i++){
				*((unsigned char*) P_src++) = *((unsigned char*) p_dst++);
				
			}
			
			
		main();
}
