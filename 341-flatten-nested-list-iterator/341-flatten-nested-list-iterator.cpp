/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    int i = -1;
    vector<int> ans;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        bool nestedListPresent = false;
        int n = nestedList.size();
        
        while(true) {
            
            nestedListPresent = false;
            
            vector<NestedInteger> temp;
            
            for(int i = 0; i < nestedList.size(); i++) {
                if(!nestedList[i].isInteger()) {
                    nestedListPresent = true;
                    vector<NestedInteger> tempList = nestedList[i].getList();
                    for(int j = 0; j < tempList.size(); j++) {
                        temp.push_back(tempList[j]);
                    }
                }
                else {
                    temp.push_back(nestedList[i]);
                }
            }
            
            nestedList = temp;
            if(nestedListPresent == false) {
                break;
            }
        }
        
        for(auto x : nestedList) {
            ans.push_back(x.getInteger());
        }
        
    }
    
    int next() {
        i += 1;
        return ans[i];
    }
    
    bool hasNext() {
        return i + 1 < ans.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */