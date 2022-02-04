class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        
        for(int i = 0; i < searchWord.length(); i++) {
            string curr = searchWord.substr(0,i + 1);
            int low = 0, high = products.size() - 1;
            vector<string> tempAns;
            while(low <= high) {
                int mid = (low + high)/2;
                string current = products[mid].substr(0,i + 1);
                if(current > curr) {
                    high = mid - 1;
                }
                else if(current < curr) {
                    low = mid + 1;
                }
                else {
                    if(mid == 0) {
                        int k = 0, count = 0;
                        while(k < products.size() and count < 3 and current == curr) {
                            tempAns.push_back(products[k]);
                            count++;
                            k++;
                            if(k < products.size())
                                current = products[k].substr(0,i + 1); 
                        }
                        break;
                    }
                    else {
                        if(products[mid - 1].substr(0,i+1) == current) {
                            high = mid - 1;
                        }
                        else {
                            int k = mid, count = 0;
                            while(k < products.size() and count < 3 and current == curr) {
                                tempAns.push_back(products[k]);
                                count++;
                                k++;
                                if(k < products.size())
                                    current = products[k].substr(0,i + 1); 
                            }
                            break;
                        }
                    }
                }
            }
            ans.push_back(tempAns);
        }
        return ans;
        
    }
};