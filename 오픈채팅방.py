def solution(record):
    arr = {}; answer = []
    for i in record:
        str = i.split(' ')
        if str[0] == 'Enter' or str[0] == 'Change':
            arr[str[1]] = str[2]
    for i in record :
        str = i.split(' ')
        if str[0] == 'Enter' or str[0] == 'Leave':
            answer.append(arr[str[1]]+"님이 들어왔습니다.") if str[0] == 'Enter' else answer.append(arr[str[1]]+"님이 나갔습니다.")  
    return answer
