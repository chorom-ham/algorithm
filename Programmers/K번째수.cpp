def solution(array, commands):
    answer = []
    
    for n in range(len(commands)):
        temp = []
        i = commands[n][0]
        j = commands[n][1]
        k = commands[n][2]
        temp = array[i-1:j]
        temp.sort()
        answer.append(temp[k-1])
    
    return answer
