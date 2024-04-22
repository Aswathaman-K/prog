#include <stdio.h>
#define MAX_BLOCKS 25
#define MAX_FILES 25

int main() {
    int fragment[MAX_FILES], blocks[MAX_BLOCKS], files[MAX_FILES], blockAllocated[MAX_BLOCKS] = {0}, fileAllocated[MAX_FILES] = {0};
    int nb, nf, i, j, highest, temp;

    printf("\n\tMemory Management Scheme - Worst Fit\n");
    
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    
    printf("Enter the number of files: ");
    scanf("%d", &nf);
    
    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &files[i]);
    }

    for (i = 0; i < nf; i++) {
        highest = -1;
        for (j = 0; j < nb; j++) {
            if (!blockAllocated[j]) { // If block is not allocated
                temp = blocks[j] - files[i];
                if (temp >= 0 && temp > highest) {
                    highest = temp;
                    fragment[i] = highest;
                    fileAllocated[i] = j + 1;
                }
            }
        }
        if (highest != -1)
            blockAllocated[fileAllocated[i] - 1] = 1; // Mark the block as allocated
    }

    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragmentation\n");
    for (i = 0; i < nf; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, files[i], fileAllocated[i], blocks[fileAllocated[i] - 1], fragment[i]);
    
    return 0;
}
