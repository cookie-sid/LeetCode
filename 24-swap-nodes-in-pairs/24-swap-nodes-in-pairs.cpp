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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        
        if(curr == NULL or curr -> next == NULL)
            return curr;
        
        bool first = true;
        ListNode * prev = curr;
        while(curr -> next != NULL) {
            ListNode * temp = curr -> next;
            curr -> next = curr -> next -> next;
            temp -> next = curr;
            if(!first) {
                prev -> next = temp;
            }
            if(first) {
                head = temp;
                first = false;
            }
            prev = curr;
            if(curr -> next == NULL)
                break;
            else
                curr = curr -> next;
            
        }
        return head;
    }
};