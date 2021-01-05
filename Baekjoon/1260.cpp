#include <cstdio>
#include <string.h>
#include <queue>
#define MAX 1001
using namespace std;

int graph[MAX][MAX]; // 입력으로 받은 정점들의 관계(간선)를 인접행렬에 저장한다
int visited[MAX];
int N, M, V; // 정점 개수, 간선 개수, 탐색 시작 정점 번호 

void input() {
	scanf("%d %d %d", &N, &M, &V);

	int v1, v2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
}

void dfs(int v) {
	visited[v] = 1;
	printf("%d ", v);

	for (int i = 1; i < N + 1; i++) {
		if (graph[v][i] == 1 && !visited[i]) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	memset(visited, 0, sizeof(int)*(N + 1));
	queue<int> q;
	
	visited[v] = 1;
	printf("%d ", v);
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i < N + 1; i++) {
			if (graph[v][i] == 1 && !visited[i]) {
				printf("%d ", i);
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

int main() {
	input();
	dfs(V);
	printf("\n");
	bfs(V);
}
