#include <stdio.h>
#include "queue.h"

void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(Queue* q) // ť �ʱ�ȭ �Լ� 
{
    q->rear = -1;
    q->front = -1;
}

int is_full(Queue* q) // ť ��ȭ 
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(Queue* q) // ť ���� 
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

void enqueue(Queue* q, int item) // �����Լ� 
{
    if (is_full(q)) {
        fprintf(stderr, "Full!\n");
        exit(1);
    }
    q->data[++(q->rear)] = item;
}

int dequeue(Queue* q) // �����Լ� 
{
    if (is_empty(q)) {
        fprintf(stderr, "Empty!\n");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}
element get_count(Queue* q) // ť�� ����� ������ ������ ��ȯ�ϴ� �Լ� 
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