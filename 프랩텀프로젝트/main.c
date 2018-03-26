/*
* 2�г� ���α׷��ַ� �⸻��� �� ������Ʈ
*    1392056 ������, 1392048 ������
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
	int n;					//���ӿ��� ����
	int key;				//Ȳ�ݿ��� Ű
	int gameover_cnt = 0;	//���ӿ��� �÷��̾� ����
	char winner;			//�̱� �÷��̾� ����?
	char zone_select;		//�� �޴� �ൿ ����
	char passcard_select;	//���� �ൿ ����
	int space_select;		//���� ���� ��� �� ����
	int toll;				//�����
	int loop = 1;			//while�� ���� ������ ���� ����
	int musictimer = 0;		//���� ���ʰ� ��������

	STATE = INTRO;	//���� ����!

	while (1)
	{
		Sleep(1);	//���ѷ�������
		switch (STATE)
		{
		case INTRO:			//��Ʈ��
			intro_start();
			gameover_cnt = 4 - player_num;
			STATE = init;
			break;

		case init:			//�ʱ�ȭ
			system("mode con: cols=160 lines=138");				// ���� â(�ܼ�â) ũ�⸦ �ٲ���
			golden_key_init();
			zone_init();
			player_init();
			mapping();
			money_show(User);
			moving_init(User);
			STATE = P_TURN;
			break;

		case P_TURN:		//�÷��̾� ��
			//�ֻ��� �Ҹ�
			if (User[turn - 1].use_space != 1)	//���ּ��� �������� �ȱ���
				run_dice(); // �ֻ����������� ���
			if (User[turn - 1].island_cnt != 1 && User[turn - 1].island_cnt != 2 && User[turn - 1].use_space != 1)	//���ε� 3�ϵ����� �ȿ�����, ���ּ��� ������ ���� ��
				moving_player(User, dice_sum);	//2���� ���̽� �ո�ŭ �̵�
			MY_ZONE_SHOW();

			if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "���ε�"))
				STATE = ISLAND;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "Ȳ�ݿ���"))
				STATE = GOLDEN_KEY;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "���"))
				STATE = NEXT_TURN;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "���ֿ���"))
				STATE = SPACESHIP;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "�ѱ�"))
				STATE = KOREA;
			else
			{
				player_color();
				MENU_CLR();
				gotoxy(80, 21);
				printf("%s ĭ�� �����Ͽ����ϴ�.", Zone[User[turn - 1].location_index].zone_name);
				gotoxy(80, 22);
				printf("���� �÷��̾�%d�� ������ : %d �����Դϴ�.", turn, User[turn - 1].money);
				if (Zone[User[turn - 1].location_index].owner == 0 || Zone[User[turn - 1].location_index].owner == turn)	//������ ���ų� �ڱ� ��
					STATE = BUY_ZONE;
				else
					STATE = TOLL;
			}
			WHITE;
			break;

		case NOT_MOVING:	//���ּ����� ������ �� �ȿ�����
			MY_ZONE_SHOW();
			if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "���ε�"))
				STATE = ISLAND;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "Ȳ�ݿ���"))
				STATE = GOLDEN_KEY;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "���"))
				STATE = NEXT_TURN;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "���ֿ���"))
				STATE = SPACESHIP;
			else if (!strcmp(Zone[User[turn - 1].location_index].zone_name, "�ѱ�"))
				STATE = KOREA;
			else
			{
				player_color();
				MENU_CLR();
				gotoxy(80, 21);
				printf("%s ĭ�� �����Ͽ����ϴ�.", Zone[User[turn - 1].location_index].zone_name);
				gotoxy(80, 22);
				printf("���� �÷��̾�%d�� ������ : %d �����Դϴ�.", turn, User[turn - 1].money);
				if (Zone[User[turn - 1].location_index].owner == 0 || Zone[User[turn - 1].location_index].owner == turn)	//������ ���ų� �ڱ� ��
					STATE = BUY_ZONE;
				else
					STATE = TOLL;
			}
			WHITE;
			break;

		case BUY_ZONE:			//�� ���, ���ִ��� ������ �˻�
			if (Zone[User[turn - 1].location_index].owner == 0)
			{
				gotoxy(80, 24); printf("������ ���� ���Դϴ�.");
			}
			else if (Zone[User[turn - 1].location_index].owner == turn)
			{
				gotoxy(80, 24); printf("����� ���Դϴ�.");
			}
			zone_menu();
			zone_select = select_menu();	//�޴� ����
			MENU_CLR();
			if (zone_select == '5')	//�׳� �������ϴ�.
			{
				STATE = NEXT_TURN;
				break;
			}
			else
			{
				if (Zone[User[turn - 1].location_index].owner == 0 && zone_select != '1')	//������ ���µ� ���Ȼ�� ���� �Ϸ��� �ϸ� �ٽ� ����
				{
					gotoxy(80, 24); printf("����� ���� �ƴմϴ�. �ൿ�� �ٽ� �������ּ���.");
					gotoxy(80, 25);	printf("ENTER�� �Է��ϼ���.");
					while (_getch() != ENTER);
					MENU_CLR();

					STATE = BUY_ZONE;
					break;
				}
				else
				{
					if (!exist_struct(zone_select))	//������ �޴��� �ǹ��̳� ���� �ִ��� ������
					{
						buy_struct(zone_select);	//���ٸ� ��
						struct_show();	//�ǹ��̳� �� �춧���� ǥ��
					}
					else //������ �޴��� �ǹ��� �ִٸ� �ൿ �ٽ� ����
					{
						gotoxy(80, 24); printf("�̹� ���̳� �ǹ��� �ֽ��ϴ�. �ൿ�� �ٽ� �������ּ���.");
						gotoxy(80, 25);	printf("ENTER�� �Է��ϼ���.");
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
			if (User[turn - 1].passcard == 1)	//���� ��� ����
			{
				gotoxy(80, 24); printf("������ �ֽ��ϴ�. ����Ͻðڽ��ϱ� (YES : 1), (NO : 2) ? ");
				passcard_select = select_passcard();
				gotoxy(80, 24); printf("                                                            ");
				if (passcard_select == '1')
				{
					gotoxy(80, 25); printf("������ ����Ͽ� �׳� �������ϴ�.");
					gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
					while (_getch() != ENTER);
					MENU_CLR();
					User[turn - 1].passcard = 0;	//���� ���!

					STATE = NEXT_TURN;
					break;
				}
				else if (passcard_select == '2')
				{
					gotoxy(80, 25); printf("������ ������� �ʽ��ϴ�.");
					gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
					while (_getch() != ENTER);
					MENU_CLR();
				}
			}

			toll = toll_money();
			gotoxy(80, 24);	printf("�ٸ� ����� ���Դϴ�. ����Ḧ �����ϼž� �մϴ�.");
			gotoxy(80, 25); printf("����� %d������ �����մϴ�.", toll);
			User[turn - 1].money -= toll;
			User[Zone[User[turn - 1].location_index].owner - 1].money += toll;	//�� �ڸ� ���ο��� ���� ��
			if (User[turn - 1].money <= 0)	//����� ���� �� 0���ϰ� �Ǹ� �Ļ�!
			{
				gotoxy(80, 26); printf("�÷��̾�%d�� �Ļ��Ͽ����ϴ�!", turn);

				PlaySound(TEXT("pasan.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // ���������� exe �����ϰ� �ִ� �����ȿ� �־���
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
			gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
			while (_getch() != ENTER);
			MENU_CLR();

			STATE = NEXT_TURN;
			break;

		case KOREA:
			PII;
			gotoxy(80, 24); printf("�ѱ��� �����ϼ̱���!");
			gotoxy(80, 25); printf("�ѱ����� ������ 1000������ �����ص帮�ڽ��ϴ�.");

			PlaySound(TEXT("hankook.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // ���������� exe �����ϰ� �ִ� �����ȿ� �־���
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
			gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
			while (_getch() != ENTER);
			MENU_CLR();
			User[turn - 1].money += 1000;

			STATE = NEXT_TURN;
			break;

		case SPACESHIP:			//���ּ�
			//���ֿ��� ���� -> ��������
			go_space();
			User[turn - 1].use_space++;	//������ ������ ����
			if (User[turn - 1].use_space == 1)
			{
				PlaySound(TEXT("trip.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // ���������� exe �����ϰ� �ִ� �����ȿ� �־���
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
				gotoxy(80, 24);	printf("���� ����� ���ּ��� ž���߽��ϴ�.");
				gotoxy(80, 25);	printf("�����Ͽ� ���ϴ� ��ҷ� �� �� �ֽ��ϴ�.");
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				STATE = NEXT_TURN;
				break;
			}
			else
			{
				DICE_CLR();
				BLUE;
				gotoxy(80, 24);	printf("�̵��ϱ⸦ ���ϴ� ������ ��ȣ�� �Է��ϼ��� (ENTER): ");
				gotoxy(80, 25); printf("���(0) ~ �ѱ�(39)");
				space_select = select_space();
				go_every(space_select);
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				User[turn - 1].use_space = 0;
				STATE = NOT_MOVING;
				break;
			}
			break;

		case ISLAND:			//���ε�
			//���ε� ����
			GREEN;
			gotoxy(80, 24);	printf("���� ����� ���ε����� ǥ�����Դϴ�.");

			PlaySound(TEXT("indo.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // ���������� exe �����ϰ� �ִ� �����ȿ� �־���
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
				gotoxy(80, 25);	printf("���ε� Ż����� ����Ͽ� �ٷ� Ż���մϴ�.");
				User[turn - 1].escape -= 1;
				User[turn - 1].island_cnt = 0;	//�ٷ� Ż��
			}
			else if (dice1 == dice2)
			{
				gotoxy(80, 25);	printf("�����Դϴ�! ���ϵ帳�ϴ�. �����Ͽ� �ٷ� Ż���մϴ�.");
				User[turn - 1].island_cnt = 0;	//�ٷ� Ż��
			}
			else
			{
				gotoxy(80, 25);	printf("3�ϵ��� ���� �ְԵ˴ϴ�.");
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();

				STATE = IN_ISLAND;
				break;
			}
			WHITE;
			gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
			while (_getch() != ENTER);
			MENU_CLR();

			STATE = NEXT_TURN;
			break;

		case IN_ISLAND:
			GREEN;
			if (User[turn - 1].island_cnt == 2)
			{
				User[turn - 1].island_cnt = 0;
				gotoxy(80, 25);	printf("���� �Ͽ� ���ε����� Ż���մϴ�!!");
			}
			else
			{
				gotoxy(80, 25);	printf("�̹� �Ͽ��� Ż���Ͻ� ���� ���׿�...");
				User[turn - 1].island_cnt++;
			}
			WHITE;
			gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
			while (_getch() != ENTER);
			MENU_CLR();

			STATE = NEXT_TURN;
			break;

		case GOLDEN_KEY:		//Ȳ�ݿ���
			//Ȳ�ݿ��� ����
			GOLD;
			gotoxy(80, 24);	printf("���ϵ帳�ϴ�. Ȳ�ݿ��踦 ������ϴ�!!!");

			PlaySound(TEXT("goldkey.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // ���������� exe �����ϰ� �ִ� �����ȿ� �־���
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
			gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
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
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 1:
				gotoxy(80, 24); printf("%s", G_KEY[1].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[1].key_content);
				User[turn - 1].money += 20;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 2:
				gotoxy(80, 24); printf("%s", G_KEY[2].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[2].key_content);
				User[turn - 1].escape = 1;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 3:
				gotoxy(80, 24); printf("%s", G_KEY[3].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[3].key_content);
				go_every(10);	//���ε��� ����������
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 4:
				gotoxy(80, 24); printf("%s", G_KEY[4].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[4].key_content);
				go_every(39); //�ѱ����� ����������
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 5:
				gotoxy(80, 24); printf("%s", G_KEY[5].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[5].key_content);
				User[turn - 1].money -= 5;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 6:
				gotoxy(80, 24); printf("%s", G_KEY[6].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[6].key_content);
				User[turn - 1].money -= 10;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 7:
				gotoxy(80, 24); printf("%s", G_KEY[7].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[7].key_content);
				User[turn - 1].money += 5;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 8:
				gotoxy(80, 24); printf("%s", G_KEY[8].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[8].key_content);
				go_every(User[turn - 1].location_index - 3); //�ڷ� ��ĭ ��������
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 9:
				gotoxy(80, 24); printf("%s", G_KEY[9].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[9].key_content);
				go_every(User[turn - 1].location_index + 2); //������ ��ĭ
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 10:
				gotoxy(80, 24); printf("%s", G_KEY[10].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[10].key_content);
				go_every(0); //�����������!
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 11:
				gotoxy(80, 24); printf("%s", G_KEY[11].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[11].key_content);
				User[turn - 1].money += 10;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 12:
				gotoxy(80, 24); printf("%s", G_KEY[12].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[12].key_content);
				User[turn - 1].passcard = 1;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 13:
				gotoxy(80, 24); printf("%s", G_KEY[13].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[13].key_content);
				go_every(25);	//�λ�
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 14:
				gotoxy(80, 24); printf("%s", G_KEY[14].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[14].key_content);
				User[turn - 1].money += 10;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 15:
				gotoxy(80, 24); printf("%s", G_KEY[15].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[15].key_content);
				moving_player(User, 40);	//�ѹ��� ����
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 16:
				gotoxy(80, 24); printf("%s", G_KEY[16].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[16].key_content);
				User[turn - 1].money += 30;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			case 17:
				gotoxy(80, 24); printf("%s", G_KEY[17].key_name);
				gotoxy(80, 25); printf("%s", G_KEY[17].key_content);
				go_every(30);	//���ּ����� ����������
				STATE = NOT_MOVING;
				WHITE;
				gotoxy(80, 27);	printf("ENTER�� �Է��ϼ���.");
				while (_getch() != ENTER);
				MENU_CLR();
				break;
			}
			if (key != 17 && key != 3 && key != 4 && key != 8 && key != 9)	//������ ���¸� �����ϴ� �͵�
				STATE = NEXT_TURN;
			break;

		case NEXT_TURN:			//���� ��
			next_turn();
			money_show(User);
			MY_ZONE_SHOW_CLR();
			DICE_CLR();
			MENU_CLR();
			gotoxy(23, 34); printf("                                                      ");
			player_color();
			gotoxy(23, 32);
			printf("�÷��̾�%d�� �����Դϴ�.", turn);
			gotoxy(23, 33);
			printf("�ֻ����� �������� ENTER�� �Է����ּ���.");

			while (_getch() != ENTER);

			STATE = P_TURN;
			break;

		case GAME_OVER:			//���� ����
		/////// ���� ���� ���� �� ���� ///////
		//���� ���� ���� ��������~
			winner = who_winner();
			while (1)
			{
				PlaySound(TEXT("gameover.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);   // ���������� exe �����ϰ� �ִ� �����ȿ� �־���
				if (winner == 'A')
					MessageBox(NULL, L"������ ����Ǿ����ϴ�--�¸��ڴ� ���÷��̾��Դϴ�", L"������-������,������", MB_OK);
				else if (winner == 'B')
					MessageBox(NULL, L"������ ����Ǿ����ϴ�--�¸��ڴ� ���÷��̾��Դϴ�", L"������-������,������", MB_OK);
				else if (winner == 'C')
					MessageBox(NULL, L"������ ����Ǿ����ϴ�--�¸��ڴ� ���÷��̾��Դϴ�", L"������-������,������", MB_OK);
				else if (winner == 'D')
					MessageBox(NULL, L"������ ����Ǿ����ϴ�--�¸��ڴ� ���÷��̾��Դϴ�", L"������-������,������", MB_OK);

				n = MessageBox(NULL, L"������ �ٽ��Ͻðڽ��ϱ�?", L"������-������,������", MB_YESNO);
				if (n != 7)	//�ٽ� ���� ��ư ������ intro���� �ٽ� ����!
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