#ifndef PLAYER_H
#define PLAYER_H

#include "struct.h"
#include "common.h"
#include "function.h"
#include "define.h"

//////////////////////////////// 플레이어 /////////////////////////////////////////
//	①;②;③;④;

void next_turn()
{
	turn = (turn % player_num) + 1;
}

void money_show(player *player)
{
	gotoxy(80, 6); VIO;
	printf("각 플레이어의 보유 아이템");
	gotoxy(118, 44);
	printf("                     ");
	gotoxy(118, 44);
	printf("각 플레이어의 소지금");
	for (int i = 0; i<player_num; i++)
	{
		switch (i)
		{
		case 0:
			RED;
			break;
		case 1:
			YEL;
			break;
		case 2:
			SKY;
			break;
		case 3:
			HIGH;
			break;
		default:
			break;
		}
		////// 소유한 돈 //////
		gotoxy(118, 45 + i);
		printf("                      ");
		gotoxy(118, 45 + i);

		if (player[i].gameover == GAMEOVER)
		{
			printf("플레이어%d : 파  산", i + 1);
			gotoxy(80, 7 + i);
			printf("                              ");
		}

		else
		{
			printf("플레이어%d : %d 만원", i + 1, player[i].money);

			////// 소유한 아이템 ///////
			gotoxy(80, 7 + i);
			printf("                              ");
			gotoxy(80, 7 + i);
			printf("플레이어%d : ", i + 1);
			if (player[i].passcard == 1 && player[i].escape == 0)
				printf("우대권 ");
			else if (player[i].passcard == 0 && player[i].escape == 1)
				printf("특수 무전기");
			else if (player[i].passcard == 1 && player[i].escape == 1)
				printf("우대권, 특수 무전기");
		}
	}
	WHITE;
}

void moving_init(player* player)
{
	int i;

	for (i = 0;i < player_num;i++)
	{
		
		gotoxy(player[i].pre_X, player[i].pre_Y);

		if (i+1 == 1)
		{
			RED;	printf("①");
		}
		else if (i + 1 == 2)
		{
			YEL;	printf("②");
		}
		else if (i + 1 == 3)
		{
			SKY;	printf("③");
		}
		else if (i + 1 == 4)
		{
			HIGH;	printf("④");
		}
	}
	WHITE;
}

void moving_player(player *player, int kan)
{
	int i;
	int new_index;
	int cnt = 0;
	//dice_sum
	for (i = 1;i <= kan ;i++)
	{
		gotoxy(player[turn - 1].pre_X, player[turn - 1].pre_Y); printf("  "); //지울 위치

		new_index = (player[turn - 1].location_index + i) % ZONE_NUM;	//zone index 구하기
		User[turn - 1].pre_X = Zone[new_index].zone_X + (2 * (turn - 1));	//플레이어마다 한칸씩 옆
		User[turn - 1].pre_Y = Zone[new_index].zone_Y;

		gotoxy(User[turn - 1].pre_X, User[turn - 1].pre_Y);	// 새로운 위치
		if (turn == 1)
		{
			RED;	printf("①");
		}
		else if (turn == 2)
		{
			YEL;	printf("②");
		}
		else if (turn == 3)
		{
			SKY;	printf("③");
		}
		else if (turn == 4)
		{
			HIGH;	printf("④");
		}

		if (player[turn - 1].location_index + i >= ZONE_NUM && cnt != 1)
		{
			player[turn - 1].money += 100;

			//	한 바퀴 돌았을때 Sound 넣자! // 반환점
			VIO;
			gotoxy(80, 32);
			printf("한 바퀴를 돌았습니다. 월급 100만원을 지급합니다.");
			WHITE;

			cnt++;	//한번만 
		}

		Sleep(150);
	}
	WHITE;

	money_show(User);
	gotoxy(23, 34);
	printf("                                                 "); //주사위 돌리란말 지우기
	gotoxy(23, 34);	
	printf("ENTER를 입력해주세요.");
	while (_getch() != ENTER);
	gotoxy(23, 34); printf("                                 ");	//enter 입력 후 텍스트 지우기
	gotoxy(80, 32);
	printf("                                               ");;	//한바퀴 돌았을때의 텍스트 지우기

	player[turn - 1].location_index = new_index;	//마지막 위치의 zone index 기억

}


void player_init()
{
	int i;

	for (i = 0;i < player_num;i++)
	{
		User[i].use_space = 0;
		User[i].location_index = 0;
		User[i].escape = 0;
		User[i].island_cnt = 0;
		User[i].money = MONEY;
		User[i].passcard = 0;
		User[i].island_cnt = 0;
		User[i].pre_X = Zone[0].zone_X + (2 * i);
		User[i].pre_Y = Zone[0].zone_Y;
		User[i].gameover = 0;
	}
}


#endif