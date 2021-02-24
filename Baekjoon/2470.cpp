#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int n, idx1, idx2;
long long arr[100000];
long long minimum;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr + n);

	minimum = LLONG_MAX;

	int i = 0, j = n - 1;

	while (i < j) {
		long long sum = arr[i] + arr[j];

		if (llabs(sum) < minimum) {
			minimum = llabs(sum);
			idx1 = i;
			idx2 = j;
		}

		if (sum < 0) {
			i++;
		}
		else {
			j--;
		}
	}

	printf("%lld %lld\n", arr[idx1], arr[idx2]);
}
