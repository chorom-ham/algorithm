#include <cstdio>
#define MAX 1001

int ans = 0;
int N;
int arr[MAX];
int dp_lis[MAX]; // dp[i]: 1~i까지의 부분 수열 중 가장 긴 증가하는 수열 길이
int dp_lds[MAX]; // dp[i]: 1~i까지의 부분 수열 중 가장 긴 감소하는 수열 길이

// 하나의 수열에서 "가장 긴 증가하는 부분수열 + 가장 긴 감소하는 부분수열" 을 합쳐놓았을 때, 
// 가장 최대길이가 되는 수열을 찾는 문제
int main() {
	scanf("%d", &N);
	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &arr[i]);
	}

	//최장 증가 수열 길이
	for (int i = 1; i <= N; i++) {
		dp_lis[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i] && dp_lis[i] < dp_lis[j] + 1) {
				dp_lis[i] = dp_lis[j] + 1;
			}
		}
	}

	//최장 감소 수열 길이
	for (int i = N; i >= 1; i--) {
		dp_lds[i] = 1;
		for (int j = N; j >= i; j--) {
			if (arr[j] < arr[i] && dp_lds[i] < dp_lds[j] + 1) {
				dp_lds[i] = dp_lds[j] + 1;
			}
		}
	}


	for (int i = 0; i <= N; i++) {
		if (ans < dp_lis[i] + dp_lds[i] - 1) {
			ans = dp_lis[i] + dp_lds[i] - 1;
		}
	}

	printf("%d", ans);
}
