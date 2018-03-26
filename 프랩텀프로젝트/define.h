#ifndef DEFINE_H
#define DEFINE_H

#define col GetStdHandle(STD_OUTPUT_HANDLE) // �ܼ�â�� �ڵ����� �ޱ�

#define BLACK SetConsoleTextAttribute(col, 0x0000);
#define RED SetConsoleTextAttribute(col, 0x000c); // ������
#define BLUE SetConsoleTextAttribute(col, 0x0001 | 0x0008); // �Ķ���
#define HIGH SetConsoleTextAttribute(col, 0x000a); // ���λ�
#define WHITE SetConsoleTextAttribute(col, 0x000f); // ���
#define SKY SetConsoleTextAttribute(col, 0x000b); // �ϴû�
#define YEL SetConsoleTextAttribute(col, 0x000e); // �����
#define HIG SetConsoleTextAttribute(col, 0x000d); // ������
#define GOLD SetConsoleTextAttribute(col, 0x0006); // �ݻ�
#define JAJU SetConsoleTextAttribute(col, 0x0005); // ���ֻ�
#define PII SetConsoleTextAttribute(col, 0x0004); // �ǻ�
#define GREEN SetConsoleTextAttribute(col, 0x0002); // ���
#define VIO SetConsoleTextAttribute(col, 0x0001 | 0x0008 | 0x000c); // �����

#define UP 72
#define DOWN 80 
#define LEFT 75 
#define RIGHT 77
#define ENTER 13

#define P1_TURN 1
#define P2_TURN 2
#define P3_TURN 3
#define P4_TURN 4

#define GAMEOVER -1
#define START 1000
#define EXIT 5000

#define MONEY 1000
#define ZONE_NUM 40

#define ZONE_COST_A 50
#define ZONE_COST_B 100
#define ZONE_COST_C 150

#define HOTEL_COST_A 200
#define HOTEL_COST_B 250
#define HOTEL_COST_C 300

#define BUILDING_COST_A 150
#define BUILDING_COST_B 200
#define BUILDING_COST_C 250

#define VILLA_COST_A 100
#define VILLA_COST_B 150
#define VILLA_COST_C 200



#define TOLL(COST) ((COST) * (2)) //������ cost * 1.5

#endif