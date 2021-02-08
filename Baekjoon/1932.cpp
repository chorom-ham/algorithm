#include <cstdio>
#include <algorithm>
using namespace std;

int triangle[500][500], best[500][500];
int l, ans = 0;

int main() {
	scanf("%d", &l);
	
	for(int i = 0; i < l; i++){
        for(int j = 0; j <= i; j++){
            scanf("%d", &triangle[i][j]);
        }
    }
	
	best[0][0] = triangle[0][0];
	
    for(int i = 1; i < l; i++){
        for(int j = 0; j <= i; j++){
        	if (j == 0) best[i][j] = best[i-1][0] + triangle[i][j];
            else best[i][j] = triangle[i][j] + max(best[i-1][j-1], best[i-1][j]);
            
            ans = max(best[i][j], ans);
        }
    }
  
    printf("%d", ans);
	return 0;
}
