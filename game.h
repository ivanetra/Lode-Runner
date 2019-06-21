/*
Deskripsi	: Header yang berisi seluruh header yang digunakan dalam project
*/

#ifndef GAME_H
#define GAME_H

//Header
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
#include <process.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include "variabel.h"
#include "header/181511005.h"
#include "header/181511013.h"
#include "header/181511015.h"
#include "header/181511019.h"
#include "header/181511049.h"

//IGNORE WARNING
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wconversion-null"
#pragma comment (lib , "winmm.lib")

//DEFINE
#define maxwidth	840
#define maxheight	620
#define BUP 1
#define BRIGHT 2
#define BDOWN 3
#define BLEFT 4
#define JARAK 6
#define USETREE 0
#define DRILL '1'
#define SCORE '2'
#define MOVE1 '3'
#define MOVE2 '4'
#define MOVE1BOOLEAN true
#define MOVE2BOOLEAN false
#define MOVEONLADDER1 '5'
#define MOVEONLADDER2 '6'
#define NAIKTANGGA1 true
#define NAIKTANGGA2 false
#define GERAKKANAN5 false
#define GERAKKANAN14 true
#define GERAKKIRI5 false
#define GERAKKIRI14 true
#define MOVEONROPE1 '7'
#define MOVEONROPE2 '8'


#endif
