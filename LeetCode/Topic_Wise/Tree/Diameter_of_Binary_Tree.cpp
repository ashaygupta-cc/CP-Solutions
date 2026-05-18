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
private: 
    int calculate(TreeNode *root,int &maxi){
     if(!root) return 0;

      int left = calculate(root->left,maxi);
      int right = calculate(root->right,maxi);

      maxi = max(maxi,left+right);

      return 1+max(left,right);

    }

public:
    int diameterOfBinaryTree(TreeNode* root) {

   int maxi = INT_MIN;
   calculate(root,maxi);
      return maxi;
   }
};