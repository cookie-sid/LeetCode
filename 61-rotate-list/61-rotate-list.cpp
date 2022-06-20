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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) {
            return head;
        }
        int n = 1;
        ListNode* temp = head;
        while(temp -> next != NULL) {
            n++;
            temp = temp -> next;
        }
        k = k % n;
        int rem = n - k, ctr = 0;
        ListNode* newHead = head;
        ListNode* prev = head;
        if(k == 0) {
            return head;
        }
        while(ctr < rem) {
            ctr += 1;
            newHead = newHead -> next;
            if(ctr != 1) {
                prev = prev -> next;
            }
        }
        prev -> next = NULL;
        ListNode* tmp = newHead;
        while(tmp -> next != NULL) {
            tmp = tmp -> next;
        }
        tmp -> next = head;
        return newHead;
    }
};