#include <stdio.h>

#define MAX 10

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;   
}

void printArray(int N, int *A)
{
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
/*
void selectionSort(int N, int *A)
{
    int flag = 1;
    int i, j, minj = 0;

    int count = 0; // swap count

    for (i = 0; i < N-1; i++) {
        minj = i;
        for (j = i; j < N; j++) {
            if (A[j] < A[minj])
                minj = j;
        }
        swap(&A[i], &A[minj]);
        count++;
    }

    // print swap count
    printf("%d\n", count);
}
*/
// lecturer's code
void selectionSort(int N, int *A)
{
    int flag = 1;
    int i, j, minj = 0;

    int count = 0; // swap count

    for (i = 0; i < N; i++) {
        minj = i;
        for (j = i; j < N; j++) {
            if (A[j] < A[minj])
                minj = j;
        }
        swap(&A[i], &A[minj]);
        if (i != minj) count++; // i != minj parts decreases sw count
    }

    // print swap count
    printf("%d\n", count);
}

int main()
{
    int N = 6;
    int arr[MAX] = {5, 6, 4, 2, 1, 3};

    //scanf("%d", &N);
    //for (int i = 0; i < N; i++)
    //    scanf("%d", &arr[i]);

    //printArray(N, arr);
    selectionSort(N, arr);
    printArray(N, arr);
}