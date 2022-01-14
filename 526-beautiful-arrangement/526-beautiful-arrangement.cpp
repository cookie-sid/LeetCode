class Solution {
public:
    int countArrangement(int n) {
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        
        vector<vector<int>> permuts;
        permuts.push_back({1,2});
        permuts.push_back({2,1});
        for(int i = 3; i <= n; i++) {
             
            set<vector<int>> new_permuts;
            for(int k = 0; k < permuts.size(); k++) {
                for(int l = 0; l < permuts[k].size(); l++) {
                    int curr = permuts[k][l];
                    if(i % curr == 0 and (i % (l + 1) == 0)) {
                        vector<int> temp_v = permuts[k];
                        int temp = curr;
                        temp_v[l] = i;
                        temp_v.push_back(temp);
                        new_permuts.insert(temp_v);
                    }
                }
            }
            
            for(auto x : permuts) {
                vector<int> always = x;
                always.push_back(i);
                new_permuts.insert(always);
            }
            
            for(auto y : new_permuts) {
                vector<int> x = y;
                for(int j = 0; j < x.size() - 1; j++) {
                    for(int k = j + 1; k < x.size(); k++) {
                        if(x[j] == i or x[k] == i){
                            continue;
                        }
                        if((x[k] % (j+1) == 0 or (j + 1)%x[k] == 0) and (x[j] % (k+1) == 0 or (k + 1)%x[j] == 0)) {
                            int temp = x[j];
                            x[j] = x[k];
                            x[k] = temp;
                            new_permuts.insert(x);
                        }
                    }
                }
            }
            
            permuts.clear();
            for(auto x : new_permuts) {
                permuts.push_back(x);
            }
            

        }
        return permuts.size();
    }
};