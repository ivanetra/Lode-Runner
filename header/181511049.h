/* 	File 		: 181511049.h
*	Deskripsi 	: Header dari modul yang dikerjakan oleh Ivan
*	Dibuat Oleh	: Ivan Eka Putra - 181511049
*/

#ifndef H_049
#define H_049
#include "..\game.h"

//IVAN
void init_array(int A[19][27], int level);
void game(int A[19][27]);
void Drill(void * arg);
bool isMauDrill(int key);
void GetDrill(int A[19][27], int key, int *lastkey);
bool isHabisDrill(int p);
bool isGameOver(int A[19][27], int temp, int level, int life);
void GameOver(data rekap, char name[10], int level);
bool isTerjebak(int A[19][27], int temp);

#endif
