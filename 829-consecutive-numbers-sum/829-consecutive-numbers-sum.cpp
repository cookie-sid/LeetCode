class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        long long num = n;
        num *= 2;
        long long first = 1, second = 2, counter = 1;
        while((counter)*(counter + 1)/2 <= num/2) {
            if(num % counter != 0) {
                counter++;
                continue;
            }
            long long inter = num/counter;
            if((inter - 1 + counter) % 2 == 0) {
                ans++;
            }
            counter += 1;
        }
        return ans;
    }
};