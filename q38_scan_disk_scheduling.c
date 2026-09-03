#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, disk_size;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[50];
    printf("Enter disk requests: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    /* sort requests */
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (req[j] > req[j + 1]) {
                int t = req[j]; req[j] = req[j + 1]; req[j + 1] = t;
            }

    int total = 0, current = head;

    /* move towards higher end first */
    for (int i = 0; i < n; i++) {
        if (req[i] >= head) {
            total += abs(req[i] - current);
            current = req[i];
        }
    }
    total += abs((disk_size - 1) - current);
    current = disk_size - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (req[i] < head) {
            total += abs(req[i] - current);
            current = req[i];
        }
    }

    printf("Total head movement: %d\n", total);
    return 0;
}
