#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 벡터와 페어 자료구조에 대해 잘 모른다면 구글링해보세요 :)
// {시작시간, 종료시간}을 pair로 묶어 저장합니다
// v[i].first: i번 학생의 희망 시작시간, v[i].second: i번 학생의 희망 종료시간
vector<pair<int,int>> v;

// 종료 시간을 기준으로 비교합니다 (작은 것이 앞으로 오는 오름차순 정렬)
// 만약 종료 시간이 같다면 시작 시간이 더 빠른 것이 앞으로 옵니다
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
	
	// 벡터에 학생의 시작 시간과 종료 시간을 짝을 묶어 저장해주었습니다
	for (int i = 0; i < N; i++) {
		v.push_back({s[i], e[i]});
	}
	
	// C++ STL의 sort를 사용해 정렬합니다
	// 첫번째, 두번째 인자는 정렬 시작 위치와 끝 위치를 가리킵니다
	// 세번째 인자는 선택적으로 사용할 수 있습니다
	// 자체적인 정렬 기준이 필요할 때 사용하는 정렬 기준이 되는 함수입니다
	sort(v.begin(), v.end(), compare);

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
