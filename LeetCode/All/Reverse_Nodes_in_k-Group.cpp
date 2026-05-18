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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k){
        if(!head || k == 1) return head;

        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp;
        long long n = 0;

        ListNode* countNode = head;
        while(countNode){
            n++;
            countNode = countNode->next;
        }

        while(n >= k){
            ListNode* groupStart = cur;
            ListNode* nextGroupStart = cur;

            for(int i = 1; i < k; i++){
                cur = cur->next;
            }
            temp = cur->next;
            cur->next = NULL;

            ListNode* newGroupHead = reverseList(groupStart);

            if(!prev){
                head = newGroupHead;
            } 
            else{
                prev->next = newGroupHead;
            }

            groupStart->next = temp;
            prev = groupStart;
            cur = temp;
            n -= k;
        }

        return head;
    }
};