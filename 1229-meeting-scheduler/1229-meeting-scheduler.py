class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        slots1.sort()
        slots2.sort()
        i,j = 0,0
        while(i < len(slots1)):
            if(j >= len(slots2)):
                break
            if(slots1[i][1] <= slots2[j][0]):
                i += 1
                continue
            else:
                if(slots1[i][0] >= slots2[j][1]):
                    j += 1
                    continue
                else:
                    commonD = min(slots2[j][1],slots1[i][1]) - max(slots1[i][0],slots2[j][0])
                    if(commonD >= duration):
                        return [max(slots1[i][0],slots2[j][0]),max(slots1[i][0],slots2[j][0]) + duration]
                    else:
                        if(slots1[i][1] < slots2[j][1]):
                            i += 1
                        else:
                            j += 1
                            
                            
                
        return []