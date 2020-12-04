def solution(skill, skill_trees):
    answer = 0
    for skillTree in skill_trees:
        sequence = list(skill)
        for index, letter in enumerate(skillTree):
            try:
                if not sequence.index(letter):
                    sequence.remove(letter)
                else:
                    break
            except:
                pass
            if index == len(skillTree)-1:
                answer += 1
    return answer
