#include <stdio.h>

void insertion(int arr[], int *n);
void deletion(int arr[], int *n);
void replace(int arr[], int n);
void search(int arr[], int n);

int main() {
    int arr[30], n, i, ch;

    printf("Enter the number of array elements: ");
    scanf("%d", &n);

    printf("Enter the %d array elements here: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n:MENU:\n");
        printf("1> Insertion\n");
        printf("2> Deletion\n");
        printf("3> Replace\n");
        printf("4> Search\n");
        printf("5> Exit\n");
        printf("Enter a choice between 1 to 5 here: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertion(arr, &n);
                break;
            case 2:
                deletion(arr, &n);
                break;
            case 3:
                replace(arr, n);
                break;
            case 4:
                search(arr, n);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Display the updated array after each operation
        printf("Updated array: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

void insertion(int arr[], int *n) {
    int pos, val, i;

    if (*n >= 30) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    printf("Enter the position to insert (1 to %d): ", *n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position. Please try again.\n");
        return;
    }

    printf("Enter the new value: ");
    scanf("%d", &val);

    for (i = *n-1; i >= pos-1; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos - 1] = val;
    (*n)++;
}

void deletion(int arr[], int *n) {
    int pos, i;

    if (*n == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter the position to delete (1 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n) {
        printf("Invalid position. Please try again.\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void replace(int arr[], int n) {
    int pos, val;

    printf("Enter the position to replace (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position. Please try again.\n");
        return;
    }

    printf("Enter the new value: ");
    scanf("%d", &val);

    arr[pos - 1] = val;
}

void search(int arr[], int n) {
    int val, i, found = 0;

    printf("Enter the value to search: ");
    scanf("%d", &val);

    for (i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Value found at position %d.\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Value not found in the array.\n");
    }
}

