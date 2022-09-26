#include <stdio.h>

int main() {
	int k, n = 0;
	double sum = 0;
	scanf("%d", &k);
	while(sum <= k) {
		n++;
		sum += 1.0/n;
	}
	printf("%d\n", n);
	return 0;
}