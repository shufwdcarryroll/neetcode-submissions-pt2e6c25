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
        if (!head) return nullptr;
        
        // Step 1: Insert copy nodes after each original node
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        
        // Step 2: Assign random pointers for copied nodes
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        // Step 3: Separate original and copied list
        cur = head;
        Node* newHead = head->next;
        while (cur) {
            Node* copy = cur->next;
            cur->next = copy->next;
            if (copy->next) copy->next = copy->next->next;
            cur = cur->next;
        }
        
        return newHead;
    }
};
