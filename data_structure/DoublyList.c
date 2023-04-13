#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef int T;
typedef struct Node {
	T val;
	struct Node* ne;
	struct Node* pr;
} Node;

Node* newNode(T val, Node* ne, Node* pr) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (!node) return NULL;
	node->val = val;
	node->ne = ne;
	node->pr = pr;
	return node;
}

typedef struct DoublyList {
	Node* head;
	Node* tail;
	int len;
} List;

List* newList() {
	List* list = (List*)malloc(sizeof(List));
	if (!list) return NULL;
	list->head = newNode(0, NULL, NULL);
	list->tail = NULL;
	list->len = 0;
	return list;
}

void printList(List *list) {
	Node *p = list->head->ne;
	while (p) {
		printf("%d ", p->val);
		p = p->ne;
	}
	printf("\n");
}

void rprintList(List *list) {
	Node *p = list->tail;
	while (p != list->head) {
		printf("%d ", p->val);
		p = p->pr;
	}
	printf("\n");
}

void push_forward(List *list, T val) {
	Node* tmp = list->head->ne;
	Node* node = newNode(val, tmp, list->head);
	if (tmp) tmp->pr = node;
	list->head->ne = node;
	if (!list->tail) list->tail = node;
	list->len ++;
}

void push_back(List *list, T val) {
	if (!list->tail) {
		push_forward(list, val);
	} else {
		Node* node = newNode(val, NULL, list->tail);
		list->tail->ne = node;
		list->tail = node;
		list->len ++;
	}
}

void insert(List *list, int K, T val) {
	if (K >= list->len) return;
	Node* p = list->head;
	while (K --) p = p->ne;
	Node* tmp = p->ne;
	Node* node = newNode(val, tmp, NULL);
	p->ne = node;
	list->len ++;
}

void erase(List *list, int K) {
	if (K >= list->len) return;
	Node* p = list->head;
	while (K --) p = p->ne;
	free(p->ne);
	p->ne = p->ne->ne;
}

void eraseNode(List* list, Node *node) {
	node->ne->pr = node->pr;
	node->pr->ne = node->ne;
	free(node);
	list->len --;
}

void readList(List *list) {
	T n;
	while (scanf("%d", &n), ~n) {
		push_back(list, n);
	}
}

T getMax(List *list) {
	Node* p = list->head->ne;
	T max = p->val;
	while (p) {
		if (p->val > max) max = p->val;
		p = p->ne;
	}
	return max;
}

T getMin(List *list) {
	Node* p = list->head->ne;
	T min = p->val;
	while (p) {
		if (p->val < min) min = p->val;
		p = p->ne;
	}
	return min;
}

T getSum(List *list) {
	Node* p = list->head->ne;
	T sum = 0;
	while (p) {
		sum += p->val;
		p = p->ne;
	}
	return sum;
}


int cmp(List *list1, List *list2) {
	Node *p = list1->head->ne;
	while (p) {
		Node *p1 = p;
		Node *p2 = list2->head->ne;
		int flag = 1;
		while (p1 && p2) {
			if (p1->val != p2->val) {
				flag = 0;
				break;
			}
			p1 = p1->ne;
			p2 = p2->ne;
		}
		if (!p2 && flag) return 1;
		p = p->ne;
	}
	return 0;
}

void swapNode(List* list, Node *a, Node *b) {
	Node *pa = a->pr, *nb = b->ne;
	if (pa) pa->ne = b;
	b->ne = a;
	b->pr = pa;
	a->ne = nb;
	a->pr = b;
	if (nb) nb->pr = a;
	if (b == list->tail) list->tail = a;
}

void sort(List *list) {
	Node* p = list->head;
	for (int i = 0; i < list->len - 1; i ++) {
		Node* q = p->ne;
		for (int j = 0; q->ne && j < list->len - i - 1; j ++) {
			if (q->val > q->ne->val) {
				swapNode(list, q, q->ne);
			} else {
				q = q->ne;
			}
		}
	}
}

void swapList(List *list, int l1, int r1, int l2, int r2) {
	Node *p = list->head->ne;
	Node *p1 = p, *p2 = p, *p3 = p, *p4 = p;
	while (-- l1) p1 = p1->ne;
	while (-- r1) p2 = p2->ne;
	while (-- l2) p3 = p3->ne;
	while (-- r2) p4 = p4->ne;
	Node *tmp;
	
	tmp = p1->pr->ne;
	if (tmp) p1->pr->ne = p3->pr->ne;
	if (p3->pr->ne) p3->pr->ne = tmp;
	
	tmp = p1->pr;
	if (tmp) p1->pr = p3->pr;
	if (p3->pr) p3->pr = tmp;
	
	tmp = p2->ne->pr;
	if (tmp) p2->ne->pr = p4->ne->pr;
	if (p4->ne->pr) p4->ne->pr = tmp;
	
	tmp = p2->ne;
	if (tmp) p2->ne = p4->ne;
	if (p4->ne) p4->ne = tmp;
}