#include<stdio.h>
#include<stdlib.h>
#define N 5

int Queue[N];

int front=-1;
int rear=-1;

void enque(int x){
	if(front==-1 && rear==-1){
		front=rear=0;
		Queue[rear]=x;
	}
	else if(rear==(N-1)){
		printf("Queue is Full");
	}
	else{
		rear++;
		Queue[rear]=x;
	}
}

void dequeue(){
	if(front==-1 && rear==-1){
		printf("Queue is Empty");
	}
	else if(front==rear){
		front=rear=-1;
	}
	else{
		front++;
	}
}

void display(){
	int i;
	if(front==-1 && rear==-1){
		printf("Queue is Empty");
	}
	else{
		for(i=front;i<rear+1;i++){
			printf("%d ",Queue[i]);
		}
	}
}

void main(){
	int x,ch;
	
	while(1){
	
	printf("\n:MENU:\n1>Enqueue\n2>Dequeue\n3>Display\nEnter a choice here: ");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			printf("Enter a data: ");
			scanf("%d",&x);
			enque(x);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		default:
			printf("Enter valid input!!");
			printf("\n");
	}
}
}

