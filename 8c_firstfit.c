#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], bf[MAX], ff[MAX];
    int i, j, nb, nf, temp;
    
    printf("\nMemory Management Scheme - First Fit\n");

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    for (i = 0; i < nf; i++) {
        temp = -1; // Initialize to a value that indicates no suitable block found
        for (j = 0; j < nb; j++) {
            if (bf[j] != 1 && b[j] >= f[i]) { // If block is not allocated and has enough space
                ff[i] = j;
                temp = b[j] - f[i];
                bf[j] = 1; // Mark the block as allocated
                break; // Move to the next file
            }
        }
        frag[i] = temp;
    }

    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment\n");
    for (i = 0; i < nf; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);

    return 0;
}
