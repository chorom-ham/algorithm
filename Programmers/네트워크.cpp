#include <vector>

using namespace std;

bool dfs(int n, vector<vector<int>>& computers) {
    if (!computers[n][n])    return false;
    computers[n][n] = 0; // 방문 체크
    for (int i = 0; i < computers.size(); i++) {
        if (computers[n][i]) dfs(i, computers);
    }
    return true;
}



int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
       if (computers[i][i] && dfs(i, computers)) answer++;
    }   
    
    return answer;
}
