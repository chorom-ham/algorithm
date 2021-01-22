#include <cstdio>
#include <cstring>
#define MAX 501
using namespace std;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

// sum: 지금까지 놓인 테트로미노 블락 칸에 쓰여있는 수의 합
// block: 놓은 정사각형 개수
void dfs(int x, int y, int sum, int block) {
	visited[x][y] = true;

	if (block == 4) {
		if (sum > ans) ans = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
			continue;
		}
		dfs(nx, ny, sum + map[nx][ny], block + 1);
		visited[nx][ny] = false;
	}
}

// dfs로 처리 불가능한 ㅗ,ㅜ,ㅏ,ㅓ 모양 처리
void specialShape(int x, int y) {
	int sum;
	// ㅗ
	if (x - 1 >= 0 && x + 1 < n && y + 1 < m) {
		sum = map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x + 1][y + 1];
		if (sum > ans) ans = sum;
	}
	// ㅜ
	if (x + 2 < n && y + 1 < m) {
		sum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
		if (sum > ans) ans = sum;
	}
	// ㅏ
	if (x + 1 < n && y + 2 < m) {
		sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1];
		if (sum > ans) ans = sum;
	}
	// ㅓ
	if (x - 1 >= 0 && y + 2 < m) {
		sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1];
		if (sum > ans) ans = sum;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, false, sizeof(visited));
			dfs(i, j, map[i][j], 1);
			specialShape(i, j);
		}
	}
	printf("%d", ans);
}
