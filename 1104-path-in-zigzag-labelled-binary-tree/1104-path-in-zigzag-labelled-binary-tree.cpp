class Solution {
public:
    
    
    vector<int> pathInZigZagTree(int label) {
        
        vector<int> graph;
        graph.push_back(1);
        int currIndex = 1, val = 2;
        int row = 1;
        while(val <= label) {
            row++;
            if(row % 2 == 0) {
                int start = val + pow(2,row-1) - 1;
                for(int i = 0; i < pow(2,row-1); i++) {
                    graph.push_back(start--);
                }
                val += pow(2,row-1);
            }
            else {
                for(int i = 0; i < pow(2,row-1) and val <= label; i++) {
                    graph.push_back(val++);
                }
            }
        }
        vector<int> ans;
        int end = graph.size() - 1;
        while(end >= 0 and graph[end] != label) {
            end--;
        }
        int currParent = end;
        while(currParent != 0) {
            ans.push_back(graph[currParent]);
            currParent = (currParent - 1)/2;
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};