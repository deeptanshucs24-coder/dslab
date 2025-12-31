#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

/* Create list */
struct node* create(struct node *head) {
    int n, val;
    struct node *temp = NULL, *newnode;

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
    return head;
}

/* Display list */
void display(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Sort list (ascending) */
void sort(struct node *head) {
    struct node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i++) {
        for (j = i->next; j != NULL; j++) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}

/* Reverse list */
struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printf("List reversed successfully.\n");
    return prev;
}

/* Concatenate two lists */
struct node* concat(struct node *head1, struct node *head2) {
    struct node *temp = head1;

    if (head1 == NULL)
        return head2;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    printf("Lists concatenated successfully.\n");
    return head1;
}

int main() {
    int choice;

    while (1) {
        printf("\n--- SLL Operations Menu ---\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List1 & List2\n");
        printf("6. Display List 1\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            head1 = create(head1);
            break;
        case 2:
            head2 = create(head2);
            break;
        case 3:
            sort(head1);
            break;
        case 4:
            head1 = reverse(head1);
            break;
        case 5:
            head1 = concat(head1, head2);
            head2 = NULL;
            break;
        case 6:
            display(head1);
            break;
        case 7:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
