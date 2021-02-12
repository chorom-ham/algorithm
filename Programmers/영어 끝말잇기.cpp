#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    char temp;
    
    for(int i=0;i<words.size();++i){
        string word=words[i];
        //제대로 된 단어인지 확인
        if(i==0) temp=word[word.length()-1];
        else{
            if(temp!=word[0]){
                answer.push_back(i%n+1);
                float order = float(i+1)/float(n);
                answer.push_back(ceil(order));
                return answer;
            }
            temp=word[word.length()-1];
        }
        //이전에 안나온 단어인지 확인
        for(int j=0;j<i;++j){
            if(words[j]==word){
                answer.push_back(i%n+1);
                float order = float(i+1)/float(n);
                answer.push_back(ceil(order));
                return answer;
            }
        }
    }
    
    return {0,0};
}
