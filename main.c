/*
 * On-demand Traffic light controlSystem.c
 *
 * Created: 12/7/2022 5:39:12 PM
 * Author : Ahmed Abdallah
 */ 

#include "Application/App.h"
#include<stdio.h>
#define F_CPU 1000000
#include<util\delay.h>

int main(void)
{
	
	//enable global interrupt
	GIE_enable();
	//enable external interrupt 0
	EXIT_INT();
//Initialize	
  APP_init();
//infinite Loop
 
    while (1) 
    {
    ISR_CALLBACK();
    APP_start();
	}
	
}

