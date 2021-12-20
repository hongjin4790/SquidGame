#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>
#include "heap.h"

void gotoxy2(int x, int y);
void display_line(int rand);
void displayBackground(int* r_start);
void game_control(int* r_start);
int TugOfWar_Launcher();
void whatTime();

clock_t start;
double pst;

void DataInsert(HeapType* heap) {
	element elArr[MAX_ELEMENT] = { {1, "놀이터"}, {2, "나홀로"}, {3, "원숭이"}, {4, "기린"}, {5, "꽃놀이"}, {6, "초콜렛"},
	{7, "시계"}, {8, "반지"}, {9, "약사"}, {10, "마우스"}, {11, "차형석"}, {12, "디스코드"}, {13, "핸드폰"}, {14, "카카오톡"}, {15, "노트북"}, {16, "돈까스"},
	{17, "노래"}, {18, "필통"}, {19, "젓가락"}, {20, "식탁"}, {21, "벚꽃놀이"}, {22, "깨다시"}, {23, "쌍절곤"}, {24, "쓰레드"}, {25, "연필꽂이"}, {26, "헬스기구"},
	{27, "우물"}, {28, "안세준"}, {29, "시리우스"}, {30, "코펜하겐"}, {31, "게슈탈트"}, {32, "수세미"}, {33, "임베디드"}, {34, "오지"}, {35, "오지랖"}, {36, "겉절이"},
	{37, "안성탕면"}, {38, "오징어"}, {39, "이코노미"}, {40, "비지니스"}, {41, "제주오름"}, {42, "알베르트"}, {43, "가돌린"}, {44, "마리퀴리"}, {45, "엔르코"}, {46, "드미트리"},
	{47, "알프레드"}, {48, "어니스트"}, {49, "러더퍼드"}, {50, "김홍진"}, {51, "시보그"}, {52, "닐스보어"}, {53, "마이트너"}, {54, "빌헬름"}, {55, "코페르니"}, {56, "플료로프"},
	{57, "오가네스"}, {58, "앨라배마"}, {59, "알래스카"}, {60, "애리조나"}, {61, "아칸소"}, {62, "콜로라도"}, {63, "코네티컷"}, {64, "델라웨어"}, {65, "플로리다"}, {66, "아이다호"},
	{67, "일리노이"}, {68, "인디애나"}, {69, "아이오와"}, {70, "캔자스"}, {71, "켄터키"}, {72, "메릴랜드"}, {73, "미시간"}, {74, "미네소타"}, {75, "미시시피"}, {76, "몬태나"},
	{77, "뉴햄프셔"}, {78, "뉴멕시코"}, {79, "오히이오"}, {80, "펜실베냐"}, {81, "김형진"}, {82, "유타"}, {83, "버지니아"}, {84, "위스콘신"}, {85, "와이오밍"}, {86, "샌디에고"},
	{87, "씨언어"}, {88, "파이썬"}, {89, "자바"}, {90, "씨플플"}, {91, "씨샾"}, {92, "할게없어"}, {93, "살려줘"}, {94, "당근"}, {95, "기말어캐"}, {96, "노가다"},
	{97, "우한폐렴"}, {98, "페브리즈"}, {99, "장첸이야"}, {100, "미쳐가네"}, {101, "다신안해"}, {102, "김준혁"}, {103, "퍼올껄"}, {104, "중고나라"}, {105, "전자회로"}, {106, "삼성전자"},
	{107, "감기인가"}, {108, "일칠화석"}, {109, "선형함수"}, {110, "탄에이치"}, {111, "엠엘피"}, {112, "피씨에이"}, {113, "씨엔엔"}, {114, "알엔엔"}, {115, "난바보다"}, {116, "상쾌한향"},
	{117, "업데이트"}, {118, "아이보리"}, {119, "훠훠궈궈"}, {120, "묬쓔꼤쯰"}, {121, "여렵꼤쯰"}, {122, "단여빠꽤"}, {123, "않이외요"}, {124, "않이되요"}, {125, "쁄뼌하졔"}, {126, "헤해혜햬"},
	{127, "데댸대댸"}, {128, "얘예예애"} };


	for (int i = 0; i < 128; i++) {
		insert_max_heap(heap, elArr[i]);
	}
}

void* input_f(void* r_start) {
	HeapType* heap;
	element e;
	int random = 0;
	int* r_start_T = (int*)r_start;
	char answer[50];

	heap = create();
	init(heap);
	DataInsert(heap);

	while (true) {
		random = rand() % 100;
		if (random % 4 == 0) {
			e = delete_max_heap(heap);
		}
		else if (random % 4 == 1) {
			for (int k = 0; k < 2; k++) {
				e = delete_max_heap(heap);
			}
		}
		else if (random % 4 == 2) {
			for (int k = 0; k < 3; k++) {
				e = delete_max_heap(heap);
			}
		}
		else {
			for (int k = 0; k < 4; k++) {
				e = delete_max_heap(heap);
			}
		}
		while (true) {
			gotoxy2(34, 8);
			printf("\n\n\n\n                               문제 : ");
			printf("%s\n                               입력 : ", e.word);
			scanf("%s", answer);

			if (strcmp(answer, e.word) == 0) {
				*r_start_T = *r_start_T + 1;
				display_line(*r_start_T);
				system("cls");
				displayBackground(r_start_T);
				break;
			}

			system("cls");
			displayBackground(r_start_T);
		}
		whatTime();
		if (pst > 99.8 || ((8 > *r_start_T) || (*r_start_T > 32))) {
			break;
		}
	}
	free(heap);
}



int TugOfWar_Launcher() {
	pthread_t inputThread;
	int r_start = 20;
	double pst, game_time = 99.8;
	int thr_id;
	void* result;
	system("mode con cols=80 lines=20 | title Squid Game");
	srand((unsigned)time(NULL));
	displayBackground(&r_start);
	thr_id = pthread_create(&inputThread, NULL, input_f, (void*)&r_start);

	r_start = 20;
	start = clock();
	pst = 0;

	do
	{
		game_control(&r_start);
	} while (pst < game_time && ((8 < r_start) && (r_start < 32))); //한곳으로 치우쳐 있지 않고 제한 시간 내라면 while문 반복

	if (20 < r_start)
	{
		printf("\n당신이 이겼습니다.");
		return 1;
	}
	else if (r_start < 20)
	{
		printf("\n당신이 졌습니다.");
		return 0;
	}
	else {
		printf("\n비겼습니다.");
		return 1;
	}

	gotoxy2(1, 15);
	pthread_join(inputThread, &result);

	printf("게임을 종료합니다. \n");
	printf("cls");
}

void gotoxy2(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void displayBackground(int* r_start)
{
	gotoxy2(1, 1);
	printf("제한시간:100 초");
	gotoxy2(30, 1);
	printf("경과시간:%4.1F 초", 0);
	gotoxy2(38, 6);
	printf("기준점");
	gotoxy2(40, 7);
	printf("▼");
	gotoxy2(40, 9);
	printf("▲");

	display_line(*r_start);
	gotoxy2(10, 6);
	printf("상대");

	gotoxy2(65, 6);
	printf("나");

	whatTime();
	gotoxy2(30, 1);
	printf("경과시간:%4.1f초", pst);
}

void display_line(int rnd)
{
	int bufferSize = 0;
	int i, line[21] = { 0 };
	line[10] = 1;
	line[4] = 2;
	line[16] = 2;
	gotoxy2(1, 8);
	for (i = 0; i < 78; i++) {
		printf(" ");
	}

	gotoxy2(rnd, 8);
	for (i = 0; i < 21; i++) {
		if (line[i] == 0)
			printf("□");
		else if (line[i] == 1)
			printf("■");
		else
			printf("◆");
	}

	whatTime();
	gotoxy2(30, 1);
	printf("경과시간:%4.1f초", pst);

	gotoxy2(39, 13);
}

void whatTime() {
	clock_t end;
	end = clock();
	pst = (double)(end - start) / CLK_TCK;
}

void game_control(int* r_start)
{
	*r_start = *r_start - 1;
	display_line(*r_start);
	Sleep(10000);

	whatTime();
	gotoxy2(30, 1);
	printf("경과시간:%4.1f초", pst);
}
