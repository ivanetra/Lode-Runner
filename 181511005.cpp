/* 	File 		: 181511005.cpp
*	Deskripsi 	: Body dari modul yang dikerjakan oleh Aji
*	Dibuat Oleh	: Aji Muhammad Zafar - 181511005
*/

#include "header/181511005.h"

void moveUP(address h, int *temp, int *lastkey, int tempbfr, int posisi){
	draw_object(h, i, j);
    *lastkey=1;
	tempbfr=*temp;
	isi_temp(h, temp, *lastkey, posisi);
	if ((isTangga(*temp) || isTangga(tempbfr)) && !isTembok(h->map[i-1][j]) && !isBeton(h->map[i-1][j])){
		i--;
	} else {
		i=i;
	}
}

void moveDOWN(address h, int *temp, int *lastkey, int posisi){
	draw_object(h, i, j);
    *lastkey=2;
	isi_temp(h, temp, *lastkey, posisi);
	if (isTangga(h->map[i+1][j]) || isBlank(h->map[i+1][j]) || isTali(h->map[i+1][j]) || isHarta(h->map[i+1][j]) || isLubang(h->map[i+1][j])){
		i++;
	} else {
		i=i;
	}
}

void moveRIGHT(address h, int *temp, int *lastkey, int *posisi){
	draw_object(h, i, j);
    *lastkey=3;
    if (*posisi==5){
    	isi_temp(h, temp, *lastkey, *posisi);
	}
	if ((!isTembok(h->map[i][j+1]) && !isBeton(h->map[i][j+1])) && (isBeton(h->map[i+1][j]) || isTembok(h->map[i+1][j]) || isTangga(h->map[i+1][j]) || isTali(h->map[i][j+1]) || isTali(h->map[i][j-1])) && j<26){
		(*posisi)++;
		if (*posisi>5){
			*posisi=1;
			j++;
		}
	} else {
		*posisi=*posisi;
	}
}

void moveLEFT(address h, int *temp, int *lastkey, int *posisi){
	draw_object(h, i, j);
    *lastkey=4;
	if (*posisi==1){
    	isi_temp(h, temp, *lastkey, *posisi);
	}
	if ((!isTembok(h->map[i][j-1]) && !isBeton(h->map[i][j-1])) && (isBeton(h->map[i+1][j]) || isTembok(h->map[i+1][j]) || isTangga(h->map[i+1][j]) || isTali(h->map[i][j+1]) || isTali(h->map[i][j-1])) && j>0){
		(*posisi)--;
		if (*posisi<1){
			*posisi=5;
			j--;
		}
	} else {
		j=j;
	}
}

void KeyboardInput(address h, int *temp, int *lastkey, int *posisi, bool *lastMoveSprite, bool *lastLadderSprite, bool *lastMoveMusic){
	int tempbfr;

    //KEY INPUT BERGERAK KE ATAS
    if (GetAsyncKeyState(VK_UP)){
    	delay(40);
    	moveUP(h, temp, lastkey, tempbfr, *posisi);
	}
	//KEY INPUT BERGERAK KE BAWAH
	if (GetAsyncKeyState(VK_DOWN)){
		delay(40);
		moveDOWN(h, temp, lastkey, *posisi);

	}
	//KEY INPUT BERGERAK KE KANAN
	if (GetAsyncKeyState(VK_RIGHT)){
		delay(40);
		moveRIGHT(h, temp, lastkey, posisi);

	}
	//KEY INPUT BERGERAK KE KIRI
	if (GetAsyncKeyState(VK_LEFT)){
		delay(40);
		moveLEFT(h, temp, lastkey, posisi);

	}
	//KEY INPUT DRILL KANAN
	if (GetAsyncKeyState(0x41)){
		int key=65;
    	GetDrill(h, key, lastkey, *posisi, &(*lastMoveSprite), &(*lastLadderSprite), &(*lastMoveMusic));
	}
	//KEY INPUT DRILL KIRI
	if (GetAsyncKeyState(0x53)){
    	int key=83;
    	GetDrill(h, key, lastkey, *posisi, &(*lastMoveSprite), &(*lastLadderSprite), &(*lastMoveMusic));
	}

	/*if (){
		idle();
	}*/
	sprintf(msg,"Temp  : %d",*temp);
	outtextxy(20,640,msg);
}


int hitung_skor(address h, int *temp)
{
	if(isHarta(h->map[i][j]))
	{
	    PlayMusic(SCORE);
		*temp=0;
		skor+=100;
	}
	sprintf(msg,"Score : %d",skor);
	outtextxy(20,620,msg);
	return skor;
}

int hitung_loote(address h, int *loot_e)
{
	if(isHarta(h->map[i][j]))
	{
		(*loot_e)++;
		IncrementChestObjectiveNumber(*loot_e);
	}
	return *loot_e;
}

int hitung_loot(address h)
{
	int loot = 0;
	int brs,klm;
	for(brs=0;brs<19;brs++)
	{
		for(klm=0;klm<27;klm++)
		{
			if(h->map[brs][klm]==5)
			{
				loot++;
			}
		}
	}
	printf("\n LOOT = %d", loot);
	return loot;
}

void bordernama()
{
	setcolor(WHITE);
	rectangle (414,264,830,334);
	setfillstyle(XHATCH_FILL,BLUE);
	floodfill(320,170,WHITE);
}


//input nama
void nameinput(int x, int y, char *title, int spacing, char name[10], int font, int direction, int charsize) {
	short int i;
	data rekap;
	bordernama();
	settextstyle(font, direction, charsize);
	outtextxy(x, y, title);
	for (i=0; i<10; i++) {
		name[i] = 0;
	}

	i = 0;
	while (i<10) {
		if (i<9) {
			do {
				name[i] = getch();
			} while (!(((name[i]>=97 && name[i]<=122) || (name[i]>=65 && name[i]<=90)) || (name[i]==8 || name[i]==13)));
			if (name[i]>=97 && name[i]<=122) {
				name[i] = name[i] - 32;
			}
		} else if (i==9) {
			do {
				name[i] = getch();
			} while (!(name[i]==8 || name[i]==13));
		}

		if (name[i]==8) {
			name[i] = 0;
			if (i>0) {
				name[i-1] = ' ';
				i--;
			}
		}
		if (name[i]==13) {
			name[i] = 0;
			if(name[0]!=0) {
				break;
			}
		}
		if ((name[i]>=65 && name[i]<=90)) {
			i++;
		}
		outtextxy(x+spacing, y, name);
	}

}


void cetak_leaderboard(){
	FILE *f_pemain;
	short int x, i;
	char print_rank[10], print_name[20], print_move[20];
	data rekap;
	printf("\nLeaderboard\n");
	if((f_pemain = fopen("leaderboard.dat", "rt")) == NULL){
		printf("File tidak dapat dibuka!");
		exit(1);
	}
	// read 1 baris
	//fscanf(f_pemain, "%s %d\n ", &rekap.nama,&rekap.poin);
	fread(&rekap,sizeof(rekap),1,f_pemain);
	x = 0;
	while (!feof(f_pemain)){
		// salin ke string pake sprintf
		i = x; // i dipakai untuk nampung nilai x sekarang
		sprintf(print_rank, "%d", x+1); // sprintf nge reset value dari x
		x = i; // karena x ke reset, kembalikan nilai x yang tadi ditampung di i
		sprintf(print_name, "%s", rekap.nama);
		sprintf(print_move, "%d", rekap.poin);

		// cek di console
		//printf("%d %s %d:%02d:%02d %d \n", x, rekap.nama,timer.jam,timer.menit,timer.detik,rekap.poin);

		// tampilkan
		outtextxy(100,(130+(x*30)), print_rank);
		outtextxy(250,130+(x*30), print_name);
		outtextxy(730,130+(x*30), print_move);

		x++;
		// read baris selanjutnya
		fread(&rekap,sizeof(rekap),1,f_pemain);
		//fscanf(f_pemain, "%s %d\n", &rekap.nama,  &rekap.poin);
	}

	// tutup file
	fclose(f_pemain);
}

void cetak_waktu()
{
	FILE *f_timer;
	char print_time[10];
	timegame waktu;
	int x=0;
	f_timer=fopen("timer.dat","rt");
	fread(&waktu,sizeof(waktu),1,f_timer);
	while(!feof(f_timer))
	{
		sprintf(print_time, "%d:%02d:%02d", waktu.jam, waktu.menit, waktu.detik);
		outtextxy(550,130+(x*30), print_time);
		fread(&waktu,sizeof(waktu),1,f_timer);
		x++;
	}
	fclose(f_timer);
}
void hiScoreLayout() {
	int x, y;
	bool click=false;

	cleardevice();
	readimagefile("img\\BG2.bmp",0,0,840,620);
	rectangle(40, 40, 800, 490);

	setfillstyle(SOLID_FILL, BLACK);

	floodfill(40 + ((800 - 40)/2), 40 + ((490 - 40)/2), WHITE);

	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
	outtextxy(maxwidth/2, 40, "LEADERBOARDS");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
	outtextxy(100,80, "RANK");
	outtextxy(250, 80, "NAME");
	outtextxy(550, 80, "WAKTU");
	outtextxy(730, 80, "POIN");
	cetak_leaderboard();
	cetak_waktu();
	settextjustify(LEFT_TEXT, TOP_TEXT);
	do {
		setbkcolor(GREEN);
		outtextxy(55,460,"Back to home...");
		setbkcolor(RED);
		outtextxy(702,460,"Quit...");
//		readimagefile("img\\p_home\\quitup.jpg",,501,,581);
//		readimagefile("img\\p_hscr\\menuup.jpg", , 507, , 577);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			printf("%d %d ",x,y);
			if ((x>55 && x<355) && (y>460 && y<480)) {
				click=true;
			//	readimagefile("img\\p_hscr\\menudown.jpg", 322, 507, 512, 577);
				//delay(300);
				//readimagefile("img\\p_hscr\\menuup.jpg", 322, 507, 512, 577);
				delay(100);
				main_menu();
			} else if ((x>702 && x<800) && (y>460 && y<480)) {
				click=true;
			//	readimagefile("img\\p_home\\quitdown.jpg",722,501,802,581);
				delay(300);
			//	readimagefile("img\\p_home\\quitup.jpg",722,501,802,581);
				delay(100);
				exit(1);
			}
		}
	} while (click==false);
}

//SAVE TO FILE
void save_data(data player)
{
	cleardevice();
	FILE *f_pemain;

//	strcpy(player.nama,nama);
//	player.poin=x;
	// buka file & bikin file
	if((f_pemain = fopen("leaderboard.dat", "at+")) == NULL){
		printf("File tidak dapat dibuka!");
		exit(1);
	}

	//player.sumWaktu = player.waktu.s + (player.waktu.m * 60) + (player.waktu.H * 3600);
	fwrite(&player,sizeof(player),1,f_pemain);
	//fprintf(f_pemain, "%s %d\n ", player.nama, player.poin);

	// tututp file
	fclose(f_pemain);
}

void waktu(void *argc)
{
	FILE *f_timer;
	f_timer=fopen("timer.dat","at+");
	char timer[20];
	 timegame rekap;
	int ms;
	bool yes=true;
	rekap.jam=0;
	rekap.menit=0;
	rekap.detik=0;
	rekap.x=0;
	while(yes)
	{
		sprintf(timer, "%d:%02d:%02d", rekap.jam, rekap.menit, rekap.detik);
	outtextxy(260,640,timer);
	ms++;
	delay(100);
	if(ms == 10)
	{
		rekap.detik++;
		rekap.x++;
		ms = 0;
	}
	if(rekap.detik==60)
	{
		rekap.menit++;
		rekap.x++;
		rekap.detik = 0;
	}
	if(rekap.menit==60)
	{
		rekap.jam++;
		rekap.x++;
		rekap.menit = 0;
	}
	if(gameover==1)
	{
		yes=false;
	}
	}
	fwrite(&rekap,sizeof(rekap),1,f_timer);
	fclose(f_timer);
	_endthread();
}
