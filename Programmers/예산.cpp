#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    int w = budget;
    
    for(int i=0; i<d.size(); ++i){
        if(d[i]<=w){
            w-=d[i];
            answer+=1;
        }
    }
    
    return answer;
}
