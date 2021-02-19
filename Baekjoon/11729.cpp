#include <cstdio>
#include <cmath>
using namespace std;

void move(int from, int to) {
	printf("%d %d\n", from, to);
}

void hanoi(int n, int from, int to, int via) {
	if (n == 1) move(from, to);
	else {
		hanoi(n - 1, from, via, to);
		move(from, to);
		hanoi(n - 1, via, to, from);
	}
	return;
}

void hanoiNum(int in) {
	if (in == 1) printf("%d\n", 1);
	else {
		int num = pow(2, in) - 1;
		printf("%d\n", num);

	}
}

int main() {
	int in = 0;
	scanf("%d", &in);
	hanoiNum(in);
	hanoi(in, 1, 3, 2);
}

