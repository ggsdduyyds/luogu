#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORD_LEN 25
#define MAX_STR_LEN 500

char* substr(char* src, int start, int end);
int thcmp(char* s1, char* s2);
void merge(char* s1, char* s2, int cnt);
void dfscat(char* prefix, int loopCount, bool usedFlags[], char words[][MAX_WORD_LEN], char* maxs);

int main() {
	int n;
	scanf("%d", &n);
	int loopCount = n * 2;
	char words[n * 2][MAX_WORD_LEN];
	for(int i=0; i<n; i++) {
		scanf("%s", &words[i]);
		strcpy(words[n+i], words[i]);
	}

	char head;
	scanf("\n%c", &head);

	char maxs[MAX_STR_LEN];
	
	for(int i=0; i<n; i++) {
		if (head != words[i][0]) continue;

		bool* flags = (bool*)malloc(loopCount * sizeof(bool));
		for (int j=0; j<n; j++) {
			flags[j] = false;
			flags[n+j] = false;
		}
		flags[i] = true;
		
		if (strlen(words[i]) > strlen(maxs)) {
			strcpy(maxs, words[i]);
		}
		
		dfscat( words[i], loopCount, flags, words, maxs);
		
	}
	printf("%d", strlen(maxs));
	return 0;
}

void dfscat(char* prefix, int loopCount, bool usedFlags[], char words[][MAX_WORD_LEN], char* maxs) {
	for (int j=0; j<loopCount; j++) {
		if (usedFlags[j]) continue;
		int cnt = thcmp(prefix, words[j]);
		if(cnt > 0) {
			bool* newFlags = (bool*)malloc(loopCount * sizeof(bool));
			for (int i=0; i<loopCount; i++) {
				newFlags[i] = usedFlags[i];
			}
			newFlags[j] = true;
			char newBuf[MAX_STR_LEN];
			strcpy(newBuf, prefix);
			merge(newBuf, words[j], cnt);
			dfscat(newBuf, loopCount, newFlags, words, maxs);
			if (strlen(newBuf) > strlen(maxs)) {
				strcpy(maxs, newBuf);
			}
		}
	}
	free(usedFlags);
}

char* substr(char* src, int start, int end) {
	int len = end - start;
	char* res = (char*)malloc(len * sizeof(char));
	for (int i=0; i<len; i++) {
		res[i] = src[start + i];
	}
	res[len] = '\0';
	return res;
}

int thcmp(char* s1, char* s2) {
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int l3 = l1 < l2 ? l1 : l2;
	int cnt = 0;
	char c1[MAX_WORD_LEN], c2[MAX_WORD_LEN];
	for (int i=1; i<=l3; i++) {
		strcpy(c1, substr(s1, l1-i, l1)) ;
		strcpy(c2, substr(s2, 0, i));
		if (strcmp(c1, c2) == 0) {
			cnt = i;
			break;
		}
	}
	if (cnt == l3) cnt = 0;
	return cnt;
}

void merge(char* s1, char* s2, int cnt) {
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	strcat(s1, substr(s2, cnt, l2));
}
