#include <stdio.h>
#define MAX 100

struct soKham {
	int stt;
	char ten[30];
	char diaChi[50];
	int namSinh;
};

template <class T>
struct queue{
	T a[MAX];
	int num;
	int front;
	int rear;
};

template <class T>
void init(queue<T> &q) {
	q.front = 0;
	q.rear = -1;
	q.num = 0;
}
template <class T>
int isFull(queue<T> q) {
	return (q.num == MAX);
}

template <class T>
int isEmpty(queue<T> q) {
	return (q.num == 0);
}

template <class T>
int enQueue(queue<T> &q, T x) {
	if (isFull(q)) {
		return 0;
	}
	q.rear++;
	q.rear = q.rear % MAX;
	q.a[q.rear] = x;
	q.num++;
	return 1;
}

template <class T>
int deQueue(queue<T> &q, T &x) {
	if (isEmpty(q)) {
		return 0;
	}
	x = q.a[q.front];
	q.front++;
	q.num--;
	if (isEmpty(q)) {
		init(q);
	}
	return 1;
}
template <class T>
int clear(queue<T> &q) {
	init(q);
	return 1;
}

template <class T> 
void queueFirst(queue<T> q, T &x) {
	if (isEmpty(q)) {
		return;
	}
	x = q.a[q.front];
}

template <class T> 
void queueLast(queue<T> q, T &x) {
	if (isEmpty(q)) {
		return;
	}
	x = q.a[q.rear];
}
template <class T> 
int queueSize(queue<T> q) {
	return q.num;
}

void nhap1BenhNhan(soKham &a) {
	do {
		printf("\nSo thu tu: ");
		scanf("%d", &a.stt);
	} while (a.stt <= 0);
	fflush(stdin);
	printf("Ten: ");
	gets(a.ten);
	printf("Dia chi: ");
	gets(a.diaChi);
	printf("Nam sinh: ");
	scanf("%d", &a.namSinh);
}

//xuat thong tin cua 1 benh nhan
void xuat1BenhNhan(soKham a) {
	printf("%-4d %-30s %-50s %-4d\n", a.stt, a.ten, a.diaChi, a.namSinh);
}

void menu() {
	printf("\n1: Thoat!");
	printf("\n2: Them benh nhan can kham!");
	printf("\n3: Hien thi thong tin nguoi kham tiep theo");
	printf("\n4: Cho biet so nguoi chua kham");
	printf("\n5: Cho biet so nguoi da kham\n");
	printf("\nMoi ban chon chuc nang: ");
}


int main () {
	queue<soKham> q;
	init(q);
	int chon, daKham = 0;;
	soKham x;
	do {
		menu();
		scanf("%d", &chon);
		switch (chon) {
			case 1: 
				return 0;
				break;
			case 2:
				printf("\nNhap thong tin benh nhan can them: \n");
				nhap1BenhNhan(x);
				enQueue(q, x);
				break;
			case 3: 
				deQueue(q, x);
				xuat1BenhNhan(x);
				daKham++;
				break;
			case 4:
				printf("\nSo nguoi chua kham: %d", queueSize(q));
				break;
			case 5: 
				printf("\nSo nguoi da kham: %d", daKham);
				break;
			default:
				printf("Vui long chon 1 -> 5");
		}		
	} while (true);	
	return 0;
}