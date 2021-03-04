#include <cstdio>

int n, m;
int adj[101][101];
int visit[101];
int ans;

void dfs(int c) {
	ans++;
	visit[c] = 1;
	for (int i = 1; i <= n; i++) {
		if (adj[c][i] && !visit[i]) dfs(i);
	}
}

int main() {
	int a, b;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	dfs(1);
	printf("%d", ans - 1); // 1번 컴퓨터는 제외해야 해서 1을 뺀다

	return 0;
}
