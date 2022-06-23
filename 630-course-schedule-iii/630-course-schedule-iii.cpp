class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        
        priority_queue<int> pq;
        int idx = 0, endTime = 0;
        for(int idx = 0; idx < courses.size(); idx++) {
            if(endTime + courses[idx][0] <= courses[idx][1]) {
                endTime += courses[idx][0];
                pq.push(courses[idx][0]);
            }
            else {
                if(!pq.empty() and pq.top() > courses[idx][0]) {
                    if(endTime + courses[idx][0] <= courses[idx][1]) {
                        endTime += courses[idx][0];
                        pq.push(courses[idx][0]);
                    }
                    else {
                        if(endTime - pq.top() + courses[idx][0] <= courses[idx][1]) {
                            endTime -= pq.top();
                            pq.pop();
                            endTime += courses[idx][0];
                            pq.push(courses[idx][0]);
                        }
                    }
                }
            }
           
        }
        
        return (int) pq.size();
    }
};