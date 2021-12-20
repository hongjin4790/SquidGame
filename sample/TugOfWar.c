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
	element elArr[MAX_ELEMENT] = { {1, "������"}, {2, "��Ȧ��"}, {3, "������"}, {4, "�⸰"}, {5, "�ɳ���"}, {6, "���ݷ�"},
	{7, "�ð�"}, {8, "����"}, {9, "���"}, {10, "���콺"}, {11, "������"}, {12, "���ڵ�"}, {13, "�ڵ���"}, {14, "īī����"}, {15, "��Ʈ��"}, {16, "���"},
	{17, "�뷡"}, {18, "����"}, {19, "������"}, {20, "��Ź"}, {21, "���ɳ���"}, {22, "���ٽ�"}, {23, "������"}, {24, "������"}, {25, "���ʲ���"}, {26, "�ｺ�ⱸ"},
	{27, "�칰"}, {28, "�ȼ���"}, {29, "�ø��콺"}, {30, "�����ϰ�"}, {31, "�Խ�ŻƮ"}, {32, "������"}, {33, "�Ӻ����"}, {34, "����"}, {35, "������"}, {36, "������"},
	{37, "�ȼ�����"}, {38, "��¡��"}, {39, "���ڳ��"}, {40, "�����Ͻ�"}, {41, "���ֿ���"}, {42, "�˺���Ʈ"}, {43, "������"}, {44, "��������"}, {45, "������"}, {46, "���Ʈ��"},
	{47, "��������"}, {48, "��Ͻ�Ʈ"}, {49, "�����۵�"}, {50, "��ȫ��"}, {51, "�ú���"}, {52, "�ҽ�����"}, {53, "����Ʈ��"}, {54, "���︧"}, {55, "���丣��"}, {56, "�÷����"},
	{57, "�����׽�"}, {58, "�ٶ�踶"}, {59, "�˷���ī"}, {60, "�ָ�����"}, {61, "��ĭ��"}, {62, "�ݷζ�"}, {63, "�ڳ�Ƽ��"}, {64, "�������"}, {65, "�÷θ���"}, {66, "���̴�ȣ"},
	{67, "�ϸ�����"}, {68, "�ε�ֳ�"}, {69, "���̿���"}, {70, "ĵ�ڽ�"}, {71, "����Ű"}, {72, "�޸�����"}, {73, "�̽ð�"}, {74, "�̳׼�Ÿ"}, {75, "�̽ý���"}, {76, "���³�"},
	{77, "��������"}, {78, "���߽���"}, {79, "�����̿�"}, {80, "��Ǻ���"}, {81, "������"}, {82, "��Ÿ"}, {83, "�����Ͼ�"}, {84, "�����ܽ�"}, {85, "���̿���"}, {86, "���𿡰�"},
	{87, "�����"}, {88, "���̽�"}, {89, "�ڹ�"}, {90, "������"}, {91, "����"}, {92, "�ҰԾ���"}, {93, "�����"}, {94, "���"}, {95, "�⸻��ĳ"}, {96, "�밡��"},
	{97, "�������"}, {98, "��긮��"}, {99, "��þ�̾�"}, {100, "���İ���"}, {101, "�ٽž���"}, {102, "������"}, {103, "�ۿò�"}, {104, "�߰���"}, {105, "����ȸ��"}, {106, "�Ｚ����"},
	{107, "�����ΰ�"}, {108, "��ĥȭ��"}, {109, "�����Լ�"}, {110, "ź����ġ"}, {111, "������"}, {112, "�Ǿ�����"}, {113, "������"}, {114, "�˿���"}, {115, "���ٺ���"}, {116, "��������"},
	{117, "������Ʈ"}, {118, "���̺���"}, {119, "���̱ű�"}, {120, "�C�o���n"}, {121, "���Ƅ��n"}, {122, "�ܿ�����"}, {123, "���̿ܿ�"}, {124, "���̵ǿ�"}, {125, "�E������"}, {126, "��������"},
	{127, "���۴��"}, {128, "�꿹����"} };


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
			printf("\n\n\n\n                               ���� : ");
			printf("%s\n                               �Է� : ", e.word);
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
	} while (pst < game_time && ((8 < r_start) && (r_start < 32))); //�Ѱ����� ġ���� ���� �ʰ� ���� �ð� ����� while�� �ݺ�

	if (20 < r_start)
	{
		printf("\n����� �̰���ϴ�.");
		return 1;
	}
	else if (r_start < 20)
	{
		printf("\n����� �����ϴ�.");
		return 0;
	}
	else {
		printf("\n�����ϴ�.");
		return 1;
	}

	gotoxy2(1, 15);
	pthread_join(inputThread, &result);

	printf("������ �����մϴ�. \n");
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
	printf("���ѽð�:100 ��");
	gotoxy2(30, 1);
	printf("����ð�:%4.1F ��", 0);
	gotoxy2(38, 6);
	printf("������");
	gotoxy2(40, 7);
	printf("��");
	gotoxy2(40, 9);
	printf("��");

	display_line(*r_start);
	gotoxy2(10, 6);
	printf("���");

	gotoxy2(65, 6);
	printf("��");

	whatTime();
	gotoxy2(30, 1);
	printf("����ð�:%4.1f��", pst);
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
			printf("��");
		else if (line[i] == 1)
			printf("��");
		else
			printf("��");
	}

	whatTime();
	gotoxy2(30, 1);
	printf("����ð�:%4.1f��", pst);

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
	printf("����ð�:%4.1f��", pst);
}
