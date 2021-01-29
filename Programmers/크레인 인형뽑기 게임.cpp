#include <string>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> s;
    int answer = 0;
 
    for(int i = 0; i < moves.size(); ++i){
        int move = moves[i]-1;
        for(int j = 0; j < board.size(); ++j){
            int num = board[j][move];
            if(num != 0){
                if(!s.empty()&&s.top()==num){
                    s.pop();
                    answer+=2;
                }
                else s.push(num);
                board[j][move]=0;
                break;
           }
        }
    }

   
    
    return answer;
}
