#include <string>
#include <vector>

using namespace std;

int ans;

void dfs(int cur, int i, vector<int>& numbers, int target) {
    if(i == numbers.size()) {
        if(cur == target) ans++;
        return;
    }
    
    dfs(cur + numbers[i], i + 1,  numbers, target);
    dfs(cur - numbers[i], i + 1,  numbers, target);
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, numbers, target);
    
    return ans;
}
