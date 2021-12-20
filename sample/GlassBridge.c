#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "queue.h"

char bridge[MAX_SIZE][MAX_SIZE] = { { '1','1','1','1','1','1','1','y','y','y','y','y','y','y','1','1','1','1','1','1'}, //map
                                 { '1','1','1','1','1','1','1','1','1','0','0','0','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','0','1','d','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},
                                 { '1','1','1','1','1','1','1','1','1','0','1','d','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','0','1','d','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','d','1','0','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','d','1','0','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','0','1','d','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','d','1','0','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','0','1','d','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','d','1','0','1','1','1','1','1','1','1','1' },
                                 { '1','1','1','1','1','1','1','1','1','0','x','0','1','1','1','1','1','1','1','1' },
};

void GotoXY(int x, int y);
void print_bridgeGame(char bridge[][MAX_SIZE], int row);
int is_block(char bridge[][MAX_SIZE], int row, int col);
int move_bridge(char bridge[][MAX_SIZE], int* row, int* col, int* life, Queue* q);
void CursorView(char show);
void complete_exit();
void restart(int* life, Queue* q);
void glassjumpLauncher();
void runBridge(int* life, Queue* q);

void glassjumpLauncher() { // ¡�˴ٸ� ���� ���� �Լ� 
    system("mode con cols=80 lines=30 | title Squid Game");
    system("cls");
    Queue q;
    init_queue(&q);
    for (int i = 0; i < 20; i++)
    {
        enqueue(&q, i);
    }
    int life = get_count(&q);
    runBridge(&life, &q);

}
void runBridge(int* life, Queue* q) {
    int row = 18, col = 10; //���� ��ġ �ʱ�ȭ
    printf("  ��������������������������������");
    printf("\n  �� ������ �ǳʱ⦢");
    printf("\n  ��������������������������������");
    CursorView(0);
    int flag = 0;
    while (flag==0) //���� start
    {
        print_bridgeGame(bridge, 20);
        flag = move_bridge(bridge, &row, &col, life, &q);
    }
    complete_exit();
}

void CursorView(char show) //Ŀ���� ���ִ� �Լ�
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKey() //Ű�� �޾Ƶ��̴� �Լ�
{
    if (_kbhit() != 0) //Ű �Է��� ��ȿ�� ���
    {
        return _getch(); //�Է��� Ű ��ȯ
    }

    return 0; //�׷��� ���� ��� 0��ȯ
}

void print_bridgeGame(char bridge[][MAX_SIZE], int row) // �� �׸��� �Լ� 
{
    for (int i = 0; i < row; i++)
    {
        GotoXY(XPOS - 1, YPOS - 2);
        GotoXY(XPOS, YPOS + i);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (bridge[i][j] == '1')
                printf("  ");
            else if (bridge[i][j] == 'y')
                printf("��");
            else if (bridge[i][j] == '0')
                printf("��");
            else if (bridge[i][j] == 'd')
                printf("��");
            else
                printf("��");
        }
        puts("");
    }
}

int is_block(char bridge[][MAX_SIZE], int i, int j)
{

    if (bridge[i][j] == '1' || bridge[i][j] == 'y' || bridge[i][j] == 'd') //���� ���, ������ ���, ������ �������� ��� 
        return 1;
    else
        return 0;
}

int is_finish(char bridge[][MAX_SIZE], int i, int j)
{

    if (bridge[i][j] == 'y') //������ ���
        return 1;
    else
        return 0;
}
int is_die(char bridge[][MAX_SIZE], int i, int j)
{

    if (bridge[i][j] == 'd') // ������ �������� ��� 
        return 1;
    else
        return 0;
}

void complete_exit() //�Ϸ��� �� ���α׷��� �����Ű�� �Լ�
{
    printf("Complete!!!\n");
    Sleep(2000);
}
void restart(int* life, Queue* q)
{
    int row = 18, col = 10;

    while (1) //���� start
    {
        print_bridgeGame(bridge, 20);
        move_bridge(bridge, &row, &col, life, &q);
    }

}

int move_bridge(char bridge[][MAX_SIZE], int* row, int* col, int* life, Queue* q) // �÷��̾ �����̴� �Լ�
{
    int chr; //Ű�� �޾Ƶ��̱� ���� ����
    int i = *row;
    int j = *col;

    printf("\n\n���� �����ڼ� : %2d\n", *life);

    chr = GetKey();

    if (chr == 0 || chr == 0xe0)
    {
        chr = GetKey();
        switch (chr)
        {


        case LEFT:
            j--;
            if (!(is_block(bridge, i, j)))
            {
                bridge[*row + 1][*col] = '0';
                bridge[i][j] = 'x';
                *col -= 1;
                *row -= 1;
            }
            else if (is_die(bridge, i, j))
            {
                *life = *life - 1;
                bridge[*row + 1][*col] = '0';
                bridge[19][10] = 'x';
                print_bridgeGame(bridge, 20);
                restart(life, &q);
                dequeue(&q);//dequeue �����ڸ� 
            }
            else if (is_finish(bridge, i, j))
            {
                bridge[*row + 1][*col] = '0';
                bridge[i][j] = 'x';
                print_bridgeGame(bridge, 20);
                return 1;
            }
            break;

        case RIGHT:
            j++;
            if (!(is_block(bridge, i, j)))
            {
                bridge[*row + 1][*col] = '0';
                bridge[i][j] = 'x';
                *col += 1;
                *row -= 1;

            }
            else if (is_die(bridge, i, j))
            {
                *life = *life - 1;
                bridge[*row + 1][*col] = '0';
                bridge[19][10] = 'x';
                print_bridgeGame(bridge, 20);
                restart(life, &q);
                dequeue(&q);//dequeue �����ڸ� 
            }
            else if (is_finish(bridge, i, j))
            {
                bridge[*row + 1][*col] = '0';
                bridge[i][j] = 'x';
                print_bridgeGame(bridge, 20);
                return 1;
            }
            break;
        }
        if (*life == 0) {
            printf("You Loss!!!\n");
            loser();
        }

    }
    return 0;


}
