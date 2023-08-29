# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        def getReversed(head):
            if not head or not head.next:
                return [head,head]
            [newHead,nexter] = getReversed(head.next)
            nexter.next = head
            return [newHead,head]
        
        [newHead,h] = getReversed(head)
        if h and h.next:
            h.next = None
        return newHead
            
        
        