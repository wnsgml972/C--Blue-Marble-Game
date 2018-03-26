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


/////////////////////////////////////// �������� //////////////////////////////////

int dice1 = 0; int dice2 = 0; int dice_sum = 0;
int turn = 1;	//�÷��̾���
int player_num = 0;	//�÷��̾� ����

player User[4];			//user ����ü
zone Zone[ZONE_NUM];	//�� ����ü
golden_key G_KEY[18];   //Ȳ�ݿ��� ����ü

/////////////////////////////////////// ���� ���� //////////////////////////////////

enum state	//���¸� ����������
{
	INTRO, init, P_TURN, BUY_ZONE, TOLL, ISLAND, IN_ISLAND, NOT_MOVING,
	KOREA, SPACESHIP, GO_SPACESHIP ,GOLDEN_KEY, GAME_OVER, NEXT_TURN, SAVE, LOAD
};

enum state STATE;

#endif