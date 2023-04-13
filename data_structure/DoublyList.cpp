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

T max(List *list) {
	Node* p = list->head->ne;
	T max_val = p->val;
	while (p) {
		if (p->val > max_val) max_val = p->val;
		p = p->ne;
	}
	return max_val;
}

T min(List *list) {
	Node* p = list->head->ne;
	T min_val = p->val;
	while (p) {
		if (p->val < min_val) min_val = p->val;
		p = p->ne;
	}
	return min_val;
}

T sum(List *list) {
	Node* p = list->head->ne;
	T sum_val = 0;
	while (p) {
		sum_val += p->val;
		p = p->ne;
	}
	return sum_val;
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

int main() {
	List *list = newList();
	readList(list);
	// printList(list);
	// rprintList(list);
}