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

  /*  vector<int>numbers(TreeNode* root){
        
        vector<int>nums;
      if(!root) return nums;
     
      queue<TreeNode*>q;
      q.push(root);

      while(!q.empty()){
         
         TreeNode* a = q.front;
         q.pop;

         if(a){
            nums.push_back(a.val);
            q.push(a->left);
            q.push(a->right);
         }
         else{
            nums.push_back(INT_MIN);
         }
      }
   return nums;
    }
  */
   
    bool Prove(TreeNode* root1,TreeNode* root2){

     TreeNode* a = root1;
     TreeNode* b = root2;

     if(!a && !b) return true;
     if(!a || !b) return false;
     if(a->val != b->val) return false;
      
      return Prove(a->left,b->right) && Prove(a->right,b->left);   
    }

    bool isSymmetric(TreeNode * root){
     
      if(!root) return true;
      
      return Prove(root->left,root->right);    
    }
};