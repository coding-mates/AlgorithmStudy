def solution(n):
    answer = ""
    while n//3 > 0 :
        answer += str(n%3)
        if n%3:
            n = n//3
        else:
            n = n//3-1
    if n:
        answer += str(n)
    answer = answer[::-1]
    answer = answer.replace("0", "4")
    return answer
