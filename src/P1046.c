#include <stdio.h>

int main() {
	int a[10];
	int h, c = 0;
	for (int i=0; i<10; i++) {
		scanf("%d", &a[i]);
	}
	h = h + 30;
	for (int i=0; i<10; i++) {
		if (h >= a[i]) {
			c++;
		}
	}
	printf("%d", c);
	return 0;
}
