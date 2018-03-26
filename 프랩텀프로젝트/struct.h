#ifndef STRUCT_H
#define STRUCT_H

//////////// ���� ���� ����ü //////////////

typedef struct
{
	int zone_index; //�ε���
	int zone_X;	//x��ǥ
	int zone_Y;	//y��ǥ
	int owner;	//���� �ִ��� ������
	int zone_cost; //�� ��
	int hotel_cost;	//ȣ�� ��
	int building_cost;//���� ��
	int villa_cost;	//���� ��
	int hotel; //���翩��
	int building;
	int villa;
	int zone_toll; //�����
	int hotel_toll;
	int building_toll;
	int villa_toll;
	char zone_name[30]; //�̸�
}zone;

///////////////////// ���� ���� ����ü //////////////////////
typedef struct
{
	int use_space;		//���ֿ��� ��
	int location_index;	//��� ������ �ִ���
	int pre_X;			//x��ǥ
	int pre_Y;			//y��ǥ
	int money;			//��
	int island_cnt; 	//���ε� ��
	int escape;			//���ε� Ż���
	int passcard; 		//����
	int gameover;		//���ӳ�
}player;

/////////////////////// Ȳ�ݿ��� ���� ����ü /////////////////////
typedef struct
{
	int key_num;	//Ű ��ȣ
	char key_name[30];	//�̸�
	char key_content[100];	//� �ŷ�?
}golden_key;

#endif