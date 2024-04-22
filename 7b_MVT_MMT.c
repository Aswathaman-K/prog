#include <stdio.h>

int main() {
    int ms, mp[10], i, temp, n = 0;
    char ch = 'y';

    printf("\nEnter the total memory available (in Bytes)-- ");
    scanf("%d", &ms);
    temp = ms;

    while (ch == 'y' || ch == 'Y') {
        printf("\nEnter memory required for process %d (in Bytes) -- ", n + 1);
        if (scanf("%d", &mp[n]) != 1) {
            printf("\nInvalid input. Please enter a valid integer.\n");
            return 1; // Exit with error code 1
        }

        if (mp[n] <= temp) {
            printf("\nMemory is allocated for Process %d ", n + 1);
            temp -= mp[n];
            n++;
        } else {
            printf("\nMemory is Full");
            break;
        }

        printf("\nDo you want to continue(y/n) -- ");
        scanf(" %c", &ch);
    }

    printf("\n\nTotal Memory Available -- %d", ms);
    printf("\n\n\tPROCESS\t\t MEMORY ALLOCATED ");
    for (i = 0; i < n; i++)
        printf("\n \t%d\t\t%d", i + 1, mp[i]);

    printf("\n\nTotal Memory Allocated is %d", ms - temp);
    printf("\nTotal External Fragmentation is %d\n", temp);

    return 0;
}
