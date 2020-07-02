Two conditions:
1. Sum of gas >= Sum of cost
2. If one cannot reach from station A to station B then he cannot reach station B from starting anywhere between A and B

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Check property 1
        int total = 0;
        for(int i = 0; i < gas.size(); i++)
            total += gas[i] - cost[i];
        if(total < 0)
            return -1;
        
        // Check property 2. There exists a unique soln, hence return return the first one that satisfies it.
        int start = 0;
        total = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                start = i+1;
                total = 0;
            }
        }
        return start;
    }
};
