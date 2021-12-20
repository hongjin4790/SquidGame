#define MAX_WORD_SIZE 50
#define MAX_ELEMENT 130
#pragma warning(disable : 4996)


typedef struct {
	int priority;
	char word[MAX_WORD_SIZE];
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int size;
} HeapType;

HeapType* create();
void init(HeapType* h);
void insert_max_heap(HeapType* h, element item);
element delete_max_heap(HeapType* h);