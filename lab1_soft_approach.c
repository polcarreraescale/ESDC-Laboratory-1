/*
 * lab1.c demo code
 *
 *  Created on: 13/09/2018
 *      Author: Josep Altet
*/



#include "xparameters.h"
#include "xgpio.h"

#define BACKGROUND 7
#define SQUARE 4
#define ROW_LOCATION 4


//====================================================

int main (void)
{

// Pointer and variable declaration
    XGpio rgb, push, leds, row, col;
	int pixel_row, pixel_col, row_loc, col_loc, color;

    xil_printf("-- Start of the Program --\r\n");

// Pointer initialization
// Check out your own XPAR ID symbol name declared in xparameters.h
// The format is always XPAR_<NAME_IN_VIVADO>_DEVICE_ID


	XGpio_Initialize(&push, XPAR_BUTTONS_DEVICE_ID);
	XGpio_SetDataDirection(&push, 1, 0xffffffff); //input

	XGpio_Initialize(&row, XPAR_READROW_DEVICE_ID);
	XGpio_SetDataDirection(&row, 1, 0xffffffff); //input

	XGpio_Initialize(&col, XPAR_READCOL_DEVICE_ID);
	XGpio_SetDataDirection(&col, 1, 0xffffffff); //input

	XGpio_Initialize(&leds, XPAR_LEDS_DEVICE_ID);
	XGpio_SetDataDirection(&leds, 1, 0x00000000); //output

	XGpio_Initialize(&rgb, XPAR_RGB_DEVICE_ID);
	XGpio_SetDataDirection(&rgb, 1, 0x00000000); //output

	row_loc = ROW_LOCATION;

	while (1)
	{
// Read value of buttons
	  col_loc = XGpio_DiscreteRead(&push, 1);


	  // Write value of buttons to leds. Optional.
	  //	  XGpio_DiscreteWrite(&leds, 1, col_loc);

	  //xil_printf("Push Buttons Status %x\r\n", psb_check);

// Read pixel rwo and pixel column
	  pixel_row = XGpio_DiscreteRead(&row, 1);
	  pixel_col = XGpio_DiscreteRead(&col, 1);



// Write RGB value  to xpos

	  color = ((pixel_row == row_loc) && (pixel_col == col_loc))?  SQUARE : BACKGROUND;
	  XGpio_DiscreteWrite(&rgb, 1, color);


	}

}
