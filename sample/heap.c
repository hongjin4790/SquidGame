#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->size);

	while ((i != 1) && (item.priority > h->heap[i / 2].priority)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->size)--];
	parent = 1;
	child = 2;

	while (child <= h->size) {
		if ((child < h->size) && (h->heap[child].priority < h->heap[child + 1].priority)) {
			child++;
		}
		if (temp.priority >= h->heap[child].priority) {
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}