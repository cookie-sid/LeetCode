class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num/2; i++) {
            int need = num - i;
            string tmp = to_string(need);
            reverse(tmp.begin(),tmp.end());
            int val = stoi(tmp);
            if(i == val) {
                return true;
            }
        }
        return false;
    }
};