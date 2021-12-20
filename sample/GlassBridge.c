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

void glassjumpLauncher() { // 징검다리 게임 시작 함수 
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
    int row = 18, col = 10; //시작 위치 초기화
    printf("  ┌━━━━━━━━━━━━━━┐");
    printf("\n  │ 유리판 건너기│");
    printf("\n  └━━━━━━━━━━━━━━┘");
    CursorView(0);
    int flag = 0;
    while (flag==0) //게임 start
    {
        print_bridgeGame(bridge, 20);
        flag = move_bridge(bridge, &row, &col, life, &q);
    }
    complete_exit();
}

void CursorView(char show) //커서를 없애는 함수
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

int GetKey() //키를 받아들이는 함수
{
    if (_kbhit() != 0) //키 입력이 유효할 경우
    {
        return _getch(); //입력한 키 반환
    }

    return 0; //그렇지 않을 경우 0반환
}

void print_bridgeGame(char bridge[][MAX_SIZE], int row) // 맵 그리는 함수 
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
                printf("★");
            else if (bridge[i][j] == '0')
                printf("□");
            else if (bridge[i][j] == 'd')
                printf("죽");
            else
                printf("●");
        }
        puts("");
    }
}

int is_block(char bridge[][MAX_SIZE], int i, int j)
{

    if (bridge[i][j] == '1' || bridge[i][j] == 'y' || bridge[i][j] == 'd') //벽일 경우, 종점일 경우, 깨지는 유리판일 경우 
        return 1;
    else
        return 0;
}

int is_finish(char bridge[][MAX_SIZE], int i, int j)
{

    if (bridge[i][j] == 'y') //종점일 경우
        return 1;
    else
        return 0;
}
int is_die(char bridge[][MAX_SIZE], int i, int j)
{

    if (bridge[i][j] == 'd') // 깨지는 유리판일 경우 
        return 1;
    else
        return 0;
}

void complete_exit() //완료한 후 프로그램을 종료시키는 함수
{
    printf("Complete!!!\n");
    Sleep(2000);
}
void restart(int* life, Queue* q)
{
    int row = 18, col = 10;

    while (1) //게임 start
    {
        print_bridgeGame(bridge, 20);
        move_bridge(bridge, &row, &col, life, &q);
    }

}

int move_bridge(char bridge[][MAX_SIZE], int* row, int* col, int* life, Queue* q) // 플레이어를 움직이는 함수
{
    int chr; //키를 받아들이기 위한 변수
    int i = *row;
    int j = *col;

    printf("\n\n남은 참가자수 : %2d\n", *life);

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
                dequeue(&q);//dequeue 넣을자리 
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
                dequeue(&q);//dequeue 넣을자리 
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
