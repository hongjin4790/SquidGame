#pragma once
#define MAX_SIZE 20
#define XPOS 20
#define YPOS 1
#define LEFT 75
#define RIGHT 77
#define MAX_QUEUE_SIZE 100

typedef int element; // 큐 구조체 
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} Queue;

void error(char* message);
void init_queue(Queue* q); // 큐 초기화 함수 
int is_full(Queue* q); // 큐 포화 
int is_empty(Queue* q); // 큐 공백 
void enqueue(Queue* q, int item); // 삽입함수 
int dequeue(Queue* q);// 삭제함수 
element get_count(Queue* q); // 큐에 저장된 데이터 갯수를 반환하는 함수 