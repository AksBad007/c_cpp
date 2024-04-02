#include<stdio.h>

int main() {
    int size, j = 0;

    printf("Enter Number of items: ");
    scanf("%d", &size);

    int arr[size] = {0};

    printf("Enter Values:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[j]);

        if(arr[j] != 0) j++;
    }

    printf("result:\n");
    for(int i = 0; i < size; i++) printf("%d", arr[i]);
    printf("\n");

    return 0;
}