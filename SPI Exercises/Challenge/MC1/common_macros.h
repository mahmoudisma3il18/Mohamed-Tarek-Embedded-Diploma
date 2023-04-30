#pragma once 

#define  SET_BIT(PORT,BIT)        (PORT = PORT |  (1<<BIT))
#define  CLEAR_BIT(PORT,BIT)      (PORT = PORT & ~(1<<BIT))
#define  TOGGLE_BIT(PORT,BIT)     (PORT = PORT ^  (1<<BIT))

#define  BIT_IS_SET(PORT,BIT)     (PORT & (1<<BIT))
#define  BIT_IS_CLEAR(PORT,BIT)   (!(PORT & (1<<BIT)))