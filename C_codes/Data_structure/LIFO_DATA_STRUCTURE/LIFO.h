//////Lifo.h //////////

// Type defentions for user 

typedef struct {
unsigned int length;
unsigned int count ;
unsigned int* base;
unsigned int* head;
}LIFO_Buf_t;

typedef enum {
LIFO_no_error,
LIFO_full,
LIFO_empty,
LIFO_null,

}LIFO_status;



////// apis

  LIFO_status LIFO_set_item (LIFO_Buf_t* lifo_buf, unsigned int item);

  LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf, unsigned int* item);


LIFO_status LIFO_Init ( LIFO_Buf_t* lifo_buf , unsigned int* buf, unsigned int length);


