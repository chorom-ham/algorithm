#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
int cnt;
int map[101][101];
int visited[101][101];
vector<int> result;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void DFS(int y, int x){
	visited[y][x] = 1;
	cnt++;
	
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx<0 || ny<0 || nx >= n || ny >= m) continue;
		if(map[ny][nx]==0 && visited[ny][nx]==0){
			DFS(ny,nx);
		}
	}
	
}

int main() {
	scanf("%d %d %d", &m, &n, &k);
	
	for(int i=0; i<k; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		for (int y = y1; y < y2; y++){
			for (int x = x1; x < x2; x++){
				map[y][x] = 1;
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(map[i][j]==0 && visited[i][j]==0){
				cnt = 0;
				DFS(i,j);
				result.push_back(cnt);
			}
		}
	}
	
	sort(result.begin(), result.end());
	
	printf("%d\n", result.size());
	for (int i = 0; i < result.size(); i++){
		printf("%d ", result[i]);
	}
	
	return 0;
}
