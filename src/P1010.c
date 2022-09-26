#include <stdio.h>
#include <string.h>

int main() {
	char buf[150] = "";
	int n;
	scanf("%d", &n);
	mcf(n, buf);
	printf("%s", buf);
	return 0;
}

void mcf(int n, char buf[]) {
	if (n > 0) {
		int len = strlen(buf);
		if (len > 0 && buf[len-1] != '(') {
			strcat(buf, "+");
		}
		int cf = 2, c = 0;
		while(cf <= n) {
			c++;
			cf = cf * 2;
		}
		int s = cf / 4;
		if (0 == s) {
			strcat(buf, "2(0)");
		} else if (1 == s) {
			strcat(buf, "2");
		} else if (2 == s) {
			strcat(buf, "2(2)");
		} else {
			strcat(buf, "2(");
			mcf(c, buf);
			strcat(buf, ")");
		}
		n = n - cf / 2;
		if (n > 0) {
			mcf(n, buf);
		}
	}
}