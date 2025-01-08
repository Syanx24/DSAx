#include <stdio.h>
#include <stdlib.h> // For malloc, free, and exit

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL; // Initialize start to NULL

struct node *createnode() {
    struct node *h1 = (struct node *)malloc(sizeof(struct node));
    if (h1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit if malloc fails
    }
    printf("Enter a data: ");
    scanf("%d", &h1->data);
    h1->next = NULL; // Initialize the next pointer
    return h1;
}

void insertstart() {
    struct node *k1 = createnode();
    k1->next = start;
    start = k1;
    printf("Node inserted at the beginning.\n");
}

void insertend() {
    struct node *j1 = createnode();
    if (start == NULL) {
        start = j1;
    } else {
        struct node *g1 = start;
        while (g1->next != NULL) {
            g1 = g1->next;
        }
        g1->next = j1;
    }
    printf("Node inserted at the end.\n");
}

void insertposition() {
    int pos, i = 1;
    struct node *newnode, *temp;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    if (pos == 1) {
        insertstart();
        return;
    }
    newnode = createnode();
    temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range. Node will be inserted at the end.\n");
        insertend();
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Node inserted at position %d.\n", pos);
    }
}

void deletestart() {
    struct node *y1;
    if (start == NULL) {
        printf("List is Empty.\n");
    } else {
        y1 = start;
        start = start->next;
        free(y1);
        printf("Node deleted from the beginning.\n");
    }
}

void deleteend() {
    struct node *h1, *a1;
    if (start == NULL) {
        printf("List is Empty.\n");
    } else if (start->next == NULL) {
        free(start);
        start = NULL;
        printf("Node deleted from the end.\n");
    } else {
        h1 = start;
        while (h1->next->next != NULL) {
            h1 = h1->next;
        }
        a1 = h1->next;
        h1->next = NULL;
        free(a1);
        printf("Node deleted from the end.\n");
    }
}

void deleteposition() {
    int pos, i = 1;
    struct node *temp, *nodeToDelete;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (pos == 1) {
        deletestart();
        return;
    }
    temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
    } else {
        nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
        printf("Node deleted from position %d.\n", pos);
    }
}

void display() {
    struct node *j1 = start;
    if (start == NULL) {
        printf("List is Empty.\n");
    } else {
        printf("Current Linked List: ");
        while (j1 != NULL) {
            printf("%d\t", j1->data);
            j1 = j1->next;
        }
        printf("\n");
    }
}

int main() {
    int ch;
    printf("Menu:\n");
    printf("1 for insert at beginning.\n");
    printf("2 for insert at end.\n");
    printf("3 for insert at a specific position.\n");
    printf("4 for delete from beginning.\n");
    printf("5 for delete from end.\n");
    printf("6 for delete from a specific position.\n");
    printf("7 for display.\n");
    printf("8 for exit.\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insertstart();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertposition();
                break;
            case 4:
                deletestart();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                deleteposition();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
