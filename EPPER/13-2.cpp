#include <cstdio>

int m, n, sort = 0, count = 0;
int money[8] = { 50000,10000,5000,1000,500,100,50,10 };

int main() {

	scanf("%d", &m);
	scanf("%d", &n);

	int change = m - n;

	for (int i = 0; i < 8; i++) {
		bool isUsed = false;
		while (change >= money[i]) {
			change = change - money[i];
			count = count + 1;
			isUsed = true;
		}

		if (isUsed) sort = sort + 1;
	}

	printf("%d %d", sort, count);
}
