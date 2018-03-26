#ifndef COMMON_H
#define COMMON_H

#define _CRT_SECURE_NO_WARNINGS

#include "struct.h"
#include "define.h"

#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>


/////////////////////////////////////// 전역변수 //////////////////////////////////

int dice1 = 0; int dice2 = 0; int dice_sum = 0;
int turn = 1;	//플레이어턴
int player_num = 0;	//플레이어 숫자

player User[4];			//user 구조체
zone Zone[ZONE_NUM];	//존 구조체
golden_key G_KEY[18];   //황금열쇠 구조체

/////////////////////////////////////// 현재 상태 //////////////////////////////////

enum state	//상태를 열거형으로
{
	INTRO, init, P_TURN, BUY_ZONE, TOLL, ISLAND, IN_ISLAND, NOT_MOVING,
	KOREA, SPACESHIP, GO_SPACESHIP ,GOLDEN_KEY, GAME_OVER, NEXT_TURN, SAVE, LOAD
};

enum state STATE;

#endif