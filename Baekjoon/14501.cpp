#include <cstdio>
#include <algorithm>
#define MAX 16
using namespace std;

int n;
int t[MAX];
int p[MAX];
int dp[MAX + 1];
int ans = 0;

void input() {
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}
}

void solve() {
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j]);
			
			if (j + t[j] == i) {
				dp[i] = max(dp[i], dp[j] + p[j]);
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
}

int main() {
	input();
	solve();
}
