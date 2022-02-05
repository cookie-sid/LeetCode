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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        ListNode* head = NULL;
        bool first = true;
        vector<bool> alltaken(lists.size());
        while(true) {
            int ind = -1;
            ListNode* minNode = NULL;
            bool firstonly = true;
            for(int i = 0; i < lists.size(); i++) {
                if(alltaken[i] == true or lists[i] == NULL) {
                    continue;
                }
                if(firstonly) {
                    minNode = lists[i];
                    ind = i;
                    firstonly = false;
                }
                else {
                    if(minNode -> val > lists[i] -> val) {
                        minNode = lists[i];
                        ind = i;
                    }
                }
            }
            if(minNode == NULL) {
                break;
            }
            if(minNode -> next == NULL) {
                alltaken[ind] = true;
                if(first) {
                    ans = minNode;
                    head = ans;
                    first = false;
                }
                else {
                    ans -> next = minNode;
                    ans = ans -> next;
                }
            }
            else {
                if(first) {
                    ans = minNode;
                    head = ans;
                    first = false;
                    lists[ind] = lists[ind] -> next;
                }
                else {
                    ans -> next = minNode;
                    ans = ans -> next;
                    lists[ind] = lists[ind] -> next;
                }
            }
        }
        return head;
    }

};