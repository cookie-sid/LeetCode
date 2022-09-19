class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = {}
        for p in paths:
            ls = p.split(" ")
            rdy = ls[0]
            ls = ls[1:]
            for item in ls:
                ind = item.find("(") + 1
                content = item[ind:len(item) - 1]
                name = item[0:ind - 1]
                name = rdy + '/' + name
                if content not in d:
                    d[content] = {}
                if name not in d[content]:
                    d[content][name] = 0
                d[content][name] += 1
                
        ans = []
        for key in d:
            group = []
            for keykey in d[key]:
                group.append(keykey)
            if len(group) == 1:
                continue
            ans.append(group)
        return ans