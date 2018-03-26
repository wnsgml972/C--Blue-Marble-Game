#ifndef FUNCTION_H
#define FUNCTION_H

#include "define.h"
#include "common.h"

//////////////////////////////// 그리기 /////////////////////////////////////////
void removeCursor(void)
{ // 커서를 안보이게 한다

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
{ // 커서를 보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void cls(int bg_color, int text_color) // 화면 지우기
{
	char cmd[100];
	int fg_color = 0;
	system("cls");
	sprintf_s(cmd, 100, "COLOR %x%x", bg_color, text_color);
	system(cmd);

}

void player_color()	//플레이어 색깔 입히기
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

/////////////////////////////////////// 지도 //////////////////////////////////
char *map[158] =
{
	{ "┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐" },
	{ "│탄자니아    │마다가스카르│황금열쇠    │앙골라      │콩고        │부산        │보츠와나    │남아공      │터키        │시리아      │우주여행    │" },
	{ "│            │            │            │            │            │            │            │            │            │            │            │" },
	{ "│            │            │            │            │            │            │            │            │            │            │            │" },
	{ "│            │            │            │            │            │            │            │            │            │            │            │" },
	{ "├──────┼──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┼──────┤" },
	{ "│케냐        │                                                                                                                            │레바논      │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "├──────┤                                                                                                                            ├──────┤" },
	{ "│소말리아    │                                                                                                                            │이스라엘    │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "├──────┤                                                                                                                            ├──────┤" },
	{ "│황금열쇠    │                                                                                                                            │요르단      │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "├──────┤                                                                                                                            ├──────┤" },
	{ "│에티오피아  │                                                                                                                            │이라크　　　│" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "├──────┤                                                                                                                            ├──────┤" },
	{ "│나이지리아  │                                                                                                                            │황금열쇠    │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "├──────┤　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　├──────┤" },
	{ "│수단        │                                                                                                                            │쿠에이트    │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "├──────┤　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　├──────┤" },
	{ "│차드        │                                                                                                                            │이란        │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "├──────┤　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　├──────┤" },
	{ "│황금열쇠    │                                                                                                                            │아프카니스탄│" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "├──────┤　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　├──────┤" },
	{ "│리제르      │                                                                                                                            │한국        │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "│            │                                                                                                                            │            │" },
	{ "├──────┼──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┼──────┤" },
	{ "│무인도      │라이베리아  │세네갈　　　│황금열쇠　　│모리타니　　│이집트　　　│리비아　　  │알제리  　　│황금열쇠　　│모로코  　　│출발　　　　│" },
	{ "│            │            │            │            │            │            │            │            │            │            │            │" },
	{ "│            │            │            │            │            │            │            │            │            │            │            │" },
	{ "│            │            │            │            │            │            │            │            │            │            │            │" },
	{ "└──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘" }
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
	gotoxy(143, 46); printf("한국");

	BLUE;
	gotoxy(143, 1);		printf("우주여행");
	gotoxy(130, 6);		printf("▲▲▲▲");
	gotoxy(124, 7);		printf("◀▣▣▣▣▣▶");
	gotoxy(122, 8);		printf("◀▣▣⊙▣▣■▶");
	gotoxy(119, 9);		printf("◀▣        ▶▶▶▶");//123, 9
	gotoxy(122, 10);	printf("◀▣▣⊙▣▣■▶");
	gotoxy(124, 11);	printf("◀▣▣▣▣▣▶");
	gotoxy(130, 12);	printf("▼▼▼▼");

	GREEN;
	gotoxy(3, 51);	printf("무인도");
	gotoxy(143, 51);	printf("출발");

	GOLD;
	gotoxy(115, 51);	printf("황금열쇠");
	gotoxy(45, 51);	printf("황금열쇠");
	gotoxy(3, 41);	printf("황금열쇠");
	gotoxy(3, 16);	printf("황금열쇠");
	gotoxy(31, 1);	printf("황금열쇠");
	gotoxy(143, 26);	printf("황금열쇠");

	WHITE;
}

//////////////////////////////// 우주선 /////////////////////////////////////////
void go_every(int select)
{
	gotoxy(User[turn - 1].pre_X, User[turn - 1].pre_Y); printf("  "); //원래 있던 공간에서 지움
	User[turn - 1].location_index = select;	//보내버림여
	gotoxy(123 + (turn - 1) * 2, 9); printf("  ");	//우주선에서 지움

	User[turn - 1].pre_X = Zone[select].zone_X + (2 * (turn - 1));	//플레이어마다 한칸씩 옆
	User[turn - 1].pre_Y = Zone[select].zone_Y;

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
	WHITE;
}

int select_space()
{
	int select1, select2;
	char enter;
	int differ = '1' - 1;	//문자 숫자 차이
	int result;
	while (1)
	{
		gotoxy(133, 24);	//첫째자리 숫자 입력
		select1 = _getch();
		if (select1 == '\b')	//벡스페이스 입력하면 다시
		{
			gotoxy(131, 24); printf("    ");
			continue;
		}
		printf("%c", select1);
		select1 -= differ;


		gotoxy(134, 24);	//둘째자리 숫자 입력
		select2 = _getch();
		if (select2 == '\b')
		{
			gotoxy(131, 24); printf("    ");
			continue;
		}
		if (select2 == ENTER)
		{
			Sleep(150);	//클리어 하기전 잠깐 속도 늦춤
			gotoxy(132, 24); printf("    ");

			result = select1;
			if (result >= 0 && result < 10)
				break;
		}
		printf("%c", select2);
		select2 -= differ;

		enter = _getch();
		if (enter != ENTER)	//엔터 안누르면 다시 위로
		{
			Sleep(150);		//클리어 하기전 잠깐 속도 늦춤
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
}

//////////////////////////////// 주사위 /////////////////////////////////////////
void print_dice_f(int X, int Y, int dice)
{
	gotoxy(X, Y++);
	GREEN;
	switch (dice)
	{
	case 1:
	{
		printf("┌──────┐"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│     ●     │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("└──────┘");
		break;
	}
	case 2:
	{
		printf("┌──────┐"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│   ●  ●   │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("└──────┘");
		break;
	}
	case 3:
	{
		printf("┌──────┐"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│     ●     │"); gotoxy(X, Y++);
		printf("│     ●     │"); gotoxy(X, Y++);
		printf("│     ●     │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("└──────┘");
		break;
	}
	case 4:
	{
		printf("┌──────┐"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│   ●  ●   │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│   ●  ●   │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("└──────┘");
		break;
	}
	case 5:
	{
		printf("┌──────┐"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│   ●  ●   │"); gotoxy(X, Y++);
		printf("│     ●     │"); gotoxy(X, Y++);
		printf("│   ●  ●   │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("└──────┘");
		break;
	}
	case 6:
	{
		printf("┌──────┐"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("│   ●  ●   │"); gotoxy(X, Y++);
		printf("│   ●  ●   │"); gotoxy(X, Y++);
		printf("│   ●  ●   │"); gotoxy(X, Y++);
		printf("│            │"); gotoxy(X, Y++);
		printf("└──────┘");
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
	printf("ENTER키를 입력하여 주사위를 멈춰 주세요.");

	PlaySound(TEXT("dice.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // 음악파일이 exe 파일하고 있는 폴더안에 있어함
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
	casting_dice(&dice1, &dice2, &dice_sum);	//주사위의 값 하나하나와 그 합을 받음
	player_color();
	gotoxy(23, 24);
	printf("플레이어%d의 주사위를 굴린 결과입니다.", turn);
	WHITE;
}


//////////////////////////////// 화면클리어 /////////////////////////////////////////

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

//////////////////////////////// 그 밖의 기능들 /////////////////////////////////////////

char who_winner()
{
	int i;
	char winner;

	for (i = 0;i < player_num;i++)
		if (User[i].gameover != GAMEOVER)
			winner = i + 'A';	//아스키코드로 알파벳
	return winner;
}

int exist_struct(char select) //1. 존 2. 호텔 3. 빌딩 4. 별장
{
	int k = 0;	//그 자리에 건물이 있는지 없는지 검사

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
	gotoxy(80, 25); printf("행동을 선택하셔야 합니다. ");
	gotoxy(80, 26); printf("1. 땅을 구매한다. ( %d만원 )", Zone[User[turn - 1].location_index].zone_cost);
	gotoxy(80, 27); printf("2. 호텔을 짓는다. ( %d만원 )", Zone[User[turn - 1].location_index].hotel_cost);
	gotoxy(80, 28); printf("3. 빌딩을 짓는다. ( %d만원 )", Zone[User[turn - 1].location_index].building_cost);
	gotoxy(80, 29); printf("4. 별장을 짓는다. ( %d만원 )", Zone[User[turn - 1].location_index].villa_cost);
	gotoxy(80, 30); printf("5. 그냥 지나간다.");
	gotoxy(80, 31); printf("행동의 번호를 입력해주세요 : ");
}

void MY_ZONE_SHOW()
{
	player_color();
	gotoxy(23, 13);
	printf("플레이어%d의 현재 보유 땅 & 건물", turn);

	WHITE;
	gotoxy(23, 14);

	//내 땅일때 뭐 가지고 있는지 보여줌
	if (Zone[User[turn - 1].location_index].owner == turn)
	{
		printf("%s", Zone[User[turn - 1].location_index].zone_name);
		gotoxy(36, 14);
		printf("(");

		if (Zone[User[turn - 1].location_index].hotel == 1)
		{
			gotoxy(39, 14); printf("호텔");
		}
		if (Zone[User[turn - 1].location_index].building == 1)
		{
			gotoxy(44, 14);	printf(" 빌딩");
		}
		if (Zone[User[turn - 1].location_index].villa == 1)
		{
			gotoxy(49, 14);	printf(" 별장");
		}
		gotoxy(56, 14);	printf(")");
	}
}

int toll_money()		// 걸렸을시 통행료
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

int zone_money(char select)  //살 수 있는 돈이 있으면 1 없으면 0 반환
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

void zone_color()	//구매한 지역에 색깔을 입힘
{
	player_color();
	gotoxy(Zone[User[turn - 1].location_index].zone_X, Zone[User[turn - 1].location_index].zone_Y - 2);
	printf("%s", Zone[User[turn - 1].location_index].zone_name);
	WHITE;
}

void buy_struct(char select) //1. 존 2. 호텔 3. 빌딩 4. 별장
{
	if (zone_money(select))	//돈 충분한지 검사
	{
		switch (select)
		{
		case '1':
			gotoxy(80, 24);	printf("%s 지역의 구매를 완료하였습니다.", Zone[User[turn - 1].location_index].zone_name);
			gotoxy(80, 25);	printf("ENTER를 입력하세요.");
			zone_color();	//구매한 지역에 색깔을 입힘
			while (_getch() != ENTER);
			MENU_CLR();
			Zone[User[turn - 1].location_index].owner = turn;	//주인으로 만듬
			User[turn - 1].money -= Zone[User[turn - 1].location_index].zone_cost;	//가격 계산

			STATE = NEXT_TURN;
			break;
		case '2':
			gotoxy(80, 24);	printf("%s 지역에 호텔을 지었습니다.", Zone[User[turn - 1].location_index].zone_name);
			gotoxy(80, 25);	printf("ENTER를 입력하세요.");
			while (_getch() != ENTER);
			MENU_CLR();
			Zone[User[turn - 1].location_index].hotel = 1;	//주인으로 만듬
			User[turn - 1].money -= Zone[User[turn - 1].location_index].hotel_cost;	//가격 계산

			STATE = NEXT_TURN;
			break;
		case '3':
			gotoxy(80, 24);	printf("%s 지역에 빌딩을 지었습니다.", Zone[User[turn - 1].location_index].zone_name);
			gotoxy(80, 25);	printf("ENTER를 입력하세요.");
			while (_getch() != ENTER);
			MENU_CLR();
			Zone[User[turn - 1].location_index].building = 1;	//주인으로 만듬
			User[turn - 1].money -= Zone[User[turn - 1].location_index].building_cost;	//가격 계산

			STATE = NEXT_TURN;
			break;
		case '4':
			gotoxy(80, 24);	printf("%s 지역에 별장을 지었습니다.", Zone[User[turn - 1].location_index].zone_name);
			gotoxy(80, 25);	printf("ENTER를 입력하세요.");
			while (_getch() != ENTER);
			MENU_CLR();
			Zone[User[turn - 1].location_index].villa = 1;	//주인으로 만듬
			User[turn - 1].money -= Zone[User[turn - 1].location_index].villa_cost;	//가격 계산

			STATE = NEXT_TURN;
			break;
		}
	}
	else
	{
		gotoxy(80, 24);	printf("돈이 부족합니다.");
		gotoxy(80, 25);	printf("다음 턴으로 넘어갑니다.");
		gotoxy(80, 26);	printf("ENTER를 입력하세요.");
		while (_getch() != ENTER);
		MENU_CLR();
		STATE = NEXT_TURN;
	}
}


void struct_show()			// 건물 을 보여줌
{
	int x = User[turn - 1].pre_X - (turn - 1) * 2;
	int y = User[turn - 1].pre_Y + 1;

	player_color();

	if (Zone[User[turn - 1].location_index].hotel == 1)
	{
		gotoxy(x, y);
		printf("◈");
	}
	if (Zone[User[turn - 1].location_index].building == 1)
	{
		gotoxy(x + 3, y);
		printf("⊙");

	}
	if (Zone[User[turn - 1].location_index].villa == 1)
	{
		gotoxy(x + 6, y);
		printf("△");
	}
	WHITE;
}


#endif