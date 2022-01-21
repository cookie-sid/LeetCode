class Solution {
public:
    
    bool checkifcycle(set<int>& alreadytaken, int toComp, vector<vector<int>>& graph, vector<bool>& done) {
        if(alreadytaken.count(toComp) == 1) {
            return true;
        }
        
        alreadytaken.insert(toComp);
        bool ans = true;
        for(int i = 0; i < graph[toComp].size(); i++) {
            if(done[graph[toComp][i]]) {
                continue;
            }
            else {
                if(checkifcycle(alreadytaken, graph[toComp][i], graph, done)) {
                    return true;
                }
                done[graph[toComp][i]] = true;
            }
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereq_for(numCourses);
        for(auto x : prerequisites) {
            prereq_for[x[0]].push_back(x[1]);
        }
        vector<bool> done(numCourses);
        for(int i = 0; i < numCourses; i++) {
            if(prereq_for[i].size() == 0) {
                done[i] = true;
            }
            else {
                set<int> s;
                if(checkifcycle(s,i,prereq_for,done)) {
                    return false;
                }
            }
        }
        return true;
    }
};