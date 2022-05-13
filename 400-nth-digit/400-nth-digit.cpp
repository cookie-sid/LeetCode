class Solution {
public:
    int findNthDigit(int n) {
        int a = (1<<30) - 1 + (1<<30);
        vector<int> vals;
        vals.push_back(0);
        long long curr = 9;
        while(curr <= a) {
            vals.push_back(curr);
            curr *= 10;
        }
        int nums = 0;
        int ind = 1;
        while(n > 0) {
            if(ceil((double)n/ind) > vals[ind]) {
                n -= vals[ind]*ind;
                nums += vals[ind];
            }
            else {
                nums += n/ind;
                int rem = n%ind;
                if(rem == 0) {
                    return nums%10;
                }
                else {
                    return to_string(nums + 1)[rem - 1] - '0';
                }
            }
            ind++;
        }
        return 0;
    }
};