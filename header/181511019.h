/* 	File 		: 181511019.h
*	Deskripsi 	: Header dari modul yang dikerjakan oleh Lia
*	Dibuat Oleh	: Lia Purnamasari - 181511019
*/

#ifndef H_019
#define H_019
#include "..\game.h"

//LIA PURNAMASARI

//Linked List
bool isEmpty (address p);
void Create_Node (address *p);
void Ins_Akhir (address *p, address pNew);
void Isi_Node (address *p , int lvl[19][27]);

//MAP & Posisi Karakter
void MAP(address *curMAP);
void show_map(address h);
void posisi_karakter(int level);
void draw_object(address h, int brs, int klm);

//Boolean untuk mengetahui objek di sekitar karakter
bool isBlank(int object);
bool isTembok(int object);
bool isTali(int object);
bool isTangga(int object);
bool isHarta(int object);
bool isBeton(int object);
bool isLubang(int object);

//Levelling 
bool isLevelUp(int level, int loot_e);
void LevelUp(address *h, int *level, int *complete);

//Life
int hitung_nyawa(address h, int *temp, int *life, int level);
bool isNyawa_berkurang(address h, int temp);


#endif


