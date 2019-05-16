/* 	File 		: 181511015.cpp
*	Deskripsi 	: Body dari modul yang dikerjakan oleh Hilmy
*	Dibuat Oleh	: Hilmy Oktoharitsa - 181511015
*/

#include "header/181511015.h"

void main_menu (){
	printf("\nMAIN MENU");
	readimagefile("gambar//kastil.jpg",0,0,800,600);
	readimagefile("gambar//escapecastle.jpg",805,60,1225,250);
	readimagefile("gambar//startdown.jpg",805,280,1220,365);
	readimagefile("gambar//developedown.jpg",30,630,230,680);
	readimagefile("gambar//highscore.jpg",700,630,750,680);
	readimagefile("gambar//instruction.jpg",620,630,670,680);
	klik ();
}

void klik (){
	int x=0, y=0;
	int play = 0;
	int Array[19][27];
		while (play == 0)
	{
	setbkcolor(BLACK);
	if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			printf("%d %d - ", x, y);
			if((x >= 804 && x <= 1221) && (y >= 279 && y <= 385)){
				//GAMEPLAY
				/*readimagefile("gambar//startdown.jpg",805,280,1220,370);
				delay(300);*/
				readimagefile("gambar//startup.jpg",805,280,1220,365);
				delay(500);
				game(Array);
				play = 1;
			}else if((x >= 699 && x <= 749) && (y >= 629 && y <= 679)){
				//HI-SCORE
				readimagefile("gambar//highscore.jpg",700,630,750,680);
				delay(500);
				hiScoreLayout();
				//tampil_leaderboard();
				play = 1;
			}else if((x >= 29 && x<=229) && (y >= 629 && y <= 679)){
				//Developer (About Us)
				readimagefile ("gambar//developeup.jpg",30,630,230,680);
				delay (500);
				showAboutUs();
			}
			
		}else play = 0;
	}
	cleardevice();
}

void showAboutUs(){
	int x, y;
	bool click=false;
	
	cleardevice();
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(40 + ((800 - 40)/2), 40 + ((490 - 40)/2), WHITE);
	readimagefile ("gambar//aboutus.jpg",50,20,750,490);
	do {
		setbkcolor(BLACK);
		outtextxy(55,460,"Back to home...");
		setbkcolor(RED);
		outtextxy(702,460,"Quit...");
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			printf("%d %d ",x,y);
			if ((x>55 && x<355) && (y>460 && y<480)) {
				click=true;
				delay(100);
				main_menu();
			} else if ((x>702 && x<800) && (y>460 && y<480)) {
				click=true;
				delay(300);
				delay(100);
				exit(1);
			}
		}
	} while (click==false);
}
