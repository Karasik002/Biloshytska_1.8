#include <stdio.h>
#include <string.h>
#include <windows.h>
unsigned long long factorial(int n) {
    if (n == 0) return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char word[15];
    printf("Введіть слово: ");
    scanf("%14s", word);

    int length = strlen(word);
    if (length > 14) {
        printf("Кількість букв у слові не повинна перевищувати 14.\n");
        return 1;
    }

    int count[256] = {0};
    for (int i = 0; i < length; i++) {
        count[(int)word[i]]++;
    }

    unsigned long long total_permutations = factorial(length);

    for (int i = 0; i < 256; i++) {
        if (count[i] > 1) {
            total_permutations /= factorial(count[i]);
        }
    }

    printf("Кількість можливих анаграм: %llu\n", total_permutations);

    return 0;
}
