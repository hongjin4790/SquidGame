#include <stdio.h>
#include "queue.h"

void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(Queue* q) // 큐 초기화 함수 
{
    q->rear = -1;
    q->front = -1;
}

int is_full(Queue* q) // 큐 포화 
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(Queue* q) // 큐 공백 
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

void enqueue(Queue* q, int item) // 삽입함수 
{
    if (is_full(q)) {
        fprintf(stderr, "Full!\n");
        exit(1);
    }
    q->data[++(q->rear)] = item;
}

int dequeue(Queue* q) // 삭제함수 
{
    if (is_empty(q)) {
        fprintf(stderr, "Empty!\n");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}
element get_count(Queue* q) // 큐에 저장된 데이터 갯수를 반환하는 함수 
{
    int i, j, count = 0;
    if (is_empty(q)) {
        return count;
    }
    if (q->front <= q->rear)
        for (i = q->front + 1; i <= q->rear; i++)
            count++;
    else {
        for (i = q->front + 1; i < MAX_QUEUE_SIZE; i++)
            count++;
        for (j = 0; j <= q->rear; j++)

            count++;
    }
    return count;

}