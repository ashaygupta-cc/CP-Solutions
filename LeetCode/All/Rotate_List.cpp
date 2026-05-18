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
        if(!head || !head->next) return head;

        int count = 0;
        ListNode* cur = head;

        while(cur != NULL){
            cur = cur->next;
            count++;
        }

        k = k % count;
        if(k == 0) return head;

        cur = head;
        for(int i = 1; i < count - k; i++){
            cur = cur->next;
        }

        ListNode* newHead = cur->next;
        cur->next = NULL;

        ListNode* temp = newHead;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;

        return newHead;
    }
};
