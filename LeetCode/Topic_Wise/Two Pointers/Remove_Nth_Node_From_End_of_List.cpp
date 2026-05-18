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
        if (!head || !head->next) return NULL;

        ListNode* prev = NULL;
        ListNode* cur = head;
        long long count = 0;

        while(cur != NULL){
            cur = cur->next;
            count++;
        }

        count -= n;
        cur = head;

        if(count == 0){
            // Special case when the head itself needs to be removed
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(count){
            prev = cur;
            cur = cur->next;
            count--;
        }

        prev->next = cur->next;
        delete cur;

        return head;
    }
};
