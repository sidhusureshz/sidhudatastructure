#include <stdio.h>
void main()
{
int arr1[20], arr2[20], arr3[40], n1, n2;
void readdata(int[], int);
void sortdata(int[], int);
void printdata(int[], int);
void mergedata(int[], int[], int[], int, int);
    printf("No. of elements in first array [1-20]:\n");
    scanf("%d", &n1);
    readdata(arr1, n1);

    printf("No. of elements in second array :\n");
    scanf("%d", &n2);
    readdata(arr2, n2);

    sortdata(arr1, n1);
    sortdata(arr2, n2);
    mergedata(arr1, arr2, arr3, n1, n2);

    printf("Sorted array 1:\n");
    printdata(arr1, n1);
    printf("Sorted array 2:\n");
    printdata(arr2, n2);
    printf("Merged array:\n");
    printdata(arr3, n1 + n2);
}

void readdata(int a[], int n) {
    int i;
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void printdata(int a[], int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void sortdata(int a[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void mergedata(int a[], int b[], int c[], int n1, int n2) {
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while(i < n1) {
        c[k++] = a[i++];
    }

    while(j < n2) {
        c[k++] = b[j++];
    }
}

