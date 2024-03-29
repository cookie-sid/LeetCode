class Solution {
public:
    
    void construct_segment_tree(vector<int>& segtree,
                            vector<int>& a, int n)
{
    // assign values to leaves of the segment tree
    for (int i = 0; i < n; i++)
        segtree[n + i] = a[i];
 
    /* assign values to internal nodes
    to compute maximum in a given range */
    for (int i = n - 1; i >= 1; i--)
        segtree[i] = max(segtree[2 * i],
                         segtree[2 * i + 1]);
}
 
void update(vector<int>& segtree, int pos, int value,
            int n)
{
    // change the index to leaf node first
    pos += n;
 
    // update the value at the leaf node
    // at the exact index
    segtree[pos] = value;
 
    while (pos > 1) {
 
        // move up one level at a time in the tree
        pos >>= 1;
 
        // update the values in the nodes in
        // the next higher level
        segtree[pos] = max(segtree[2 * pos],
                           segtree[2 * pos + 1]);
    }
}
 
int range_query(vector<int>& segtree, int left, int right, int n)
{
    /* Basically the left and right indices will move
        towards right and left respectively and with
        every each next higher level and compute the
        maximum at each height. */
    // change the index to leaf node first
    left += n;
    right += n;
 
    // initialize maximum to a very low value
    int ma = INT_MIN;
 
    while (left < right) {
 
        // if left index in odd
        if (left & 1) {
            ma = max(ma, segtree[left]);
 
            // make left index even
            left++;
        }
 
        // if right index in odd
        if (right & 1) {
 
            // make right index even
            right--;
 
            ma = max(ma, segtree[right]);
        }
 
        // move to the next higher level
        left /= 2;
        right /= 2;
    }
    return ma;
}
    
    int lengthOfLIS(vector<int>& nums, int k) {
        if(nums.size() == 1) {
            return 1;
        }
        vector<int> v(200003,0);
        int n = 200003;
        vector<int> segTree(2*n);
        construct_segment_tree(segTree,v,n);
        for(int i = nums.size() - 1; i >= 0; i--) {
            int maxi = range_query(segTree,nums[i] + 1,nums[i] + k + 1,n);
            // cout<<segTree[nums[i]+n+1]<<" "<<segTree[nums[i]+n+2]<<" "<<segTree[nums[i]+n+3]<<endl;
            // cout<<maxi<<" "<<nums[i]<<" ";
            update(segTree,nums[i],maxi + 1,n);
            // cout<<segTree[nums[i] + 100001]<<endl;
        }
        return range_query(segTree,0,100000,n);
    }
};