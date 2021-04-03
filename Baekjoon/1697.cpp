#include <cstdio>
#include <queue>
using namespace std;

int N, K, ans;
queue<pair<int, int>> q;
bool visited[100001];

bool isOkay(int n) {
	if (n < 0 || n>100000 || visited[n]) {
		return false;
	}
	return true;
}

void bfs(int n) {
	while (!q.empty()) {
		int idx = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (idx == K) {
			ans = depth;
			return;
		}

		if (isOkay(idx - 1)) {
			visited[idx - 1] = true;
			q.push({ idx - 1,depth + 1 });
		}
		if (isOkay(idx + 1)) {
			visited[idx + 1] = true;
			q.push({ idx + 1, depth + 1 });
		}
		if (isOkay(2 * idx)) {
			visited[2 * idx] = true;
			q.push({ 2 * idx,depth + 1 });
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);

	q.push({ N, 0 });
	visited[N] = true;
	bfs(N);

	printf("%d", ans);
}
