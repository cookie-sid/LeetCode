/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    
    Node* leftMost(Node* node) {
        
        if(node -> left != NULL) {
            node = node -> left;
            return leftMost(node);
        }
        return node;
    }
    
    Node* inorderSuccessor(Node* node) {
        
        if(node -> right != NULL) {
            return leftMost(node -> right);
        }
        
        while(node -> parent != NULL and node -> parent -> right == node) {
            node = node -> parent;
        }
        
        return node -> parent;
        
    }
};