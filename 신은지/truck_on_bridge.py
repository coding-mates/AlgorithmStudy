def solution(bridge_length, weight, truck_weights):
    on_bridge = [0 for _ in range(bridge_length)]
    timer = 0
    while len(truck_weights):
        timer += 1
        on_bridge.pop(0)
        if sum(on_bridge) + truck_weights[0] > weight:
            on_bridge.append(0)
        else:
            on_bridge.append(truck_weights.pop(0))
    answer = timer + bridge_length
    return answer
