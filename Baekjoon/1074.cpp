#include <cstdio>

int n, r, c;
int ans;

int main() {
	scanf("%d %d %d", &n, &r, &c);

	int x = 1 << (n - 1);
	int y = x;

	while (n-- > 0) {
		int temp = 1 << (n - 1);
		int skip = 1 << 2 * n;

		if (r < y && c < x) {
			// 0
			x -= temp;
			y -= temp;
		}
		else if (r < y && x <= c) {
			// 1
			x += temp;
			y -= temp;
			ans += skip;
		}
		else if (y <= r && c < x) {
			// 2
			x -= temp;
			y += temp;
			ans += skip * 2;
		}
		else {
			// 3
			x += temp;
			y += temp;
			ans += skip * 3;
		}
	}

	printf("%d", ans);

	return 0;
}
