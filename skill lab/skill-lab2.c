#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mergeSortedLists(char** list1, int size1, char** list2, int size2, char*** mergedList, int* mergedSize) {
    *mergedSize = size1 + size2;
    *mergedList = (char**)malloc(sizeof(char*//) * (*mergedSize));
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (strcmp(list1[i], list2[j]) < 0) {
            (*mergedList)[k++] = strdup(list1[i++]);
        } else {
            (*mergedList)[k++] = strdup(list2[j++]);
        }
    }
    while (i < size1) {
        (*mergedList)[k++] = strdup(list1[i++]);
    }
    while (j < size2) {
        (*mergedList)[k++] = strdup(list2[j++]);
    }
}
void printList(char** list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", list[i]);
    }
}
void freeList(char** list, int size) {
    for (int i = 0; i < size; i++) {
        free(list[i]);
    }
    free(list);
}
int main() {
    char* contactList1[] = {"Alice Adams", "Bob Brown", "David Smith"};
    char* contactList2[] = {"Charlie Johnson", "Edward Davis", "Frank White"};
    int size1 = sizeof(contactList1) / sizeof(contactList1[0]);
    int size2 = sizeof(contactList2) / sizeof(contactList2[0]);
    char** mergedList;
    int mergedSize;
    mergeSortedLists(contactList1, size1, contactList2, size2, &mergedList, &mergedSize);
    printf("Merged List:\n");
    printList(mergedList, mergedSize);
    freeList(mergedList, mergedSize);
    return 0;
}