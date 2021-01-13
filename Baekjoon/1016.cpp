#include <cstdio>
#include <cmath>
#include <cstring>

long long min, max;

// arr[0]: min이 제곱ㄴㄴ수인지, arr[1]: min + 1이 제곱ㄴㄴ수인지 ...
bool arr[1000001];

int main() {
	scanf("%lld %lld", &min, &max);
	memset(arr, true, sizeof(arr));

	for (long long i = 2; i <= sqrt(max); i++) {
		long long x = min / (i * i);
		if (min % (i * i) != 0)	x++;

		while (x * (i * i) <= max) {
			arr[x * (i * i) - min] = false;
			x++;
		}
	}

	int ans = 0;
	for (int i = 0; i <= max - min; i++) {
		if (arr[i]) ans++;
	}

	printf("%d", ans);
}
