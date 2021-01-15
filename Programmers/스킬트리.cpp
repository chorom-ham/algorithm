#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> temp;
    
    for(int i=0;i<skill_trees.size();++i){
        string st = skill_trees[i];
        for(int j=0;j<st.length();++j){
            char a = st[j];
            for(int k=0; k<skill.length();++k){
                if(a==skill[k]){
                    temp.push_back(a);
                    break;
                }
            }
        }
        //가능한지 확인
        bool flag=1;
        for(int l=0;l<temp.size();++l){
           if(temp[l]!=skill[l]){
               flag=0;
               break;
           }
       }
        if(flag) answer+=1;
        temp.clear();
    }
    
  
    return answer;
}
