/* 	File 		: 181511013.cpp
*	Deskripsi 	: Body dari modul yang dikerjakan oleh Febri
*	Dibuat Oleh	: Febriyoga Bagus Satria - 181511013
*/

#include "header/181511013.h"

void choose_sprite(int A[19][27], int temp, int lastkey){
	if (lastkey==0){ //POSISI AWAL
		readimagefile("gambar//Blu.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
	}
	if (lastkey==1){ //Gambar yang akan dipilih setelah bergerak KE ATAS
		if (temp==3){
			if (i%2==0){
				readimagefile("gambar//Naik_Tangga1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			} else{
				readimagefile("gambar//Naik_Tangga2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			}
		} else if(isTali(temp)){
			readimagefile("gambar//Menggantung_Kanan1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
		} else {
			readimagefile("gambar//Blu.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
		}
	}
	if (lastkey==2){
		if (temp==3){
			if (i%2==0){
			readimagefile("gambar//Naik_Tangga1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			} else{
			readimagefile("gambar//Naik_Tangga2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
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
		} else if ((A[i][j+1]==1 && isTangga(temp)) || temp==3){
			readimagefile("gambar//Naik_Tangga1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
		}else {
				readimagefile("gambar//Gerak_Kanan1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			//	delay(75);
				readimagefile("gambar//Gerak_Kanan2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			//	delay(75);
				readimagefile("gambar//Gerak_Kanan3.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			//	delay(75);
				readimagefile("gambar//Gerak_Kanan4.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			//	delay(75);
				readimagefile("gambar//Gerak_Kanan5.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
		}
	}
	if (lastkey==4){ //Key Terakhir = KEY_LEFT
		if (temp==2){
			if (j%2==0){
				readimagefile("gambar//Menggantung_Kiri1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			} else{
				readimagefile("gambar//Menggantung_Kiri2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
			}
		} else if ((A[i][j-1]==1 && isTangga(temp))|| temp==3){
			readimagefile("gambar//Naik_Tangga1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
		}else {
				readimagefile("gambar//Gerak_Kiri1.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
				//delay(75);
				readimagefile("gambar//Gerak_Kiri2.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
				//delay(75);
				readimagefile("gambar//Gerak_Kiri3.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
				//delay(75);
				readimagefile("gambar//Gerak_Kiri4.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
				//delay(75);
				readimagefile("gambar//Gerak_Kiri5.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
		}
	}
	if(lastkey==5){ // Drills a hole on the left side of the lode runner
        readimagefile("gambar//Gerak_Kiri5.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
	}
	if(lastkey==6){
        readimagefile("gambar//Gerak_Kanan5.jpg", 0+32*j, 0+32*i, 32+32*j, 32+32*i);
	}
}

void draw_sprite(int A[19][27], int temp, int lastkey){
		A[i][j] = 4;
		if (A[i][j]== 4){
			choose_sprite(A, temp, lastkey);
			A[i][j]=temp;
		}
}

void isi_temp(int A[19][27], int *temp, int lastkey){
	switch(lastkey){
		case 1 : {
			if((A[i+1][j]!=1 && A[i+1][j]!=3 && A[i-1][j]!=3 && isBeton(A[i-1][j]) && !isTali(*temp)) || *temp==3){
				*temp=A[i-1][j];
			} else {
				*temp=*temp;
			}
			break;
		}
		case 2 : {
			if(A[i+1][j]!=1){
				*temp=A[i+1][j];
			} else {
				*temp=*temp;
			}
			break;
		}
		case 3 : {
			if(A[i][j+1]!=1 && A[i][j+1]!=5 && A[i][j+1]!=6){
				*temp=A[i][j+1];
			} else if(A[i][j+1]==5){
				*temp=0;
			} else {
				*temp=*temp;
			}
			break;
		}
		case 4 : {
			if(A[i][j-1]!=1 && A[i][j-1]!=5 && A[i][j-1]!=6){
				*temp=A[i][j-1];
			} else if(A[i][j-1]==5){
				*temp=0;
			} else {
				*temp=*temp;
			}
			break;
		}
	}
}

bool isJatuh(int A[19][27], int temp){
	if ((isBlank(A[i+1][j]) || isTali(A[i+1][j]) || isHarta(A[i+1][j]) || isLubang(A[i+1][j])) && !isTali(temp) && !isTangga(temp)){
		return true;
	} else {
		return false;
	}
}
