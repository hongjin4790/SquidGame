#include <stdio.h> 
#include <stdlib.h>
#include "listNode.h"

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; // ��� �������� ���� ����
	head = p; // ��� ������ ����
	return head;
}

int search_list(ListNode* head, element x) {
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == x)
			return p->data;
		p = p->link;
	}

	return 0; // Ž�� ���� 
}

void print_list(ListNode* head) {
	setcolor(7);
	gotoxy_l(20, MapHeight);
	printf("���� [");
	gotoxy_l(26, MapHeight);
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == 13) {
			printf("���ΰ� ");
		}
		else if (p->data == 3) {
			printf("1�� ");
		}
		else if (p->data == 6) {
			printf("2�� ");
		}
		else if (p->data == 9) {
			printf("3�� ");
		}
		else if (p->data == 17) {
			printf("4�� ");
		}
		else if (p->data == 20) {
			printf("5�� ");
		}
		else if (p->data == 23) {
			printf("6�� ");
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
