from itertools import combinations

def solution(numbers,target):
    plus = list((len(numbers)) * '+')
    print(len(numbers))
    cnt = 0
    for i in range(len(numbers) + 1):
        combination = list(combinations(list(range(len(numbers))),i))
        for combi in combination:
            oper = plus.copy()
            for idx in combi:
                oper[idx] = '-'
            sik = ''
            tempVal = 0
            for j in range(len(numbers)):
                if oper[j] == '-':
                    tempVal -= numbers[j]
                else :
                    tempVal += numbers[j]
            if(tempVal == target):
                cnt += 1
    return cnt
solution([1, 1, 1, 1, 1],3)