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

void bubbleSort(int N, int *A)
{
    int flag = 1;
    int i = 0;

    int count = 0; // swap count

    while (flag) {
        flag = 0;
        for (int j = N-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                swap(&A[j], &A[j-1]);
                flag = 1; count++;
            }
        }
        i++;
    }

    // print swap count
    printf("%d\n", count);
}

int main()
{
    int N = 5;
    int arr[MAX] = {5, 3, 2, 4, 1};

    //scanf("%d", &N);
    //for (int i = 0; i < N; i++)
    //    scanf("%d", &arr[i]);

    //printArray(N, arr);
    bubbleSort(N, arr);
    printArray(N, arr);
}