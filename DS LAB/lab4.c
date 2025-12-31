#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Create list */
void create() {
    int n, val;
    struct node *temp, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

/* Insert at beginning */
void insert_begin() {
    int val;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value to insert at beginning: ");
    scanf("%d", &val);

    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

/* Insert at end */
void insert_end() {
    int val;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    printf("Enter value to insert at end: ");
    scanf("%d", &val);

    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

/* Insert at any position */
void insert_pos() {
    int val, pos;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    printf("Enter value and position: ");
    scanf("%d %d", &val, &pos);

    newnode->data = val;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

/* Display list */
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: create(); break;
        case 2: insert_begin(); break;
        case 3: insert_end(); break;
        case 4: insert_pos(); break;
        case 5: display(); break;
        case 6:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
