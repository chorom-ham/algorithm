#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 삽입 정렬
void bubble_sort(int* s, int* e, int N) {
	int i, j, tmp;
    for (i = N - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if((e[j] > e[j + 1]) || (e[j] == e[j + 1] && s[j] > s[j + 1])) { // 끝나는 시간이 같은 경우는 시작 시간이 더 빠른 순으로 정렬
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
				tmp = e[j];
				e[j] = e[j + 1];
				e[j + 1] = tmp;
            }
        }
    }
}

int solution(int s[], int e[], int N){
	int answer = 0;
	int i, j, tmp, e1 = -1, e2 = -1;
	
	bubble_sort(s, e, N);

	for (int i = 0; i < N; i++){
		if (e1 <= s[i]){
			answer++;
			e1 = e[i];
		}
		else if (e2 <= s[i]){
			e2 = e1;
			e1 = e[i];
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
