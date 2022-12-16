/*
 * GIE_program.c
 *
 * Created on: 12/13/2022 3:22:35 PM
 *      Author: Ahmed Abdallah
 */
#include"../../Utilities/STD_TYPES.h"
#include"../../Utilities/BIT_MATH.h"
#include"GIE_interface.h"
#include"GIE_privit.h"

void GIE_enable(void)
{
	SET_BIT(SREG,7);
}
void GIE_disable(void)
{
	CLR_BIT(SREG,7);
}
