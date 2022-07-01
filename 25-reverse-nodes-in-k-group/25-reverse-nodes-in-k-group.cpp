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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int current = 0, size = 1;
        ListNode *curr = head;
        while(curr -> next != NULL) {
            curr = curr -> next;
            size++;
        }
        curr = head;
        ListNode *prev, *newS;
        while(current + k <= size) {
            int c = 1;
            ListNode *first = curr;
            ListNode *after = curr -> next, *temp = after;
            while(c < k) {
                temp = after;
                if(after -> next == NULL) {
                    after -> next = curr;
                    curr = after;
                    temp = NULL;
                }
                else {
                    temp = after -> next;
                    after -> next = curr;
                    curr = after;
                    after = temp;
                }
                c++;
            }
            first -> next = temp;
            if(current == 0) {
                newS = curr;
                prev = first;
                current += k;
                curr = temp;
                continue;
            }
            else {
                prev -> next = curr;
                prev = first;
                current += k;
                curr = temp;
            }
        }
        return newS;
    }
};