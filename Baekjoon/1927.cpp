#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int N;
	priority_queue<int, vector<int>, greater<int>> pq;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);

		if (input == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n",pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}

	return 0;
}
