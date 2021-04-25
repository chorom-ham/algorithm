#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int t, m, n, k;
int map[50][50];
int visited[50][50];
int cnt;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (visited[nx][ny] == 1 || map[nx][ny] == 0) continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}
	cnt++;
}

int main() {
	int r, c;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d %d", &r, &c);
			map[r][c] = 1;
		}
		cnt = 0;
		for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++) {
				if (map[x][y] == 1 && visited[x][y] == 0) bfs(x, y);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
