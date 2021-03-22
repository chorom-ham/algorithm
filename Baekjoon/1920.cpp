#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void binary_search(int key, int low, int high) {
	while (low <= high) {
		int middle = (low + high) / 2;
		if (key == v[middle]) {
			printf("1\n");
			return;
		}
		else if (key < v[middle]) {
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}	
	printf("0\n");
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int input;
		scanf("%d", &input);
		binary_search(input, 0, n - 1);
	}
	return 0;
}
