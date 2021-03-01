#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    // 첫 차 나가는 지점
    int temp = routes[0][1];
    
    for (auto car : routes) {
        // 이번 차 들어오는 지점이 직전 차 나가는 지점보다 앞이면(이어져 있지 않으면)
        if (temp < car[0]) {
            answer++;
            temp = car[1];
        }
        
        //직전 차보다 이번 차가 먼저나가면 
        if (temp >= car[1]) {
            temp = car[1];
        }
    }
    
    return answer;
}
