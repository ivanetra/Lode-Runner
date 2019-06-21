/* 	File 		: 181511049.h
*	Deskripsi 	: Header dari modul yang dikerjakan oleh Ivan
*	Dibuat Oleh	: Ivan Eka Putra - 181511049
*/

#ifndef H_049
#define H_049
#include "..\game.h"

//IVAN EKA PUTRA

/*void init_array(int A[19][27], int level);*/

//Gameplay
void game();

//Drill
void Drill(void * arg);
bool isMauDrill(int key);
void GetDrill(address h, int key, int *lastkey, int posisi, bool *lastMoveSprite, bool *lastLadderSprite, bool *lastMoveMusic);
bool isHabisDrill(int p);

//Game
bool isGameCompleted(int complete);
bool isGameOver(address h, int temp, int level, int life, int complete);
void GameOver(data rekap, char name[10], int level, int complete);
bool isTerjebak(address h, int temp);

//Objective
bool isObjectiveClear(int level, int loot_e);
void IncrementChestObjectiveNumber(int nChest);
void ShowObjective(int level);

// Audio
void PlayMusic(char musicName);

#endif
