#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef char *string;

typedef struct node {
    int number;
    struct node *next;
} node;

typedef struct hashmap {
    string key;
    int value;
    struct hashmap *next;
} hashmap;

int RandInt(int range) {
    return rand() % (2 * range + 1) - range;
}

int hash(string s) {
    int result = 0;
    for (int i = 0; i < strlen(s); i++) {
        int value = (int)s[i];
        result += value * RandInt(value);
    }
    return result;
}

hashmap *createNode(string key, int value) {
    hashmap *newNode = (hashmap *)malloc(sizeof(hashmap));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(hashmap **hashTable, string key, int value) {
    int index = hash(key);

    hashmap *newNode = createNode(key, value);

    if (hashTable[index] == NULL) {
        // No collision, insert at the beginning
        hashTable[index] = newNode;
    } else {
        // Collision handling (insert at the beginning)
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int main(void) {
    srand(time(0));

    // Choose an appropriate size for your hashmap
    int hashTableSize = 100;
    hashmap *hashTable[hashTableSize];

    // Initialize hashTable with NULL
    for (int i = 0; i < hashTableSize; i++) {
        hashTable[i] = NULL;
    }

    insert(hashTable, "one", 1);
    insert(hashTable, "two", 2);
    insert(hashTable, "three", 3);

    return 0;
}
