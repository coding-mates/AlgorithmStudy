#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define w first
#define t second
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // {weight, start_time}
    queue<pair<int, int>> bridge;
    int total_weights = 0;
    
    int idx = 0;
    for(int time = 1; ;time++){
        if(!bridge.empty() && bridge.front().t + bridge_length == time){
            total_weights -= bridge.front().w;
            bridge.pop();
        }

        if(bridge.empty() && idx == truck_weights.size()) return time;
        
        if(total_weights + truck_weights[idx] <= weight && idx != truck_weights.size()){
            total_weights += truck_weights[idx];
            bridge.push({truck_weights[idx++], time});
        }
    }
    
}
