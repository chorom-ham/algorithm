#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 8
using namespace std;

int n, m;
int map[MAX][MAX]; // 0: 빈칸, 1: 벽, 2: 바이러스
int temp_map[MAX][MAX];
vector<pair<int, int>> virus;
vector<pair<int, int>> empty_map;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[MAX * MAX]; // 벽 조합 용
bool visited[MAX][MAX];

int ans;

void input() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				empty_map.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
}


void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//범위 체크
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
			
			if (!visited[nx][ny] && temp_map[nx][ny] == 0) {
				temp_map[nx][ny] = 2;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void count() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp_map[i][j] == 0) cnt++;
		}
	}
	ans = max(ans, cnt);
}

void spread_virus() {
	memset(visited, false, sizeof(visited));
	memcpy(temp_map, map, sizeof(map));

	int cnt = 0;
	// 벽 세우기 (1로 변경)
	for (int i = 0; i < empty_map.size(); i++) {
		if (cnt == 3) break;

		if (check[i]) {
			int x = empty_map[i].first;
			int y = empty_map[i].second;
			temp_map[x][y] = 1;
			cnt++;
		}
	}

	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		bfs(x, y);
	}

	count();
}

// 벽 3개 조합 찾기
void combination(int index, int count) {
	if (count == 3) {
		spread_virus();
		return;
	}

	for (int i = index; i < empty_map.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		combination(i + 1, count + 1);
		check[i] = false;
	}
}

int main() {
	input();
	combination(0, 0);
	printf("%d", ans);
}
