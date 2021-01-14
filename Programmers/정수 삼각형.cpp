#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int best[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int l = triangle.size();
    for(int i=1; i<l+1; i++){
        for(int j=1; j<i+1; j++){
            best[i][j] = triangle[i-1][j-1] + max(best[i-1][j-1], best[i-1][j]); 
        }
    }
    
    for(int i=1; i<l; i++){
        answer = max(best[l][i], answer);
    }                  
                                                  
    return answer;
}
