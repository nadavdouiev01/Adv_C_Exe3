#define _CRT_SECURE_NO_WARNINGS
#define MAXI 30
#define SIZE 10
#include<stdio.h>
#include<stdlib.h>

typedef struct intNode
{
	unsigned int data;
	struct intNode* next;
}intNode;

typedef struct Queue
{
	intNode* head;
	intNode* tail;
}Queue;
void sort(Queue* q);
void cutAndReplace(Queue* q);
void initQueue(Queue* q);
void destroyQueue(Queue* q);
void enqueue(Queue* q, unsigned int data);
int isEmpty2(Queue* q);
unsigned int dequeue(Queue* q);
void rotateQueue(Queue* q);
int SizeW(Queue* q);
void printQueue(Queue* q);



void main()
{
	Queue* Queuemain = (Queue*)malloc(sizeof(Queue));
	if (!Queuemain) {
		printf("ERROR\n");
		exit(1);
	}
	initQueue(Queuemain);
	int ch;
	int dataD;
	int	dataE;
	printf("what do you want to do ?\n");
	printf("1.enqueue\n");
	printf("2.dequeue\n");
	printf("3.empty?\n");
	printf("4.use rotateQueue? \n");
	printf("5.cutAndReplace\n");
	printf("6.sort \n");
	printf("7.EXIT \n");

	while (1)
	{
		printf("what your choice \n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("what data do you want to enter queue? \n");
			scanf("%d", &dataE);
			enqueue(Queuemain, dataE);
			break;
		case 2:
			if (isEmpty2(Queuemain)) {
				printf("queue IS EMPTY! \n");
				break;
			}
			dataD = dequeue(Queuemain);
			printf("the data that out of the queue %d \n",
				dataD);
			break;

		case 3:
			if (isEmpty2(Queuemain))
			{
				printf("IS EMPTY! \n");
				break;
			}
			else
			{
				printf("IS NOT EMPTY! \n");
			}
			break;
		case 4:
			if (isEmpty2(Queuemain)) {
				printf("IS EMPTY! \n");
				break;
			}
			rotateQueue(Queuemain);
			printf("Done\n");
			break;
		case 5:
			if (isEmpty2(Queuemain)) {
				printf("IS EMPTY! \n");
				break;
			}
			else
			{
				cutAndReplace(Queuemain);
			}
			printf("done\n");
			break;
		case 6:
			if (isEmpty2(Queuemain)) {
				printf("IS EMPTY! \n");
				break;
			}
			else
			{
				sort(Queuemain);
			}
			printf("done\n");
			break;
		case 7:
			exit(0);
		}
	}
	return;
}

void printQueue(Queue* q)
{
	printf("Queue => : \n");//פונקצית הדפסה 
	intNode* ptr = q->head;
	while (ptr != NULL)
	{
		printf("The element is %d\n", ptr->data);
		ptr = ptr->next;
	}
}

int SizeW(Queue* q)
{
	int cnt = 0;
	intNode* startQ = q->head;
	intNode* ptr = q->head;
	if (!ptr) {
		printf("ERROR\n");
		exit(1);
	}

	while (ptr != NULL)
	{

		ptr = ptr->next;
		cnt++;
	}
	return cnt;
}


int isEmpty2(Queue* q)
{
	if (q->head == NULL)
	{
		return 1;
	}
	return 0;
}

void initQueue(Queue* q)//אתחול
{
	q->head = NULL;
	q->tail = NULL;
}
void destroyQueue(Queue* q) {//השחרור זכרון בתור 
	Queue* b;
	b = q;
	if (b->head != b->tail) {
		free(b->head->data);
		free(b->head);
		b->head = b->head->next;
	}
}



void enqueue(Queue* q, unsigned int data)//הוספת איבר לתור
{
	intNode* t = (intNode*)malloc(sizeof(intNode));
	if (t == NULL) {
		printf("ERROR\n");
		exit(0);
	}
	t->data = data;
	t->next = NULL;
	if (!isEmpty2(q)) {
		q->tail->next = t;
	}
	else
		q->head = t;
	q->tail = t;
}


unsigned int dequeue(Queue* q) { //החסרת איבר מהתור
	intNode* g = (intNode*)calloc(1, sizeof(intNode));
	unsigned int y;
	if (isEmpty2(q))//בודק האם ריק 
	{
		printf("queue is empty\n");
		return 0;
	}

	y = q->head->data;
	g = q->head;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(g);
	return y;
}


void rotateQueue(Queue* q) {//הפונקציה מעבירה את האחרון בתור לתחילת התור
	Queue* r1 = (Queue*)malloc(sizeof(Queue));
	int num;
	if (!r1) {
		printf("error\n");
	}
	num = SizeW(q);
	if (num == 2) {
		int element = dequeue(q);
		enqueue(q, element);
	}

	for (int h = 0; h < num; h++)//הוספה לתור מהתחלה לסוף
	{
		enqueue(q, dequeue(q));
	}
	printQueue(q);
}



void cutAndReplace(Queue* q) {

	int e = SizeW(q);//גודל התור
	Queue* qnew = (Queue*)malloc(sizeof(Queue));
	if (!qnew) {
		printf("ERROR\n");
		exit(1);
	}
	int half = e / 2; //חצי מגודל התור
	int avg = 0;
	int sum = 0;
	int	tmp;

	initQueue(qnew);//מאתחל 

	intNode* ptr = q->head;
	while (ptr != NULL) //לולאה הסוכמת את ערכים כל האיברים 
	{
		sum += ptr->data;
		ptr = ptr->next;
	}
	int u = sum / e;// מחלקת סכום בבמספר האיברים
	enqueue(q, u);//מוסיף אותו בסוף הרשימה 

	for (int i = 0; i < half; i++)//מעביר את החצי ערכים הראשונים לסוף התור 
	{
		tmp = dequeue(q);
		enqueue(qnew, tmp);
	}
	rotateQueue(q);// מעבירה את האחרון בתור לתחילת התור 

	while (!isEmpty2(qnew))
	{
		if (!isEmpty2(qnew)) {
			enqueue(q, dequeue(qnew));
		}
	}
	printQueue(q);
}


void sort(Queue* q)//פונקציה הממינת את המספרים מהראש לזנב
{
	if (isEmpty2(q))
		return;
	int A = MAXI;
	int B = MAXI;
	int n = SizeW(q);
	for (int i = 0; i < n; i++)//צמד לולאות פור לבדיקה של מה גדול ממה והכנסתם לתור לפי הסדר הדרוש
	{
		A = dequeue(q);
		for (int j = 0; j < (n - 1); j++)
		{
			B = dequeue(q);
			if (A < B)
			{
				enqueue(q, B);
			}
			else
			{
				enqueue(q, A);
				A = B;
			}
		}
		enqueue(q, A);
	}
	rotateQueue(q);//העברת האיבר האחרון לראש התור 
}