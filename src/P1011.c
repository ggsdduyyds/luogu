#include <stdio.h>

int main() {
	int a, n, m, x;
	scanf("%d%d%d%d", &a, &n, &m, &x);
	int c = 0, u1, u2, d, t = 0, r = 0;
	while(t < m) {
		t = a;
		d = c;
		u1 = a;
		u2 = c;
		for(int i=3; i<n; i++) {
			t += u1;
			d = u2;
			u2 = u1 + u2;
			u1 = d;
			if(i == x) {
				r = t;
			}
		}
		c++;
	}
	printf("%d", r);
	return 0;
}