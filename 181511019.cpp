/* 	File 		: 18151019.cpp
*	Deskripsi 	: Body dari modul yang dikerjakan oleh Lia
*	Dibuat Oleh	: Lia Purnamasari - 181511019
*/

#include "header/181511019.h"

bool isLevelUp(int loot, int loot_e){
	if(loot_e==loot){
		printf("\nLOOT_E=LOOT");
		return true;
	} else{
		return false;
	}
}

void LevelUp(int A[19][27], int *level){
	int brs, klm;
		printf("\n LEVEL UP");
		brs=i;
		for(klm=j;klm<=25;klm++)
		{
			A[brs][klm]=2;
			draw_object(A, brs, klm);
		}
		for(brs=i;brs>=0;brs--)
		{
			A[brs][klm]=3;
			draw_object(A, brs, klm);
		} 
		while (j!=26){
			if (j%2==0){
				readimagefile("gambar//Menggantung_Kanan1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			} else{
				readimagefile("gambar//Menggantung_Kanan2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			}
			delay(100);
			A[i][j-1]=2;
			draw_object(A, i, j);
				j++;
		}
		while (i!=-1){
			if (i%2==0){
				readimagefile("gambar//Naik_Tangga1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			} else{
				readimagefile("gambar//Naik_Tangga2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			}
			delay(100);
			A[i+1][j]=3;
			draw_object(A, i, j);
				i--;
		}
	(*level)++; printf("\nLEVEL= %d", *level);
	cleardevice();
	settextjustify(LEFT_TEXT, TOP_TEXT);	
	outtextxy(450,250,"LEVEL COMPLETED....");
	delay(2000);
	cleardevice();
}

int MAP(int level, int baris, int kolom){
	if (level==1){
		int Array[19][27] = {
		{6, 6, 6, 6, 6, 6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6, 6},
		{6, 0, 0, 0, 0, 0,	0, 	0, 	0, 	0, 	0, 	0, 	0, 	0,	0, 	0, 	0, 	0,	0,	0,	0,	0,	0,	0,	0,	0, 6},
		{6, 1,	1, 1, 1, 1,	3,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0, 6},
		{6, 0,	0, 0, 0, 0,	3,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0, 6},
		{6, 0,	0, 0, 0, 0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0, 6},
		{6, 0,	0, 0, 0, 0,	3,	0,	0,	0,	0,	0,	1,	1,	3,	1,	0,	0,	1,	1,	1,	1,	1,	3,	1,	1, 6},
		{6, 0,	0, 0, 0, 0,	3,	0,	0,	0,	0,	0,	1,	1,	3,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0, 6},
		{6, 0,	0, 0, 0, 0,	3,	0,	0,	0,	0,	0,	1,	1, 	3,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0, 6},
		{6, 1,	3, 1, 1, 1,	1,	2,	2,	2,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	3,	1,	1,	1,	1,	1, 6},
		{6, 0,	3, 0, 0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0, 6},
		{6, 0,	3, 0, 0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0, 6},
		{6, 1,	1, 1, 1, 1,	1,	3,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	3,	0,	0,	0,	0,	0, 6},
		{6, 0,	0, 0, 0, 0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0, 6},
		{6, 0,	0, 0, 0, 0,	0,	3,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	3,	0,	0,	0,	0,	0, 6},
		{6, 0,	0, 0, 0, 0,	0,	3,	5,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0, 6},
		{6, 0,	0, 0, 3, 1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	5,	0,	0,	0,	0,	1,	1,	1,	1,	3,	0, 6},
		{6, 0,	0, 0, 3, 5,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0, 6},
		{6, 1,	1, 1, 1, 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1, 6},
		{6, 6, 6, 6, 6, 6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6, 6}
		};
	//Posisi Karakter Blu di level ini
	posisi_karakter(level);
	return Array[baris][kolom];
	} else if (level==2){
		int Array[19][27] = {
		{6, 6, 6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6, 6},
		{6, 0,	0,	5,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},
		{6, 3,	1,	1,	1,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},
		{6, 3,	1,	1,	1,	3,	0,	0,	0,	0,	3,	1,	1,	1,	1,	1,	1,	1,	1,	1,	3,	0,	0,	0,	0,	3, 6},//6
		{6, 3,	0,	0,	0,	3,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	3, 6},//7
		{6, 3,	0,	0,	0,	3,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	3, 6},//8
		{6, 3,	0,	0,	0,	3,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	3, 6},//9
		{6, 3,	1,	1,	1,	3,	2,	2,	2,	2,	3,	2,	2,	2,	2,	2,	2,	2,	2,	2,	3,	0,	0,	0,	0,	3, 6},//10
		{6, 3,	0,	0,	0,	3,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	1,	1,	1,	1,	3, 6},//1
		{6, 3,	0,	0,	0,	3,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	3, 6},//12
		{6, 3,	0,	0,	0,	3,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	3, 6},//13
		{6, 3,	0,	0,	0,	3,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	3, 6},//14
		{6, 1,  0,	0,	1,	1,	1,	1,	1,	1,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	1,	3,	1,	1,	1, 6},//15
		{6, 1,  0,	0,	1,	0,	0,	0,	5,	0,	3,	0,	0,	0,	2,	2,	2,	2,	2,	2,	3,	0,	3,	0,	0,	0, 6},//16
		{6, 1,	0,	0,	1,	1,	1,	3,	1,	1,	3,	1,	1,	1,	1,	0,	0,	0,	0,	0,	3,	0,	1,	1,	1,	1, 6},//17
		{6, 1,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0, 6},//18
		{6, 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1, 6},//19
		{6, 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1, 6},//20
		{6, 6, 6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6, 6}
		};
	//Posisi Karakter Blu di level ini
	i=15; j=3;
	return Array[baris][kolom];
	} else if (level==3){
		int Array[19][27] = {
		{6, 6, 6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6, 6},
		{6, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},//4
		{6, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},//5
		{6, 0,	0,	0,	0,	0,	3,	2,	2,	2,	2,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	2,	2,	2,	3, 6},//6
		{6, 0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},//7
		{6, 1,	1,	1,	1,	1,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},//8
		{6, 1,	5,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	3, 6},//9
		{6, 1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},//10
		{6, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},//1
		{6, 0,	0,	0,	0,	0,	0,	0,	0,	3,	1,	1,	1,	1,	1,	1,	3,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},//12
		{6, 3,	1,	1,	1,	1,	1,	1,	3,	3,	0,	0,	0,	0,	0,	0,	3,	1,	1,	1,	1,	1,	1,	1,	1,	3, 6},//13
		{6, 3,	5,	0,	0,	0,	0,	1,	3,	3,	0,	0,	0,	0,	0,	0,	3,	1,	1,	0,	0,	0,	0,	0,	0,	3, 6},//14
		{6, 3,	1,	1,	1,	2,	2,	2,	3,	1,	0,	0,	0,	0,	0,	0,	1,	1,	2,	2,	2,	2,	2,	2,	2,	3, 6},//15
		{6, 3,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	3, 6},//16
		{6, 3,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3, 6},//17
		{6, 3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	1,	1,	1, 6},//18
		{6, 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1, 6},//19
		{6, 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1, 6},//20
		{6, 6, 6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6, 6}
		};
	//Posisi Karakter Blu di level ini
	posisi_karakter(level);
	return Array[baris][kolom];
	}
}

void draw_object(int A[19][27], int brs, int klm){
		if (A[brs][klm]== 0){
			readimagefile("gambar//Obj_Blank.jpg", 0+32*klm, 0+32*brs, 32+32*klm, 32+32*brs);
		}
		if (A[brs][klm]== 1){
			readimagefile("gambar//Obj_Balok.jpg", 0+32*klm, 0+32*brs, 32+32*klm, 32+32*brs);
		}
		if (A[brs][klm]== 2){
			readimagefile("gambar//Obj_Tali.jpg", 0+32*klm, 0+32*brs, 32+32*klm, 32+32*brs);
		}
		if (A[brs][klm]== 3){
			readimagefile("gambar//Obj_Tangga.jpg", 0+32*klm, 0+32*brs, 32+32*klm, 32+32*brs);
		}
		if (A[brs][klm]== 5){
			readimagefile("gambar//Obj_Harta.jpg", 0+32*klm, 0+32*brs, 32+32*klm, 32+32*brs);
		}
		if (A[brs][klm]== 6){
			readimagefile("gambar//Obj_Solid.jpg", 0+32*klm, 0+32*brs, 32+32*klm, 32+32*brs);
		}
}

void show_map(int A[19][27]){
	int b, k;
	setbkcolor(BLACK);
	for(b=0; b<19; b++){
		for(k=0; k<27; k++){
			draw_object(A, b, k);
		}
	}
}

bool isBlank(int object){
	if(object == 0){
        return true;
    } else{
        return false;
    }
}

bool isTembok(int object){
    if(object == 1){
        return true;
    } else{
        return false;
    }
}

bool isTali(int object){
    if(object == 2){
        return true;
    } else{
        return false;
    }
}

bool isTangga(int object){
    if(object == 3){
        return true;
    } else{
        return false;
    }
}

bool isHarta(int object){
    if(object == 5){
        return true;
    } else{
        return false;
    }
}

bool isBeton(int object){
    if(object == 6){
        return true;
    } else{
        return false;
    }
}

bool isLubang(int object){
    if(object == 7){
        return true;
    } else{
        return false;
    }
}

bool isNyawa_berkurang(int A[19][27], int temp){


	if(isTerjebak(A, temp)){
		return true;
	}
	else{
        return false;
	}
}

void posisi_karakter(int level){
	switch(level){
		case 1 :{
			i=16; j=2;
			break;
		}
		case 2 :{
			i=15; j=3;
			break;
		}
		case 3 :{
			i=15; j=3;
			break;
		}
	}
}

int hitung_nyawa(int A[19][27], int *temp, int *life, int level){
    if(isNyawa_berkurang(A, *temp)){
    		delay(1000);
			(*life)--;
			settextjustify(LEFT_TEXT, TOP_TEXT);
			outtextxy(450,250,"LIFE -1");
			delay(1000);
			posisi_karakter(level);
			*temp=0;
        }
    else{
    	*life=*life;
	}
	sprintf(msg4,"Life : %d", *life);
	outtextxy(20,660,msg4);
	return *life;
}
