#include <cstdio>
#define MAX 1000+1

int n;
int cost[3][MAX];
int dp[3][MAX];

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[j][i]);
		}
	}

	dp[0][0] = cost[0][0];
	dp[1][0] = cost[1][0];
	dp[2][0] = cost[2][0];

	for (int i = 1; i < n; i++) {
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + cost[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + cost[1][i];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + cost[2][i];
	}
	
	int ans = min(dp[0][n - 1], dp[1][n - 1]);
	ans = min(ans, dp[2][n - 1]);

	printf("%d", ans);
	return 0;
}
