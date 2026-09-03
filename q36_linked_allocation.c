#include <stdio.h>

struct Block {
    int block_no;
    int next;
};

int main() {
    int n;
    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    struct Block blocks[20];
    printf("Enter block number and next block (-1 for last block):\n");
    for (int i = 0; i < n; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d %d", &blocks[i].block_no, &blocks[i].next);
    }

    printf("\nFile blocks in order:\n");
    int current = blocks[0].block_no;
    int index = 0;
    while (current != -1) {
        printf("Block %d -> ", current);
        current = blocks[index].next;
        index++;
    }
    printf("NULL\n");

    return 0;
}
