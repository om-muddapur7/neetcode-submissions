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

        if(head == nullptr) return nullptr;

        Node* newHead = new Node(head->val);

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        unordered_map<Node*, Node*> m;
        m[head] = newHead;

        while(oldTemp != nullptr){
            Node* copynode = new Node(oldTemp->val);
            m[oldTemp] = copynode;
            newTemp->next = copynode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != nullptr){
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
