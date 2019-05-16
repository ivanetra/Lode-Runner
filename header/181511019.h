/* 	File 		: 181511019.h
*	Deskripsi 	: Header dari modul yang dikerjakan oleh Lia
*	Dibuat Oleh	: Lia Purnamasari - 181511019
*/

#ifndef H_019
#define H_019
#include "..\game.h"

//LIA
int MAP(int level, int baris, int kolom);
void show_map(int A[19][27]);
void draw_object(int A[19][27], int brs, int klm);
bool isBlank(int object);
bool isTembok(int object);
bool isTali(int object);
bool isTangga(int object);
bool isHarta(int object);
bool isBeton(int object);
bool isLubang(int object);
bool isLevelUp(int loot, int loot_e);
void LevelUp(int A[19][27], int *level);
int hitung_nyawa(int A[19][27], int *temp, int *life, int level);
bool isNyawa_berkurang(int A[19][27], int temp);
void posisi_karakter(int level);

#endif


