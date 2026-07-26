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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        if(!root) return level;

        queue<TreeNode*> q;
        q.push(root);

        while(q.size() > 0){
            vector<int> level2;
            int size = q.size();
            
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                level2.push_back(cur->val);

                if(cur->left!=nullptr){
                    q.push(cur->left);
                }
                if(cur->right!=nullptr){
                    q.push(cur->right);
                }
            }

            level.push_back(level2);
            
        }

        return level;
    }
};
