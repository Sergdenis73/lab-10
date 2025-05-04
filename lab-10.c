#include <stdio.h>
#include <stdlib.h>

void inputArray(int **arr, int *size) {
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", size);
    
    *arr = (int*)malloc(*size * sizeof(int));
    if (*arr == NULL) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }
    
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < *size; i++) {
        printf("Елемент %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}

void analyzeArray(int *arr, int size, int lower, int upper, int *sum, double *average, int *count) {
    *sum = 0;
    *count = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] >= lower && arr[i] <= upper) {
            *sum += arr[i];
            (*count)++;
        }
    }
    
    if (*count > 0) {
        *average = (double)*sum / *count;
    } else {
        *average = 0.0;
    }
}

int main() {
    system("chcp 65001");
    int *array1 = NULL, *array2 = NULL, *array3 = NULL;
    int size1, size2, size3;
    int lower, upper;

    printf("Введіть нижню межу інтервалу: ");
    scanf("%d", &lower);
    printf("Введіть верхню межу інтервалу: ");
    scanf("%d", &upper);

    printf("\nМасив 1:\n");
    inputArray(&array1, &size1);

    printf("\nМасив 2:\n");
    inputArray(&array2, &size2);

    printf("\nМасив 3:\n");
    inputArray(&array3, &size3);

    int sum1, sum2, sum3;
    double avg1, avg2, avg3;
    int count1, count2, count3;
    
    analyzeArray(array1, size1, lower, upper, &sum1, &avg1, &count1);
    analyzeArray(array2, size2, lower, upper, &sum2, &avg2, &count2);
    analyzeArray(array3, size3, lower, upper, &sum3, &avg3, &count3);

    printf("\nРезультати:\n");
    printf("Масив 1: Сума = %d, Середнє = %.2f, Кількість елементів в інтервалі = %d\n", sum1, avg1, count1);
    printf("Масив 2: Сума = %d, Середнє = %.2f, Кількість елементів в інтервалі = %d\n", sum2, avg2, count2);
    printf("Масив 3: Сума = %d, Середнє = %.2f, Кількість елементів в інтервалі = %d\n", sum3, avg3, count3);

    free(array1);
    free(array2);
    free(array3);
    
    return 0;
}