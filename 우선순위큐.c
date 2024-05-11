#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996)

#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;  // 히프에 들어갈 노드

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;  // 배열로 구현한 히프

void insert_max_heap(HeapType* h, element item)  // 히프트리 삽입 함수
{
	int i;
	i = ++(h->heap_size);  // 마지막 노드에서 시작

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {  // 루트노드가 아니고 들어온 노드의 값이 부모 노드의 값보다 크면
		h->heap[i] = h->heap[i / 2]; // 부모노드를 자식노드로 끌어내림
		i /= 2;  // 위로 올라감
	}
	h->heap[i] = item;  // 노드 삽입
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];  // 루트 노드
	temp = h->heap[(h->heap_size)--];  // 마지막 노드
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {  // 마지막 노드 까지
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)  // child가 마지막 노드가 아니고, child의 값이 child의 다음 값보다 작으면
			child++;  // child 1 증가
		if (temp.key >= h->heap[child].key) break;  // 마지막 노드 값이 child 값보다 크거나 같으면 중단

		h->heap[parent] = h->heap[child];  // 자식 값을 부모 자리로 올리고
		child *= 2;  // 자식은 하나 내려옴
	}
	h->heap[parent] = temp;
	return item;  // 첫번째 값을 반환
}

// 히프 생성
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// 히프 초기화
void init(HeapType* h)
{
	h->heap_size = 0;
}

// 테스트
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