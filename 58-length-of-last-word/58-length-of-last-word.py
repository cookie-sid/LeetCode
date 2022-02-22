class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        newarr = s.split(" ")
        while len(newarr) != 0 and len(newarr[len(newarr) - 1]) == 0:
            newarr.pop()
        if(len(newarr) == 0) :
            return 0;
        return len(newarr[len(newarr) - 1])