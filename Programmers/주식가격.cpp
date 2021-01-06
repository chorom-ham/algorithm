#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    
    int num = prices.size();
    for(int i=0; i<prices.size(); ++i){
        bool flag = true;
        int p = prices[i];
        for(int j=i+1; j<prices.size(); ++j){
            if(p>prices[j]){
                answer.push_back(j-i);
                flag=0;
                break;
            }
        }
        if(flag) answer.push_back(num-i-1);
    }
    
    return answer;
}
