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
        ListNode* first = new ListNode((l1 -> val + l2 -> val)%10);
        ListNode* h = first;
        int carry = l1 -> val + l2 -> val;
        carry /= 10;
        
        while(l1 -> next != NULL and l2 -> next != NULL) {
            l1 = l1 -> next;
            l2 = l2 -> next;
            carry += l1 -> val + l2 -> val;
            ListNode* afterFirst = new ListNode(carry % 10);
            carry /= 10;
            first -> next = afterFirst;
            first = first -> next;
        }
        while(l1 -> next != NULL) {
            l1 = l1 -> next;
            carry += l1 -> val;
            ListNode* afterFirst = new ListNode(carry % 10);
            carry /= 10;
            first -> next = afterFirst;
            first = first -> next;
        }
        while(l2 -> next != NULL) {
            l2 = l2 -> next;
            carry += l2 -> val;
            ListNode* afterFirst = new ListNode(carry % 10);
            carry /= 10;
            first -> next = afterFirst;
            first = first -> next;
        }
        while(carry != 0) {
            ListNode* afterFirst = new ListNode(carry % 10);
            carry /= 10;
            first -> next = afterFirst;
            first = first -> next;
        }
        return h;
    }
};