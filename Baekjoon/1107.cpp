#include<cstdio>
#include<cmath>
using namespace std;

bool broken[10];

// n으로 이동할 수 있는지 확인하고, 바로 이동 가능할 때 n으로 이동하려면 눌러야 하는 횟수 리턴
int check(int n) {
    if (n == 0) {
        if (broken[0]) {
            return 0;
        }
        else {
            return 1;
        }
    }

    int len = 0;

    while (n > 0) {
        if (broken[n % 10]) return 0;
        n = n / 10;
        len += 1;
    }

    return len;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int j;
        scanf("%d", &j);
        broken[j] = true;
    }


    // +/-로 중복없이 하나하나 이동했을 때 이동횟수로 초기화
    int ans = abs(n - 100);

    for (int i = 0; i <= 1000000; i++) {
        int c = i;
        int len = check(c);

        if (len > 0) {
            int press = abs(c - n);

            // 비교해서 더 작은 값으로 갱신
            if (ans > press + len) {
                ans = press + len;
            }
        }
    }

    printf("%d", ans);
    return 0;
}
