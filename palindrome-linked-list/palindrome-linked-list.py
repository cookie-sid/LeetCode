# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow = head
        if not head or not head.next:
            return True
        while fast:
            if fast.next:
                fast = fast.next
            else:
                break
            if fast.next:
                fast = fast.next
            else:
                break
            slow = slow.next
            
        second = slow.next
        first = head
        slow.next = None
        this = second
        that = second
        while that:
            afterThat = that.next
            that.next = this
            this = that
            that = afterThat
        second.next = None
        that = this
        
        while first and that:
            if first.val != that.val:
                return False
            first = first.next
            that = that.next
        return True
        
        
        
        
        
        
        
        
        
        