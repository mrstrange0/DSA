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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (node == nullptr)
                return;
            
            inorder(node->left);       // Left
            ans.push_back(node->val);  // Root
            inorder(node->right);      // Right
        };
        
        inorder(root);
        return ans;
    }
};