class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int temp = 0, mini = 1e9, index = -1, neg = 0;
        for(int i = 0; i < gas.size(); i++) {
            temp += (gas[i] - cost[i]);
            if(gas[i] - cost[i] < 0) {
                neg += gas[i] - cost[i];
            }
            else {
                neg = 0;
            }
            mini = min(mini, gas[i] - cost[i]);
            mini = min(mini, neg);
        }
        if(temp < 0) {
            return -1;
        }
        int sum = 0;
        for(int i = 0; i < gas.size(); i++) {
            if(gas[i] - cost[i] < 0) {
                continue;
            }
            else {
                int sum = 0, ind = i, count = 0; 
                while(sum + gas[ind] - cost[ind] >= 0 and count <= gas.size()) {
                    sum += gas[ind] - cost[ind];
                    if(sum >= abs(mini)) {
                        return i;
                    }
                    ind++;
                    if(ind >= gas.size())
                        ind = 0;
                    count++;
                }
                if(ind > i) {
                    i = ind - 1;
                }
            }
        }
        return -1;
    }
};