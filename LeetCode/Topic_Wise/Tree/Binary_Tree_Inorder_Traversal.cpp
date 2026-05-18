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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){
          vector<int>ans;
    if(root == NULL)return ans;

    stack<TreeNode*>inorder;
    TreeNode* node = root;

 while(true){
    if(node != NULL){
        inorder.push(node);
        node = node->left;
    }

    else{
     if(inorder.empty()) break;
     node = inorder.top();
        inorder.pop();
      ans.push_back(node->val);
      node = node->right;
    }
 }
  return ans;
    }
};