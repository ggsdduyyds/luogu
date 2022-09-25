#include <stdio.h>

int main() {
	int num[3];
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=9; j++) {
			if (i == 3 && j > 2) {
				return 0;
			}
			for(int y=1; y<=9; y++) {
				num[0] = i * 100 + j * 10 + y;
				num[1] = num[0] * 2;
				num[2] = num[0] * 3;

				int pos[10] = {0};
				for(int z=0; z<3; z++) {
					pos[num[z] / 100] = 1;
					pos[num[z] % 100 / 10] = 1;
					pos[num[z] % 10] = 1;
				}

				int printable = 1;
				for (int x=1; x<=9; x++) {
					if (0 == pos[x]) {
						printable = 0;
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