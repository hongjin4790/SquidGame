#pragma once
#define MAX_SIZE 20
#define XPOS 20
#define YPOS 1
#define LEFT 75
#define RIGHT 77
#define MAX_QUEUE_SIZE 100

typedef int element; // ť ����ü 
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} Queue;

void error(char* message);
void init_queue(Queue* q); // ť �ʱ�ȭ �Լ� 
int is_full(Queue* q); // ť ��ȭ 
int is_empty(Queue* q); // ť ���� 
void enqueue(Queue* q, int item); // �����Լ� 
int dequeue(Queue* q);// �����Լ� 
element get_count(Queue* q); // ť�� ����� ������ ������ ��ȯ�ϴ� �Լ� 