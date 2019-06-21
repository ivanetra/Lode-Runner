#include "game.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int i, j, skor=0, gameover;
	char msg[120];

int main (int argc, char** argv)
{
	initwindow(1366, 768, "Escape the Castle");
	while(1){
		main_menu();
	}
	closegraph();
	return 0;
}
