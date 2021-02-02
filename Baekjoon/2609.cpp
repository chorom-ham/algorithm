#include <cstdio>

// gcd(a,b) == gcd (b, a mod b) (단, a > b)
int gcd(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	while (b!=0) {
		int n = a % b;
		a = b;
		b = n;
	}

	return a;
}

// gcd(a,b) * lcm(a,b) == a*b
int lcm(int a, int b) {
	return (a*b) / gcd(a, b);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", gcd(a, b));
	printf("%d\n", lcm(a, b));
}
