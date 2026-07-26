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
        ListNode* cur = head;
        int grp = 0;

        while(cur != nullptr && grp < k){
            cur = cur->next;
            grp++;
        }

        if(grp == k){
            cur = reverseKGroup(cur, k);
            while(grp-- > 0){
                ListNode* temp = head->next;
                head->next = cur;
                cur = head;
                head = temp;
            }
            head = cur;
        }
        return head;
    }
};
