#include<stdio.h>
#define size 5
int rear=0,front=0;

struct Job_Sequ
{
int id;
char title[20];
};


int isfull(){
	if((rear+1)%size ==front)
		return 1;
	else
		return 0;
}

int isempty(){
	if (rear==front)
		return 1;
	else
		return 0;
}

void AddQ(struct Job_Sequ queue[size],struct Job_Sequ elem){
	if(isfull()==0){
		rear=(rear+1)%size;
		queue[rear] = elem;

		}
}

struct Job_Sequ DelQ(struct Job_Sequ queue[size]){
	struct Job_Sequ elem;
	if(isempty()==0){
		front=(front+1)%size;
		elem = queue[front];
		return elem;
		}
	else
		printf("Queue is empty\n");
}

int main()
{
int ch=0,exit=0;
struct Job_Sequ que[size],elem;
while(exit==0){
	ch =0;
	printf("\nEnter operation to be done\n1. Add\n2. Delete\n3. Exit\nYour Choice: ");
	scanf("%d",&ch);

	switch(ch){
	case 1:
		if(isfull()==1)
			printf("Queue is Full\n");
		else{
			printf("Enter element");
			printf("\nEnter ID: ");
			scanf("%d",&elem.id);
			printf("Enter Title: ");
			scanf("%s",elem.title);
			AddQ(que,elem);	
		}
		break;
	case 2:
		elem = DelQ(que);
		
		break;
	
	case 3:
		exit=1;
		break;
	default:
		printf("Invalid");
		exit=1;
		break;
		}
	
	}
return 0;
}





