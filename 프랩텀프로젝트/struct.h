#ifndef STRUCT_H
#define STRUCT_H

//////////// 지역 정보 구조체 //////////////

typedef struct
{
	int zone_index; //인덱스
	int zone_X;	//x좌표
	int zone_Y;	//y좌표
	int owner;	//주인 있는지 없는지
	int zone_cost; //땅 값
	int hotel_cost;	//호텔 값
	int building_cost;//빌딩 값
	int villa_cost;	//빌라 값
	int hotel; //존재여부
	int building;
	int villa;
	int zone_toll; //통행료
	int hotel_toll;
	int building_toll;
	int villa_toll;
	char zone_name[30]; //이름
}zone;

///////////////////// 유저 정보 구조체 //////////////////////
typedef struct
{
	int use_space;		//우주여행 턴
	int location_index;	//어디 지역에 있는지
	int pre_X;			//x좌표
	int pre_Y;			//y좌표
	int money;			//돈
	int island_cnt; 	//무인도 턴
	int escape;			//무인도 탈출권
	int passcard; 		//우대권
	int gameover;		//게임끝
}player;

/////////////////////// 황금열쇠 정보 구조체 /////////////////////
typedef struct
{
	int key_num;	//키 번호
	char key_name[30];	//이름
	char key_content[100];	//어떤 거로?
}golden_key;

#endif