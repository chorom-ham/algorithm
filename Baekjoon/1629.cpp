#include <cstdio>

long long pow(int a, int b, int c) {
	if (b == 1) {
		return a;
	}
	long long ans = pow(a, b / 2, c);
	if (b % 2 == 1) {
		return ((ans * ans) % c * a) % c;
	}
	else {
		return (ans * ans) % c;
	}
}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	long long ans = pow(a % c, b, c);
	printf("%d", ans);
	return 0;
}
