/*
Deskripsi	: Tipe data bentukan dan variabel global yang digunakan
*/

#ifndef variabel_H_
#define variabel_H_

#define scr_length 640
#define scr_width 640

typedef struct{
	short int jam, menit, detik,x;
}timegame;

typedef struct{
	char nama[10];
	int poin;
	//timegame waktu;
	int sumWaktu;
}data;

extern int i, j, skor, gameover;
extern char msg2[120], msg4[120];

#endif
