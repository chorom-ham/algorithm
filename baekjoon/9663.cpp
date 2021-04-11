#include <cstdio>

int N;
int col[15];
int ans;

int abs(int a, int b) {
	return a - b > 0 ? a - b : b - a;
}

bool promising(int i) {
	int k;
	bool flag;
	k = 1;
	flag = true;
	while (k < i && flag) {
		if (col[i] == col[k] || abs(col[i], col[k]) == i - k) {
			flag = false;
		}
		k++;
	}
	return flag;
}


void queens(int i) {
	int j;

	if (promising(i)) {
		if (i == N) {
			ans++;
		}
		else {
			for (j = 1; j <= N; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	queens(0);
	printf("%d", ans);

	return 0;
}
