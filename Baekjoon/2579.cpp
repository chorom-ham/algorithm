#include <cstdio>

int n;
int arr[301];
int dp[301];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d", &n);

	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = arr[i] + max(dp[i - 2], arr[i - 1] + dp[i - 3]);
	}

	printf("%d", dp[n]);
	return 0;
}
