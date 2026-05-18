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
    vector<vector<int>>zigzagLevelOrder(TreeNode* root){
        
        bool bl = true;
        vector<vector<int>>ZZLO;
        if (!root) return ZZLO;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size(); 
            vector<int>level;

            for(int i = 0; i < size; i++){
                TreeNode* s = q.front();
                q.pop();
                level.push_back(s->val);
                
                if(s->left) q.push(s->left);
                if(s->right) q.push(s->right);
            }

            if(!bl) reverse(level.begin(),level.end()); 
            bl = !bl;
            ZZLO.push_back(level);
        }
        return ZZLO;
    }
};
