/* 	File 		: 181511013.h
*	Deskripsi 	: Header dari modul yang dikerjakan oleh Febri
*	Dibuat Oleh	: Febriyoga Bagus Satria - 181511013
*/

#ifndef H_013
#define H_013
#include "..\game.h"

//FEBRI
void choose_sprite(int A[19][27], int temp, int lastkey);
void draw_sprite(int A[19][27], int temp, int lastkey);
void isi_temp(int A[19][27], int *temp, int lastkey);
bool isJatuh(int A[19][27], int temp);
void Jatuh(int A[19][27], int *temp, int *lastkey, int *loot_e);

#endif
