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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>num1,num2;
        ListNode* cur = l1;
       
        while(cur != NULL){
            num1.push_back(cur->val);
            cur = cur->next;
        }
        cur = l2;
        while(cur != NULL){
            num2.push_back(cur->val);
            cur = cur->next;
        }

        int sum = 0;
        vector<int>result;
        int i = 0,j = 0;
        while(i < num1.size() || j < num2.size() || sum > 0){
            int total = sum;
            if(i < num1.size()) total += num1[i++];
            if(j < num2.size()) total += num2[j++];
            sum = total/10;
            result.push_back(total % 10);
        }

        ListNode* head = new ListNode(result[0]);
        ListNode* node = head;
        for(int i = 1; i < result.size(); i++){
            node->next = new ListNode(result[i]);
            node = node->next;
        }
        
        return head;
    }
};
