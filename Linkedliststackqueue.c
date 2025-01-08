#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Global pointers for stack and queue
struct node *stack_top = NULL;  // Stack top
struct node *queue_front = NULL, *queue_rear = NULL;  // Queue front and rear

// Function to create a new node
struct node *createnode() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

// Stack Operations
void push() {
    struct node *newnode = createnode();
    newnode->next = stack_top;
    stack_top = newnode;
    printf("Pushed onto stack.\n");
}

void pop() {
    if (stack_top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct node *temp = stack_top;
        stack_top = stack_top->next;
        printf("Popped %d from stack.\n", temp->data);
        free(temp);
    }
}

void display_stack() {
    if (stack_top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct node *temp = stack_top;
        printf("Stack: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Queue Operations
void enqueue() {
    struct node *newnode = createnode();
    if (queue_rear == NULL) {
        queue_front = queue_rear = newnode;
    } else {
        queue_rear->next = newnode;
        queue_rear = newnode;
    }
    printf("Enqueued into queue.\n");
}

void dequeue() {
    if (queue_front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct node *temp = queue_front;
        queue_front = queue_front->next;
        if (queue_front == NULL) {
            queue_rear = NULL;
        }
        printf("Dequeued %d from queue.\n", temp->data);
        free(temp);
    }
}

void display_queue() {
    if (queue_front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct node *temp = queue_front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch;
    printf("Menu:\n");
    printf("1 for Push (Stack).\n");
    printf("2 for Pop (Stack).\n");
    printf("3 for Display Stack.\n");
    printf("4 for Enqueue (Queue).\n");
    printf("5 for Dequeue (Queue).\n");
    printf("6 for Display Queue.\n");
    printf("7 for Exit.\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display_stack();
                break;
            case 4:
                enqueue();
                break;
            case 5:
                dequeue();
                break;
            case 6:
                display_queue();
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
