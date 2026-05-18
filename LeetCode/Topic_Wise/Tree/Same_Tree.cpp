/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if (!p && !q) return true;  // BOTH NULL
        if (!p || !q) return false;  // ONE OF THEM NULL
        if (p->val != q->val) return false; // BOTH NOT EQUAL
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right); // BOTH TRUE THEN TRUE ELSE FALSE.
    }
};
