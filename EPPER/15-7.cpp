#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int solution(int s[], int e[], int N){
	int answer = 0;
	int e1 = -1, e2 = -1;
	
	for (int i = 0; i < N; i++) {
		v.push_back({s[i], e[i]});
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++){
		if (e1 <= v[i].first){
			answer++;
			e1 = v[i].second;
		}
		else if (e2 <= v[i].first){
			e2 = e1;
			e1 = v[i].second;
			answer++;
		}
	}

	return answer;
}

int main() {
	int s[1000];
	int e[1000];
	int N = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &s[i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &e[i]);
	
	printf("%d", solution(s, e, N));
	return 0;
}
