//
//  main.c
//  C13_Snake-C-RUS
//
//  Created by BassmanOff on 29.07.2020.
//

#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

void gameloop(void){
	bool gamego = 1;				// 1 - продолжить игру, 0 - завершить
	
	unsigned char Y = 10;			// Стартовая точка
	unsigned char X = 25;
	
	unsigned char tailY = 10;
	unsigned char tailX = 22;
	
	halfdelay(1);					// Ограничение ожидания ввода = 0.1 сек
									// Если установить больше змея замедлится
	
	unsigned char lastkey = 'd';	// Последняя нажатая клавиша из "wasd"
	
	unsigned short int max_length = 3;
	
	//char snake_Y[1920];				// Здесь лежат все координаты, которые
	//char snake_X[1920];				// занимает змея
	//
	//snake_Y[0] = Y;					// Координаты начальной точки
	//snake_X[0] = X;
	
	char direction_queue[1920];
	
	while (gamego){
		move(Y, X);
		unsigned char inputkey = getch();
		switch (inputkey) {			// Считывание нажатой клавиши
			case 'w':
				lastkey = 'w';		// Можно использовать только
				break;				// wasd и q для выхода
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
					Y--;
					strcat(direction_queue, "w");}
				break;
			case 's':
				if (Y!=23){
					Y++;
					strcat(direction_queue, "s");}
				break;
			case 'a':
				if (X!=0){
					X--;
					strcat(direction_queue, "a");}
				break;
			case 'd':
				if (X!=79){
					X++;
					strcat(direction_queue, "d");}
				break;
		}
		printw("@");
		wrefresh(stdscr);
		
		move(tailY, tailX);
		printw(" ");
		
		switch (direction_queue[6]) {	// Движение хвоста в зависимости
			case 'w':					// от очереди
				tailY--;
				move(tailY, tailX);
				printw("#");
				direction_queue[6] = 0;
				break;
			case 's':
				tailY++;
				move(tailY, tailX);
				printw("#");
				direction_queue[6] = 0;
				break;
			case 'a':
				tailX--;
				move(tailY, tailX);
				printw("#");
				direction_queue[6] = 0;
				break;
			case 'd':
				tailX++;
				move(tailY, tailX);
				printw("#");
				direction_queue[6] = 0;
				break;
		}
		for (int iDirQueue = 6; iDirQueue < 1919; iDirQueue++){
			direction_queue[iDirQueue] = direction_queue[iDirQueue+1];
		}
		printw(" %c", direction_queue[6]);
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
