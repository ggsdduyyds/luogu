#include <stdio.h>
#include <stdbool.h>

int main() {
	int num[3];
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=9; j++) {
			if (i == 3 && j > 2) return 0;
			if (j == i) continue;
			for(int y=1; y<=9; y++) {
				if (y == i || y == j) continue;

				num[0] = i * 100 + j * 10 + y;
				num[1] = num[0] * 2;
				num[2] = num[0] * 3;

				bool exists[10] = {false};
				for(int z=0; z<3; z++) {
					exists[num[z] / 100] = true;
					exists[num[z] % 100 / 10] = true;
					exists[num[z] % 10] = true;
				}

				int printable = true;
				for (int x=1; x<=9; x++) {
					if (!exists[x]) {
						printable = false;
						break;
					}
				}
				if (printable) {
					printf("%d %d %d\n", num[0], num[1], num[2]);
				}
			}
		}
	}
	return 0;
}