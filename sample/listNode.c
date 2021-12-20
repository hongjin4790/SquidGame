#include <stdio.h> 
#include <stdlib.h>
#include "listNode.h"

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; // 헤드 포인터의 값을 복사
	head = p; // 헤드 포인터 변경
	return head;
}

int search_list(ListNode* head, element x) {
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == x)
			return p->data;
		p = p->link;
	}

	return 0; // 탐색 실패 
}

void print_list(ListNode* head) {
	setcolor(7);
	gotoxy_l(20, MapHeight);
	printf("생존 [");
	gotoxy_l(26, MapHeight);
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == 13) {
			printf("주인공 ");
		}
		else if (p->data == 3) {
			printf("1번 ");
		}
		else if (p->data == 6) {
			printf("2번 ");
		}
		else if (p->data == 9) {
			printf("3번 ");
		}
		else if (p->data == 17) {
			printf("4번 ");
		}
		else if (p->data == 20) {
			printf("5번 ");
		}
		else if (p->data == 23) {
			printf("6번 ");
		}
		else {
			printf("  ");
		}
	}
	printf(" ]         ");
}

ListNode* delete_node_l(ListNode* head, element value) {
	ListNode* pre = NULL;

	for (ListNode* p = head; p != NULL; pre = p, p = p->link) {
		if (p->data == value) {
			if (p == head) {
				ListNode* removed = head;
				head = head->link;
				free(removed);
			}
			else {
				pre->link = p->link;
				free(p);
				p = pre;
			}
		}
	}
	return head;
}
