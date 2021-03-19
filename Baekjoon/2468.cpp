#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 101

using namespace std;

int n, maxh, lowh, cnt, ans = 1;
int arr[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int a, int b, int height) {
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

			if (visited[nx][ny] || arr[nx][ny] <= height) continue;

			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > maxh) maxh = arr[i][j];
			if (arr[i][j] < lowh) lowh = arr[i][j];
		}
	}

	for (int h = lowh; h <= maxh; h++) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] || arr[i][j] <= h) continue;
				bfs(i, j, h);
				cnt++;
			}
		}
		if (cnt > ans) ans = cnt;
	}

	printf("%d", ans);
}
