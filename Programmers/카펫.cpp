#include <string>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int x, y; //x: answer[0], y: answer[1]
    int value = brown + yellow;
    //brown 개수: 2x + 2y - 4
    //yellow개수: (x-2)*(y-2)
    //brown + yellow: x*y
    
    for(int x = 1 ; x < value ; x++){     
        if(value % x != 0) continue;
        y = value / x;
        if(brown == (2 * x + 2 * y - 4) && yellow == (x - 2) * (y - 2)){
            answer.push_back(y);
            answer.push_back(x);
            return answer;
        }  
    }
    return answer;
}
