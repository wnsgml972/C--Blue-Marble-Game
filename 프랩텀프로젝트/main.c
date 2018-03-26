/*
* 2학년 프로그래밍랩 기말고사 텀 프로젝트
*    1392056 김준희, 1392048 안형우
*        2016.06.07   ver 0.9
*/

#include "common.h"
#include "define.h"
#include "function.h"
#include "struct.h"
#include "intro.h"
#include "zone.h"
#include "player.h"
#include "goldenkey.h"

int main()
{
	int n;					//게임오버 조종
	int key;				//황금열쇠 키
	int gameover_cnt = 0;	//게임오버 플레이어 숫자
	char winner;			//이긴 플레이어 누구?
	char zone_select;		//존 메뉴 행동 선택
	char passcard_select;	//우대권 행동 선택
	int space_select;		//우주 여행 어디 갈 건지
	int toll;				//통행료
	int loop = 1;			//while문 무한 루프를 위한 변수
	int musictimer = 0;		//음악 몇초간 돌릴껀지

	STATE = INTRO;	//게임 시작!

	while (1)
	{
		Sleep(1);	//무한루프에서
		switch (STATE)
		{
		case INTRO:			//인트로
			intro_start();
			gameover_cnt = 4 - player_num;
			STATE = init;
			break;

		case init:			//초기화
			system("mode con: cols=160 lines=138");				// 게임 창(콘솔창) 크기를 바꿔줌
			golden_key_init();
			zone_init();
			player_init();
			mapping();
			money_show(User);
			moving_init(User);
			STATE = P_TURN;
			break;

		case P_TURN:		//플레이어 턴
			//주사위 소리
			if (User[turn - 1].use_space != 1)	//우주선에 있을때는 안굴림
				run_dice(); // 주사위굴러가는 모습
			if (User[turn - 1].island_cnt != 1 && User[turn - 1].island_cnt != 2 && User[turn - 1].use_space != 1)	//무인도 3턴동안은 안움직임, 우주선에 있을때 한턴 쉼
				moving_player(User, dice_sum);	//2개의 다이스 합만큼 이동
			MY_ZONE_SHOW();

			if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "무인도"))
				STATE = ISLAND;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "황금열쇠"))
				STATE = GOLDEN_KEY;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "출발"))
				STATE = NEXT_TURN;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "우주여행"))
				STATE = SPACESHIP;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "한국"))
				STATE = KOREA;
			else
			{
				player_color();
				MENU_CLR();
				gotoxy(80, 21);
				printf("%s 칸에 도착하였습니다.", Zone[User[turn - 1].location_index].zone_name);
				gotoxy(80, 22);
				printf("현재 플레이어%d의 소지금 : %d 만원입니다.", turn, User[turn - 1].money);
				if (Zone[User[turn - 1].location_index].owner == 0 || Zone[User[turn - 1].location_index].owner == turn)	//주인이 없거나 자기 것
					STATE = BUY_ZONE;
				else
					STATE = TOLL;
			}
			WHITE;
			break;

		case NOT_MOVING:	//우주선에서 도착한 후 안움직임
			MY_ZONE_SHOW();
			if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "무인도"))
				STATE = ISLAND;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "황금열쇠"))
				STATE = GOLDEN_KEY;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "출발"))
				STATE = NEXT_TURN;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "우주여행"))
				STATE = SPACESHIP;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "한국"))
				STATE = KOREA;
			else
			{
				player_color();
				MENU_CLR();
				gotoxy(80, 21);
				printf("%s 칸에 도착하였습니다.", Zone[User[turn - 1].location_index].zone_name);
				gotoxy(80, 22);
				printf("현재 플레이어%d의 소지금 : %d 만원입니다.", turn, User[turn - 1].money);
				if (Zone[User[turn - 1].location_index].owner == 0 || Zone[User[turn - 1].location_index].owner == turn)	//주인이 없거나 자기 것
					STATE = BUY_ZONE;
				else
					STATE = TOLL;
			}
			WHITE;
			break;

		case BUY_ZONE:			//땅 사기, 돈있는지 없는지 검사
			if (Zone[User[turn - 1].location_index].owner == 0)
			{
				gotoxy(80, 24); printf("주인이 없는 땅입니다.");
			}
			else if (Zone[User[turn - 1].location_index].owner == turn)
			{
				gotoxy(80, 24); printf("당신의 땅입니다.");
			}
			zone_menu();
			zone_select = select_menu();	//메뉴 선택
			MENU_CLR();
			if (zone_select == '5')	//그냥 지나갑니다.
			{
				STATE = NEXT_TURN;
				break;
			}
			else
			{
				if (Zone[User[turn - 1].location_index].owner == 0 && zone_select != '1')	//주인이 없는데 땅안사고 딴거 하려고 하면 다시 선택
				{
					gotoxy(80, 24); printf("당신의 땅이 아닙니다. 행동을 다시 선택해주세요.");
					gotoxy(80, 25);	printf("ENTER를 입력하세요.");
					while (_getch() != ENTER);
					MENU_CLR();

					STATE = BUY_ZONE;
					break;
				}
				else
				{
					if (!exist_struct(zone_select))	//선택한 메뉴에 건물이나 땅이 있는지 없는지
					{
						buy_struct(zone_select);	//없다면 삼
						struct_show();	//건물이나 땅 살때마다 표시
					}
					else //선택한 메뉴에 건물이 있다면 행동 다시 선택
					{
						gotoxy(80, 24); printf("이미 땅이나 건물이 있습니다. 행동을 다시 선택해주세요.");
						gotoxy(80, 25);	printf("ENTER를 입력하세요.");
						while (_getch() != ENTER);
						MENU_CLR();

						STATE = BUY_ZONE;
						break;
					}
				}
			}
			STATE = NEXT_TURN;
			break;

		case TOLL:
			if (User[turn - 1].passcard == 1)	//우대권 사용 여부
			{
				gotoxy(80, 24); printf("우대권이 있습니다. 사용하시겠습니까 (YES : 1), (NO : 2) ? ");
				passcard_select = select_passcard();
				gotoxy(80, 24); printf("                                                            ");
				if (passcard_select == '1')
				{
					gotoxy(80, 25); printf("우대권을 사용하여 그냥 지나갑니다.");
					gotoxy(80, 27);	printf("ENTER를 입력하세요.");
					while (_getch() != ENTER);
					MENU_CLR();
					User[turn - 1].passcard = 0;	//우대권 사용!

					STATE = NEXT_TURN;
					break;
				}
				else if (passcard_select == '2')
				{
					gotoxy(80, 25); printf("우대권을 사용하지 않습니다.");
					gotoxy(80, 27);	printf("ENTER를 입력하세요.");
					while (_getch() != ENTER);
					MENU_CLR();
				}
			}

			toll = toll_money();
			gotoxy(80, 24);	printf("다른 사람의 땅입니다. 통행료를 지불하셔야 합니다.");
			gotoxy(80, 25); printf("통행료 %d만원을 지불합니다.", toll);
			User[turn - 1].money -= toll;
			User[Zone[User[turn - 1].location_index].owner - 1].money += toll;	//그 자리 주인에게 돈을 줌
			if (User[turn - 1].money <= 0)	//통행료 내고 돈 0이하가 되면 파산!
			{
				gotoxy(80, 26); printf("플레이어%d는 파산하였습니다!", turn);

				PlaySound(TEXT("pasan.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // 음악파일이 exe 파일하고 있는 폴더안에 있어함
				while (1) 
				{
					Sleep(100);
					musictimer++;
					if (musictimer == 21) 
					{
						musictimer = 0;
						break;
					}
				}
				PlaySound(NULL, NULL, NULL);
				User[turn - 1].gameover = GAMEOVER;
				gameover_cnt++;
				if (gameover_cnt == 3)
				{
					STATE = GAME_OVER;
					break;
				}
			}
			gotoxy(80, 27);	printf("ENTER를 입력하세요.");
			while (_getch() != ENTER);
			MENU_CLR();

			STATE = NEXT_TURN;
			break;

		case KOREA:
			PII;
			gotoxy(80, 24); printf("한국에 도착하셨군요!");
			gotoxy(80, 25); printf("한국인의 정으로 1000만원을 지급해드리겠습니다.");

			PlaySound(TEXT("hankook.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // 음악파일이 exe 파일하고 있는 폴더안에 있어함
			while (1) {
				Sleep(100);
				musictimer++;
				if (musictimer == 20) {
					musictimer = 0;
					break;
				}
			}
			PlaySound(NULL, NULL, NULL);

			WHITE;
			gotoxy(80, 27);	printf("ENTER를 입력하세요.");
			while (_getch() != ENTER);
			MENU_CLR();
			User[turn - 1].money += 1000;

			STATE = NEXT_TURN;
			break;

		case SPACESHIP:			//우주선
			//우주여행 음악 -> 피유유융
			go_space();
			User[turn - 1].use_space++;	//한턴은 가만히 있음
			if (User[turn - 1].use_space == 1)
			{
				PlaySound(TEXT("trip.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // 음악파일이 exe 파일하고 있는 폴더안에 있어함
				while (1) {
					Sleep(100);
					musictimer++;
					if (musictimer == 22) {
						musictimer = 0;
						break;
					}
				}
				PlaySound(NULL, NULL, NULL);

				BLUE;
				gotoxy(80, 24);	printf("현재 당신은 우주선에 탑승했습니다.");
				gotoxy(80, 25);	printf("다음턴에 원하는 장소로 갈 수 있습니다.");
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				STATE = NEXT_TURN;
				break;
			}
			else
			{
				DICE_CLR();
				BLUE;
				gotoxy(80, 24);	printf("이동하기를 원하는 지역의 번호를 입력하세요 (ENTER): ");
				gotoxy(80, 25); printf("출발(0) ~ 한국(39)");
				space_select = select_space();
				go_every(space_select);
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				User[turn - 1].use_space = 0;
				STATE = NOT_MOVING;
				break;
			}
			break;

		case ISLAND:			//무인도
			//무인도 음악
			GREEN;
			gotoxy(80, 24);	printf("현재 당신은 무인도에서 표류중입니다.");

			PlaySound(TEXT("indo.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // 음악파일이 exe 파일하고 있는 폴더안에 있어함
			while (1) {
				Sleep(100);
				musictimer++;
				if (musictimer == 24) {
					musictimer = 0;
					break;
				}
			}
			PlaySound(NULL, NULL, NULL);

			if (User[turn - 1].escape == 1)
			{
				gotoxy(80, 25);	printf("무인도 탈출권을 사용하여 바로 탈출합니다.");
				User[turn - 1].escape -= 1;
				User[turn - 1].island_cnt = 0;	//바로 탈출
			}
			else if (dice1 == dice2)
			{
				gotoxy(80, 25);	printf("더블입니다! 축하드립니다. 다음턴에 바로 탈출합니다.");
				User[turn - 1].island_cnt = 0;	//바로 탈출
			}
			else
			{
				gotoxy(80, 25);	printf("3턴동안 갇혀 있게됩니다.");
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();

				STATE = IN_ISLAND;
				break;
			}
			WHITE;
			gotoxy(80, 27);	printf("ENTER를 입력하세요.");
			while (_getch() != ENTER);
			MENU_CLR();

			STATE = NEXT_TURN;
			break;

		case IN_ISLAND:
			GREEN;
			if (User[turn - 1].island_cnt == 2)
			{
				User[turn - 1].island_cnt = 0;
				gotoxy(80, 25);	printf("다음 턴에 무인도에서 탈출합니다!!");
			}
			else
			{
				gotoxy(80, 25);	printf("이번 턴에는 탈출하실 수가 없네요...");
				User[turn - 1].island_cnt++;
			}
			WHITE;
			gotoxy(80, 27);	printf("ENTER를 입력하세요.");
			while (_getch() != ENTER);
			MENU_CLR();

			STATE = NEXT_TURN;
			break;

		case GOLDEN_KEY:		//황금열쇠
			//황금열쇠 음악
			GOLD;
			gotoxy(80, 24);	printf("축하드립니다. 황금열쇠를 얻었습니다!!!");

			PlaySound(TEXT("goldkey.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // 음악파일이 exe 파일하고 있는 폴더안에 있어함
			while (1) {
				Sleep(100);
				musictimer++;
				if (musictimer == 12) {
					musictimer = 0;
					break;
				}
			}
			PlaySound(NULL, NULL, NULL);

			WHITE;
			gotoxy(80, 27);	printf("ENTER를 입력하세요.");
			while (_getch() != ENTER);
			MENU_CLR();
			GOLD;
			key = get_golden_key();
			switch (key)
			{
			case 0:
				gotoxy(80, 24); printf("%s", G_KEY[0].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[0].key_content);
				User[turn - 1].money -= 5;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 1:
				gotoxy(80, 24); printf("%s", G_KEY[1].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[1].key_content);
				User[turn - 1].money += 20;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 2:
				gotoxy(80, 24); printf("%s", G_KEY[2].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[2].key_content);
				User[turn - 1].escape = 1;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 3:
				gotoxy(80, 24); printf("%s", G_KEY[3].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[3].key_content);
				go_every(10);	//무인도로 보내버림여
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 4:
				gotoxy(80, 24); printf("%s", G_KEY[4].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[4].key_content);
				go_every(39); //한국으로 보내버림여
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 5:
				gotoxy(80, 24); printf("%s", G_KEY[5].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[5].key_content);
				User[turn - 1].money -= 5;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 6:
				gotoxy(80, 24); printf("%s", G_KEY[6].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[6].key_content);
				User[turn - 1].money -= 10;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 7:
				gotoxy(80, 24); printf("%s", G_KEY[7].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[7].key_content);
				User[turn - 1].money += 5;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 8:
				gotoxy(80, 24); printf("%s", G_KEY[8].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[8].key_content);
				go_every(User[turn - 1].location_index - 3); //뒤로 세칸 보내버림
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 9:
				gotoxy(80, 24); printf("%s", G_KEY[9].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[9].key_content);
				go_every(User[turn - 1].location_index + 2); //앞으로 두칸
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 10:
				gotoxy(80, 24); printf("%s", G_KEY[10].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[10].key_content);
				go_every(0); //출발지점으로!
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 11:
				gotoxy(80, 24); printf("%s", G_KEY[11].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[11].key_content);
				User[turn - 1].money += 10;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 12:
				gotoxy(80, 24); printf("%s", G_KEY[12].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[12].key_content);
				User[turn - 1].passcard = 1;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 13:
				gotoxy(80, 24); printf("%s", G_KEY[13].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[13].key_content);
				go_every(25);	//부산
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 14:
				gotoxy(80, 24); printf("%s", G_KEY[14].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[14].key_content);
				User[turn - 1].money += 10;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 15:
				gotoxy(80, 24); printf("%s", G_KEY[15].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[15].key_content);
				moving_player(User, 40);	//한바퀴 돌아
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 16:
				gotoxy(80, 24); printf("%s", G_KEY[16].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[16].key_content);
				User[turn - 1].money += 30;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 17:
				gotoxy(80, 24); printf("%s", G_KEY[17].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[17].key_content);
				go_every(30);	//우주선으로 보내버림여
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER를 입력하세요.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			}
			if (key != 17 && key != 3 && key != 4 && key != 8 && key != 9)	//위에서 상태를 변경하는 것들
				STATE = NEXT_TURN;
			break;

		case NEXT_TURN:			//다음 턴
			next_turn();
			money_show(User);
			MY_ZONE_SHOW_CLR();
			DICE_CLR();
			MENU_CLR();
			gotoxy(23, 34); printf("                                                      ");
			player_color();
			gotoxy(23, 32);
			printf("플레이어%d의 차례입니다.", turn);
			gotoxy(23, 33);
			printf("주사위를 굴리려면 ENTER를 입력해주세요.");

			while (_getch() != ENTER);

			STATE = P_TURN;
			break;

		case GAME_OVER:			//게임 오버
		/////// 세명 게임 오버 시 종료 ///////
		//게임 오버 음악 딴따라라라~
			winner = who_winner();
			while (1)
			{
				PlaySound(TEXT("gameover.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // 음악파일이 exe 파일하고 있는 폴더안에 있어함
				if (winner == 'A')
					MessageBox(NULL, L"게임이 종료되었습니다--승리자는 ①플레이어입니다", L"제작자-안형우,김준희", MB_OK);
				else if (winner == 'B')
					MessageBox(NULL, L"게임이 종료되었습니다--승리자는 ②플레이어입니다", L"제작자-안형우,김준희", MB_OK);
				else if (winner == 'C')
					MessageBox(NULL, L"게임이 종료되었습니다--승리자는 ③플레이어입니다", L"제작자-안형우,김준희", MB_OK);
				else if (winner == 'D')
					MessageBox(NULL, L"게임이 종료되었습니다--승리자는 ④플레이어입니다", L"제작자-안형우,김준희", MB_OK);

				n = MessageBox(NULL, L"게임을 다시하시겠습니까?", L"제작자-안형우,김준희", MB_YESNO);
				if (n != 7)	//다시 시작 버튼 누르면 intro부터 다시 시작!
				{
					STATE = INTRO;
					break;
				}
				else
				{
					system("cls");
					exit(1);
				}
				break;
			}
		default:
			break;

		}
	}
	return 0;
}