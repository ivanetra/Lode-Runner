/* 	File 		: 181511005.h
*	Deskripsi 	: Header dari modul yang dikerjakan oleh Aji
*	Dibuat Oleh	: Aji Muhammad Zafar - 181511005
*/

#ifndef H_005
#define H_005
#include "..\game.h"

//AJI
void KeyboardInput(int *key);
void GetMove(int A[19][27], int key, int *temp, int *lastkey, int *loot_e);
int hitung_loot(int A[19][27]);
int hitung_loote(int A[19][27], int *loot_e);
int hitung_skor(int A[19][27], int *temp);
void nameinput(int x, int y, char *title, int spacing, char name[10], int font, int direction, int charsize);
void bordernama();
void save_data(data player);
void cetak_leaderboard();
void hiScoreLayout();
void waktu(void *argc);

#endif


