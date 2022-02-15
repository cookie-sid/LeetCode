class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        
        s = path.replace("/"," ")
        s = s.split(" ")
        ans = ""
        stack = []
        stack.append("/");
        for t in s :
            if len(t) != 0:
                if t == "." :
                    continue;
                
                if t == ".." :
                    if(len(stack) != 1) :
                        stack.pop()
                else:
                    if(len(stack) == 1) :
                        stack.append(t)
                    else :
                        stack.append("/" + t);
                    
        ans = ""
        for p in stack:
            ans += p
        return ans