#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>

using namespace std;

int n, m;

string s;

map<string, int> map1;   //문자열 기준으로 정렬
string map2[100001];     //번호 기준으로 정렬

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		map1.insert(pair<string, int>(s, i));
		map2[i] = s;
	}
}


void solution() {
	for (int i = 0; i < m; i++) {
		cin >> s;

		if (isdigit(s[0])) {
			cout << map2[atoi(s.c_str()) - 1] << "\n";
		}
		else {
			cout << map1[s] + 1 << "\n";
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	input();
	solution();
	return 0;
}
