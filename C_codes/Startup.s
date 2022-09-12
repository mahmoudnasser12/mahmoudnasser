/* stratup code for cortex M3 */

/* sp */
.section .vectors
.word 0x200001000
.word _reset
.word Vector_Handler 


.section .text
_reset:
bl main()
b .
.thumb_func
Vector_Handler:
b _reset