#include <cstdio>

int fib[41];

void fibonacci() {  
	for (int i = 0; i <= 41; i++) {
		if (i == 0) {
			fib[i] = 0;
		}
		else if (i == 1) {
			fib[i] = 1;
		}
		else {
			fib[i] = fib[i - 1] + fib[i - 2];
		}
	}
}

int main() {
	int caseNum, input;
	fibonacci();

	scanf("%d", &caseNum);
	for (int i = 0; i < caseNum; ++i) {
		scanf("%d", &input);
		if (input == 0) printf("%d %d\n",1,0);
		else printf("%d %d\n", fib[input-1], fib[input]);
	}
}
