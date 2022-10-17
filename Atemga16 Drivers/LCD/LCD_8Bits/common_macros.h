/*
 * common_macros.h
 *
 * Created: 10/17/2022 2:25:07 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define SET_BIT(REG,BIT)      (REG |= (1<<BIT))
#define CLEAR_BIT(REG,BIT)    (REG &= ~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)   (REG ^= (1<<BIT))

#define BIT_IS_SET            (REG & (1<<BIT))
#define BIT_IS_CLEAR          (!(REG & (1<<BIT)))
 


#endif /* COMMON_MACROS_H_ */