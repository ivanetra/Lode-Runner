/* 	File 		: 181511013.cpp
*	Deskripsi 	: Body dari modul yang dikerjakan oleh Febri
*	Dibuat Oleh	: Febriyoga Bagus Satria - 181511013
*/

#include "header/181511013.h"

void choose_sprite(address h, int temp, int lastkey, int posisi, bool *lastMoveSprite, bool *lastLadderSprite, bool *lastMoveMusic){
	if (lastkey==0){ //POSISI AWAL
		readimagefile("gambar//Blu.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
	}
	if (lastkey==1){ //Gambar yang akan dipilih setelah bergerak KE ATAS
		if (temp==3){
			if (i%2==0){
				readimagefile("gambar//Naik_Tangga1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
				if(*lastLadderSprite != NAIKTANGGA1){
                    PlayMusic(MOVEONLADDER1);
                    *lastLadderSprite = NAIKTANGGA1;
				}
			} else{
				readimagefile("gambar//Naik_Tangga2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
				if(*lastLadderSprite != NAIKTANGGA2){
                    PlayMusic(MOVEONLADDER2);
                    *lastLadderSprite = NAIKTANGGA2;
				}
			}
		} else if(isTali(temp)){
			readimagefile("gambar//Menggantung_Kanan1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
            if(*lastRopeSprite != NAIKTANGGA1){
                PlayMusic(MOVEONLADDER1);
                *lastLadderSprite = NAIKTANGGA1;
            }
		} else {
			readimagefile("gambar//Blu.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
		}
	}
	if (lastkey==2){
		if (temp==3){
			if (i%2==0){
                readimagefile("gambar//Naik_Tangga1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
                if(*lastLadderSprite != NAIKTANGGA1){
                    PlayMusic(MOVEONLADDER1);
                    *lastLadderSprite = NAIKTANGGA1;
				}
            } else{
                readimagefile("gambar//Naik_Tangga2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
                if(*lastLadderSprite != NAIKTANGGA2){
                    PlayMusic(MOVEONLADDER2);
                    *lastLadderSprite = NAIKTANGGA2;
                }
            }
		} else {
			readimagefile("gambar//Blu.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
		}
	}
	if (lastkey==3){ //Key Terakhir = KEY_RIGHT
		if (temp==2){
			if (j%2==0){
				readimagefile("gambar//Menggantung_Kanan1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			} else{
				readimagefile("gambar//Menggantung_Kanan2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			}
		} else if ((h->map[i][j+1]==1 && isTangga(temp)) || temp==3){
			readimagefile("gambar//Naik_Tangga1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
            if(*lastLadderSprite != NAIKTANGGA1){
                PlayMusic(MOVEONLADDER1);
                *lastLadderSprite = NAIKTANGGA1;
            }
		}else {
			switch(posisi){
				case 1 : {
						readimagefile("gambar//Gerak_Kanan1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
                        *lastMoveSprite = GERAKKANAN14;
					break;
				}
				case 2 : {
						readimagefile("gambar//Gerak_Kanan2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
                        *lastMoveSprite = GERAKKANAN14;
					break;
				}
				case 3 : {
						readimagefile("gambar//Gerak_Kanan3.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
                        *lastMoveSprite = GERAKKANAN14;
					break;
				}
				case 4 : {
						readimagefile("gambar//Gerak_Kanan4.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
                        *lastMoveSprite = GERAKKANAN14;

					break;
				}
				case 5 : {
                    if(*lastMoveMusic != MOVE1BOOLEAN){
                        if(*lastMoveSprite != GERAKKANAN5){
                            PlayMusic(MOVE1);
                            *lastMoveMusic = MOVE1BOOLEAN;
                            *lastMoveSprite = GERAKKANAN5;
                        }
                    } else{
                        if(*lastMoveSprite != GERAKKANAN5){
                            PlayMusic(MOVE2);
                            *lastMoveMusic = MOVE2BOOLEAN;
                            *lastMoveSprite = GERAKKANAN5;
                        }
                    }
                    readimagefile("gambar//Gerak_Kanan5.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
					break;
				}
			}
		}
	}
	if (lastkey==4){ //Key Terakhir = KEY_LEFT
		if (temp==2){
			if (j%2==0){
				readimagefile("gambar//Menggantung_Kiri1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			} else{
				readimagefile("gambar//Menggantung_Kiri2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			}
		} else if ((h->map[i][j-1]==1 && isTangga(temp))|| temp==3){
			readimagefile("gambar//Naik_Tangga1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
            if(*lastLadderSprite != NAIKTANGGA1){
                PlayMusic(MOVEONLADDER1);
                *lastLadderSprite = NAIKTANGGA1;
            }
		}else {
				switch(posisi){
					case 1 : {
						readimagefile("gambar//Gerak_Kiri1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
						*lastMoveSprite = GERAKKIRI14;
						break;
					}
					case 2 : {
						readimagefile("gambar//Gerak_Kiri2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
						*lastMoveSprite = GERAKKIRI14;
						break;
					}
					case 3 : {
						readimagefile("gambar//Gerak_Kiri3.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
						*lastMoveSprite = GERAKKIRI14;
						break;
					}
					case 4 : {
						readimagefile("gambar//Gerak_Kiri4.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
						*lastMoveSprite = GERAKKIRI14;
						break;
					}
					case 5 : {
                        if(*lastMoveMusic != MOVE1BOOLEAN){
                            if(*lastMoveSprite != GERAKKIRI5){
                                PlayMusic(MOVE1);
                                *lastMoveMusic = MOVE1BOOLEAN;
                                *lastMoveSprite = GERAKKIRI5;
                            }
                        } else{
                            if(*lastMoveSprite != GERAKKIRI5){
                                PlayMusic(MOVE2);
                                *lastMoveMusic = MOVE2BOOLEAN;
                                *lastMoveSprite = GERAKKIRI5;
                            }
                        }
                        readimagefile("gambar//Gerak_Kiri5.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
						break;
					}
				}
		}
	}
	if(lastkey==5){ // Drills a hole on the left side of the lode runner
        readimagefile("gambar//Gerak_Kiri5.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
	}
	if(lastkey==6){
        readimagefile("gambar//Gerak_Kanan5.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
	}
}

void draw_sprite(address h, int temp, int lastkey, int posisi, bool *lastMoveSprite, bool *lastLadderSprite, bool *lastMoveMusic){
		h->map[i][j] = 4;
		if (h->map[i][j]== 4){
			choose_sprite(h, temp, lastkey, posisi, &(*lastMoveSprite), &(*lastLadderSprite), &(*lastMoveMusic));
			h->map[i][j]=temp;
		}
}

void isi_temp(address h, int *temp, int lastkey, int posisi){
	switch(lastkey){
		case 1 : {
			if((h->map[i+1][j]!=1 && h->map[i+1][j]!=3 && h->map[i-1][j]!=3 && isBeton(h->map[i-1][j]) && !isTali(*temp)) || *temp==3){
				*temp=h->map[i-1][j];
			} else {
				*temp=*temp;
			}
			break;
		}
		case 2 : {
			if(h->map[i+1][j]!=1){
				*temp=h->map[i+1][j];
			} else {
				*temp=*temp;
			}
			break;
		}
		case 3 : {
			if(h->map[i][j+1]!=1 && h->map[i][j+1]!=5 && h->map[i][j+1]!=6 ){
				*temp=h->map[i][j+1];
			} else if(h->map[i][j+1]==5){
				*temp=0;
			} else {
				*temp=*temp;
			}
			break;
		}
		case 4 : {
			if(h->map[i][j-1]!=1 && h->map[i][j-1]!=5 && h->map[i][j-1]!=6 ){
				*temp=h->map[i][j-1];
			} else if(h->map[i][j-1]==5){
				*temp=0;
			} else {
				*temp=*temp;
			}
			break;
		}
	}
}

bool isJatuh(address h, int temp){
	if ((isBlank(h->map[i+1][j]) || isTali(h->map[i+1][j]) || isHarta(h->map[i+1][j]) || isLubang(h->map[i+1][j])) && !isTali(temp) && !isTangga(temp)){
		return true;
	} else {
		return false;
	}
}

void layer(){

}
