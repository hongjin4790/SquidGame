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
		printf("��  \n");
	}
}

void squid_HP(int hp)
{
	gotoxy(53, 25);
	printf("��������������������������������������������\n");
	gotoxy(53, 26);
	printf("��       ü�� %d      ��\n", hp);
	gotoxy(53, 27);
	printf("��������������������������������������������\n");
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

//������: �������� ���ݰ��� ��������µ� �ߺ����� ���ݰ� ��������ԵǸ� ���������� ���۵Ǳ��ϴµ� ���ݹ�ȣ�� �� ����µ� ��¡� ���������� ��������
void run(TreeNode* attackTree, TreeNode* inputTree) {
	remove_scrollbar();
	int input, squid_hp = 80;
	int damage = rand() % 10 + 20; //������ 20~29
	int isTurn = 1; // ���� 1�̸� ������ ��
	int winner; // ���� 1�̸� ������ �¸� 0�̸� ��ǻ�� �¸�
	int x, y;




	srand(time(NULL));
	for (int i = 0; i < 5; i++) // i�� ���� ���ݼ��� ����
	{
		int random = rand() % 100 + 1; //1~100 ����
		attackTree = insert_node(attackTree, random);
	}

	drawMap();
	squid_HP(squid_hp);
	inorder(attackTree); printf("\n");// ���ݹ�ȣ Ȯ�� �׽�Ʈ

	int i = 0, j = 0;
	while (squid_hp != 0)
	{
		squid_HP(squid_hp);
		if (isTurn)
		{
			gotoxy(0, i);
			printf("**********MY TURN ************** \n");
			printf("���ݼ��ڸ� �Է��ϼ���:");
			scanf_s("%d", &input);

			if (input <= 100)
			{
				//���ݹ�ȣ�����ƴ��� üũ
				if (search(attackTree, input) != NULL) // ���ݹ�ȣ ���߸�
				{
					squid_hp -= damage;
					if (squid_hp < 0)
					{
						squid_hp = 0;
						winner = 1;
					}
					printf("��¡��� �������� �������ϴ�.\n");
					setColor(white, red);
					squid_HP(squid_hp);
					Sleep(1000);
					setColor(white, black);
					attackTree = delete_node(attackTree, input);
					inputTree = insert_node(inputTree, input);
					isTurn = 0;
				}
				else {// Ʋ����
					if (search(inputTree, input) != NULL)
					{
						if (attackTree == NULL) // ���ݹ�ȣ�� �ٸ���µ� ��¡� ���������  << �������� ������ ������ �װ��ϴ� ���������
						{
							printf("��¡�� �� �뵥? �Ѵ� Ż��\n");
							break;
						}
						else {
							printf("�ߺ��Է��߽��ϴ�\n");

						}

					}
					else {
						printf("���ݹ�ȣ�� ������ ���߽��ϴ�.\n");
						inputTree = insert_node(inputTree, input);
						isTurn = 0;
					}

				}
			}
			else {
				printf("0~100���̿��� �Է��ϼ���\n");
			}
		}
		else
		{//����� ����
			int input_com = rand() % 100 + 1;
			if (search(inputTree, input_com) == NULL)
			{
				gotoxy(0, j);
				printf("**********COMPUTER TURN ******** \n");
				Sleep(1000);
				printf("��ǻ�� �Է�: %d\n", input_com);
			}


			//���ݹ�ȣ�����ƴ��� üũ
			if (search(attackTree, input_com) != NULL) // ���ݹ�ȣ ���߸�
			{
				squid_hp -= damage;
				if (squid_hp < 0)
				{
					squid_hp = 0;
					winner = 0;
				}

				printf("��¡��� �������� �������ϴ�. \n\n");
				setColor(white, red);
				squid_HP(squid_hp);
				Sleep(1000);
				setColor(white, black);
				attackTree = delete_node(attackTree, input_com);
				inputTree = insert_node(inputTree, input_com);
				isTurn = 1;
			}
			else {// Ʋ����
				if (search(inputTree, input_com) != NULL)
				{
					if (attackTree == NULL) // ���ݹ�ȣ�� �ٸ���µ� ��¡� ���������  << �������� ������ ������ �װ��ϴ� ���������
					{
						printf("��¡�� �� �뵥? �Ѵ� Ż��\n");
						break;
					}


				}
				else {
					printf("���ݹ�ȣ�� ������ ���߽��ϴ�.\n\n");
					inputTree = insert_node(inputTree, input_com);
					isTurn = 1;
				}

			}
		}

		if (i < 20) //â�Ѿ�� ��ǥ
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

		printf("����ڴ� �����!!");
		Sleep(2000);
	}
	else {
		printf("����ڴ� ��ǻ��!!");
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


