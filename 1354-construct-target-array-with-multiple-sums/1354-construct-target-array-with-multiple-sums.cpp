class Solution {
public: 
    
    // 3 5 9 -> 3 5 17 -> 3 5 25
    
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) {
            return target[0] == 1;
        }
        
        priority_queue<long long> pq;
        long long ones = 0, onesMade = 0, sum = 0;
        for(auto x : target) {
            pq.push((long long)x);
            if(x == 1) {
                ones++;
            }
            sum += x;
        }
        while(pq.top() != 1) {
            long long biggest = pq.top();
            pq.pop();
            if(sum - biggest >= biggest and sum - biggest != 1) {
                return false;
            }
            long long numAtThatPos = sum - biggest == 1 ? 1 : biggest % (sum - biggest);
            if(numAtThatPos < 1) {
                return false;
            }
            if(numAtThatPos == 1) {
                onesMade++;
            }
            pq.push(numAtThatPos);
            sum -= biggest;
            sum += numAtThatPos;
            cout<<pq.top()<<" ";
        }
        if(onesMade + ones == target.size())
            return true;
        
        return false;
        
    }
};