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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        int cnt = 0;

        while(cur != nullptr){
            cur = cur->next;
            cnt++;
        }

        int idx = cnt - n;
        cur = head;

        if(idx == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        } 

        for(int i=0; i<idx; i++){
            prev = cur;
            cur = cur->next;
        }

        prev->next = cur->next;
        delete cur;

        return head;
    }
};
