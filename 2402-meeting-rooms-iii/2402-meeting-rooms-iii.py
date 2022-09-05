from heapq import heapify, heappush, heappop

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        # print(meetings)
        unocc,occ = [],[]
        
        for i in range(n):
            unocc.append(i)
            
        count = [0]*n
        heapify(occ)
        heapify(unocc)
        for meeting in meetings:
            if len(occ) == 0:
                top = heappop(unocc)
                heappush(occ,[meeting[1],top])
                count[top] += 1
            else:
                if len(unocc) == 0:
                    mini = 102
                    ls = []
                    while len(occ) != 0:
                        topRoom = occ[0]
                        if topRoom[0] <= meeting[0] :
                            mini = min(mini,topRoom[1])
                            ls.append(occ[0])
                            heappop(occ)
                        else:
                            break
                    if mini == 102 :
                        topRoom = heappop(occ)
                        heappush(occ,[meeting[1] + topRoom[0] - meeting[0],topRoom[1]])
                        count[topRoom[1]] += 1
                    else:
                        heappush(occ,[meeting[1],mini])
                        count[mini] += 1
                        for ele in ls:
                            if ele[1] != mini:
                                heappush(unocc,ele[1])
                else:
                    firstEmpty = unocc[0]
                    mini = 102
                    ls = []
                    while len(occ) != 0:
                        topRoom = occ[0]
                        if topRoom[0] <= meeting[0] :
                            mini = min(mini,topRoom[1])
                            ls.append(occ[0])
                            heappop(occ)
                        else:
                            break
                    if mini == 102 :
                        tR = heappop(unocc)
                        heappush(occ,[meeting[1],tR])
                        count[tR] += 1
                    else:
                        if(mini > firstEmpty):
                            mini = firstEmpty
                            heappop(unocc)
                        heappush(occ,[meeting[1],mini])
                        count[mini] += 1
                        for ele in ls:
                            if ele[1] != mini:
                                heappush(unocc,ele[1])
            # for i in range(0,n):
            #     if(count[i] == 0):
            #         print(count[0:i])
            #         break
            # print(occ)
            # print(unocc)
        # print(count)
        maxi = 0
        num = 0
        for i in range(n):
            if count[i] > maxi:
                maxi = count[i]
                num = i
                
        return num