#include <cstdio>
#include <string.h>
#include <math.h>

#define MAX 123456*2

char isPrime[MAX + 1];

void makeEratostenes();
int getBertrang(int n);

int main(void) {
	int n;
	memset(isPrime, 1, sizeof(isPrime));
	makeEratostenes();
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		printf("%d\n", getBertrang(n));
	}
}

void makeEratostenes() {
	for (int i = 2; i < sqrt(MAX); ++i) {
		if (isPrime[i] == 0) {
			continue;
		}
		for (int j = i * 2; j < MAX+1 ; j += i) {
			isPrime[j] = 0;
		}
	}
}

int getBertrang(int n) {
	int count = 0;
	for (int i = n + 1; i <= 2 * n; ++i) {
		if (isPrime[i]) {
			count++;
		}
	}
	return count;
}
