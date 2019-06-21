/* 	File 		: 181511049.cpp
*	Deskripsi 	: Body dari modul yang dikerjakan oleh Ivan
*	Dibuat Oleh	: Ivan Eka Putra - 181511049
*/

#include "header/181511049.h"

address h;
int lastkey_;

/*void init_array(int A[19][27], int level){
	int b,k;
	for(b=0; b<19; b++){
		for(k=0; k<27; k++){
			A[b][k]=MAP(level, b, k);
		}
	}
}*/

void PlayMusic(char musicName){
    switch (musicName){
        case DRILL:
            PlaySound("D:\\Ivan (My Documents)\\Ivan\\Politeknik Negeri Bandung\\2018\\Proyek Perangkat Lunak 2\\Beta (V7.6)\\wav\\Drill.wav", NULL, SND_ASYNC | SND_FILENAME);
            break;
        case SCORE:
            PlaySound("D:\\Ivan (My Documents)\\Ivan\\Politeknik Negeri Bandung\\2018\\Proyek Perangkat Lunak 2\\Beta (V7.6)\\wav\\Chess.wav", NULL, SND_ASYNC | SND_FILENAME);
            break;
        case MOVE1:
            PlaySound("D:\\Ivan (My Documents)\\Ivan\\Politeknik Negeri Bandung\\2018\\Proyek Perangkat Lunak 2\\Beta (V7.6)\\wav\\Move 1.wav", NULL, SND_ASYNC | SND_FILENAME);
            break;
        case MOVE2:
            PlaySound("D:\\Ivan (My Documents)\\Ivan\\Politeknik Negeri Bandung\\2018\\Proyek Perangkat Lunak 2\\Beta (V7.6)\\wav\\Move 2.wav", NULL, SND_ASYNC | SND_FILENAME);
            break;
        case MOVEONLADDER1:
            PlaySound("D:\\Ivan (My Documents)\\Ivan\\Politeknik Negeri Bandung\\2018\\Proyek Perangkat Lunak 2\\Beta (V7.6)\\wav\\Move on Ladder 1.wav", NULL, SND_ASYNC | SND_FILENAME);
            break;
        case MOVEONLADDER2:
            PlaySound("D:\\Ivan (My Documents)\\Ivan\\Politeknik Negeri Bandung\\2018\\Proyek Perangkat Lunak 2\\Beta (V7.6)\\wav\\Move on Ladder 2.wav", NULL, SND_ASYNC | SND_FILENAME);
            break;
        case MOVEONROPE1:
            PlaySound("D:\\Ivan (My Documents)\\Ivan\\Politeknik Negeri Bandung\\2018\\Proyek Perangkat Lunak 2\\Beta (V7.6)\\wav\\Move on Rope 1.wav", NULL, SND_ASYNC | SND_FILENAME);
            break;
        case MOVEONROPE2:
            PlaySound("D:\\Ivan (My Documents)\\Ivan\\Politeknik Negeri Bandung\\2018\\Proyek Perangkat Lunak 2\\Beta (V7.6)\\wav\\Move on Rope 2.wav", NULL, SND_ASYNC | SND_FILENAME);
            break;
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
    printf("\nDRILL\n");
    h->map[baris][kolom] = 7;
    readimagefile("gambar//Obj_Blank.jpg", 0+32*kolom, 0+32*baris, 32+32*kolom, 32+32*baris);
    delay(1000);
    h->map[baris][kolom] = 1;
    readimagefile("gambar//Obj_Hancur.jpg", 0+32*kolom, 0+32*baris, 32+32*kolom, 32+32*baris);
    delay(1000);
    readimagefile("gambar//Obj_Balok.jpg", 0+32*kolom, 0+32*baris, 32+32*kolom, 32+32*baris);
    ;
    _endthread();
}

void GetDrill(address h, int key, int *lastkey, int posisi, bool *lastMoveSprite, bool *lastLadderSprite, bool *lastMoveMusic){
	if((key == 65 || key == 97) && isTembok(h->map[i + 1][j - 1])){
            *lastkey = 5; lastkey_=*lastkey;
            draw_sprite(h, h->map[i][j], *lastkey, posisi, &(*lastMoveSprite), &(*lastLadderSprite), &(*lastMoveMusic));
            printf("\nGETDRILL\n");
            PlayMusic(DRILL);
            _beginthread(Drill, 0, NULL);
	}else if((key == 83 || key == 115) && isTembok(h->map[i + 1][j + 1])){
            *lastkey = 6; lastkey_=*lastkey;
            draw_sprite(h, h->map[i][j], *lastkey, posisi, &(*lastMoveSprite), &(*lastLadderSprite), &(*lastMoveMusic));
        	PlayMusic(DRILL);
        	_beginthread(Drill, 0, NULL);
            }
}

bool isTerjebak(address h, int temp){
	if((isBeton(h->map[i+1][j]) || isTembok(h->map[i+1][j])) && (isBeton(h->map[i][j+1]) || isTembok(h->map[i][j+1])) && (isBeton(h->map[i][j-1]) || isTembok(h->map[i][j-1])) && isLubang(temp)){
		return true;
	} else {
		return false;
	}
}

bool isGameOver(address h, int temp, int level, int life, int complete){
	if(life == 0 || isGameCompleted(complete)){
		printf("\nGAMEOVER");
		gameover = 1;
		return true;
	} else {
		return false;
	}
}

bool isGameCompleted(int complete){
	if (complete == 1){
		return true;
	} else {
		return false;
	}
}

void GameOver(data rekap, char name[10], int level, int complete){
		delay(2000);
		strcpy(rekap.nama,name);
		rekap.poin=skor;
		save_data(rekap);
		if(complete==1){
			settextjustify(LEFT_TEXT, TOP_TEXT);
			outtextxy(450,250,"CONGRATULATIONS");
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

void game(){

	//VARIABEL LOKAL
	MAP(&h);
	int complete=0;
	int temp=0;
	int key;
	int lastkey=0;
	int life=5;
	data rekap;
	skor=0;
	int level=1; //Game dimulai dari Level 1
	int posisi=1;

	//INPUT NAMA
	char name[10];
	setbkcolor(BLACK);
	cleardevice();
	settextjustify(LEFT_TEXT, TOP_TEXT);
	nameinput(441, 290, "YOUR NAME:              ", 220, name, COMPLEX_FONT, LEFT_TEXT, 3);
	cleardevice();

	//GAMEPLAY
	while(!isGameOver(h, temp, level, life, complete)){
        bool lastMoveSprite = GERAKKIRI5;
        bool lastLadderSprite = NAIKTANGGA1;
        bool lastMoveMusic;

		gameover=0;

		//Menggambar Peta sesuai isi Array yang ditunjuk oleh pointer h
		show_map(h);

		//Mendefinisikan posisi karakter sesuai level
		posisi_karakter(level);

		//Menampilkan Objective
		ShowObjective(level);

		int loot=hitung_loot(h);//Variabel penyimpan jumlah loot yang tersedia dalam satu level
		int loot_e=0;			//Variabel penyimpan jumlah loot yang telah didapat

		while(!isLevelUp(level, loot_e) && !isGameOver(h, temp, level, life, complete)){
			sprintf(msg,"Level  : %d",level); outtextxy(260,620,msg); //Menampilkan Level yang sedang dimainkan
			sprintf(msg,"Temp  : %d",temp); outtextxy(20,640,msg); //Menampilkan kode objek yang sedang ditimpa gambar karakter

			//Melakukan perubahan nilai terhadap SKOR, NYAWA & HARTA yang telah didapat
			skor = hitung_skor(h, &temp);
			life=hitung_nyawa(h, &temp, &life, level);
			loot_e=hitung_loote(h, &loot_e);

			//Jika tidak habis melakukan Drill, gambar karakter
			if (!isHabisDrill(lastkey)){
				draw_sprite(h, temp, lastkey, posisi, &lastMoveSprite, &lastLadderSprite, &lastMoveMusic);
			}

			//MOVEMENT & ACTION
            if(isJatuh(h, temp)){
            	moveDOWN(h, &temp, &lastkey, posisi);
            	delay(100);
        	}else{
                KeyboardInput(h, &temp, &lastkey, &posisi, &lastMoveSprite, &lastLadderSprite, &lastMoveMusic);
        	}
		}
		if(isLevelUp(level, loot_e)){
				LevelUp(&h, &level, &complete);
		}
	}
	GameOver(rekap, name, level, complete);
}

bool isObjectiveClear(int level, int loot_e){
	switch(level){
		case 1:{
			if (loot_e==1){
				return true;
			} else {
				return false;
			}
			break;
		}
		case 2:{
			if (loot_e==2){
				return true;
			} else {
				return false;
			}
			break;
		}
		case 3:{
			if (loot_e==3){
				return true;
			} else {
				return false;
			}
			break;
		}
		case 4:{
			if (loot_e==4){
				return true;
			} else {
				return false;
			}
			break;
		}
		case 5:{
			if (loot_e==5){
				return true;
			} else {
				return false;
			}
			break;
		}
		case 6:{
			if (loot_e==6){
				return true;
			} else {
				return false;
			}
			break;
		}
	}
}
void ShowObjective(int level){
    // Display objective board image
    readimagefile("gambar//Objective-Board.jpg", 903, 38, 1203, 680);

    settextstyle(4, HORIZ_DIR, 2);

    // Display initial state chest objective number
    switch(level){
        case 1:
            outtextxy(1033, 162, "0/1");
            break;
        case 2:
            outtextxy(1033, 162, "0/2");
            break;
        case 3:
            outtextxy(1033, 162, "0/3");
            break;
        case 4:
            outtextxy(1033, 162, "0/4");
            break;
        case 5:
            outtextxy(1033, 162, "0/5");
            break;
        case 6:
            outtextxy(1033, 162, "0/6");
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
        case 4:
            outtextxy(1033, 162, "4");
            break;
        case 5:
            outtextxy(1033, 162, "5");
            break;
        case 6:
            outtextxy(1033, 162, "6");
            break;
    }
}


