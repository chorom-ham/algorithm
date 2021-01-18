#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b){
    if(a.length()<b.length()) return true;
    else return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> v;
    vector<vector<int>> intv;
    vector<int> temp;
    
    //양쪽 괄호 제거
    string str=s.substr(1,s.size()-2);
    
    istringstream ss(str);
    string stringBuffer;
    string stringBuffer2;
    while (getline(ss, stringBuffer, '{'))
    {
        istringstream ss2(stringBuffer);
        getline(ss2, stringBuffer2, '}');
        v.push_back(stringBuffer2);
    }
    
    sort(v.begin(), v.end(),compare);
    
    for(int i=0;i<v.size();++i){
        istringstream iss(v[i]);
        string st;
        while(getline(iss, st, ',')){
            int num=stoi(st);
            temp.push_back(num);
        }
        intv.push_back(temp);
        while(!temp.empty()) temp.pop_back();
    }
    answer.push_back(intv[1].at(0));
    for(int i=2;i<intv.size();++i){
        for(int j=0;j<intv[i].size();++j){
            for(int k=0;k<intv[i-1].size();++k){
                if(intv[i][j]==intv[i-1][k]) break;
                else if((k==intv[i-1].size()-1)&&(intv[i][j]!=intv[i-1][k])) answer.push_back(intv[i][j]);
            }
        }
    }
    
    return answer;
}
