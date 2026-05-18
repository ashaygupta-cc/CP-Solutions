/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        unordered_set<ListNode*> num;
        ListNode* cur = head;

        while(cur != NULL){
            if(num.find(cur) != num.end()){
                return cur;
            }
            num.insert(cur);
            cur = cur->next;
        }
        return NULL;
    }
};
