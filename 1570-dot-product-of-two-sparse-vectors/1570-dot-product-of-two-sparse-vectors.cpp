class SparseVector {
public:
    
    vector<pair<int,int>> v;
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                this -> v.push_back(make_pair(nums[i],i));
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int start = 0, ans = 0;
        for(int i = 0; i < (int)this -> v.size() and start < (int)vec.v.size(); i++) {
            if(this -> v[i].second > vec.v[start].second) {
                start++;
                i--;
            }
            else if(this -> v[i].second == vec.v[start].second) {
                ans += this -> v[i].first * vec.v[start].first;
                start++;
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);