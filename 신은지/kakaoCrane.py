def solution(board, moves):
    # 바구니 리스트 선언
    basket = []
    answer = 0
    boardSize= len(board)
    for row in moves:
        row = row - 1
        for col in range(boardSize):
            if (board[col][row]):
                basket.append(board[col][row])
                board[col][row] = 0
                break
        index= len(basket) - 1
        if (index > 0):
            if(basket[index] == basket[index-1]):
                basket.pop()
                basket.pop()
                answer= answer + 2

    return answer
