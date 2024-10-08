/*
 * file.h
 *
 *  Created on: 6 Sep 2022
 *      Author: p&p
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)      reg=reg|(1<<bit)
#define TOGLLE_BIT(reg,bit)   reg=reg^(1<<bit)
#define CLR_BIT(reg,bit)      reg=reg&(~(1<<bit))
#define GET_BIT(reg,bit)      ((reg>>bit)&1)


#endif /* BIT_MATH_H_ */
