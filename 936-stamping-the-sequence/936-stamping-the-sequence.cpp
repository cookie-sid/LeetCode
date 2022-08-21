class Solution {
public:
    
    vector<int> movesToStamp(string stamp, string target) {
        
        
        map<string,bool> pref,suff;
        string s = "";
        for(int i = 0; i < stamp.length(); i++) {
            s += stamp[i];
            suff[stamp.substr(i)] = true;
            pref[s] = true;
        }
        
        vector<int> indices;
        int pos = -1;
        while(target.find(stamp,pos + 1) != string::npos) {
            indices.push_back(target.find(stamp,pos + 1));
            pos = target.find(stamp,pos + 1);
        }
        
        int last = -1;
        vector<int> ans;
        for(int i = 0; i < indices.size(); i++) {
            if(last > indices[i])
                continue;
            ans.push_back(indices[i]);
            int start = indices[i];
            string tmp = "";
            int lastPushed = -1;
            while(start - 1 > last) {
                start -= 1;
                tmp = target[start] + tmp;
                if(pref.find(tmp) != pref.end()) {
                    ans.push_back(start);
                    lastPushed = start;
                    tmp = "";
                }
            }
            last = indices[i] + stamp.length() - 1;
            
            if(lastPushed != start and tmp != "") {
                bool found = false;
                for(auto x : pref) {
                    cout<<tmp<<endl;
                    if(x.first.find(tmp) != string::npos) {
                        found = true;
                        ans.push_back(start - x.first.find(tmp));
                        break;
                    }
                }
                if(!found) {
                    return {};
                }
            }
            start = last;
            tmp = "";
            while(start + 1 < target.length()) {
                start += 1;
                tmp += target[start];
                if(suff.find(tmp) != suff.end()) {
                    ans.push_back(start - stamp.length() + 1);
                    last = start;
                    tmp = "";
                }
                if(tmp.length() > stamp.length())
                    break;
            }
        }
        if(last != target.length() - 1)
            return {};
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};