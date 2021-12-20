#include <stdio.h> 
#include <Windows.h> 
#include <conio.h>
#include <stdlib.h> //srand, rand를 사용하기 위한 헤더파일
#include <time.h> // time을 사용하기 위한 헤더파일
#include <string.h>
#include <process.h>
#include "listNode.h"

int maze[MapHeight][MapWidth] = { 0, };
int checkFrontBack;
int playerLife = 1;

// x, y 좌표 바꿔주는 함수  
void gotoxy_l(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void setcolor(int i) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
// 터미널 창에서 커서형태  바꿔주는 함수
// NOCURSOR를 주면 커서가 숨겨짐   
void setcursortype(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}



void setPromptSize() {
	char s1[30] = "mode con:cols=";
	char s2[30] = " lines=";
	char width[20] = "";
	char height[20] = "";
	_itoa(MapWidth * 2, width, 10);
	_itoa(MapHeight + 2, height, 10);
	strcat(s1, width);
	strcat(s2, height);
	strcat(s1, s2);
	system(s1); //col = 가로(MapWidth*2), lines = 세로(MapHeight+2)  
}



void draw_map() {
	coordinate younghee = { MapWidth - 5, 14 };

	for (int i = 0; i < MapHeight; i++) { // 양 옆  세로 벽 그리기  
		maze[i][MapWidth - 13] = 2;
		maze[i][MapWidth - 1] = 1;
		maze[i][0] = 1;
	}

	for (int i = 0; i < MapWidth; i++) { // 위, 아래 가로 벽 그리기  
		maze[0][i] = 1;
		maze[MapHeight - 1][i] = 1;
	}

	maze[2][MapWidth - 3] = 555; // 요원들 
	maze[4][MapWidth - 3] = 555; // 요원들 
	maze[6][MapWidth - 3] = 555; // 요원들 
	maze[8][MapWidth - 3] = 555; // 요원들 
	maze[MapHeight - 3][MapWidth - 3] = 555; // 요원들
	maze[MapHeight - 5][MapWidth - 3] = 555; // 요원들
	maze[MapHeight - 7][MapWidth - 3] = 555; // 요원들
	maze[MapHeight - 9][MapWidth - 3] = 555; // 요원들

	// ********** 영희 앞모습 그리기  **********   
	maze[younghee.y - 3][younghee.x - 2] = 4;
	maze[younghee.y - 3][younghee.x + 1] = 3;
	maze[younghee.y - 3][younghee.x] = 8;
	maze[younghee.y - 3][younghee.x - 1] = 8;
	maze[younghee.y - 2][younghee.x - 2] = 9;
	maze[younghee.y - 2][younghee.x + 2] = 66;
	maze[younghee.y - 2][younghee.x - 1] = 10;
	maze[younghee.y - 2][younghee.x + 1] = 10;
	maze[younghee.y - 2][younghee.x] = 10;
	maze[younghee.y - 1][younghee.x - 1] = 8;
	maze[younghee.y - 1][younghee.x + 1] = 8;
	maze[younghee.y - 1][younghee.x] = 8;
	maze[younghee.y - 1][younghee.x + 2] = 9;
	maze[younghee.y - 1][younghee.x + 3] = 55;
	maze[younghee.y - 1][younghee.x - 3] = 5;
	maze[younghee.y - 1][younghee.x - 2] = 9;
	maze[younghee.y][younghee.x + 3] = 3;
	maze[younghee.y][younghee.x - 4] = 4;
	maze[younghee.y][younghee.x - 2] = 9;
	maze[younghee.y][younghee.x + 2] = 66;
	maze[younghee.y][younghee.x + 1] = 51;
	maze[younghee.y][younghee.x - 1] = 51;
	maze[younghee.y + 1][younghee.x - 2] = 3;
	maze[younghee.y + 1][younghee.x + 1] = 4;
	maze[younghee.y + 1][younghee.x] = 99;
	maze[younghee.y + 2][younghee.x] = 8;
	maze[younghee.y + 2][younghee.x - 1] = 8;
	// ********** 영희 앞모습 그리기  ********** 

	for (int i = 0; i < MapHeight; i++) {
		for (int j = 0; j < MapWidth; j++) {
			if (maze[i][j] == 1) { // 1 = 테두리 벽 
				printf("■");
			}
			else if (maze[i][j] == 2) { // 2 = 빨간 도착선 
				setcolor(12);
				printf("▒▒");
				setcolor(7);
			}
			else if (maze[i][j] == 3) {
				printf("＼");
			}
			else if (maze[i][j] == 4) {
				printf("／");
			}
			else if (maze[i][j] == 5) {
				printf("●");
			}
			else if (maze[i][j] == 555) {
				setcolor(13);
				printf("●");
				setcolor(7);
			}
			else if (maze[i][j] == 55) {
				printf("●  ");
			}
			else if (maze[i][j] == 51) {
				printf("○");
			}
			else if (maze[i][j] == 6) {
				printf("| ");
			}
			else if (maze[i][j] == 66) {
				printf("|  ");
			}
			else if (maze[i][j] == 7) {
				printf(" |");
			}
			else if (maze[i][j] == 8) {
				printf("￣");
			}
			else if (maze[i][j] == 9) {
				printf("|");
			}
			else if (maze[i][j] == 10) {
				printf("//");
			}
			else if (maze[i][j] == 99) {
				printf("\bㅁ ");
			}
			else { // 0 = 빈칸  
				printf("  "); // ■는 2칸 차지하기때문에 2칸 띄워야함  
			}
		}
		printf("\n");
	}
	printf("\n");
}

void draw_younghee(int fb) {
	coordinate younghee = { MapWidth - 5, 14 };

	if (fb == 1) {
		// ********** 영희 앞모습 그리기  **********   
		maze[younghee.y - 3][younghee.x - 2] = 4;
		maze[younghee.y - 3][younghee.x + 1] = 3;
		maze[younghee.y - 3][younghee.x] = 8;
		maze[younghee.y - 3][younghee.x - 1] = 8;
		maze[younghee.y - 2][younghee.x - 2] = 9;
		maze[younghee.y - 2][younghee.x + 2] = 66;
		maze[younghee.y - 2][younghee.x - 1] = 10;
		maze[younghee.y - 2][younghee.x + 1] = 10;
		maze[younghee.y - 2][younghee.x] = 10;
		maze[younghee.y - 1][younghee.x - 1] = 8;
		maze[younghee.y - 1][younghee.x + 1] = 8;
		maze[younghee.y - 1][younghee.x] = 8;
		maze[younghee.y - 1][younghee.x + 2] = 9;
		maze[younghee.y - 1][younghee.x + 3] = 55;
		maze[younghee.y - 1][younghee.x - 3] = 5;
		maze[younghee.y - 1][younghee.x - 2] = 9;
		maze[younghee.y][younghee.x + 3] = 3;
		maze[younghee.y][younghee.x - 4] = 4;
		maze[younghee.y][younghee.x - 2] = 9;
		maze[younghee.y][younghee.x + 2] = 66;
		maze[younghee.y][younghee.x + 1] = 51;
		maze[younghee.y][younghee.x - 1] = 51;
		maze[younghee.y][younghee.x] = 0;
		maze[younghee.y + 1][younghee.x - 2] = 3;
		maze[younghee.y + 1][younghee.x + 1] = 4;
		maze[younghee.y + 1][younghee.x] = 99;
		maze[younghee.y + 2][younghee.x] = 8;
		maze[younghee.y + 2][younghee.x - 1] = 8;
		// ********** 영희 앞모습 그리기  ********** 
	}
	else {
		// ********** 영희 뒷모습 그리기  **********   
		maze[younghee.y - 3][younghee.x - 2] = 4;
		maze[younghee.y - 3][younghee.x + 1] = 3;
		maze[younghee.y - 3][younghee.x] = 8;
		maze[younghee.y - 3][younghee.x - 1] = 8;
		maze[younghee.y - 2][younghee.x - 2] = 9;
		maze[younghee.y - 2][younghee.x + 2] = 66;
		maze[younghee.y - 2][younghee.x - 1] = 10;
		maze[younghee.y - 2][younghee.x + 1] = 10;
		maze[younghee.y - 2][younghee.x] = 10;
		maze[younghee.y - 1][younghee.x - 1] = 10;
		maze[younghee.y - 1][younghee.x + 1] = 10;
		maze[younghee.y - 1][younghee.x] = 10;
		maze[younghee.y - 1][younghee.x + 2] = 9;
		maze[younghee.y - 1][younghee.x + 3] = 55;
		maze[younghee.y - 1][younghee.x - 3] = 5;
		maze[younghee.y - 1][younghee.x - 2] = 9;
		maze[younghee.y][younghee.x + 3] = 3;
		maze[younghee.y][younghee.x - 4] = 4;
		maze[younghee.y][younghee.x - 2] = 9;
		maze[younghee.y][younghee.x + 2] = 66;
		maze[younghee.y][younghee.x + 1] = 10;
		maze[younghee.y][younghee.x - 1] = 10;
		maze[younghee.y][younghee.x] = 10;
		maze[younghee.y + 1][younghee.x - 2] = 3;
		maze[younghee.y + 1][younghee.x + 1] = 4;
		maze[younghee.y + 1][younghee.x] = 10;
		maze[younghee.y + 1][younghee.x - 1] = 10;
		maze[younghee.y + 2][younghee.x] = 8;
		maze[younghee.y + 2][younghee.x - 1] = 8;
		// ********** 영희 뒷모습 그리기  ********** 
	}

	for (int i = younghee.y - 3; i < younghee.y + 3; i++) {
		gotoxy_l((MapWidth - 9) * 2, i);
		for (int j = younghee.x - 4; j < MapWidth - 1; j++) {
			if (maze[i][j] == 3) {
				printf("＼");
			}
			else if (maze[i][j] == 4) {
				printf("／");
			}
			else if (maze[i][j] == 5) {
				printf("●");
			}
			else if (maze[i][j] == 55) {
				printf("●  ");
			}
			else if (maze[i][j] == 51) {
				printf("○");
			}
			else if (maze[i][j] == 6) {
				printf("| ");
			}
			else if (maze[i][j] == 66) {
				printf("|  ");
			}
			else if (maze[i][j] == 7) {
				printf(" |");
			}
			else if (maze[i][j] == 8) {
				printf("￣");
			}
			else if (maze[i][j] == 9) {
				printf("|");
			}
			else if (maze[i][j] == 10) {
				printf("//");
			}
			else if (maze[i][j] == 99) {
				printf("\b\b ㅁ ");
			}
			else { // 0 = 빈칸  
				printf("  "); // ■는 2칸 차지하기때문에 2칸 띄워야함  
			}
		}
		printf("\n");
	}
}

void draw_redLine(coordinate* red) {
	for (red->y; red->y < MapHeight - 1; red->y++) {
		gotoxy_l(red->x, red->y);
		setcolor(12);
		printf("▒▒");
		setcolor(7);
	}
	red->y = 2;
}

void delete_player(int x, int y) {
	gotoxy_l(x, y); // 이전에 출력된 플레이어의 좌표(x, y)로 이동
	printf("  "); // 출력된 플레이어를 지워 새 위치에 플레이어가 출력되었을 때 잔상이 남지 않게 함
}

void draw_player(int x, int y, int color) {
	gotoxy_l(x, y); // 변경된 좌표로 커서 이동
	setcolor(color);
	printf("●"); // 플레이어 출력
}

void extra_move(coordinate* a, ListNode* head, int random) {
	if (search_list(head, a->y) != 0) {
		if (random < 1 && (a->x < (MapWidth - 2) * 2 - 18)) {
			delete_player(a->x, a->y);
			a->x = a->x + 2;
			draw_player(a->x, a->y, 11);

			if (checkFrontBack == 1) {
				a->checkBullet = 1;
			}
		}
		else {
			gotoxy_l(a->x, a->y); // 변경된 좌표로 커서 이동
			setcolor(11);
			printf("●");
		}
	}
	else {
		delete_player(a->x, a->y);
	}
}

void player_move(coordinate* a, ListNode* head) {
	if (_kbhit()) { // 키보드 입력이 발생했는지 확인  
		int key = _getch(); // getch() 함수는 키보드를 누르면 대기 없이 입력한 값을 변수에 저장, 화면에 출력도 안함 
		if (key == 224 || key == 0) {
			key = _getch();
			delete_player(a->x, a->y);  // 이전 좌표의 잔상 삭제  
			switch (key) {
			case UP:
				if (a->y > 1) a->y--;
				break;
			case DOWN:
				if (a->y < MapHeight - 2) a->y++;
				break;
			case LEFT:
				if (a->x > 2) a->x = a->x - 2;
				break;
			case RIGHT:
				if (a->x < (MapWidth - 2) * 2 - 18) a->x = a->x + 2;
				break;
			}
			draw_player(a->x, a->y, 10);  // 변경된 좌표로 새로 출력
			if (checkFrontBack == 1) {
				a->checkBullet = 1;
			}
		}
	}
	else {
		draw_player(a->x, a->y, 10);  // 변경된 좌표로 새로 출력
	}
}

void print_mugunghwa(int i) {
	gotoxy_l(MapWidth * 2 - 11, 17);
	setcolor(7);
	if (i == 0) {
		printf("무");
		Sleep(100);
		checkFrontBack = 0; // 영희 뒷모습 
		draw_younghee(0);
	}
	else if (i == 1) {
		printf("궁");
		Sleep(10);
	}
	else if (i == 2) {
		printf("화");
		Sleep(10);
	}
	else if (i == 3) {
		printf("꽃");
		Sleep(10);
	}
	else if (i == 4) {
		printf("이");
		Sleep(10);
	}
	else if (i == 5) {
		printf("피");
		Sleep(10);
	}
	else if (i == 6) {
		printf("었");
		Sleep(10);
	}
	else if (i == 7) {
		printf("습");
		Sleep(10);
	}
	else if (i == 8) {
		printf("니");
		Sleep(10);
	}
	else if (i == 9) {
		printf("다");
		Sleep(10);
		checkFrontBack = 1; // 영희 앞모습  
		draw_younghee(1);
	}
	Sleep(100);
}

void print_time(int countdown) {
	gotoxy_l(MapWidth * 2 - 56, MapHeight);
	setcolor(7);
	printf("남은 시간 %3d 초", countdown);
}

void shoot_bullet(coordinate* a) {
	if (a->x > 2) {
		gotoxy_l(a->x, a->y);
		printf("  ");
		a->x = a->x - 2;

		gotoxy_l(a->x, a->y);
		setcolor(12);
		printf("◀");
	}
	else {
		gotoxy_l(a->x, a->y);
		printf("  ");
	}
}

void check_bullet(coordinate* a, coordinate* bullet, ListNode* head) {
	if (a->checkBullet == 1) {
		if (a->x >= bullet->x && a->y == bullet->y) {
			delete_node_l(head, a->y);
			print_list(head);
		}
		shoot_bullet(bullet);
	}
}

void check_bullet_player(coordinate* a, coordinate* bullet, ListNode* head) {
	if (a->checkBullet == 1) {
		if (a->x == bullet->x && a->y == bullet->y) {
			delete_node_l(head, a->y);
			print_list(head);
			playerLife = 0;
		}
		shoot_bullet(bullet);
	}
}

int MugunghwaGameStart() {
	setcursortype(NOCURSOR); // 커서 제거 
	setPromptSize(); // 프롬프트창 크기 설정  
	draw_map();
	Sleep(800);

	ListNode* head = NULL; // 리스트 선언  
	int node_num = 7;

	// 좌표 값 셋팅
	coordinate aa = { 2, 13 };  // 주인공 player 
	coordinate e1 = { 2, 3 }; // extra
	coordinate e2 = { 2, 6 };
	coordinate e3 = { 2, 9 };
	coordinate e4 = { 2, 17 };
	coordinate e5 = { 2, 20 };
	coordinate e6 = { 2, 23 };
	coordinate bulleta = { (MapWidth - 13) * 2, 13 }; // 주인공 bullet 
	coordinate bullet1 = { (MapWidth - 13) * 2, 3 }; // extra bullet
	coordinate bullet2 = { (MapWidth - 13) * 2, 6 };
	coordinate bullet3 = { (MapWidth - 13) * 2, 9 };
	coordinate bullet4 = { (MapWidth - 13) * 2, 17 };
	coordinate bullet5 = { (MapWidth - 13) * 2, 20 };
	coordinate bullet6 = { (MapWidth - 13) * 2, 23 };

	coordinate red = { (MapWidth - 13) * 2, 2 }; // 빨간색 도착 선  

	head = insert_first(head, e6.y); // 리스트에 참가자 삽입 
	head = insert_first(head, e5.y);
	head = insert_first(head, e4.y);
	head = insert_first(head, e3.y);
	head = insert_first(head, e2.y);
	head = insert_first(head, e1.y);
	head = insert_first(head, aa.y);
	head = insert_first(head, 0);
	print_list(head);

	draw_player(aa.x, aa.y, 10); // 처음 위치 player 출력  
	draw_player(e1.x, e1.y, 11);
	draw_player(e2.x, e2.y, 11);
	draw_player(e3.x, e3.y, 11);
	draw_player(e4.x, e4.y, 11);
	draw_player(e5.x, e5.y, 11);
	draw_player(e6.x, e6.y, 11);

	char* script = "무궁화꽃이피었습니다";
	int length = strlen(script);

	int i = 0;
	int countdown, totalTime = 60;
	clock_t startTime = clock();
	clock_t endTime;

	while (1) {
		print_mugunghwa(i);
		draw_redLine(&red);
		player_move(&aa, head);

		srand(clock()); // 난수 초기화
		extra_move(&e1, head, rand() % 10);
		extra_move(&e2, head, rand() % 10);
		extra_move(&e3, head, rand() % 10);
		extra_move(&e4, head, rand() % 10);
		extra_move(&e5, head, rand() % 10);
		extra_move(&e6, head, rand() % 10);

		check_bullet_player(&aa, &bulleta, head);
		check_bullet(&e1, &bullet1, head);
		check_bullet(&e2, &bullet2, head);
		check_bullet(&e3, &bullet3, head);
		check_bullet(&e4, &bullet4, head);
		check_bullet(&e5, &bullet5, head);
		check_bullet(&e6, &bullet6, head);

		if (aa.x > (MapWidth - 13) * 2) { // 플레이어가 도착선 통과  
			break;
		}
		if (playerLife == 0) { // 플레이어 죽음  
			break;
		}

		// 남은 시간 표시  
		endTime = clock();
		countdown = totalTime - ((endTime - startTime) / CLOCKS_PER_SEC);
		if (countdown > 0) {
			print_time(countdown);
		}
		else {
			print_time(countdown);
			playerLife = 0;
		}

		// 무궁화 글자 변환  
		i++;
		if (i == length) {
			i = 0;
		}
	}

	system("cls");
	gotoxy_l(0, 0);
	setcolor(7);
	if (playerLife == 1) {
		printf("플레이어 Win");
		return 1;
	}
	else {
		printf("플레이어 사망");
		return 0;
	}

}

