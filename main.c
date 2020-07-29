//
//  main.c
//  C13_Snake-C-RUS
//
//  Created by BassmanOff on 29.07.2020.
//

#include <stdlib.h>
#include <ncurses.h>

void gameloop(void){
	unsigned char gamego = 1;		// 1 - продолжить игру, 0 - завершить
	
	unsigned char Y = 10;			// Стартовая точку
	unsigned char X = 25;
	
	halfdelay(1);					// Ограничение ожидания ввода = 0.1 сек
									// Если установить больше змея замедлится
	
	unsigned char lastkey = 'd';	// Последняя нажатая клавиша из "wasd"
	
	unsigned short int ct_length = 0;
	
	unsigned char snake_end_Y;		// Координаты последней точки змеи
	unsigned char snake_end_X;
	
	while (gamego){
		move(Y, X);
		unsigned char inputkey = getch();
		switch (inputkey) {			// Считывание нажатой клавиши
			case 'w':
				lastkey = 'w';
				break;
			case 's':
				lastkey = 's';
				break;
			case 'a':
				lastkey = 'a';
				break;
			case 'd':
				lastkey = 'd';
				break;
			case 'q':
				gamego = 0;
			default:
				break;
		}
		
		switch (lastkey) {			// Движение в зависимости от
			case 'w':				// последней нажатой клавиши
				if (Y!=0){
					Y--;}
				break;
			case 's':
				if (Y!=23){
					Y++;}
				break;
			case 'a':
				if (X!=0){
					X--;}
				break;
			case 'd':
				if (X!=79){
					X++;}
				break;
		}
		
		printw("@");
		wrefresh(stdscr);
		
		
		for (unsigned short int Y = 0; Y < 79; Y++){
			for (unsigned short int X = 0; X < 23; X++){
				move(Y, X);
				(inch() == '@') ? (ct_length++) : (ct_length = ct_length);
			}
		}
	}
	
}

int main() {
	initscr();
	nocbreak();
	noecho();
	//napms(100);
	//beep();
	//flash();
	//wrefresh(stdscr);
	gameloop();
	endwin();
	system("clear");
	
}
