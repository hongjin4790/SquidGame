#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define MapWidth 60
#define MapHeight 29
#define _CRT_SECURE_NO_WARNINGS   // strcat 보안 경고로 인한 컴파일 에러 방지
#pragma warning(disable : 4996)

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
typedef struct coordinate {
	int x;
	int y;
	int checkBullet;
}coordinate;

typedef int element;
typedef struct ListNode { //노드 타입
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value);
int search_list(ListNode* head, element x);
void print_list(ListNode* head);
ListNode* delete_node_l(ListNode* head, element value);