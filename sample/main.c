#include <stdio.h>
#include <time.h>
#include <windows.h>

void script_1();
void pressEnter() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n\n  [��� �����Ͻ÷��� Enter �� �����ּ���]");
	while (getchar() != '\n') {}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void script_0() {
	system("mode con cols=80 lines=20 | title Squid Game");
	Sleep(1000);
	printf("\n  ���� ���� ��� �����е���\n");
	Sleep(2000);

	printf("\n  ��� ������ �� ���� ���� ����\n");
	Sleep(2500);

	printf("\n  ���� ���� ���� �� ��� �е��Դϴ�\n");
	Sleep(2500);
	pressEnter();
	script_1();
}

void script_1() {

	Sleep(1000);
	system("cls");
	printf("\n\n  [HOST] : ��¡�� ������ ������ �����е� ȯ���մϴ�.\n");
	Sleep(2000);
	printf("\n  [HOST] : ��¡�� ������ �� 4���� �������� 4�ϰ� ����˴ϴ�.\n");
	Sleep(2000);
	printf("\n  [HOST] : ��� ���ӿ��� ��Ƴ����� �е鿡�Դ� �ž��� ����� ���� �˴ϴ�. \n");
	Sleep(2000);
	printf("\n  [HOST] : ������ �����ϸ� �ߵ� ����� �Ұ��� �մϴ�.\n");
	Sleep(2000);
	pressEnter();
}


void manual_RLGL() {
	system("cls");
	Sleep(500);
	printf("\n\n  [HOST] : ù��° ������ ����ȭ ���� �Ǿ����ϴ� �Դϴ�.\n");
	Sleep(500);
	printf("\n  [HOST] : ������ ���� ���� \"����ȭ ���� �Ǿ����ϴ�\" ��ȣ�� ��Ĩ�ϴ�. \n");
	Sleep(500);
	printf("\n  [HOST] : ��ȣ�� ���� ���ÿ� ������ �ڸ� ���ƺ� ��  \n");
	Sleep(500);
	printf("\n  [HOST] : �����̴� ����� Ż���ϰ� �˴ϴ�.\n");
	Sleep(500);
	printf("\n  (��,��,��,�� ����Ű�� �̵��� �����ϴ�).\n");
	Sleep(2000);
	pressEnter();
}

void manual_TOW() {
	system("cls");
	Sleep(500);
	printf("\n\n  [HOST] : �ι�° ������ �ٴٸ��� �Դϴ�.\n");
	Sleep(500);
	printf("\n  [HOST] : �� ���� �� ���� ���� ��� ���� ���ϴ�. \n");
	Sleep(500);
	printf("\n  [HOST] : ���� ��� �κ��� �� ���� �������� ����ϰ� �Ǹ� �¸��մϴ�.  \n");
	Sleep(500);
	printf("\n  (���õ� �ܾ ��Ȯ�ϰ� �Է�����).\n");
	Sleep(2000);
	pressEnter();
}
void manual_GB() {
	system("cls");
	Sleep(500);
	printf("\n\n  [HOST] : ����° ������ ���� ¡�˴ٸ� �ǳʱ� �Դϴ�.\n");
	Sleep(500);
	printf("\n  [HOST] : ���� ¡�˴ٸ��� ��, �� �ΰ��� ���������� ���� �� �̾����ֽ��ϴ�. \n");
	Sleep(500);
	printf("\n  [HOST] : �� ������ �ϳ��� ��ԵǸ� �ٷ� �����ϴ�. \n");
	Sleep(500);
	printf("\n  [HOST] : ������ �ٸ��� �ǳʸ� �¸��մϴ�. \n");
	Sleep(500);
	printf("\n  (��,��,��,�� ����Ű�� �̵��� �����ϴ�).\n");
	Sleep(2000);
	pressEnter();
}
void manual_SG() {
	system("cls");
	Sleep(500);
	printf("\n\n  [HOST] : ������ ������ ��¡�� ��� �Դϴ�.\n");
	Sleep(500);
	printf("\n  [HOST] : ���� �� �����ڰ� �� �� ���� ������ ���ڸ� �����մϴ�. \n");
	Sleep(500);
	printf("\n  [HOST] : �� �����ڰ� �����ư��鼭 ���ڸ� �����մϴ�. \n");
	Sleep(500);
	printf("\n  [HOST] : ������ ���ڰ� ������ ���ڿ� �����ϴٸ� ��¡�� �������� ���ظ� �ݴϴ�. \n");
	Sleep(500);
	printf("\n  [HOST] : ��¡� ���̴� ������ ���� �����ڰ� �¸��մϴ�. \n");
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
	printf("\n       �����մϴ�! ����� ��¡�� ���ӿ��� �¸��ϼ̽��ϴ�. \n\n");
	Sleep(1500);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n\n\n              [Enter �� ���� 456����� �����ϼ���]");
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
	printf("\n                 ��Ÿ���Ե� ����� Ż���߽��ϴ�...  \n");
	Sleep(1500);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n\n\n              [Enter �� ������ ������ ����˴ϴ�]");
	while (getchar() != '\n') {}
	exit(0);
}
void result(int result) {
	if (result == 0) loser();
}




void print_title() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("                                                                           \n");
	printf("     �������   �������    ���      ���  ����  �������   \n");
	printf("    �������� ��������   ���      ���  ����  �������� \n");
	printf("    ���           ���      ���   ���      ���   ���   ���      ��� \n");
	printf("    ���           ���      ���   ���      ���   ���   ���      ��� \n");
	printf("    ���           ���      ���   ���      ���   ���   ���      ��� \n");
	printf("    �������� ���      ���   ���      ���   ���   ���      ��� \n");
	printf("    �������� ���      ���   ���      ���   ���   ���      ��� \n");
	printf("              ��� ���   ��� ��   ���      ���   ���   ���      ��� \n");
	printf("              ��� ���    ����   ���      ���   ���   ���      ��� \n");
	printf("              ��� ���     ���    ���      ���   ���   ���      ��� \n");
	printf("    �������� ������ ���   �������   ����  �������� \n");
	printf("     �������   ������ ���   ������    ����  �������   \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf("                            ��������������������������������������������    \n");
	printf("                            ��   Press Enter Key  ��                        \n");
	printf("                            ��������������������������������������������    \n");


	printf("    ��������    ��������   ���            ���   �������� \n");
	printf("  ���������  ���������� ���            ��� ��������� \n");
	printf("  ����            ����      ���� ����        ���� ���             \n");
	printf("  ����            ����      ���� ����        ���� ���             \n");
	printf("  ����            ����      ���� �����    ����� ���             \n");
	printf("  ����  �����  ����      ���� ����������� ��������� \n");
	printf("  ����  �����  ���������� ����������� ��������� \n");
	printf("  ����    ����  ���������� ���� ���� ���� ���             \n");
	printf("  ����      ���  ����      ���� ����  ���  ���� ���             \n");
	printf("  ����    ����  ����      ���� ����   ��   ���� ���             \n");
	printf("  ���������  ����      ���� ����        ���� ��������� \n");
	printf("    �������    ����      ���� ����        ����   �������� \n");
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