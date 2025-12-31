#include <stdio.h>
#define MAX 50

int HT[MAX];
int m;

/* Initialize hash table */
void init() {
    for (int i = 0; i < m; i++)
        HT[i] = -1;
}

/* Insert key using Linear Probing */
void insert(int key) {
    int index = key % m;

    if (HT[index] == -1) {
        HT[index] = key;
    } else {
        printf("Collision at index %d for key %d\n", index, key);
        int i = 1;
        while (HT[(index + i) % m] != -1) {
            i++;
        }
        HT[(index + i) % m] = key;
        printf("Key %d inserted at index %d using linear probing\n",
               key, (index + i) % m);
    }
}

/* Display hash table */
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (HT[i] != -1)
            printf("HT[%d] = %d\n", i, HT[i]);
        else
            printf("HT[%d] = ---\n", i);
    }
}

int main() {
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    init();

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d four-digit keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
