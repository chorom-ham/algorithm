#include <cstdio>
#include <algorithm>
#define INF 271
using namespace std;

int N, M, H, ans = INF;
bool visited[11][30];

bool do_ladder_game() {
	for (int i = 1; i <= N; i++) {
		int current_location = i;
		for (int j = 1; j <= H; j++) {
			if (visited[current_location][j]) {
				current_location = current_location + 1;
			}
			else if (visited[current_location - 1][j]) {
				current_location = current_location - 1;
			}
		}

		if (current_location != i) {
			return false;
		}
	}
	return true;
}

void select_line(int index, int count){
	if (count >= 4) return;

	if (do_ladder_game() == true) {
		ans = min(ans, count);
		return;
	}

	for (int i = index; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (visited[j][i]) continue;
			if (visited[j - 1][i]) continue;
			if (visited[j + 1][i]) continue;

			visited[j][i] = true;
			select_line(i, count + 1);
			visited[j][i] = false;
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		visited[b][a] = true;
	}

	select_line(1, 0);

	if (ans == INF) ans = -1;

	printf("%d",ans);
	
	return 0;
}
