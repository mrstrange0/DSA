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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int width=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size=q.size();
            int min=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                long long curr_indx=q.front().second-min;
                TreeNode* node=q.front().first;
                q.pop();
                //storing the first and last guy
                if(i==0) first=curr_indx;
                if(i==size-1) last=curr_indx;

                if(node->left){
                q.push({node->left,curr_indx*2+1});
                }
                if(node->right){
                q.push({node->right,curr_indx*2+2});
                }
            }    
             width=max(width,last-first+1);       
        }
        return width;
    }
};