#include <stdio.h>
#include <stdbool.h>

void mcf(int n, bool plus);

int main() {
	int n;
	scanf("%d", &n);
	mcf(n, false);
	return 0;
}

void mcf(int n, bool plus) {
	if (n > 0) {
		if (plus) {
			printf("+");
		}
		int cf = 2, c = 0;
		while(cf <= n) {
			c++;
			cf = cf * 2;
		}
		int s = cf / 4;
		if (0 == s) {
			printf("2(0)");
		} else if (1 == s) {
			printf("2");
		} else if (2 == s) {
			printf("2(2)");
		} else {
			printf("2(");
			mcf(c, false);
			printf(")");
		}
		n = n - cf / 2;
		if (n > 0) {
			mcf(n, true);
		}
	}
}
