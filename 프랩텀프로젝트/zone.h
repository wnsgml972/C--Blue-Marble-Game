#ifndef ZONE_H
#define ZONE_H

#include "define.h"
#include "common.h"
#include "struct.h"

//////////////////////////////// ���� /////////////////////////////////////////
//40����

void insert_zone(char name[], int index, int X, int Y, int Z_cost, int H_cost, int B_cost, int V_cost, int Z_toll, int H_toll, int B_toll, int V_toll)
{
	strcpy(Zone[index].zone_name, name);
	Zone[index].zone_index = index;

	// ���� ����
	Zone[index].owner = 0;

	// �ǹ� ����
	Zone[index].building = 0;
	Zone[index].hotel = 0;
	Zone[index].villa = 0;

	//����
	Zone[index].zone_cost = Z_cost;
	Zone[index].hotel_cost = H_cost;
	Zone[index].building_cost = B_cost;
	Zone[index].villa_cost = V_cost;

	//��ġ ����
	Zone[index].zone_X = X;		// �� �÷��̾ŭ ��ĭ�� ������
	Zone[index].zone_Y = Y;

	//�����
	Zone[index].zone_toll = Z_toll;
	Zone[index].hotel_toll = H_toll;
	Zone[index].building_toll = B_toll;
	Zone[index].villa_toll = V_toll;

}
//����� Ȳ�ݿ��� ������ �����
void zone_init(void)
{
	insert_zone("���", 0, 143, 53, 0, 0, 0, 0, 0, 0, 0, 0);	//���
	insert_zone("�����", 1, 129, 53, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("Ȳ�ݿ���", 2, 115, 53, 0, 0, 0, 0, 0, 0, 0, 0);	//Ȳ�ݿ���
	insert_zone("������", 3, 101, 53, ZONE_COST_B, HOTEL_COST_B, BUILDING_COST_B, VILLA_COST_B, TOLL(ZONE_COST_B), TOLL(HOTEL_COST_B), TOLL(BUILDING_COST_B), TOLL(VILLA_COST_B));
	insert_zone("�����", 4, 87, 53, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("����Ʈ", 5, 73, 53, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("��Ÿ��", 6, 59, 53, ZONE_COST_B, HOTEL_COST_B, BUILDING_COST_B, VILLA_COST_B, TOLL(ZONE_COST_B), TOLL(HOTEL_COST_B), TOLL(BUILDING_COST_B), TOLL(VILLA_COST_B));
	insert_zone("Ȳ�ݿ���", 7, 45, 53, 0, 0, 0, 0, 0, 0, 0, 0);	//Ȳ�ݿ���
	insert_zone("���װ�", 8, 31, 53, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("���̺�����", 9, 17, 53, ZONE_COST_B, HOTEL_COST_B, BUILDING_COST_B, VILLA_COST_B, TOLL(ZONE_COST_B), TOLL(HOTEL_COST_B), TOLL(BUILDING_COST_B), TOLL(VILLA_COST_B));
	insert_zone("���ε�", 10, 3, 53, 0, 0, 0, 0, 0, 0, 0, 0);	//���ε�
	insert_zone("������", 11, 3, 48, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("Ȳ�ݿ���", 12, 3, 43, 0, 0, 0, 0, 0, 0, 0, 0); //Ȳ�ݿ���
	insert_zone("����", 13, 3, 38, ZONE_COST_C, HOTEL_COST_C, BUILDING_COST_C, VILLA_COST_C, TOLL(ZONE_COST_C), TOLL(HOTEL_COST_C), TOLL(BUILDING_COST_C), TOLL(VILLA_COST_C));
	insert_zone("����", 14, 3, 33, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("����������", 15, 3, 28, ZONE_COST_B, HOTEL_COST_B, BUILDING_COST_B, VILLA_COST_B, TOLL(ZONE_COST_B), TOLL(HOTEL_COST_B), TOLL(BUILDING_COST_B), TOLL(VILLA_COST_B));
	insert_zone("��Ƽ���Ǿ�", 16, 3, 23, ZONE_COST_B, HOTEL_COST_B, BUILDING_COST_B, VILLA_COST_B, TOLL(ZONE_COST_B), TOLL(HOTEL_COST_B), TOLL(BUILDING_COST_B), TOLL(VILLA_COST_B));
	insert_zone("Ȳ�ݿ���", 17, 3, 18, 0, 0, 0, 0, 0, 0, 0, 0); //Ȳ�ݿ���
	insert_zone("�Ҹ�����", 18, 3, 13, ZONE_COST_C, HOTEL_COST_C, BUILDING_COST_C, VILLA_COST_C, TOLL(ZONE_COST_C), TOLL(HOTEL_COST_C), TOLL(BUILDING_COST_C), TOLL(VILLA_COST_C));
	insert_zone("�ɳ�", 19, 3, 8, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("ź���Ͼ�", 20, 3, 3, ZONE_COST_B, HOTEL_COST_B, BUILDING_COST_B, VILLA_COST_B, TOLL(ZONE_COST_B), TOLL(HOTEL_COST_B), TOLL(BUILDING_COST_B), TOLL(VILLA_COST_B));
	insert_zone("���ٰ���ī��", 21, 17, 3, ZONE_COST_C, HOTEL_COST_C, BUILDING_COST_C, VILLA_COST_C, TOLL(ZONE_COST_C), TOLL(HOTEL_COST_C), TOLL(BUILDING_COST_C), TOLL(VILLA_COST_C));
	insert_zone("Ȳ�ݿ���", 22, 31, 3, 0, 0, 0, 0, 0, 0, 0, 0);	//Ȳ�ݿ���
	insert_zone("�Ӱ��", 23, 45, 3, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("���", 24, 59, 3, ZONE_COST_B, HOTEL_COST_B, BUILDING_COST_B, VILLA_COST_B, TOLL(ZONE_COST_B), TOLL(HOTEL_COST_B), TOLL(BUILDING_COST_B), TOLL(VILLA_COST_B));
	insert_zone("�λ�", 25, 73, 3, ZONE_COST_C, HOTEL_COST_C, BUILDING_COST_C, VILLA_COST_C, TOLL(ZONE_COST_C), TOLL(HOTEL_COST_C), TOLL(BUILDING_COST_C), TOLL(VILLA_COST_C));
	insert_zone("�����ͳ�", 26, 87, 3, ZONE_COST_C, HOTEL_COST_C, BUILDING_COST_C, VILLA_COST_C, TOLL(ZONE_COST_C), TOLL(HOTEL_COST_C), TOLL(BUILDING_COST_C), TOLL(VILLA_COST_C));
	insert_zone("���ư�", 27, 101, 3, ZONE_COST_C, HOTEL_COST_C, BUILDING_COST_C, VILLA_COST_C, TOLL(ZONE_COST_C), TOLL(HOTEL_COST_C), TOLL(BUILDING_COST_C), TOLL(VILLA_COST_C));
	insert_zone("��Ű", 28, 115, 3, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("�ø���", 29, 129, 3, ZONE_COST_B, HOTEL_COST_B, BUILDING_COST_B, VILLA_COST_B, TOLL(ZONE_COST_B), TOLL(HOTEL_COST_B), TOLL(BUILDING_COST_B), TOLL(VILLA_COST_B));
	insert_zone("���ֿ���", 30, 143, 3, 0, 0, 0, 0, 0, 0, 0, 0);	//���ֿ���
	insert_zone("���ٳ�", 31, 143, 8, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("�̽���", 32, 143, 13, ZONE_COST_B, HOTEL_COST_B, BUILDING_COST_B, VILLA_COST_B, TOLL(ZONE_COST_B), TOLL(HOTEL_COST_B), TOLL(BUILDING_COST_B), TOLL(VILLA_COST_B));
	insert_zone("�丣��", 33, 143, 18, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("�̶�ũ", 34, 143, 23, ZONE_COST_C, HOTEL_COST_C, BUILDING_COST_C, VILLA_COST_C, TOLL(ZONE_COST_C), TOLL(HOTEL_COST_C), TOLL(BUILDING_COST_C), TOLL(VILLA_COST_C));
	insert_zone("Ȳ�ݿ���", 35, 143, 28, 0, 0, 0, 0, 0, 0, 0, 0); //Ȳ�ݿ���
	insert_zone("����Ʈ", 36, 143, 33, ZONE_COST_C, HOTEL_COST_C, BUILDING_COST_C, VILLA_COST_C, TOLL(ZONE_COST_C), TOLL(HOTEL_COST_C), TOLL(BUILDING_COST_C), TOLL(VILLA_COST_C));
	insert_zone("�̶�", 37, 143, 38, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("�������Ͻ�ź", 38, 143, 43, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_A), TOLL(HOTEL_COST_A), TOLL(BUILDING_COST_A), TOLL(VILLA_COST_A));
	insert_zone("�ѱ�", 39, 143, 48, ZONE_COST_A, HOTEL_COST_A, BUILDING_COST_A, VILLA_COST_A, TOLL(ZONE_COST_C), TOLL(HOTEL_COST_C), TOLL(HOTEL_COST_C), TOLL(HOTEL_COST_C)); //�ѱ�!
}

#endif