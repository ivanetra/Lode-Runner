/* 	File 		: 181511013.h
*	Deskripsi 	: Header dari modul yang dikerjakan oleh Febri
*	Dibuat Oleh	: Febriyoga Bagus Satria - 181511013
*/

#ifndef H_013
#define H_013
#include "..\game.h"

//FEBRI

//Character Movement Image
void choose_sprite(address h, int temp, int lastkey, int posisi, bool *lastMoveSprite, bool *lastLadderSprite, bool *lastMoveMusic);
void draw_sprite(address h, int temp, int lastkey, int posisi, bool *lastMoveSprite, bool *lastLadderSprite, bool *lastMoveMusic);
void isi_temp(address h, int *temp, int lastkey, int posisi);

//Jatuh
bool isJatuh(address h, int temp);
void Jatuh(address h, int *temp, int *lastkey, int *loot_e);

#endif
