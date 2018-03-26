#ifndef PLAYER_H
#define PLAYER_H

#include "struct.h"
#include "common.h"
#include "function.h"
#include "define.h"

//////////////////////////////// �÷��̾� /////////////////////////////////////////
//	��;��;��;��;

void next_turn()
{
	turn = (turn % player_num) + 1;
}

void money_show(player *player)
{
	gotoxy(80, 6); VIO;
	printf("�� �÷��̾��� ���� ������");
	gotoxy(118, 44);
	printf("                     ");
	gotoxy(118, 44);
	printf("�� �÷��̾��� ������");
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
		////// ������ �� //////
		gotoxy(118, 45 + i);
		printf("                      ");
		gotoxy(118, 45 + i);

		if (player[i].gameover == GAMEOVER)
		{
			printf("�÷��̾�%d : ��  ��", i + 1);
			gotoxy(80, 7 + i);
			printf("                              ");
		}

		else
		{
			printf("�÷��̾�%d : %d ����", i + 1, player[i].money);

			////// ������ ������ ///////
			gotoxy(80, 7 + i);
			printf("                              ");
			gotoxy(80, 7 + i);
			printf("�÷��̾�%d : ", i + 1);
			if (player[i].passcard == 1 && player[i].escape == 0)
				printf("���� ");
			else if (player[i].passcard == 0 && player[i].escape == 1)
				printf("Ư�� ������");
			else if (player[i].passcard == 1 && player[i].escape == 1)
				printf("����, Ư�� ������");
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
			RED;	printf("��");
		}
		else if (i + 1 == 2)
		{
			YEL;	printf("��");
		}
		else if (i + 1 == 3)
		{
			SKY;	printf("��");
		}
		else if (i + 1 == 4)
		{
			HIGH;	printf("��");
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
		gotoxy(player[turn - 1].pre_X, player[turn - 1].pre_Y); printf("  "); //���� ��ġ

		new_index = (player[turn - 1].location_index + i) % ZONE_NUM;	//zone index ���ϱ�
		User[turn - 1].pre_X = Zone[new_index].zone_X + (2 * (turn - 1));	//�÷��̾�� ��ĭ�� ��
		User[turn - 1].pre_Y = Zone[new_index].zone_Y;

		gotoxy(User[turn - 1].pre_X, User[turn - 1].pre_Y);	// ���ο� ��ġ
		if (turn == 1)
		{
			RED;	printf("��");
		}
		else if (turn == 2)
		{
			YEL;	printf("��");
		}
		else if (turn == 3)
		{
			SKY;	printf("��");
		}
		else if (turn == 4)
		{
			HIGH;	printf("��");
		}

		if (player[turn - 1].location_index + i >= ZONE_NUM && cnt != 1)
		{
			player[turn - 1].money += 100;

			//	�� ���� �������� Sound ����! // ��ȯ��
			VIO;
			gotoxy(80, 32);
			printf("�� ������ ���ҽ��ϴ�. ���� 100������ �����մϴ�.");
			WHITE;

			cnt++;	//�ѹ��� 
		}

		Sleep(150);
	}
	WHITE;

	money_show(User);
	gotoxy(23, 34);
	printf("                                                 "); //�ֻ��� �������� �����
	gotoxy(23, 34);	
	printf("ENTER�� �Է����ּ���.");
	while (_getch() != ENTER);
	gotoxy(23, 34); printf("                                 ");	//enter �Է� �� �ؽ�Ʈ �����
	gotoxy(80, 32);
	printf("                                               ");;	//�ѹ��� ���������� �ؽ�Ʈ �����

	player[turn - 1].location_index = new_index;	//������ ��ġ�� zone index ���

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