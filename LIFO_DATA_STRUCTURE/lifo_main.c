/////////////////////////////////// main file 


#include "LIFO"
#include <stdio.h>
unsigned int buffer1 [100];
unsigned int buffer2 [100];


int main(){
int i , temp = 0;
LIFO_Buf_t uart_lifo, i2c_lifo;

LIFO_Init (&uart_lifo, buffer1);


for (i =0; i <5, i++){
 LIFO_set_item  (&uart_lifo , i);
 printf (LIFO is %d /n, i);
 


}

for (i =0; i <5, i++){
 LIFO_get_item  (&uart_lifo , temp);
 printf (LIFO is %d /n, temp);
 


}