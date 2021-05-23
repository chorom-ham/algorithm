#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int adj[1001][1001];
int visited[1001];
queue<int> q;
int ans;

void bfs() {
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			if (adj[n][i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	ans++;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = adj[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		q.push(i);
		bfs();
	}

	printf("%d", ans);
}
