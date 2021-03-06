#include "common.h"
#include "function.h"
#include "struct.h"

#pragma comment (lib,"winmm.lib")	

char *text[158] =
{
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },// [0]
	{ "         □                  □                                                                          ■                 □                □              " },
	{ "         □                  □                                                                          ■                 □                □              " },
	{ "         □                  □               □□□□□□□□□□□                                     ■                 □                □              " },
	{ "         □                  □                                   □                                     ■                 □□□□□□□□□□              " },
	{ "         □□□□□□□□□□□                                   □             ■■■■■■■■■      ■                 □                □              " },
	{ "         □                  □                                   □             ■                ■    ■                 □                □              " }, // [5]
	{ "         ■                  ■                                   □             ■                ■    ■                 □                □              " },
	{ "         ■                  ■               □□□□□□□□□□□             ■                ■    ■                 □□□□□□□□□□              " },
	{ "         ■                  ■               □                                 ■                ■    ■■■■                                             " },
	{ "         ■                  ■               □                                 ■                ■    ■             □□□□□□□□□□□□□□□        " },
	{ "         ■■■■■■■■■■■               □                                 ■                ■    ■                                                   " },
	{ "                                              □                                 ■                ■    ■                 □□□□□□□□□□              " }, // [10]
	{ "                                              □□□□□□□□□□□               ■■■■■■■■■    ■                                   □              " },
	{ "   ▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣                                                                    ■                                   □              " },
	{ "                   ▣                                                                                    ■                 □□□□□□□□□□              " },
	{ "                   ▣                                                                                    ■                 □                                " }, // [15]
	{ "                   ▣                                                                                    ■                 □                                " },
	{ "                   ▣                     □□□□□□□□□□□□□□□□                               ■                 □□□□□□□□□□              " },
	{ "                   ▣                                                                                                                                         " },
	{ "                   ▣                                                                                                                                         " },
	{ "                   ▣                                                                                                                                         " }, // [20]
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " }, // [25]
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " }, // [30]
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " },
	{ "                                                                                                                                                              " }
};

char *a[158] =
{
	{ "                                                                                                                                                  " }, //0 
	{ "                                                                                                                                                  " },
	{ "　　┌　건　물　───────────────────────┐　　　　　　　　　　　　┌　오브젝트　────────────────────┐" },
	{ "　　│                                                        │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　　│                                                        │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　　│                                                        │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" }, //5
	{ "　　│  　△ 별　장 : 건물 중 가장 가격이싸며,                │　　　　　　　　　　　　│　　특수무전기　:　무인도에서 3턴을 기다리거나　　　│" },
	{ "　　│  　            통행료에 영향을 제일 적게 끼침          │　　　　　　　　　　　　│　　　　　　　　 　주사위가 더블이 나오지 않아도　　│" },
	{ "　　│  　                                                    │　　　　　　　　　　　　│　　　　　　　　　 무인도를 탈출할수 있게 해준다. 　│" },
	{ "　　│   　                                                   │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　　│    　                                                  │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" }, //10
	{ "　　│  　⊙ 빌　딩 : 건물 중 보통가격이며,                   │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　　│   　           통행료가 어느정도 증가하게 해준다.      │　　　　　　　　　　　　│　　우　대　권　:　통칭 'VIP권'이라 부르며        　│" },
	{ "　　│    　          (추천 : 건물)                           │　　　　　　　　　　　　│　　　　　　　　　 우대권이 있다면 어느땅에 가도　　│" },
	{ "　　│     　                                                 │　　　　　　　　　　　　│　　　　　　　　 　통행료를 한푼도 지불하지않고　 　│" },
	{ "　　│   　                                                   │　　　　　　　　　　　　│　　　　　　　　　 그냥 지나갈수 있다. 　　　　　　 │" }, //15
	{ "　　│ 　                                                     │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　　│ 　 ◈ 호　텔 : 건물 중 가격이 가장 비싸다.             │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　　│   　           통행료를 크게 상승하게 해주며,          │　　　　　　　　　　　　│　　돈 (MONEY)　:　게임의 승패를 좌지우지한다. 　 　│" },
	{ "　　│     　         비싼 가격만큼 값어치를 한다.            │　　　　　　　　　　　　│　　　　　　　　   '다다익선' 으로써 　　　　　　 　│" },
	{ "　　│                                                        │　　　　　　　　　　　　│　　　　　　　  　 그냥 많을수록 장땡이다　　　　　 │" }, // 20
	{ "　　│                                                        │　　　　　　　　　　　　│　　　　　　　  　 0원 미만이 될시에 파산이 된다  　│" },
	{ "　　│                                                        │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　　│                                                        │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　　│                                                        │　　　　　　　　　　　　│　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　　└────────────────────────────┘　　　　　　　　　　　　└──────────────────────────┘" }, //25
	{ "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" },
	{ "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" },
	{ "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" },
	{ "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" },
	{ "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" }, //30
	{ "　┌─────────────────────────────────────────────────────────────────────┐" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" }, //35
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },  //40
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" }, //45
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　│　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　│" },
	{ "　└─────────────────────────────────────────────────────────────────────┘" },

};

void puttext(short x, short y, int n)		// 부르마블 글자 출력
{
	gotoxy(x, y);

	textcolor(n, 0);
	printf("▣");  // printf 안에 한글이나 특수문자를 넣으면 표기가 안됨, 배열자체부분에 색깔을 넣은거임
}

void press()
{
	int n;
	n = rand() % 15;

	gotoxy(66, 43); textcolor(n++, 14); printf("┏━━━━━━━┓");
	gotoxy(66, 45); textcolor(n++, 14); printf("┗━━━━━━━┛");


	gotoxy(66, 44);
	textcolor(n++, 14); printf("　"); 	if (n>7) { n = rand() % 15; }
	gotoxy(82, 44);
	textcolor(n++, 14); printf("　"); 	if (n>7) { n = rand() % 15; }

	//press any key 구현부분
	gotoxy(68, 44);
	textcolor(n++, 14); printf("p"); 	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("r"); 	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("e"); 	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("s"); 	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("s  ");	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("a"); 	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("n"); 	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("y ");	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("k");	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("e"); 	if (n>7) { n = rand() % 15; }
	textcolor(n++, 14); printf("y"); 	if (n>7) { n = rand() % 15; }
}

void neon()
{
	int i, n;
	n = rand() % 15;

	for (i = 0;i<35;i++)
	{
		gotoxy(1, i);
		textcolor(n, 0);
		printf("%s", text[i]);
	}
}

void version()
{
	gotoxy(88, 40); printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(88, 41); printf("┃");                                    gotoxy(154, 41); printf("┃");
	gotoxy(88, 42); printf("┃");                                    gotoxy(154, 42); printf("┃");
	gotoxy(88, 43); printf("┃");                                    gotoxy(154, 43); printf("┃");
	gotoxy(88, 44); printf("┃");                                    gotoxy(154, 44); printf("┃");
	gotoxy(88, 45); printf("┃");                                    gotoxy(154, 45); printf("┃");
	gotoxy(88, 46); printf("┃");                                    gotoxy(154, 46); printf("┃");
	gotoxy(88, 47); printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

	//제작자 코멘트 란
	RED;
	gotoxy(100, 43);
	printf("프로그래밍랩 텀 프로젝트");
	gotoxy(100, 44);
	printf("ver 0.9");

	WHITE;
}

int helpboard()
{
	int j;
	char select;
	for (j = 5; j<23; j++) 
	{
		WHITE; gotoxy(72, j++); printf("▽");
		if (_kbhit())					// for문이 돌아가는 중간에 enter키가 들어오면 즉시 리턴1을해서 끝낸다.
		{
			select = _getch();
			if (select == ENTER)
				return 1;
		}
		Sleep(100);
	}

	for (j = 5; j<23; j++) 
	{
		WHITE; gotoxy(72, j++); printf("　");
		if (_kbhit())
		{
			select = _getch();
			if (select == ENTER)
				return 1;
		}
		Sleep(100);
	}

	for (j = 21; j>3; j--) 
	{
		WHITE; gotoxy(81, j--); printf("△");
		if (_kbhit())
		{
			select = _getch();
			if (select == ENTER)
				return 1;
		}
		Sleep(100);
	}

	for (j = 21; j>3; j--)
	{
		WHITE; gotoxy(81, j--); printf("　");
		if (_kbhit())
		{
			select = _getch();
			if (select == ENTER)
				return 1;
		}
		Sleep(100);
	}

}


void help()
{
	system("cls");
	int i;

	for (i = 0;i < 50;i++)
	{
		WHITE;
		gotoxy(1, i);
		printf("%s", a[i]);
	}
	SKY; gotoxy(9, 2); printf("건　물");	gotoxy(93, 2); printf("오브젝트");
	GOLD; gotoxy(10, 6); printf("△");
	GREEN; gotoxy(10, 11); printf("⊙");
	PII; gotoxy(10, 17); printf("◈");


	GREEN; gotoxy(8, 33); printf("무인도 - 외딴섬으로 3턴이 지날때까지는 탈출 할 수 없다. 단 주사위가 더블이 나오면 탈출 할 수 있다.");
	BLUE; gotoxy(8, 37); printf("우주여행 - 도착한다음턴에 자신의 원하는 곳으로 자유롭게 갈수있다. 출발(0) - 한국(39)로써 숫자를 입력하면 입력에 맞는 지역으로 간다.");
	PII; gotoxy(8, 41); printf("한국 - 자랑스런 대한민국 땅으로써 도착하는 승리에 큰 도움이 되는 돈 1000만원을 즉시 받을수있다.");
	GOLD; gotoxy(8, 45); printf("황금열쇠 - 게임에 대해 득이 될수도 실이 될수도 있는 복불복 오브젝트이다. 뭐가 나올지는 아무도 모른다");
	gotoxy(19, 46); printf("게임에 승패를 도와줄 '우대권' 과 '특수무전기' 를 얻을 수 있는 유일한 방법이다.");
	
	WHITE; gotoxy(77, 7); printf("H"); gotoxy(77, 11); printf("E"); gotoxy(77, 15); printf("L"); gotoxy(77, 19); printf("P");

	gotoxy(58, 53); printf("도움말을 그만보시려면 'ENTER'키를 입력해주세요. ");

	while (1)
	{
		if (helpboard() == 1)				// 화면 중앙 HELP 주위 상하화살표
			break;
	}
}

int intro()
{
	cls(0, 15);
	srand((unsigned int)time(NULL));    // press, neon에서 쓸 랜덤함수

	PlaySound(TEXT("hello.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // 음악파일이 exe 파일하고 있는 폴더안에 있어함
																			   //PlaySound(NULL,NULL,NULL);   사운드 멈춤
	gotoxy(130, 37);
	printf("제작자 ┌ 1392024 안형우");
	gotoxy(130, 38);
	printf("       └ 1392056 김준희");
	version();

	while (1)
	{
		press();   // press any key
		neon();    // 부르마블글자 화면출력 겸 네온효과
		if (_kbhit() == 1)
		{
			_getch();         // 키보드입력한값을 버퍼에 집어넣기위해 씀
			return 1;
		}
	}
}

void choice()
{
	WHITE;
	gotoxy(75, 40);
	printf("게임시작");
	gotoxy(75, 44);
	printf("도 움 말");
	gotoxy(75, 48);
	printf("게임종료");
}



int intro2()
{
	cls(0, 15);
	srand((unsigned int)time(NULL));    // press, neon에서 쓸 랜덤함수
	int select = 0;
	int count = 2;
	int start_flag = 1;
	gotoxy(71, 40);
	printf("▶");

	while (1)
	{
		neon();   // press any key
		choice();    // "게임시작 , 세이브 , 로드 선택 표시 "

		if (_kbhit())
		{

			select = _getch();

			switch (select)
			{
			case UP:					// 화살표위키를 입력받을시 count증가 // 맨위일때는 그대로
			{
				if (count == 2)
					count = 2;
				else
					count++;
				break;
			}
			case DOWN:					// 화살표아래키를 입력받을시 count감사 // 맨아래일때는 그대로
			{
				if (count == 0)
					count = 0;
				else
					count--;
				break;
			}
			case ENTER:
			{
				return start_flag;
			}
			}
			switch (count)
			{
			case 2:						// 게임시작
			{
				gotoxy(71, 40);
				printf("▶");
				gotoxy(71, 44);
				printf(" ");
				gotoxy(71, 48);
				printf(" ");
				start_flag = 1;
				select = 0;
				break;
			}

			case 1:						// LOAD
			{
				gotoxy(71, 40);
				printf(" ");
				gotoxy(71, 44);
				printf("▶");
				gotoxy(71, 48);
				printf(" ");
				start_flag = 2;
				select = 0;
				break;
			}

			case 0:						// 게임종료
			{
				gotoxy(71, 40);
				printf(" ");
				gotoxy(71, 44);
				printf(" ");
				gotoxy(71, 48);
				printf("▶");
				start_flag = 3;
				select = 0;
				break;
			}
			}
		}
	}
}

void intro_start()
{
	int hit, n = 0;
	system("mode con: cols=160 lines=58");				// 게임 창(콘솔창) 크기를 바꿔줌
	removeCursor(); // 커서를 안보이게 한다

	cls(15, 0);
	while (1)
	{
		hit = intro();		// 인트로화면이 계속 되면서, 키를입력받으면 1을 리턴함
		if (hit == 1)		// 1값을 리턴 받았을시 바로 브레이크
			break;
	}
	WHITE;

	while (1)
	{
		hit = intro2();		// 인트로화면이 계속 되면서, 키를입력받으면 2을 리턴함
		if (hit == 1)		// intro2에서 1값을 리턴 받았을시 - 게임시작
		{
			while (1) {
				system("cls");
				gotoxy(50, 18);
				printf("게임을 플레이할 2부터 4의 플레이어 수를 입력하세요.. -> ");
				scanf_s("%d", &player_num);
				PlaySound(NULL, NULL, NULL);
				if (player_num > 1 && player_num <= 4)
					break;
			}
			break;
		}
		else if (hit == 2)	// 도움말
			help();
		else if (hit == 3)	// 게임종료
		{
			system("cls");
			n = MessageBox(NULL, L"게임을 종료하시겠습니까?", L"제작자-안형우,김준희", MB_YESNO);
			if (n != 7)	// ok버튼누르면 종료
			{
				exit(0);
			}
		}
	}
}