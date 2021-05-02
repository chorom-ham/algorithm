#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <queue>
#define MAX 100

using namespace std;

int m, n;
string arr[MAX];
int visit[MAX][MAX];
int cnt[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int i, int j) {
	visit[i][j] = 1;

	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n && !visit[ny][nx] && arr[ny][nx]=='1') {
				cnt[ny][nx] = cnt[y][x] + 1;
				visit[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cnt[0][0] = 1;
	bfs(0, 0);
	printf("%d", cnt[n - 1][m - 1]);
	
	return 0; 
}
