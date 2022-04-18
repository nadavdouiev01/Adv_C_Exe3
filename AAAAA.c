#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 30
typedef struct Node {
	char data;
	struct Node* next;
} Node;

typedef struct Stack {
	Node* head;
}Stack;
int size = 0; //���� ������� 
int SizeW(Stack* s);
void printStack(Stack* s);
void rotate(Stack* s, int n);
int isPlindrom(Stack s);
void flipBetweenHashes(char* sentence);
void initStack(Stack* s);
void destroyStack(Stack* s);
void push(Stack* s, char data);
char pop(Stack* s);
int isEmpty2(Stack s);

void main() {

	int a, b, c;
	char d, f, g;
	char* r[] = { "MY#EMAN#ISNADAV" };
	Stack* stack1 = (Stack*)malloc(sizeof(Stack));//����� �������
	initStack(stack1);
	if (!stack1) {
		printf("THE MALLOC NOT SECXEED");
	}

	printf("what you want to do ? \n");
	printf("1 -> push \n");
	printf("2 -> pop \n");
	printf("3 -> empty check \n");
	printf("4 -> pilndrom check \n");
	printf("5 -> make a flip \n");
	printf("6 -> rotate \n");
	printf("7 -> exit \n");

	while (1) {
		printf("enter the number of your choice\n");
		scanf_s("%d",&a);
		switch (a) {
		case 1: // �� ���� 1 ������ ����� �������
			printf("enter data into  the stack: \n");
			scanf_s(" %c",&d);
			push(stack1,d);
			break;
		case 2: // �� ���� 2 ����� ����� �������� 
			if (stack1->head == NULL) {
				printf("stack => EMPTY\n");
				break;
			}
			d = pop(stack1);
			if (stack1->head == NULL) {
				printf("%c <=> stack empty\n",d);
				break;
			}
			else {
				printf("data top => %c\n", d);
				break;
			}
		case 3:// ����� ��� ������� ����
			c = isEmpty2(*stack1);
			if (c == 1) {
				printf("*******the list empty*****");
				break;
			}
			else printf("full\n");
			break;
		case 4:     // �� ���� 4 ���� ����� ��� �������
			c = isPlindrom(*stack1);
			if (c == 1) {
				printf("its A polindrom\n");
				break;
			}
			else printf("its not polindrom\n");
			break;
		case 5: // �� ���� 5 ���� ���� ����� ��� ������
		      flipBetweenHashes(r);
			break;
		case 6:	//�� ���� 6 ���� ��  ������� ���� ��� ������
 
			if (!isEmpty2(*stack1)) {
				printf("\n stack is EMPTY!\n");
				break;
			}
			printf("how many Node do you want to rotate? \n");
			scanf("%d",&a);
			rotate(stack1,a);
			printStack(stack1); //�����
			break;
		case 7:
			exit (0); //���� 7 ����� 

		}




	}

}

void printStack(Stack* s) //�������� �����
{
	printf("Stack = \n");
	Node* ptr = s->head;
	while (ptr != NULL)
	{
		printf("The element is %c\n", ptr->data);
		ptr = ptr->next;
	}
}
void push(Stack* s, char data) { //����� ����� ������� 
	if (size >= SIZE) //�� �� ���� ���� ������ �������
	{
		printf("######## Stack have an overflow ########\n");
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node)); 
	newNode->data = data;                                  // ����� �� ����� 
	newNode->next = s->head;
	s->head = newNode;
	size++;
	
}





char pop(Stack* s) { //���� ����� ��������
	char data;
	Node* y = s->head;
	data = y->data;

	if (s->head == NULL) { //�� ������� ���� 
		printf("the stack is EMPTY \n");
		return data;
	}
	else if (size == 1) { //�� ���� �� ���� 1 �������
		size--;
		s->head = NULL;
		return data;
	}
	else {
		s->head = s->head->next;// ��������� ���� ���� ����� 1 
		size--;  //��� ������ ��� ����� ��� ��� 
		free(y);
		return data;
	}
}


int isEmpty2(Stack s) { //����� ��� ������� ���� �� ����
	if (s.head == NULL)
		return 0;
	else return 1;
}


void initStack(Stack* s) //����� 
{
	s->head = NULL;
}




void destroyStack(Stack* s) {   //����� ������
	Node* h = s->head;
	while (s->head->next != NULL) {
		free(h->data);
		free(h);
		s->head = s->head->next;
	}
}

void flipBetweenHashes(char* sentence) { 

	char newStr[SIZE] = " ";
	char* thechar = sentence;
	int i = 0;
	Stack* newStack = (Stack*)malloc(sizeof(Stack));//����� �������
	while (thechar != '\0')//���� �����
	{
		while (*thechar != '#')//�� ��� �� # ���� �� ������� �����
		{
			newStr[i] = *thechar;
			thechar++;
			i++;
			if (*thechar == '\0') {
				newStr[i] = '\0';
				printf("%s", newStr);
			}
		}
		while (*thechar == '#') //�� ��� ������ ���� �� ������� �����
		{
			thechar++;
			while (*thechar != '#')//�� ����� ��� �� # �����
			{
				if (*thechar == '\0') {
					printf("%s", newStr);
				}
				push(newStack, *thechar);
				thechar++;
			}
			thechar++;
		}
		while (!isEmpty2(*newStack))
		{
			newStr[i] = pop(newStack);
			i++;
		}
	}
	
	newStr[i] = '\0';
	printf("%s", newStack);
}

int isPlindrom(Stack s) {//����� ��� ���������
	Stack thenews;
	thenews = s;
	int halfStack;
	char chA, chB;
	Stack* s12 = (Stack*)malloc(sizeof(Stack));
	if (!s12) {
		printf("ERROR\n");
		exit(1);
	}
	s12->head = NULL;
	halfStack = size / 2;
	for (int y = 0; y < halfStack; y++)
	{
		push(s12, pop(&thenews));
	}
	if (size % 2) {
		char n = pop(&thenews);//
	}
	while (isEmpty2(*s12))//��� S12 ����?
	{
		chA = pop(s12);       //����� �� ����� ������ � S12 
		chB = pop(&thenews); // ����� �� ����� ������ �thenews
		if (chA != chB) { //���� ��� �� ����� �� �� ����� 0 ����� ������� �� �������� 
			return 0;
		}
		else return 1;// ���� ����� 1 ������� ������ ���������
	}
}
int SizeW(Stack* s) //������� ������� �� ���� ������� ������ ���� 
{
	int cnt = 0;
	Node* ptr = s->head;
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


void rotate(Stack* s, int n) { //�������  ����� �� ���� ������� ����� ������ ������� ������� ���� ����

	Stack* yuyu = (Stack*)malloc(sizeof(Stack));
	yuyu->head = NULL;
	Stack* yuyu2 = (Stack*)malloc(sizeof(Stack));
		yuyu2->head = NULL;


		int u = SizeW(s);
		for (int h = 0; h < (u - n); h++)  //    
		{
			push(yuyu,pop(s));
		}
		for (int k = 0; k < n; k++) {
			push(yuyu2,pop(s));
		}
		for(int a = 0;a<n;a++)
		{
			push(yuyu, pop(yuyu2));
		}
		s->head = yuyu->head;
		printStack(yuyu);
	}

