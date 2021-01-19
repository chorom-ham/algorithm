#include<iostream>
#include<utility>
#include<queue>
#include<cmath>
#define MAX 10
using namespace std;

int n, m;
char arr[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX];
pair<int, int> red, blue;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

struct INFO {
	int rx, ry, bx, by, count;
};

void BFS() {
	queue<INFO> q;
	q.push({ red.first,red.second,blue.first,blue.second, 0 });
	visit[red.first][red.second][blue.first][blue.second] = true;

	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int count = q.front().count;
		q.pop();

		for (int i = 0; i < 4; i++) {
			bool isRedInHole = false;
			bool isBlueInHole = false;

			int nrx = rx + dx[i];
			int nry = ry + dy[i];
			int nbx = bx + dx[i];
			int nby = by + dy[i];
			int nCount = count + 1;
			if (nCount > 10) {
				cout << -1;
				return;
			}

			while (1) {
				if (arr[nrx][nry] == '#') {
					break;
				}
				if (arr[nrx][nry] == 'O') {
					isRedInHole = true;
					break;
				}
				nrx = nrx + dx[i];
				nry = nry + dy[i];
			}
			nrx = nrx - dx[i];
			nry = nry - dy[i];

			while (1) {
				if (arr[nbx][nby] == '#') {
					break;
				}
				if (arr[nbx][nby] == 'O') {
					isBlueInHole = true;
					break;
				}
				nbx = nbx + dx[i];
				nby = nby + dy[i];
			}
			nbx = nbx - dx[i];
			nby = nby - dy[i];

			if (isBlueInHole) {
				continue;
			}
			if (isRedInHole) {
				cout << nCount; 
				return;
			}

			if (nrx == nbx && nry == nby) {
				int rdis = abs(rx - nrx) + abs(ry - nry);
				int bdis = abs(bx - nbx) + abs(by - nby);
				if (rdis > bdis) {
					nrx = nrx - dx[i];
					nry = nry - dy[i];
				}
				else {
					nbx = nbx - dx[i];
					nby = nby - dy[i];
				}
			}
			if (visit[nrx][nry][nbx][nby]) {
				continue;
			}
			visit[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,nCount });
		}
	}
	cout << -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				red = make_pair(i, j);
				arr[i][j] = '.';
			}
			if (arr[i][j] == 'B') {
				blue = make_pair(i, j);
				arr[i][j] = '.';
			}
		}
	}

	BFS();

	return 0;
}
