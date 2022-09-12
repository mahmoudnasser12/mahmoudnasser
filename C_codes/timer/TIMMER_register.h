#ifndef TIMERS_REGISTER_H_
#define TIMERS_REGISTER_H_
#define TIMSK       *((volatile u8*)0x59)
#define TIMSK_TOIE0     0
#define TCCR0_WGM00     6
#define TCCR0_WGM01     3

#define TCNT0   *((volatile u8*)0x52)

#endif 
