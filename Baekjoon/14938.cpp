#include <cstdio>
#include <vector>
#include <queue>
#define INF 1500 + 1
using namespace std;

int n, m, r;
vector<pair<int, int>> v[101];
int item[101];
int dist[101];
int ans = 0;

int max(int a, int b) {
	return a > b ? a : b;
}

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nCost = v[cur][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				pq.push({ -dist[next],next });
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &item[i]);
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		v[a].push_back({ b,l });
		v[b].push_back({ a,l });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[j] = INF;
		}
		dijkstra(i);
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[j] <= m) {
				tmp += item[j];
			}
		}
		ans = max(ans, tmp);
	}

	printf("%d", ans);
	return 0;
}
