/* 	File 		: 181511049.cpp
*	Deskripsi 	: Body dari modul yang dikerjakan oleh Ivan
*	Dibuat Oleh	: Ivan Eka Putra - 181511049
*/

#include "header/181511049.h"

int (*B)[27];
int lastkey_;

void init_array(int A[19][27], int level){
	int b,k;
	for(b=0; b<19; b++){
		for(k=0; k<27; k++){
			A[b][k]=MAP(level, b, k);
		}
	}
}

void Drill(void * arg){
    int baris, kolom;
    if(lastkey_ == 5){
        baris = i + 1;
        kolom = j - 1;
    } else {
        baris = i + 1;
        kolom = j + 1;
    }
    B[baris][kolom] = 7;
    readimagefile("gambar//Obj_Blank.jpg", 0+32*kolom, 0+32*baris, 32+32*kolom, 32+32*baris);
    delay(1000);
    B[baris][kolom] = 1;
    readimagefile("gambar//Obj_Hancur.jpg", 0+32*kolom, 0+32*baris, 32+32*kolom, 32+32*baris);
    delay(1000);
    readimagefile("gambar//Obj_Balok.jpg", 0+32*kolom, 0+32*baris, 32+32*kolom, 32+32*baris);
    _endthread();
}

void GetDrill(int A[19][27], int key, int *lastkey){
	if((key == 65 || key == 97) && isTembok(A[i + 1][j - 1])){
            *lastkey = 5; lastkey_=*lastkey;
            draw_sprite(A, A[i][j], *lastkey);
            _beginthread(Drill, 0, NULL);
	}else if((key == 83 || key == 115) && isTembok(A[i + 1][j + 1])){
            *lastkey = 6; lastkey_=*lastkey;
            draw_sprite(A, A[i][j], *lastkey);
        	_beginthread(Drill, 0, NULL);
            }
}

bool isTerjebak(int A[19][27], int temp){
	if((isBeton(A[i+1][j]) || isTembok(A[i+1][j])) && (isBeton(A[i][j+1]) || isTembok(A[i][j+1])) && (isBeton(A[i][j-1]) || isTembok(A[i][j-1])) && isLubang(temp)){
		return true;
	} else {
		return false;
	}
}

bool isGameOver(int A[19][27], int temp, int level, int life){
	if(life == 0 || level>3){
		printf("\nGAMEOVER");
		gameover = 1;
		return true;
	} else {
		return false;
	}

}

void GameOver(data rekap, char name[10], int level){
		delay(2000);
		strcpy(rekap.nama,name);
		rekap.poin=skor;
		save_data(rekap);
		if(level>3){
			settextjustify(LEFT_TEXT, TOP_TEXT);
			outtextxy(450,250,"GAME OVER....");
			settextjustify(LEFT_TEXT, TOP_TEXT);
			outtextxy(470,270,"YOU WIN");
		} else {
			settextjustify(LEFT_TEXT, TOP_TEXT);
			outtextxy(450,250,"GAME OVER....");
			settextjustify(LEFT_TEXT, TOP_TEXT);
			outtextxy(470,270,"YOU LOSE");
		}
		delay(4000);
		cleardevice();
		main_menu();
}


bool isHabisDrill(int p){
	if (p==5 || p==6){
		return true;
	} else {
		return false;
	}
}

bool isMauDrill(int key){
	if (key==65 || key==97 || key==83 || key==115){
		return true;
	} else {
		return false;
	}
}

void game(int A[19][27]){
	//VARIABEL LOKAL
	B = A;
	int temp=0; sprintf(msg2,"Temp  : %d",temp); outtextxy(20,640,msg2);
	int key;
	int lastkey=0;
	int life=5;
	char name[10];
	char msg3[20];
	data rekap;
	skor=0;
	int level=1; //Game dimulai dari Level 1


	//INPUT NAMA
	setbkcolor(BLACK);
	cleardevice();
	settextjustify(LEFT_TEXT, TOP_TEXT);
	nameinput(441, 290, "YOUR NAME:              ", 220, name, COMPLEX_FONT, LEFT_TEXT, 3);
	cleardevice();

	//GAMEPLAY
	_beginthread(waktu,0,NULL);
	while(!isGameOver(A, temp, level, life)){
		gameover=0;
		init_array(A, level);//Menginisialisasi Array A sesuai level yang dimainkan
		show_map(A);		//Menggambar Peta sesuai isi Array A
		ShowObjective(level);
		int loot=hitung_loot(A);//Variabel penyimpan jumlah loot yang tersedia dalam satu level
		int loot_e=0;			//Variabel penyimpan jumlah loot yang telah didapat

		while(!isLevelUp(loot, loot_e) && !isGameOver(A, temp, level, life)){
			sprintf(msg3,"Level  : %d",level); outtextxy(260,620,msg3); //Menampilkan Level yang sedang dimainkan

			//Melakukan perubahan nilai terhadap SKOR, NYAWA & HARTA yang telah didapat
			skor = hitung_skor(A, &temp);
			life=hitung_nyawa(A, &temp, &life, level);
			loot_e=hitung_loote(A, &loot_e);

			//Jika tidak habis melakukan Drill, gambar karakter
			if (!isHabisDrill(lastkey)){
				draw_sprite(A, temp, lastkey);
			}

			//Jika kondisi akan jatuh TRUE, masukkan key 80 (DOWN)
            if(isJatuh(A, temp)){
            	key = 80;
            	delay(100);
        	}else{
        			key=(getch()); printf("KEY = %d", key);
                	KeyboardInput(&key);
        	}

        	//Jika key yang diinput adalah key melakukan drill, mulai thread drill
            if(isMauDrill(key)){
            	printf("\nDRILL");
            	GetDrill(A, key, &lastkey);
			} else { //Jika bukan, maka karakter akan bergerak sesuai key
				draw_object(A, i, j);
				printf("\nMOVE");
				GetMove(A, key, &temp, &lastkey, &loot_e);
			}
		}
		if(isLevelUp(loot, loot_e)){
			LevelUp(A, &level);
		}
	}
	GameOver(rekap, name, level);
}

void ShowObjective(int level){
    // Display objective board image
    readimagefile("gambar//Objective-Board.jpg", 903, 38, 1203, 680);

    settextstyle(4, HORIZ_DIR, 2);

    // Display initial state chest objective number
    switch(level){
        case 1:
            outtextxy(1033, 162, "0/3");
            break;
        case 2:
            outtextxy(1033, 162, "0/2");
            break;
        case 3:
            outtextxy(1033, 162, "0/2");
            break;
    }
}

void IncrementChestObjectiveNumber(int nChest){
    // Increment chest objective number
    switch(nChest){
        case 1:
            outtextxy(1033, 162, "1");
            break;
        case 2:
            outtextxy(1033, 162, "2");
            break;
        case 3:
            outtextxy(1033, 162, "3");
            break;
    }
}
