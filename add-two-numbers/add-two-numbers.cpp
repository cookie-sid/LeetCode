/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int carry = 0, present;
        
        while(l1 != nullptr || l2 != nullptr)
        {
            int x = 0, y = 0;
            if(l1)
                x = l1->val, l1 = l1->next;
            if(l2)
                y = l2->val, l2 = l2->next;
            
            present = x + y + carry;
            carry = present/10;
            
            ListNode* nextnode = new ListNode(present%10);
            
            curr->next = nextnode;
            curr = curr->next;
            
        }
        
        if(carry)
        {
            ListNode* nextnode = new ListNode(carry%10);
            carry /= 10;
            
            curr->next = nextnode;
            curr = curr->next;
        }
        
        
        return ans->next;
        
    }
};