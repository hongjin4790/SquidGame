#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "squid_util.h"
#include "binaryTree.h"

void inorder(TreeNode* root) {
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void remove_scrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}



char map[24][40] = {
	{"0000000000000000000000000000000000000000"},
	{"0000000000000000000000000000000000000000"},
	{"0000000000000000000100000000000000000000"},
	{"0000000000000000011011000000000000000000"},
	{"0000000000000001100000110000000000000000"},
	{"0000000000000110000000001100000000000000"},
	{"0000000000011000000000000011000000000000"},
	{"0000000001111110000000001111110000000000"},
	{"0000000000000010000000001000000000000000"},
	{"0000000000000010111011101000000000000000"},
	{"0000000000000010101010101000000000000000"},
	{"0000000000000010111011101000000000000000"},
	{"0000000000000010000000001000000000000000"},
	{"0000000000000010000000001000000000000000"},
	{"0000000000000010000000001000000000000000"},
	{"0000000000000010000000001000000000000000"},
	{"0000000000000100110110100100000000000000"},
	{"0000000000001001010110110010000000000000"},
	{"0000000000010010010110101001000000000000"},
	{"0000000000100100010110100100100000000000"},
	{"0000000001001000010110100010010000000000"},
	{"0000000010010000010110100001111000000000"},
	{"0000000100100000010110100000111100000000"},
	{"0000001111000000010110100000011110000000"}
};

void border() {
	for (int i = 0; i < 30; i++)
	{
		gotoxy(40, i);
		printf("┃  \n");
	}
}

void squid_HP(int hp)
{
	gotoxy(53, 25);
	printf("┏━━━━━━━━━━━━━━━━━━━━┓\n");
	gotoxy(53, 26);
	printf("┃       체력 %d      ┃\n", hp);
	gotoxy(53, 27);
	printf("┗━━━━━━━━━━━━━━━━━━━━┛\n");
}


void drawMap() {
	system("cls");
	int h, w;
	border();
	for (h = 0; h < 24; h++)
	{

		for (w = 0; w < 40; w++)
		{
			char temp = map[h][w];
			if (temp == '0') {
				gotoxy(45 + w, h);
				printf(" ");
			}
			else if (temp == '1') {
				gotoxy(45 + w, h);
				printf("*");
			}

		}
		printf("\n");
	}

}
void attackedSquid() {

	int h, w;
	border();
	for (h = 0; h < 20; h++)
	{

		for (w = 0; w < 40; w++)
		{
			char temp = map[h][w];
			if (temp == '0') {
				gotoxy(45 + w, h);
				printf(" ");
			}
			else if (temp == '1') {
				gotoxy(45 + w, h);
				setColor(red, black);
				printf("*");
			}

		}
		setColor(white, black);


		printf("\n");

	}
}

//문제점: 랜덤으로 공격값이 만들어지는데 중복으로 공격값 만들어지게되면 정상적으로 동작되긴하는데 공격번호를 다 맞췄는데 오징어가 죽지않으면 오류생김
void run(TreeNode* attackTree, TreeNode* inputTree) {
	remove_scrollbar();
	int input, squid_hp = 80;
	int damage = rand() % 10 + 20; //데미지 20~29
	int isTurn = 1; // 값이 1이면 유저의 턴
	int winner; // 값이 1이면 유저의 승리 0이면 컴퓨터 승리
	int x, y;




	srand(time(NULL));
	for (int i = 0; i < 5; i++) // i는 랜덤 공격숫자 개수
	{
		int random = rand() % 100 + 1; //1~100 랜덤
		attackTree = insert_node(attackTree, random);
	}

	drawMap();
	squid_HP(squid_hp);
	inorder(attackTree); printf("\n");// 공격번호 확인 테스트

	int i = 0, j = 0;
	while (squid_hp != 0)
	{
		squid_HP(squid_hp);
		if (isTurn)
		{
			gotoxy(0, i);
			printf("**********MY TURN ************** \n");
			printf("공격숫자를 입력하세요:");
			scanf_s("%d", &input);

			if (input <= 100)
			{
				//공격번호인지아닌지 체크
				if (search(attackTree, input) != NULL) // 공격번호 맞추면
				{
					squid_hp -= damage;
					if (squid_hp < 0)
					{
						squid_hp = 0;
						winner = 1;
					}
					printf("오징어에게 데미지를 입혔습니다.\n");
					setColor(white, red);
					squid_HP(squid_hp);
					Sleep(1000);
					setColor(white, black);
					attackTree = delete_node(attackTree, input);
					inputTree = insert_node(inputTree, input);
					isTurn = 0;
				}
				else {// 틀리면
					if (search(inputTree, input) != NULL)
					{
						if (attackTree == NULL) // 공격번호를 다맞췄는데 오징어가 안죽은경우  << 데미지를 높여서 무조건 죽게하는 방법이있음
						{
							printf("오징어 좀 쎈데? 둘다 탈락\n");
							break;
						}
						else {
							printf("중복입력했습니다\n");

						}

					}
					else {
						printf("공격번호를 맞추지 못했습니다.\n");
						inputTree = insert_node(inputTree, input);
						isTurn = 0;
					}

				}
			}
			else {
				printf("0~100사이에서 입력하세요\n");
			}
		}
		else
		{//상대편 차례
			int input_com = rand() % 100 + 1;
			if (search(inputTree, input_com) == NULL)
			{
				gotoxy(0, j);
				printf("**********COMPUTER TURN ******** \n");
				Sleep(1000);
				printf("컴퓨터 입력: %d\n", input_com);
			}


			//공격번호인지아닌지 체크
			if (search(attackTree, input_com) != NULL) // 공격번호 맞추면
			{
				squid_hp -= damage;
				if (squid_hp < 0)
				{
					squid_hp = 0;
					winner = 0;
				}

				printf("오징어에게 데미지를 입혔습니다. \n\n");
				setColor(white, red);
				squid_HP(squid_hp);
				Sleep(1000);
				setColor(white, black);
				attackTree = delete_node(attackTree, input_com);
				inputTree = insert_node(inputTree, input_com);
				isTurn = 1;
			}
			else {// 틀리면
				if (search(inputTree, input_com) != NULL)
				{
					if (attackTree == NULL) // 공격번호를 다맞췄는데 오징어가 안죽은경우  << 데미지를 높여서 무조건 죽게하는 방법이있음
					{
						printf("오징어 좀 쎈데? 둘다 탈락\n");
						break;
					}


				}
				else {
					printf("공격번호를 맞추지 못했습니다.\n\n");
					inputTree = insert_node(inputTree, input_com);
					isTurn = 1;
				}

			}
		}

		if (i < 20) //창넘어가기 좌표
		{
			i += 4;
			j += 4;
		}
		else {
			Sleep(2000);

			drawMap();
			i = 0;
			j = 0;

		}
	}

	if (winner == 1)
	{

		printf("우승자는 사용자!!");
		Sleep(2000);
	}
	else {
		printf("우승자는 컴퓨터!!");
		Sleep(2000);
	}

}
void squidGame() {
	printf("cls");
	system("mode con cols=90 lines=30 | title Squid Game");
	TreeNode* attackTree = NULL;
	TreeNode* inputTree = NULL;
	run(attackTree, inputTree);
}


