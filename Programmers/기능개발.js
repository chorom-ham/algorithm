function max(a, b){
    if(a>b) return a;
    else return b;
}

function solution(progresses, speeds) {
    var answer = [];
    var endDay = [];
    
    const taskNum = progresses.length;
    
    for(var i = 0; i < taskNum; i++){
        var day = 0;
        var progress = progresses[i];
        while(progress < 100){
            progress += speeds[i];
            day++;
        }
        endDay.push(day);
    }  
    
    var count = 1;
    
    for(var i = 1; i < taskNum; i++) {
        if (endDay[i-count] >= endDay[i]) {
            count++;
        }
        else {
            answer.push(count);
            count = 1;
        }
    }
    answer.push(count);
    
    return answer;
}
