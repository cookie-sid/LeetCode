class Solution {
public:
    
    
    bool ds(string s, map<string,vector<string>> &m, map<string,bool> &supply, map<string,bool> &canBeMade) {
        if(canBeMade[s])
            return true;
        if(m.find(s) == m.end() and !supply[s]) {
            canBeMade[s] = false;
            return false;
        }
        if(m.find(s) == m.end() and supply[s]) {
            canBeMade[s] = true;
            return true;
        }
        for(auto ingre : m[s]) {
            if(canBeMade.find(ingre) == canBeMade.end()) {
                ds(ingre,m,supply,canBeMade);
            }
            if(!canBeMade[ingre]) {
                canBeMade[s] = false;
                return false;
            }
        }
        canBeMade[s] = true;
        return true;
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,vector<string>> m;
        vector<string> ans;
        for(int i = 0; i < recipes.size(); i++) {
            for(int j = 0; j < ingredients[i].size(); j++) {
                m[recipes[i]].push_back(ingredients[i][j]);
            }
        }
        map<string,bool> supply;
        for(auto x : supplies) {
            supply[x] = true;
        }
        map<string,bool> canBeMade;
        for(auto x : recipes) {
            if(ds(x,m,supply,canBeMade))
                ans.push_back(x);
        }
        return ans;
    }
};