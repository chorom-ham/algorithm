#include <cstdio>
#include <string>
#include <cstring>
#define MAX 988
using namespace std;

bool arr[MAX];
int n, answer, strike, ball, possible;
string one, two;

void initialize() {
	memset(arr, true, sizeof(arr)); //초기화
	int a, b, c;

	for (int i = 0; i < 123; i++) {
		arr[i] = false;
	}

	for (int i = 123; i < 988; i++) {
		a = i / 100;
		b = i / 10 - 10 * a;
		c = i % 10;

		if (a == b || b == c || c == a) {
			arr[i] = false;
		}
		if (a == 0 || b == 0 || c == 0) {
			arr[i] = false;
		}
	}
}

void check() {
	for (int i = 123; i < 988; i++) { //정답 가능성이 있는 모든 수를 정답이라고 가정하고 확인
		int strikeCount = 0, ballCount = 0; //테스트용
		one = to_string(answer);
		two = to_string(i);

		if (arr[i]) { //정답일 가능성이 있는 수만 확인
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					if (x == y && one[x] == two[y]) strikeCount++;
					if(x != y && one[x] == two[y]) ballCount++;
				}
			}
			if (strike != strikeCount || ball != ballCount) {
				arr[i] = false;
			}
		}
	}
}

int main() {
	initialize();
	int a, b, c;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &answer, &strike, &ball);
		check();
	}

	for (int i = 123; i < MAX; i++) {
		if (arr[i] == true)
			possible++;
	}

	printf("%d", possible);

	return 0;
}
