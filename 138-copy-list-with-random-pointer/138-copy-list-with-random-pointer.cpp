/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return head;
        }
        Node* h = head;
        unordered_map<Node*,Node*> m;
        Node *newH = new Node(h -> val);
        m[h] = newH;
        h = h -> next;
        Node *prev = newH;
        while(h != NULL) {
            Node *temp = new Node(h -> val);
            prev -> next = temp;
            prev = prev -> next;
            m[h] = temp;
            h = h -> next;
        }
        h = head;
        while(h != NULL) {
            m[h] -> random = m[h -> random];
            h =  h-> next;
        }
        return newH;
    }
};