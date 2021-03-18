#include <cstdio>
#include <queue>
#include <vector>

#define MAX 20001
#define INF 200000 + 1
using namespace std;

int v, e, k;
vector<pair<int, int>> arr[20001];
int dist[20001];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	dist[k] = 0;
	pq.push({ 0, k });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nCost = arr[cur][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				pq.push({ -dist[next],next });
			}
		}
	}
}


int main() {
	scanf("%d %d %d", &v, &e, &k);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		arr[u].push_back({ v,w });
	}

	for (int i = 1; i <= v; i++) {
		dist[i] = INF;
	}

	dijkstra();

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}
