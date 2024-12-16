#include <stdio.h>
#include <stdlib.h>
#define M 100  // Size of the hash table (number of memory locations)

// Employee record structure
typedef struct {
    int key;  // Unique 4-digit key
    char name[30]; // Employee name
} Employee;

// Hash table array
Employee hashTable[M];
int isOccupied[M] = {0};  // Tracks if a hash table slot is occupied

// Hash function
int hashFunction(int key) {
    return key % M;
}

// Function to insert a key into the hash table
void insert(Employee emp) {
    int index = hashFunction(emp.key);
    int originalIndex = index;
    
    while (isOccupied[index]) {
        if (hashTable[index].key == emp.key) {
            printf("Error: Duplicate key %d.\n", emp.key);
            return;
        }
        // Linear probing
        index = (index + 1) % M;
        if (index == originalIndex) {
            printf("Error: Hash table is full.\n");
            return;
        }
    }

    // Insert employee record
    hashTable[index] = emp;
    isOccupied[index] = 1;
    printf("Inserted key %d at index %d\n", emp.key, index);
}

// Function to search for a key in the hash table
void search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (isOccupied[index]) {
        if (hashTable[index].key == key) {
            printf("Key %d found at index %d (Employee: %s)\n", key, index, hashTable[index].name);
            return;
        }
        // Linear probing
        index = (index + 1) % M;
        if (index == originalIndex) {
            break;
        }
    }

    printf("Key %d not found.\n", key);
}

// Function to display the hash table
void displayHashTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < M; i++) {
        if (isOccupied[i]) {
            printf("Index %d: Key %d, Name %s\n", i, hashTable[i].key, hashTable[i].name);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    int choice, key;
    Employee emp;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Employee\n");
        printf("2. Search Employee\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter 4-digit key: ");
                scanf("%d", &emp.key);
                printf("Enter employee name: ");
                scanf("%s", emp.name);
                insert(emp);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                displayHashTable();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
