// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        long long start = 0;
        for(int i = n; i >= 1; i/=2) {
            while(start + i <= n and !isBadVersion(start + i))
                start += i;
        }
        return start + 1;
    }
};