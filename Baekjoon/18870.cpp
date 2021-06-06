#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

bool idx(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back({ num,i });
	}

	sort(v.begin(), v.end());

	int num = 0;
	int temp = v[0].first;
	v[0].first = num;
	for (int i = 1; i < n; i++) {
		if (temp < v[i].first) {
			num++;
		}
		temp = v[i].first;
		v[i].first = num;
	}

	sort(v.begin(), v.end(), idx);

	for (int i = 0; i < n; i++) {
		printf("%d ", v[i].first);
	}

	return 0;
}
