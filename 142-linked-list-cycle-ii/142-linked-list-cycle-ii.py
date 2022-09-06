# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if not head:
            return None
        
        slow = head
        fast = head
        if not fast.next:
            return None
        else:
            fast = fast.next
        if not fast.next:
            return None
        else:
            fast = fast.next
            
        ds = 0
        df = 2
        while slow.next and fast.next:
            # print(slow)
            # print(fast)
            if slow == fast :
                break
            ds += 1
            df += 2
            slow = slow.next
            fast = fast.next
            if not fast.next:
                break
            else:
                fast = fast.next
            
        if not slow.next or not fast.next:
            return None
            
        steps = df - ds
        # print(df)
        # print(ds)
        # print(steps)
        slow = head
        fast = head
        c = 0
        while c != steps:
            fast = fast.next
            c += 1
        while slow != fast:
            slow = slow.next
            fast = fast.next
        
        return slow
        
        
        