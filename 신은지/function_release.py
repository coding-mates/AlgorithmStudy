def solution(progresses, speeds):
    answer = []
    days = []
    for index, prog in enumerate(progresses):
        if (100 - prog) % speeds[index]:
            n = (100 - prog) // speeds[index] + 1
        else:
            n = (100 - prog) // speeds[index]
        days.append(n)
    while len(days):
        release = 0
        for index in range(len(days)):
            if days[index] <= days[0]:
                release = index
            else:
                break
        days = days[release+1:]
        answer.append(release+1)
    return answer
