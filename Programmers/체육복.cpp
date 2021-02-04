#include <string>
#include <vector>

using namespace std;

int arr[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i=1;i<n+1;i++){
        arr[i]=1;
    }
    for(int i=0;i<lost.size();i++){
        arr[lost[i]]=0;
    }
    for(int i=0;i<reserve.size();i++){
        arr[reserve[i]] += 1;
    } 
    for(int i=1;i<n+1;i++){
        if(arr[i]==0){
            if(arr[i-1]>1){
                arr[i]=1;
                arr[i-1] -= 1;
            }else if(arr[i+1]>1){
                arr[i]=1;
                arr[i+1] -= 1;
            }
        }
    }
    
    for(int i=1;i<n+1;i++){
        if(arr[i]>0) answer++;
    }
    
    return answer;
}
