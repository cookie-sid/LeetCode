class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> rF(n,1e9), lF(n,1e9);
        if(dominoes[n-1] == 'R') {
            rF[n-1] = n-1;
        }
        if(dominoes[n-1] == 'L') {
            lF[n-1] = n-1;
        }
        for(int i = n-2; i > -1; i--) {
            if(dominoes[i] == 'R') {
                rF[i] = i;
            }
            else {
                rF[i] = rF[i+1];
            }
            if(dominoes[i] == 'L') {
                lF[i] = i;
            }
            else {
                lF[i] = lF[i+1];
            }
        }
        int prevRAt = -1, prevLAt = -1;
        for(int i = 0; i < dominoes.length(); i++) {
            if(dominoes[i] == '.') {
                //force from left
                int fLeft = -1, fRight = -1;
                if(prevRAt != -1) {
                    if(prevRAt > prevLAt) {
                        fLeft = prevRAt;
                    }
                }
                //force from right
                if(lF[i] != 1e9) {
                    if(lF[i] < rF[i]) {
                        fRight = lF[i];
                    }
                }
                if(fLeft == -1) {
                    if(fRight != -1) {
                        dominoes[i] = 'L';
                    }
                }
                else {
                    if(fRight == -1) {
                        dominoes[i] = 'R';
                    }
                    else {
                        if(i - fLeft < fRight - i) {
                            dominoes[i] = 'R';
                        }
                        else if(i - fLeft > fRight - i) {
                            dominoes[i] = 'L';
                        }
                    }
                }
            }
            else {
                if(dominoes[i] == 'L') {
                    prevLAt = i;
                }
                else {
                    prevRAt = i;
                }
            }
        }
        return dominoes;
    }
};