#ifndef GOLDEN_KEY_H
#define GOLDEN_KEY_H

//////////////////////////////// 황금열쇠 /////////////////////////////////////////
/*
1.우대권
2.돈 얼마 받기
3.우주비행
4.앞으로 몇칸
5.뒤로 몇칸
6.무인도 탈출권
7.돈 뺏기
8.
9.
10.
11.
*/


#include "common.h"
#include "struct.h"
#include "function.h"

void insertKey(int num, char name[], char content[])
{
	G_KEY[num].key_num = num;
	strcpy(G_KEY[num].key_name, name);
	strcpy(G_KEY[num].key_content, content);
}

void golden_key_init()
{
	insertKey(0, "병원비 지불", "병원에서 건강진단을 받았음. 병원비 5만원을 은행에 내시오.");
	insertKey(1, "복권 당첨", "축하합니다. 복권에 당첨되었음. =당첨금 20만원=");
	insertKey(2, "무인도탈출용(특수무전기)", "무인도에 갇혔을 경우 사용할 수 있음.");
	insertKey(3, "무인도로 가시오.", "폭풍을 만났음. 무인도로 곧장가시오.");
	insertKey(4, "관광여행(한국)", "한국으로 가시오");
	insertKey(5, "과속운전벌금", "과속운전을 했으므로 벌금으로 5만원을 내시오");
	insertKey(6, "해외유학", "학교 등록금 10만원을 내시오");
	insertKey(7, "연금혜택", "은행에서 노후연금 5만원을 받으시오");
	insertKey(8, "이사가시오", "뒤로 세칸 옮기시오");
	insertKey(9, "이사가시오", "앞으로 두칸 옮기시오");
	insertKey(10, "고속도로", "출발지까지 곧바로 가시오");
	insertKey(11, "자동차 경주 우승", "자동차 경주에서 챔피온이 되었음. 상금10만원");
	insertKey(12, "우대권", "상대방의 장소를 통행료없이 머무를 수 있음");
	insertKey(13, "관광여행", "부산으로 가시오");
	insertKey(14, "장학금혜택", "은행에서 장학금 10만원을 받으시오");
	insertKey(15, "세계일주초대권", "축하하오, 현재위치에서 한바퀴를 돌아오시오.");
	insertKey(16, "노벨평화상수상", "세계평화를 위해 공헌하였으므로 상금 30만원을 받습니다.");
	insertKey(17, "우주여행초청장", "우주항공국에서 우주여행초청장이 왔음(무료임)");
}

int get_golden_key()
{
	int key;
	srand((int)time(NULL));
	key = rand() % 18;
	return key;
}

#endif