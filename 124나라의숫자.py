def solution(num):
    strs = ''
    while(num > 0):
        if num % 3 == 0:
            strs = '4' + strs
            num = num // 3
            num -= 1
        else :
            strs = str(num % 3) + strs
            num = num // 3
    return strs