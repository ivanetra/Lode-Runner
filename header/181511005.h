/* 	File 		: 181511005.h
*	Deskripsi 	: Header dari modul yang dikerjakan oleh Aji
*	Dibuat Oleh	: Aji Muhammad Zafar - 181511005
*/

#ifndef H_005
#define H_005
#include "..\game.h"

//AJI MUHAMMAD ZAFAR

//Movement
void KeyboardInput( address h, int *temp, int *lastkey, int *posisi, bool *lastMoveSprite, bool *lastLadderSprite, bool *lastMoveMusic);
void moveUP(address h, int *temp, int *lastkey, int tempbfr, int posisi);
void moveDOWN(address h, int *temp, int *lastkey, int posisi);
void moveRIGHT(address h, int *temp, int *lastkey, int *posisi);
void moveLEFT(address h, int *temp, int *lastkey, int *posisi);

//Scoring
int hitung_loot(address h);
int hitung_loote(address h, int *loot_e);
int hitung_skor(address h, int *temp);

//Input Nama
void nameinput(int x, int y, char *title, int spacing, char name[10], int font, int direction, int charsize);
void bordernama();


void save_data(data player);
void cetak_leaderboard();
void hiScoreLayout();
void waktu(void *argc);

#endif


