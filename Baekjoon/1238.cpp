#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 1000000
#define INF 101

using namespace std;

int n, m, x;
vector<pair<int, int>> v[MAX];
int dist[MAX], total[MAX];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i].first;
            int nCost = v[current][i].second;

            if (dist[next] > cost + nCost) {
                dist[next] = cost + nCost;
                pq.push({ -dist[next],next });
            }
        }
    }
}

int main(void) {
    scanf("%d %d %d", &n, &m, &x);

    for (int i = 0; i < m; i++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        v[a].push_back({ b,t });
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[j] = INF;
        }
        dijkstra(i);
        total[i] = dist[x];
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dijkstra(x);
    for (int i = 1; i <= n; i++) {
        total[i] += dist[i];
    }

    sort(total + 1, total + n + 1);
    printf("%d", total[n]);

    return 0;
}
