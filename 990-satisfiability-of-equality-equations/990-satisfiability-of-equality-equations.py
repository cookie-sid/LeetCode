class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        
        lsnum = [-1]*26
        currentNum = 0
        for e in equations:
            var1 = e[0]
            var2 = e[3]
            sign = e[1]
            if sign == "=":
                if lsnum[ord(var1)-ord("a")] == -1 and lsnum[ord(var2)-ord("a")] == -1:
                    lsnum[ord(var1)-ord("a")] = currentNum
                    lsnum[ord(var2)-ord("a")] = currentNum
                    currentNum += 1
                else:
                    if lsnum[ord(var1)-ord("a")] == -1:
                        lsnum[ord(var1)-ord("a")] = lsnum[ord(var2)-ord("a")]
                    elif lsnum[ord(var2)-ord("a")] == -1:
                        lsnum[ord(var2)-ord("a")] = lsnum[ord(var1)-ord("a")]
                    else:
                        p = lsnum[ord(var1)-ord("a")]
                        q = lsnum[ord(var2)-ord("a")]
                        for i in range(26):
                            if lsnum[i] == p or lsnum[i] == q:
                                lsnum[i] = currentNum
                        currentNum += 1
            print(lsnum)
                        
                    
        for e in equations:
            var1 = e[0]
            var2 = e[3]
            sign = e[1]
            if sign == "!":
                if var1 == var2 or (lsnum[ord(var1)-ord("a")] == lsnum[ord(var2)-ord("a")] and lsnum[ord(var2)-ord("a")] != -1):
                    return False
        return True
            
            
        