#ifndef FUNCTION_H
#define FUNCTION_H

#include "define.h"
#include "common.h"

//////////////////////////////// �׸��� /////////////////////////////////////////
void removeCursor(void)
{ // Ŀ���� �Ⱥ��̰� �Ѵ�

	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void gotoxy(int x, int y)
{
	COORD pos = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

void showCursor(void)
{ // Ŀ���� ���̰� �Ѵ�
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void cls(int bg_color, int text_color) // ȭ�� �����
{
	char cmd[100];
	int fg_color = 0;
	system("cls");
	sprintf_s(cmd, 100, "COLOR %x%x", bg_color, text_color);
	system(cmd);

}

void player_color()	//�÷��̾� ���� ������
{
	if (turn == P1_TURN)
	{
		RED;
	}
	else if (turn == P2_TURN)
	{
		YEL;
	}
	else if (turn == P3_TURN)
	{
		SKY;
	}
	else if (turn == P4_TURN)
	{
		HIGH;
	}
}

/////////////////////////////////////// ���� //////////////////////////////////
char *map[158] =
{
	{ "������������������������������������������������������������������������������������������������������������������������������������������������������������" },
	{ "��ź�ڴϾ�    �����ٰ���ī����Ȳ�ݿ���    ���Ӱ��      �����        ���λ�        �������ͳ�    �����ư�      ����Ű        ���ø���      �����ֿ���    ��" },
	{ "��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��" },
	{ "��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��" },
	{ "��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��" },
	{ "������������������������������������������������������������������������������������������������������������������������������������������������������������" },
	{ "���ɳ�        ��                                                                                                                            �����ٳ�      ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "����������������                                                                                                                            ����������������" },
	{ "���Ҹ�����    ��                                                                                                                            ���̽���    ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "����������������                                                                                                                            ����������������" },
	{ "��Ȳ�ݿ���    ��                                                                                                                            ���丣��      ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "����������������                                                                                                                            ����������������" },
	{ "����Ƽ���Ǿ�  ��                                                                                                                            ���̶�ũ��������" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "����������������                                                                                                                            ����������������" },
	{ "������������  ��                                                                                                                            ��Ȳ�ݿ���    ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "������������������������������������������������������������������������������������������������������������������������������������������������������������" },
	{ "������        ��                                                                                                                            ������Ʈ    ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "������������������������������������������������������������������������������������������������������������������������������������������������������������" },
	{ "������        ��                                                                                                                            ���̶�        ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "������������������������������������������������������������������������������������������������������������������������������������������������������������" },
	{ "��Ȳ�ݿ���    ��                                                                                                                            ������ī�Ͻ�ź��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "������������������������������������������������������������������������������������������������������������������������������������������������������������" },
	{ "��������      ��                                                                                                                            ���ѱ�        ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "��            ��                                                                                                                            ��            ��" },
	{ "������������������������������������������������������������������������������������������������������������������������������������������������������������" },
	{ "�����ε�      �����̺�����  �����װ���������Ȳ�ݿ��衡������Ÿ�ϡ���������Ʈ������������ơ���  ��������  ������Ȳ�ݿ��衡���������  ��������ߡ���������" },
	{ "��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��" },
	{ "��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��" },
	{ "��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��            ��" },
	{ "������������������������������������������������������������������������������������������������������������������������������������������������������������" }
};

void mapping(void)
{
	int i;
	for (i = 0;i < 56;i++)
	{
		gotoxy(1, i);
		printf("%s", map[i]);
	}

	PII;
	gotoxy(143, 46); printf("�ѱ�");

	BLUE;
	gotoxy(143, 1);		printf("���ֿ���");
	gotoxy(130, 6);		printf("�����");
	gotoxy(124, 7);		printf("���âââââ�");
	gotoxy(122, 8);		printf("���ââ��âáᢺ");
	gotoxy(119, 9);		printf("����        ��������");//123, 9
	gotoxy(122, 10);	printf("���ââ��âáᢺ");
	gotoxy(124, 11);	printf("���âââââ�");
	gotoxy(130, 12);	printf("�����");

	GREEN;
	gotoxy(3, 51);	printf("���ε�");
	gotoxy(143, 51);	printf("���");

	GOLD;
	gotoxy(115, 51);	printf("Ȳ�ݿ���");
	gotoxy(45, 51);	printf("Ȳ�ݿ���");
	gotoxy(3, 41);	printf("Ȳ�ݿ���");
	gotoxy(3, 16);	printf("Ȳ�ݿ���");
	gotoxy(31, 1);	printf("Ȳ�ݿ���");
	gotoxy(143, 26);	printf("Ȳ�ݿ���");

	WHITE;
}

//////////////////////////////// ���ּ� /////////////////////////////////////////
void go_every(int select)
{
	gotoxy(User[turn - 1].pre_X, User[turn - 1].pre_Y); printf("  "); //���� �ִ� �������� ����
	User[turn - 1].location_index = select;	//����������
	gotoxy(123 + (turn - 1) * 2, 9); printf("  ");	//���ּ����� ����

	User[turn - 1].pre_X = Zone[select].zone_X + (2 * (turn - 1));	//�÷��̾�� ��ĭ�� ��
	User[turn - 1].pre_Y = Zone[select].zone_Y;

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
	WHITE;
}

int select_space()
{
	int select1, select2;
	char enter;
	int differ = '1' - 1;	//���� ���� ����
	int result;
	while (1)
	{
		gotoxy(133, 24);	//ù°�ڸ� ���� �Է�
		select1 = _getch();
		if (select1 == '\b')	//�������̽� �Է��ϸ� �ٽ�
		{
			gotoxy(131, 24); printf("    ");
			continue;
		}
		printf("%c", select1);
		select1 -= differ;


		gotoxy(134, 24);	//��°�ڸ� ���� �Է�
		select2 = _getch();
		if (select2 == '\b')
		{
			gotoxy(131, 24); printf("    ");
			continue;
		}
		if (select2 == ENTER)
		{
			Sleep(150);	//Ŭ���� �ϱ��� ��� �ӵ� ����
			gotoxy(132, 24); printf("    ");

			result = select1;
			if (result >= 0 && result < 10)
				break;
		}
		printf("%c", select2);
		select2 -= differ;

		enter = _getch();
		if (enter != ENTER)	//���� �ȴ����� �ٽ� ����
		{
			Sleep(150);		//Ŭ���� �ϱ��� ��� �ӵ� ����
			gotoxy(132, 24); printf("    ");
			continue;
		}
		Sleep(150);
		gotoxy(132, 24); printf("    ");

		result = select1 * 10 + select2;
		if (result >= 0 && result < 40)
			break;
	}

	return result;
}

void go_space()
{
	gotoxy(User[turn - 1].pre_X, User[turn - 1].pre_Y); printf("  ");;
	gotoxy(123 + (turn - 1) * 2, 9);
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
}

//////////////////////////////// �ֻ��� /////////////////////////////////////////
void print_dice_f(int X, int Y, int dice)
{
	gotoxy(X, Y++);
	GREEN;
	switch (dice)
	{
	case 1:
	{
		printf("����������������"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��     ��     ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("����������������");
		break;
	}
	case 2:
	{
		printf("����������������"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��   ��  ��   ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("����������������");
		break;
	}
	case 3:
	{
		printf("����������������"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��     ��     ��"); gotoxy(X, Y++);
		printf("��     ��     ��"); gotoxy(X, Y++);
		printf("��     ��     ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("����������������");
		break;
	}
	case 4:
	{
		printf("����������������"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��   ��  ��   ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��   ��  ��   ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("����������������");
		break;
	}
	case 5:
	{
		printf("����������������"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��   ��  ��   ��"); gotoxy(X, Y++);
		printf("��     ��     ��"); gotoxy(X, Y++);
		printf("��   ��  ��   ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("����������������");
		break;
	}
	case 6:
	{
		printf("����������������"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("��   ��  ��   ��"); gotoxy(X, Y++);
		printf("��   ��  ��   ��"); gotoxy(X, Y++);
		printf("��   ��  ��   ��"); gotoxy(X, Y++);
		printf("��            ��"); gotoxy(X, Y++);
		printf("����������������");
		break;
	}
	default:
		break;
	}
	gotoxy(X, Y++);
	printf("                              ");
	WHITE;
}


void DICE_CLR(void)
{
	gotoxy(23, 22);
	printf("                                                      "); gotoxy(23, 23);
	printf("                                                      "); gotoxy(23, 24);
	printf("                                                      "); gotoxy(23, 25);
	printf("                                                      "); gotoxy(23, 26);
	printf("                                                      "); gotoxy(23, 27);
	printf("                                                      "); gotoxy(23, 28);
	printf("                                                      "); gotoxy(23, 29);
	printf("                                                      "); gotoxy(23, 30);
	printf("                                                      "); gotoxy(23, 31);
	printf("                                                      "); gotoxy(23, 32);
	printf("                                                      "); gotoxy(23, 33);
	printf("                                                      ");
}

void print_dice(int dice1, int dice2)
{
	print_dice_f(23, 25, dice1);
	print_dice_f(40, 25, dice2);
}

int dice_rand(void)
{
	int dice_buf = 0;
	while (1)
	{
		dice_buf = rand() % 6 + 1;
		if (dice_buf != 0)
			return dice_buf;
	}
}

void casting_dice(int *dice1, int *dice2, int *dice_sum)
{
	*dice1 = dice_rand();
	*dice2 = dice_rand();
	*dice_sum = (*dice1) + (*dice2);

	print_dice(*dice1, *dice2);
}

void run_dice(void)
{
	GREEN;
	gotoxy(23, 34);
	printf("ENTERŰ�� �Է��Ͽ� �ֻ����� ���� �ּ���.");

	PlaySound(TEXT("dice.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // ���������� exe �����ϰ� �ִ� �����ȿ� �־���
	while (1)
	{
		if (_kbhit())
		{
			if (_getch() == ENTER) {
				PlaySound(NULL, NULL, NULL);
				break;
			}
		}
		else
		{
			DICE_CLR();
			print_dice(dice_rand(), dice_rand());
			Sleep(100);
		}
	}
	gotoxy(23, 40);
	printf("                                        ");
	casting_dice(&dice1, &dice2, &dice_sum);	//�ֻ����� �� �ϳ��ϳ��� �� ���� ����
	player_color();
	gotoxy(23, 24);
	printf("�÷��̾�%d�� �ֻ����� ���� ����Դϴ�.", turn);
	WHITE;
}


//////////////////////////////// ȭ��Ŭ���� /////////////////////////////////////////

void MENU_CLR(void)
{
	gotoxy(80, 20); printf("                                                        ");
	gotoxy(80, 21); printf("                                                        ");
	gotoxy(80, 22); printf("                                                        ");
	gotoxy(80, 23); printf("                                                        ");
	gotoxy(80, 24); printf("                                                        ");
	gotoxy(80, 25); printf("                                                        ");
	gotoxy(80, 26); printf("                                                        ");
	gotoxy(80, 27); printf("                                                        ");
	gotoxy(80, 28); printf("                                                        ");
	gotoxy(80, 29); printf("                                                        ");
	gotoxy(80, 30); printf("                                                        ");
	gotoxy(80, 31); printf("                                                        ");
	gotoxy(80, 32); printf("                                                        ");
}


void MY_ZONE_SHOW_CLR(void)
{
	gotoxy(23, 13); printf("                                                       ");
	gotoxy(23, 14); printf("                                                       ");
}

void SELL_LIST_CLR(void)
{
	int x = 0, y = 0;
	gotoxy(x, ++y);
	while (y < 55)
	{
		printf("                         ");
		gotoxy(x, ++y);
	}
}

//////////////////////////////// �� ���� ��ɵ� /////////////////////////////////////////

char who_winner()
{
	int i;
	char winner;

	for (i = 0;i < player_num;i++)
		if (User[i].gameover != GAMEOVER)
			winner = i + 'A';	//�ƽ�Ű�ڵ�� ���ĺ�
	return winner;
}

int exist_struct(char select) //1. �� 2. ȣ�� 3. ���� 4. ����
{
	int k = 0;	//�� �ڸ��� �ǹ��� �ִ��� ������ �˻�

	switch (select)
	{
	case '1':
		if (Zone[User[turn - 1].location_index].owner != 0)
			k = 1;
		break;
	case '2':
		if (Zone[User[turn - 1].location_index].hotel == 1)
			k = 1;
		break;
	case '3':
		if (Zone[User[turn - 1].location_index].building == 1)
			k = 1;
		break;
	case '4':
		if (Zone[User[turn - 1].location_index].villa == 1)
			k = 1;
		break;
	}
	return k;
}

char select_menu(void)
{
	char select;
	while (1)
	{
		gotoxy(110, 31);
		while ((select = _getch()) == ENTER);
		printf("%c", select);
		if (select == '1' || select == '2' || select == '3' || select == '4' || select == '5')
			break;
	}
	return select;
}

char select_passcard(void)
{
	char select;
	while (1)
	{
		gotoxy(139, 24);
		while ((select = _getch()) == ENTER);
		printf("%c", select);
		if (select == '1' || select == '2')
			break;
	}
	return select;
}

void zone_menu()
{
	gotoxy(80, 25); printf("�ൿ�� �����ϼž� �մϴ�. ");
	gotoxy(80, 26); printf("1. ���� �����Ѵ�. ( %d���� )", Zone[User[turn - 1].location_index].zone_cost);
	gotoxy(80, 27); printf("2. ȣ���� ���´�. ( %d���� )", Zone[User[turn - 1].location_index].hotel_cost);
	gotoxy(80, 28); printf("3. ������ ���´�. ( %d���� )", Zone[User[turn - 1].location_index].building_cost);
	gotoxy(80, 29); printf("4. ������ ���´�. ( %d���� )", Zone[User[turn - 1].location_index].villa_cost);
	gotoxy(80, 30); printf("5. �׳� ��������.");
	gotoxy(80, 31); printf("�ൿ�� ��ȣ�� �Է����ּ��� : ");
}

void MY_ZONE_SHOW()
{
	player_color();
	gotoxy(23, 13);
	printf("�÷��̾�%d�� ���� ���� �� & �ǹ�", turn);

	WHITE;
	gotoxy(23, 14);

	//�� ���϶� �� ������ �ִ��� ������
	if (Zone[User[turn - 1].location_index].owner == turn)
	{
		printf("%s", Zone[User[turn - 1].location_index].zone_name);
		gotoxy(36, 14);
		printf("(");

		if (Zone[User[turn - 1].location_index].hotel == 1)
		{
			gotoxy(39, 14); printf("ȣ��");
		}
		if (Zone[User[turn - 1].location_index].building == 1)
		{
			gotoxy(44, 14);	printf(" ����");
		}
		if (Zone[User[turn - 1].location_index].villa == 1)
		{
			gotoxy(49, 14);	printf(" ����");
		}
		gotoxy(56, 14);	printf(")");
	}
}

int toll_money()		// �ɷ����� �����
{
	int money = 0;

	if (Zone[User[turn - 1].location_index].owner > 0)
		money += Zone[User[turn - 1].location_index].zone_toll;
	if (Zone[User[turn - 1].location_index].hotel == 1)
		money += Zone[User[turn - 1].location_index].hotel_toll;
	if (Zone[User[turn - 1].location_index].building == 1)
		money += Zone[User[turn - 1].location_index].building_toll;
	if (Zone[User[turn - 1].location_index].villa == 1)
		money += Zone[User[turn - 1].location_index].villa_toll;

	return money;
}

int zone_money(char select)  //�� �� �ִ� ���� ������ 1 ������ 0 ��ȯ
{
	int k = 0;
	switch (select)
	{
	case '1':
		if (User[turn - 1].money > Zone[User[turn - 1].location_index].zone_cost)
			k = 1;
		break;
	case '2':
		if (User[turn - 1].money > Zone[User[turn - 1].location_index].hotel_cost)
			k = 1;
		break;
	case '3':
		if (User[turn - 1].money > Zone[User[turn - 1].location_index].building_cost)
			k = 1;
		break;
	case '4':
		if (User[turn - 1].money > Zone[User[turn - 1].location_index].villa_cost)
			k = 1;
		break;
	}
	return k;
}

void zone_color()	//������ ������ ������ ����
{
	player_color();
	gotoxy(Zone[User[turn - 1].location_index].zone_X, Zone[User[turn - 1].location_index].zone_Y - 2);
	printf("%s", Zone[User[turn - 1].location_index].zone_name);
	WHITE;
}

void buy_struct(char select) //1. �� 2. ȣ�� 3. ���� 4. ����
{
	if (zone_money(select))	//�� ������� �˻�
	{
		switch (select)
		{
		case '1':
			gotoxy(80, 24);	printf("%s ������ ���Ÿ� �Ϸ��Ͽ����ϴ�.", Zone[User[turn - 1].location_index].zone_name);
			gotoxy(80, 25);	printf("ENTER�� �Է��ϼ���.");
			zone_color();	//������ ������ ������ ����
			while (_getch() != ENTER);
			MENU_CLR();
			Zone[User[turn - 1].location_index].owner = turn;	//�������� ����
			User[turn - 1].money -= Zone[User[turn - 1].location_index].zone_cost;	//���� ���

			STATE = NEXT_TURN;
			break;
		case '2':
			gotoxy(80, 24);	printf("%s ������ ȣ���� �������ϴ�.", Zone[User[turn - 1].location_index].zone_name);
			gotoxy(80, 25);	printf("ENTER�� �Է��ϼ���.");
			while (_getch() != ENTER);
			MENU_CLR();
			Zone[User[turn - 1].location_index].hotel = 1;	//�������� ����
			User[turn - 1].money -= Zone[User[turn - 1].location_index].hotel_cost;	//���� ���

			STATE = NEXT_TURN;
			break;
		case '3':
			gotoxy(80, 24);	printf("%s ������ ������ �������ϴ�.", Zone[User[turn - 1].location_index].zone_name);
			gotoxy(80, 25);	printf("ENTER�� �Է��ϼ���.");
			while (_getch() != ENTER);
			MENU_CLR();
			Zone[User[turn - 1].location_index].building = 1;	//�������� ����
			User[turn - 1].money -= Zone[User[turn - 1].location_index].building_cost;	//���� ���

			STATE = NEXT_TURN;
			break;
		case '4':
			gotoxy(80, 24);	printf("%s ������ ������ �������ϴ�.", Zone[User[turn - 1].location_index].zone_name);
			gotoxy(80, 25);	printf("ENTER�� �Է��ϼ���.");
			while (_getch() != ENTER);
			MENU_CLR();
			Zone[User[turn - 1].location_index].villa = 1;	//�������� ����
			User[turn - 1].money -= Zone[User[turn - 1].location_index].villa_cost;	//���� ���

			STATE = NEXT_TURN;
			break;
		}
	}
	else
	{
		gotoxy(80, 24);	printf("���� �����մϴ�.");
		gotoxy(80, 25);	printf("���� ������ �Ѿ�ϴ�.");
		gotoxy(80, 26);	printf("ENTER�� �Է��ϼ���.");
		while (_getch() != ENTER);
		MENU_CLR();
		STATE = NEXT_TURN;
	}
}


void struct_show()			// �ǹ� �� ������
{
	int x = User[turn - 1].pre_X - (turn - 1) * 2;
	int y = User[turn - 1].pre_Y + 1;

	player_color();

	if (Zone[User[turn - 1].location_index].hotel == 1)
	{
		gotoxy(x, y);
		printf("��");
	}
	if (Zone[User[turn - 1].location_index].building == 1)
	{
		gotoxy(x + 3, y);
		printf("��");

	}
	if (Zone[User[turn - 1].location_index].villa == 1)
	{
		gotoxy(x + 6, y);
		printf("��");
	}
	WHITE;
}


#endif