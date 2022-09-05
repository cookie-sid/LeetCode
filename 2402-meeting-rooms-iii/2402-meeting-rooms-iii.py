from heapq import heapify, heappush, heappop

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        rooms = []
        
        for i in range(n):
            rooms.append([-1 ,i])
            
        maxi = [0]*n
        heapify(rooms)
        
        for m in meetings:
            # print(rooms)
            ls = heappop(rooms)
            endTime = ls[0]
            rnum = ls[1]
            if endTime == -2 :
                heappush(rooms,[m[1],rnum])
                maxi[rnum] += 1
            else:
                b = []
                heappush(rooms,ls)
                mini = 102
                while len(rooms) > 0:
                    ele = heappop(rooms)
                    if(ele[0] > m[0]):
                        heappush(rooms,ele)
                        break
                    else:
                        b.append(ele)
                        mini = min(mini,ele[1])
                
                if mini == 102:
                    ele = heappop(rooms)
                    heappush(rooms,[m[1] + ele[0] - m[0],ele[1]])
                    maxi[ele[1]] += 1
                else:
                    maxi[mini] += 1
                    for ele in b:
                        if ele[1] == mini:
                            heappush(rooms,[m[1],ele[1]])
                        else:
                            heappush(rooms,[-1,ele[1]])
                    
            
        top = 0
        num = 0
        for i in range(0,n):
            
            
            if(top < maxi[i]):
                top = maxi[i]
                num = i
                
        return num
                    
            