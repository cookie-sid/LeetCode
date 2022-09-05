# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1
        
        ch1, ch2 = list1, list2
        if list1.val > list2.val:
            ch1, ch2 = list2, list1
            
        first = ch1
        prev = None
        
        while ch1 and ch2:
            
            while ch1 and ch1.val <= ch2.val:
                prev = ch1
                ch1 = ch1.next
            
            prev.next = ch2
            ch2 = ch1
            ch1 = prev.next
        
        return first
            