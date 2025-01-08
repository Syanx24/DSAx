#include<stdio.h>
#include<stdlib.h>
#define N 4

char queue[N];
int front = -1;
int rear = -1;

void enqueue(char data) {
    if (((rear + 1) % N) == front) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("%c dequeued\n", queue[front]);
        front = rear = -1;
    } else {
        printf("%c dequeued\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is: ");
        int i = front;
        while (i != rear) {
            printf("%c ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%c \n", queue[rear]);
    }
}

int main() {
    int choice;
    char value;

    while (1) {
        printf("\n-------- MENU --------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to enqueue: ");
                scanf(" %c", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

