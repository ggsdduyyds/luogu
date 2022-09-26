#include <stdio.h>

int main() {
	int a[10];
	int h, c = 0;
	scanf("%d %d %d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);
	h = h + 30;
	for (int i=0; i<10; i++) {
		if (h >= a[i]) {
			c++;
		}
	}
	printf("%d", c);
	return 0;
}
