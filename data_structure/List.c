#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef int T;
typedef struct Node {
	T val;
	struct Node* ne;
} Node;

Node* newNode(T val, Node* ne) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (!node) return NULL;
	node->val = val;
	node->ne = ne;
	return node;
}

typedef struct List {
	Node* head;
	Node* tail;
	int len;
} List;

List* newList() {
	List* list=  (List*)malloc(sizeof(List));
	if (!list) return NULL;
	list->head = newNode(0, NULL);
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

void push_forward(List *list, T val) {
	Node* tmp = list->head->ne;
	Node* node = newNode(val, tmp);
	list->head->ne = node;
	if (!list->tail) list->tail = node;
	list->len ++;
}

void push_back(List *list, T val) {
	if (!list->tail) {
		push_forward(list, val);
	} else {
		Node* node = newNode(val, NULL);
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
	Node* node = newNode(val, tmp);
	p->ne = node;
	list->len ++;
}

void erase(List *list, int K) {
	if (K >= list->len) return;
	Node* p = list->head;
	while (K --) p = p->ne;
	p->ne = p->ne->ne;
}

void eraseNode(List* list, Node *node) {
	node->ne = node->ne->ne;
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
		if (flag) return 1;
		p = p->ne;
	}
	return 0;
}

void swap(Node *p) {
	Node *a = p->ne, *b = p->ne->ne;
	a->ne = b->ne;
	b->ne = a;
	p->ne = b;
}

void sort(List *list) {
	int n = list->len;
	Node *p = list->head;
	for (int i = 0; i < n - 1; i ++) {
		Node *cur = p;
		for (int j = 0; j < n - i - 1; j ++) {
			if (cur->ne->val > cur->ne->ne->val) {
				swap(cur);
			}
			cur = cur->ne;
		}
	}
}

void freeList(List *list) {
	Node *p = list->head->ne;
	while (p) {
		Node *q = p->ne;
		free(p);
		p = q;
	}
	list->head->ne = NULL;
}



int main() {
	List *list1 = newList(), *list2 = newList();
	readList(list1);
	readList(list2);
	printf("%s\n", cmp(list1, list2) ? "yes" : "no");
	freeList(list1);
	freeList(list2);
}