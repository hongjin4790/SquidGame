#include <stdio.h>
#include <time.h>
#include <windows.h>

void script_1();
void pressEnter() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n\n  [계속 진행하시려면 Enter 를 눌러주세요]");
	while (getchar() != '\n') {}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void script_0() {
	system("mode con cols=80 lines=20 | title Squid Game");
	Sleep(1000);
	printf("\n  지금 여기 계신 여러분들은\n");
	Sleep(2000);

	printf("\n  모두 감당할 수 없는 빚을 지고\n");
	Sleep(2500);

	printf("\n  삶의 벼랑 끝에 서 계신 분들입니다\n");
	Sleep(2500);
	pressEnter();
	script_1();
}

void script_1() {

	Sleep(1000);
	system("cls");
	printf("\n\n  [HOST] : 오징어 게임의 참가자 여러분들 환영합니다.\n");
	Sleep(2000);
	printf("\n  [HOST] : 오징어 게임은 총 4개의 게임으로 4일간 진행됩니다.\n");
	Sleep(2000);
	printf("\n  [HOST] : 모든 게임에서 살아남으신 분들에게는 거액의 상금이 지급 됩니다. \n");
	Sleep(2000);
	printf("\n  [HOST] : 게임이 시작하면 중도 포기는 불가능 합니다.\n");
	Sleep(2000);
	pressEnter();
}


void manual_RLGL() {
	system("cls");
	Sleep(500);
	printf("\n\n  [HOST] : 첫번째 게임은 무궁화 꽃이 피었습니다 입니다.\n");
	Sleep(500);
	printf("\n  [HOST] : 술래가 벽을 보고 \"무궁화 꽃이 피었습니다\" 구호를 외칩니다. \n");
	Sleep(500);
	printf("\n  [HOST] : 구호가 끝난 동시에 술래가 뒤를 돌아볼 때  \n");
	Sleep(500);
	printf("\n  [HOST] : 움직이는 사람은 탈락하게 됩니다.\n");
	Sleep(500);
	printf("\n  (상,하,좌,우 방향키로 이동이 가능하다).\n");
	Sleep(2000);
	pressEnter();
}

void manual_TOW() {
	system("cls");
	Sleep(500);
	printf("\n\n  [HOST] : 두번째 게임은 줄다리기 입니다.\n");
	Sleep(500);
	printf("\n  [HOST] : 양 팀이 줄 양쪽 끝을 잡고 서로 당깁니다. \n");
	Sleep(500);
	printf("\n  [HOST] : 줄의 가운데 부분이 내 방향 기준점을 통과하게 되면 승리합니다.  \n");
	Sleep(500);
	printf("\n  (제시된 단어를 정확하게 입력하자).\n");
	Sleep(2000);
	pressEnter();
}
void manual_GB() {
	system("cls");
	Sleep(500);
	printf("\n\n  [HOST] : 세번째 게임은 유리 징검다리 건너기 입니다.\n");
	Sleep(500);
	printf("\n  [HOST] : 유리 징검다리는 좌, 우 두개의 유리발판이 여러 행 이어져있습니다. \n");
	Sleep(500);
	printf("\n  [HOST] : 두 발판중 하나는 밟게되면 바로 깨집니다. \n");
	Sleep(500);
	printf("\n  [HOST] : 무사히 다리를 건너면 승리합니다. \n");
	Sleep(500);
	printf("\n  (상,하,좌,우 방향키로 이동이 가능하다).\n");
	Sleep(2000);
	pressEnter();
}
void manual_SG() {
	system("cls");
	Sleep(500);
	printf("\n\n  [HOST] : 마지막 게임은 오징어 잡기 입니다.\n");
	Sleep(500);
	printf("\n  [HOST] : 시작 전 참가자가 알 수 없게 임의의 숫자를 지정합니다. \n");
	Sleep(500);
	printf("\n  [HOST] : 두 참가자가 번갈아가면서 숫자를 제시합니다. \n");
	Sleep(500);
	printf("\n  [HOST] : 제시한 숫자가 지정된 숫자와 동일하다면 오징어 괴물에게 피해를 줍니다. \n");
	Sleep(500);
	printf("\n  [HOST] : 오징어를 죽이는 공격을 가한 참가자가 승리합니다. \n");
	Sleep(2000);
	pressEnter();
}

void winner() {
	system("mode con cols=65 lines=15 | title Squid Game");
	system("cls");
	Sleep(1500);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n\n                            CONGRATS!                        \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n       축하합니다! 당신은 오징어 게임에서 승리하셨습니다. \n\n");
	Sleep(1500);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n\n\n              [Enter 를 눌러 456억원을 수령하세요]");
	while (getchar() != '\n') {}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}

void loser() {
	system("mode con cols=65 lines=15 | title Squid Game");
	system("cls");
	Sleep(1500);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("\n\n                            RETIRED                        \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n                 안타깝게도 당신은 탈락했습니다...  \n");
	Sleep(1500);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n\n\n              [Enter 를 누르면 게임이 종료됩니다]");
	while (getchar() != '\n') {}
	exit(0);
}
void result(int result) {
	if (result == 0) loser();
}




void print_title() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("                                                                           \n");
	printf("     ■■■■■■   ■■■■■■    ■■      ■■  ■■■  ■■■■■■   \n");
	printf("    ■■■■■■■ ■■■■■■■   ■■      ■■  ■■■  ■■■■■■■ \n");
	printf("    ■■           ■■      ■■   ■■      ■■   ■■   ■■      ■■ \n");
	printf("    ■■           ■■      ■■   ■■      ■■   ■■   ■■      ■■ \n");
	printf("    ■■           ■■      ■■   ■■      ■■   ■■   ■■      ■■ \n");
	printf("    ■■■■■■■ ■■      ■■   ■■      ■■   ■■   ■■      ■■ \n");
	printf("    ■■■■■■■ ■■      ■■   ■■      ■■   ■■   ■■      ■■ \n");
	printf("              ■■ ■■   ■■ ■   ■■      ■■   ■■   ■■      ■■ \n");
	printf("              ■■ ■■    ■■■   ■■      ■■   ■■   ■■      ■■ \n");
	printf("              ■■ ■■     ■■    ■■      ■■   ■■   ■■      ■■ \n");
	printf("    ■■■■■■■ ■■■■■ ■■   ■■■■■■   ■■■  ■■■■■■■ \n");
	printf("     ■■■■■■   ■■■■■ ■■   ■■■■■    ■■■  ■■■■■■   \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf("                            ┌━━━━━━━━━━━━━━━━━━━━┐    \n");
	printf("                            │   Press Enter Key  │                        \n");
	printf("                            └━━━━━━━━━━━━━━━━━━━━┘    \n");


	printf("    ■■■■■■■    ■■■■■■■   ■■            ■■   ■■■■■■■ \n");
	printf("  ■■■■■■■■  ■■■■■■■■■ ■■            ■■ ■■■■■■■■ \n");
	printf("  ■■■            ■■■      ■■■ ■■■        ■■■ ■■             \n");
	printf("  ■■■            ■■■      ■■■ ■■■        ■■■ ■■             \n");
	printf("  ■■■            ■■■      ■■■ ■■■■    ■■■■ ■■             \n");
	printf("  ■■■  ■■■■  ■■■      ■■■ ■■■■■■■■■■ ■■■■■■■■ \n");
	printf("  ■■■  ■■■■  ■■■■■■■■■ ■■■■■■■■■■ ■■■■■■■■ \n");
	printf("  ■■■    ■■■  ■■■■■■■■■ ■■■ ■■■ ■■■ ■■             \n");
	printf("  ■■■      ■■  ■■■      ■■■ ■■■  ■■  ■■■ ■■             \n");
	printf("  ■■■    ■■■  ■■■      ■■■ ■■■   ■   ■■■ ■■             \n");
	printf("  ■■■■■■■■  ■■■      ■■■ ■■■        ■■■ ■■■■■■■■ \n");
	printf("    ■■■■■■    ■■■      ■■■ ■■■        ■■■   ■■■■■■■ \n");
	while (getchar() != '\n') {}
	script_0();
}
int main(void) {
	int life = 0;
	system("mode con cols=80 lines=30 | title Squid Game");
	/*print_title();

	manual_RLGL();
	result(MugunghwaGameStart());

	manual_TOW();
	TugOfWar_Launcher();

	manual_GB();*/
	result(glassjumpLauncher());
	
	manual_SG();
	result(squidGame());

	winner();

	return 0;
}