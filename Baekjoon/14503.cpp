#include <cstdio>
#define MAX 51

// 북 동 남 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m, r, c, d;
int map[MAX][MAX]; // 0: 빈칸, 1: 벽
int ans = 0; // 청소 영역 개수

void input() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void solution() {
	int nr, nc, nd;

	while (true) {
		if (map[r][c] == 0) {
			map[r][c] = 2;  // 현재 위치를 청소한다
			ans++;
		}
		
		bool flag = false; // 왼쪽 방향으로 전진 가능한지 여부
		for (int i = 0; i < 4; i++) { // 차례로 탐색 진행
			d -= 1;
			if (d < 0) d = 3;
			nr = r + dx[d];
			nc = c + dy[d];
			if (map[nr][nc] == 0) { // 2 - 1
				r = nr;
				c = nc;
				flag = true;
				break;
			}
		}

		// 전진. while문 내 처음으로 감.
		if (flag) continue;

		// 2 - 3 후진
		nd = d - 2;
		if (nd == -2) nd = 2;
		if (nd == -1) nd = 3;
		r = r + dx[nd];
		c = c + dy[nd];
		
		// 후진 불가 시 while문 탈출
		if (map[r][c] == 1) break;
	}
	printf("%d", ans);
}

int main() {
	input();
	solution();
}
