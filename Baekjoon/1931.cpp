#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 회의 개수
vector<pair<int, int>> schedule; // 회의별 (시작, 끝)시간을 pair로 벡터에 저장 
int ans;

// 끝나는 시간이 빠른 순대로 정렬. 같으면 시작하는 시간이 빠른 게 앞에 온다
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		schedule.push_back(make_pair(start, end));
	}
	
	sort(schedule.begin(), schedule.end(), cmp);

	ans = 1;
	int last_finished = schedule[0].second;

	for (int i = 1; i < n; i++) {
		if (schedule[i].first < last_finished) {
			continue;
		}
		ans++;
		last_finished = schedule[i].second;
	}

	printf("%d", ans);
}
