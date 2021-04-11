#include <cstdio>

int n;
int wine[10001];
int dp[10001];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &wine[i]);
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = wine[i] + max(dp[i - 3] + wine[i - 1], dp[i - 2]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	printf("%d", dp[n]);
}
