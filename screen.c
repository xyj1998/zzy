//contains screen manioulation functions, such as chearscreen gotoxy();
//setColor(), etc
#include "screen.h"
#include <stdio.h>
/*
	functiom definition of clearScreen()
	This function uses VT100 escape sequence \ESC[2J to make the whole
	terminal screen empty
	argument : no
	return : no
*/
void clearScreen(void){
	printf("%c[2J",ESC);
	fflush(stdout);
}
/*
	function definition of gotoxy()
	This function uses VT100 escape sequence \ESC[row,colH to set cursor
	to a sepcific location on the terminal screen
	arguement:	row number, 1 is top row
				col number. 1 is left colum
	return: no
*/
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);

}
/*
	function definition of SetColor()
	This function uses VT100 escape sequence \ESC[color,to change the color 
	for difference voice
	return: no
*/
void setColor(int color){
	if(color>=BLACK && color<=WHITE){
		printf("%c[1;%dm", ESC, color);
		fflush(stdout);
		}
}
/*
	function definition of bar()
	This function is to make the sound appear as a bar

*/
void bar(int col, double dB){
	int i;
	for(i=0; i<dB/4; i++){
		gotoxy(25-i, col);
#ifndef UNICODE
		printf("%c", '*');
#else
		if(i<60/4) setColor(WHITE);
		else if(i<80/4) setColor(YELLOW);
		else setColor(RED);
		printf("%s",BAR);
#endif
	}
}
