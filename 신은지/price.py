def solution(prices):
    answer = [0 for i in range(len(prices))]
    stack = []
    for i in range(len(prices)-1):
        stack.append([prices[i], i])
        for (price, index) in stack[::-1]:
            answer[index] += 1
            if prices[i+1] < price:
                stack.pop()
    return answer
