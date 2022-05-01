class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stackS = []
        stackT = []
        for i in range(len(s)):
            if(s[i] == '#'):
                if(len(stackS) != 0):
                    stackS.pop()
            else:
                stackS.append(s[i])
        
        for i in range(len(t)):
            if(t[i] == '#'):
                if(len(stackT) != 0):
                    stackT.pop()
            else:
                stackT.append(t[i])
        
        if(len(stackS) != len(stackT)):
            return False
        
        for i in range(len(stackS)):
            if(stackS[i] != stackT[i]):
                return False
        
        return True