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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(cur == nullptr) s.append("#,");
            else s.append(to_string(cur->val) + ',');

            if(cur != nullptr){
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") cur->left = nullptr;
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                cur->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#") cur->right = nullptr;
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                cur->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};
