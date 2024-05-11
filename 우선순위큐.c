#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996)

#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;  // ������ �� ���

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;  // �迭�� ������ ����

void insert_max_heap(HeapType* h, element item)  // ����Ʈ�� ���� �Լ�
{
	int i;
	i = ++(h->heap_size);  // ������ ��忡�� ����

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {  // ��Ʈ��尡 �ƴϰ� ���� ����� ���� �θ� ����� ������ ũ��
		h->heap[i] = h->heap[i / 2]; // �θ��带 �ڽĳ��� �����
		i /= 2;  // ���� �ö�
	}
	h->heap[i] = item;  // ��� ����
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];  // ��Ʈ ���
	temp = h->heap[(h->heap_size)--];  // ������ ���
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {  // ������ ��� ����
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)  // child�� ������ ��尡 �ƴϰ�, child�� ���� child�� ���� ������ ������
			child++;  // child 1 ����
		if (temp.key >= h->heap[child].key) break;  // ������ ��� ���� child ������ ũ�ų� ������ �ߴ�

		h->heap[parent] = h->heap[child];  // �ڽ� ���� �θ� �ڸ��� �ø���
		child *= 2;  // �ڽ��� �ϳ� ������
	}
	h->heap[parent] = temp;
	return item;  // ù��° ���� ��ȯ
}

// ���� ����
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// ���� �ʱ�ȭ
void init(HeapType* h)
{
	h->heap_size = 0;
}

// �׽�Ʈ
int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	e4 = delete_max_heap(heap);
	printf("< %d > \n", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > \n", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > \n", e6.key);

	free(heap);
	return 0;
}