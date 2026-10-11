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
    int maxi=INT_MIN;
    int maxPath(TreeNode* node){
        if(node==NULL) return 0;

        //this max is used to remove -ve contributions in tree it will taje it as 0
        int leftsum=max(0,maxPath(node->left));
        int rightsum=max(0,maxPath(node->right));
        maxi=max(maxi,leftsum + rightsum + node->val);
        return node->val + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxi;
    }
};