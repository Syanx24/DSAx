#include<stdio.h>
#include<stdlib.h>
#define N 5

int stack[N];
int top=-1;

void push(){
	int x;
	printf("Enter a data: ");
	scanf("%d",&x);
	
	if(top==N-1){
		printf("Overflow");
	}
	else{
		top++;
		stack[top]=x;
		printf("Data inserted %d",x);
	}
	printf("\n");
	
}

void pop(){
	int item;
	if(top==-1){
		printf("Underflow");
	}
	else{
		item=stack[top];
		top--;
		printf("Deleted item is %d",item);
	}
	printf("\n");
}

void display(){
	int i;
	if(top==-1){
		printf("Underflow");
	}
	else{
	printf("Your stack elements are: ");
	for(i=top;i>=0;i--){
		printf("%d ",stack[i]);
	}
}
	printf("\n");
}

void main(){
	int ch;
	
	while(1){
	
	printf(":MENU:\n1>PUSH\n2>POP\n3>DISPLAY\nEnter a choice here: ");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			push();
			break;
		case 2:
			pop();
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
















