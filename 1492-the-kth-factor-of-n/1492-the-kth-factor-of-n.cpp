class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> facs(n + 1);
        int first = 0, last = n;
        int total = 0;
        for(int i = 1; i <= (int)sqrt(n); i++) {
            if(n % i == 0 and (n/i) != i) {
                facs[first++] = i;
                facs[last--] = n/i;
                total += 2;
            }
            if(n%i == 0 and n/i == i) {
                facs[last--] = i;
                total += 1;
            }
        }
        for(auto x: facs) {
            cout<<x<<" ";
        }
        if(total < k) {
            return -1;
        }
        if(k - 1 < total/2) {
            return facs[k - 1];
        }
        return facs[n - (total - k)]; 
    }
};