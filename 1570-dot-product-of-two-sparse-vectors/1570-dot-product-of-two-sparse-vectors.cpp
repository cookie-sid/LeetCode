class SparseVector {
public:
    
    vector<pair<int,int>> v;
    int size;
    
    SparseVector(vector<int> &nums) {
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                v.push_back(make_pair(nums[i],i));
            }
        }
        size = v.size();
        
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int start = 0, ans = 0;
        for(int i = 0; i < vec.size and start < size; i++) {
            if(vec.v[i].second < v[start].second) {
                continue;
            }
            else if(vec.v[i].second == v[start].second) {
                ans += vec.v[i].first * v[start].first;
                start++;
            }
            else {
                start++;
                i--;
            }
        }
        return ans;
    }
    
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);