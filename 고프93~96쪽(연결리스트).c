#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma pack(push,1) 
typedef struct t_rec {int id; char name[16]; double ave; int game; struct t_rec *next;
} Student;
#pragma pack(pop)

static/*일단 보류,,,*/ Student *head = NULL;

void ShowList(); // 연결리스트 모두 출력 
void Append(int i, char *s, double a, int g); // 연결리스트 맨 끝에 새로울 리스트 추가하기 
Student *FindList(char *s); // name을 알 때 name이 들어있는 리스트를 찾는 함수 
int *FindId(char *s); // name을 알 때 name의 id를 찾는 함수
void Insert(char *exist/*삽입 하고 싶은 곳의 전 리스트 name*/, int i, char *s, double a, int g); // 연결리스트 중간에 새로운 리스트 삽입
void FindLast(); // 마지막 리스트에서 name을 출력 
void FreeAll(); // 모든 연결리스트를 free한다 


int main_linkedlist5(void) {
	Student *m;
	Append(1, "TimDuncon", 0.986, 98);
	Append(4, "ToyParker", 0.567, 43);
	Append(3, "ManuGinobili", 0.876, 43); 
	Append(8, "DemarDrozen", 0.365, 89); 
	Append(5, "BrynFores", 0.333, 38);
	Append(7, "MarcoBelinelli", 0.756, 67);	
	ShowList();
	
	// FinList와 FindId 출력 
	printf("sd");
	m = FindList("ToyParker");
	printf("ToyParker의 node값은 %d", m);
	int *a;
	a = FindId("ToyParker");
	printf("ToyParker의 id값은 %d", a);
	printf("%4d %16s %4.3f %4d\n", m->id, m->name, m->ave, m->game);
	
	
	// 삽입 
	Insert("DemarDrozen", 11, "JakobPoeltl", 0.333, 55);
	Insert("BrynFores", 22, "DejonteMurray", 0.777, 66);
	ShowList();
	
	
	/*// Practice 1) 가장 큰 avg를 가진 포인터 값을 출력 
	Student *s, *f;
	double d = -100;
	s = head;
	while(s != NULL) {
		if(s->ave > d) {
			d = s->ave;
			f = s;
		}
		s = s->next;
	}
	printf("\n\n 가장 큰 ave는 %2f \n가장 큰 ave의 node는 %d", d, f);*/
	
	FreeAll();
	getchar();
	
	
}

Student *FindList(char *s) {
	Student *p;
	p = head;
	while(p != NULL) {
		if(! strcmp(p->name,s))
			return p;
		p = p->next;
	}
	return NULL;
}

int *FindId(char *s) {
	Student *p;
	p = head;
	while(p != NULL) {
		if(! strcmp(p->name,s))
			return &(p->id);
		p = p->next;
	} 
	return NULL;
}

void Insert(char *exist/*삽입 하고 싶은 곳의 전 리스트 name*/, int i, char *s, double a, int g) {
	Student *p, *q; 
	p = FindList(exist);
	if(p != NULL) {
		q = p->next;
		p->next = (Student *) malloc(sizeof(Student));
		p = p->next;
		p->id = i; strcpy(p->name,s); p->ave = a; p->game = g;
		p->next = q;
	}
	else Append(i,s,a,g);
}

void FindLast() {
	Student *p;
	p = head;
	if(p==NULL)
		return;
	while(p != NULL) 
		p = p->next;
	printf("%s", p->name);
}

void FreeAll() {
	Student *p, *q;
	p = head;
	while(p != NULL) {
		q = p->next;
		free(p);
		p = q;
	} 
	head = NULL;
}

//void ShowList() {
//	Student *p;
//	p = head;
//	while(p != NULL) {
//		printf("%4d %16s %4.3f %4d\n",p->id, p->name, p->ave, p->game);
//		p = p->next;
//	}
//} 
//
//void Append(int i, char *s, double a, int g) {
//	Student *p;
//	if(head == NULL) /*리스트가 없을 때*/ {
//		head = (Student *) malloc(sizeof(Student));
//		head->id = i; strcpy(head->name,s); head->ave = a; head->game = g;
//		head->next = NULL;
//	}
//	else /*이미 만들어진 리스트가 있을 때*/ {
//		p = head;
//		while(p->next != NULL) {
//			p = p->next;
//		}
//		p->next = (Student *) malloc(sizeof(Student));
//		p = p->next;
//		p->id = i; strcpy(p->name,s); p->ave = a; p->game = g;
//		p->next = NULL;
//	}
//}



