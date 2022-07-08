///// LIFO.c /////////
#include "LIFO.h"

 LIFO_status LIFO_set_item (LIFO_Buf_t* lifo_buf, unsigned int item){
 // to add new item 
 // check lifo is valid
 if (! lifo_buf -> base || lifo_buf -> head)
 return lifo_null;
 // check lifo is full 
//  if (lifo_buf -> head == (lifo_buf -> base + (lifo_buf -> length * 4)
 // or we could check with this 
 if (lifo_buf -> count == lifo_buf -> length )
 return lifo_full;
  *(lifo_buf -> head) = item;
  lifo_buf -> head++;
  lifo_buf -> count++;
 
 return LIFO_no_error;
 }
 
 

 LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf, unsigned int* item){
	 
	 // check lifo is valid
 if (! lifo_buf -> base || lifo_buf -> head)
 return lifo_null;
	 
	 // check lifo is full
	 
	 if (lifo_buf -> count == 0 )
	 return lifo_empty;
	 lifo_buf -> head --;
	 *item = lifo_buf -> head;
	 lifo_buf -> count--;
	  return LIFO_no_error;
 }


LIFO_status LIFO_Init ( LIFO_Buf_t* lifo_buf , unsigned int* buf, unsigned int length) {
if (lifo_buf == NULL)
return lifo_null; 
lifo_buf -> base = buf;
lifo_buf ->  head = buf;
lifo_buf -> length = length;
lifo_buf -> count = 0;
return lifo_no_error;
