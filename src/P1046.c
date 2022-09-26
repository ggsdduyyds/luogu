#include <stdio.h>

int main() {
	int apples[10];
	int h, count;
	scanf("%d %d %d %d %d %d %d %d %d %d", &apples[0], &apples[1], &apples[2], &apples[3], &apples[4], &apples[5], &apples[6], &apples[7], &apples[8], &apples[9]);
	scanf("%d", &h);
	h = h + 30;
	for (int i=0; i<10; i++) {
		if (h >= apples[i]) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}