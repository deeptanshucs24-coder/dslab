#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    if (front == -1)
        front = 0;

    printf("Enter element to insert: ");
    scanf("%d", &item);

    rear++;
    queue[rear] = item;
    printf("Inserted element: %d\n", item);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    // Reset queue when empty
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
