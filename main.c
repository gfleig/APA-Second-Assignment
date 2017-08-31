#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

#define AR_SIZE 20

int scrambled[AR_SIZE] = { 20, 8, 1, 9, 18, 15, 7, 11, 6, 3,
12, 4, 2, 10, 19, 5, 13, 16, 14, 17};

void printArray(int ar[])
{
    printf("[");
    int i;
    for( i = 0; i < AR_SIZE; i++)
    {
        if( i == AR_SIZE - 1)
        {
            printf("%d", ar[i]);
            continue;
        }
        printf("%d, ", ar[i]);
    }
    printf("]\n");
}

int main()
{
    int choice;

    printf(",.~* Welcome to Gabriel Fleig's Single Source File Sorting Realm! *~., \n\n");
    printf("Choose the sorting method to be used:\n\t1)Merge Sort\n\t2)Quick Sort\n\t3)Heap Sort\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printArray(scrambled);
            mergeSort(scrambled, AR_SIZE);
            printArray(scrambled);
            break;
        case 2:
            printArray(scrambled);
            quickSort(scrambled, AR_SIZE);
            printArray(scrambled);
            break;
        case 3:
            printArray(scrambled);
            heapSort(scrambled, AR_SIZE);
            printArray(scrambled);
            break;
        default:
            printf("\nI wonder if Fleig actually implemented separated \nsorting methods or this is just a pretty facade.\n\n");
            break;
    }

    return 0;
}
