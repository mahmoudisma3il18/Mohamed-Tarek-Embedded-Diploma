/*
 * common_macros.h
 *
 * Created: 10/16/2022 8:24:32 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


#define SET_BIT(REG,BIT)         (REG |= (1<<BIT))
#define CLEAR_BIT(REG,BIT)       (REG &= ~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)      (REG ^= (1<<BIT))

#define BIT_IS_SET(REG,BIT)      (REG & (1<<BIT))
#define BIT_IS_CLEAR(REG,BIT)    (!(REG & (1<<BIT)))



#endif /* COMMON_MACROS_H_ */