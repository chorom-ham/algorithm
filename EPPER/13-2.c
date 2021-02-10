#include <stdio.h>

int m, n, sort = 0, count = 0;
int money[8] = { 50000,10000,5000,1000,500,100,50,10 };

int main() {

	scanf("%d", &m);
	scanf("%d", &n);
	
	// 처리해야 할 남은 거스름돈 금액
	// (지불한 금액) - (물품 가격)으로 초기화
	int change = m - n;
	
	// 금액이 큰 화폐 단위 순으로 거스름돈을 처리할 수 있는지 확인
	for (int i = 0; i < 8; i++) {
		int isUsed = 0;  // 0: false, 1: true
		
		// 현재 확인하고 있는 화폐가 지불해야 하는 남은 거스름돈 금액보다 작다면 해당 화페 사용 
		while (change >= money[i]) {
			// 사용한 횟수만큼 count에 값을 더해줌
			// 해당 화폐 사용할 때마다 현재 남은 거스름돈 금액 업데이트
			// 해당 화폐를 사용했다면 해당 금액의 화폐를 사용했는지 체크하는 isUsed값을 true(1)로 업데이트
			change = change - money[i];
			count = count + 1;
			isUsed = 1;
		}
		// 해당 금액권의 화폐를 사용 가능한지 끝까지 확인했다면(while문을 탈출했다면)
		// isUsed 값에 따라 화폐 종류 개수를 체크하는 sort변수의 값을 업데이트한다
		if (isUsed) sort = sort + 1;
	}

	printf("%d %d", sort, count);
}
