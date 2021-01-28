#include <cstdio>
#include <cstring>
#define MAX 1001

bool isPrime[MAX];
int n, ans = 0; 

void eratos() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		for (int j = 2; j < MAX; j++) {
			if (!isPrime[j]) continue;
			if (j != i && j % i == 0) isPrime[j] = false;
		}
	}
}

int main() {
	eratos();

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		if (isPrime[input]) ans++;
	}

	printf("%d", ans);
}
