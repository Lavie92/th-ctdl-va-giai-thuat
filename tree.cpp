#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//dinh nghia lai kieu int -> dataType
typedef int dataType;

//Khai bao struct node
struct node {
	dataType info;
	node *pLeft;
	node *pRight;
};

//khoi tao 1 tree
void init(node *&t) {
	t = NULL;	
}

//kiem tra tree rong?
int isEmpty(node *t) {
	return (t == NULL);
}

//khoi tao 1 node
node *createNode(dataType x) {
	node *p;
	p = new node();
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

//show 1 node
void show(dataType x) {
	printf("\t%d", x);
}

//hien thi cay theo thu tu truoc
void preOrder(node *t) {
	if (isEmpty(t)) {
		return;
	}
	show(t->info);
	preOrder(t->pLeft);
	preOrder(t->pRight);
}


//xoa toan bo cay
void clearTree(node *&t) {
	if (isEmpty(t)) {
		return;
	}
	clearTree(t->pLeft);
	clearTree(t->pRight);
	delete t;
}

//chen 1 node vao cay
void insert(node *&t, dataType x) {
	if (isEmpty(t)) {
		t = createNode(x); 
	}
	else {
	if (t->info < x) {
		insert(t->pRight, x);
	}
	else if (t->info > x) {
		insert(t->pLeft, x);
		}
	}
}

void menu(node *&t) {
	while (true) {
		printf("\t\t\n\n=============MENU======================");
		printf("\n0: Thoat!");
		printf("\n1: Them 1 node vao cay");
		printf("\n2: Hien thi cay theo thu tu truoc");
		printf("\n\n\t\t=======================================\n\n");
		printf("\nMoi ban chon chuc nang: ");
		int chon;
		scanf("%d", &chon);		
		if (chon < 0 || chon > 9) {
			printf("\nKhong co chuc nang nay!!");
		}
		switch (chon) {
			case 0:
				return;
			case 1: 
				dataType x;
				printf("Nhap gia tri can chen: ");
				scanf("%d", &x);
				insert(t, x);
				break;
			case 2: 
				printf("\nThu tu truoc: ");
				preOrder(t);
				break;
		}
	}
}

int main () {
	node *t;      
	init(t); 
	insert(t, 34);
	insert(t, 17);
	insert(t, 66);
	insert(t, 50);
	insert(t, 71);
	insert(t, 68);
	insert(t, 94);
	insert(t, 25);
	menu(t);
	return 0;
}