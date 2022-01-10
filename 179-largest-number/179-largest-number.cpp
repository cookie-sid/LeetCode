class Solution {

public:
    
    static bool comp(int a, int b)
    {
        string tempa = to_string(a);
        string tempb = to_string(b);
        string fin1 = tempa + tempb;
        string fin2 = tempb + tempa;
        if(fin1 > fin2)
        {
            return true;
        }
        else
        {
            return false;
        }
        return false;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        bool allzeros = true;
        for(auto x : nums)
        {
            if(x != 0)
            {
                allzeros = false;
            }
        }
        if(allzeros)
            return "0";
        string ans = "";
        for(auto x : nums)
        {
            ans += to_string(x);
        }
        return ans;
    }
};