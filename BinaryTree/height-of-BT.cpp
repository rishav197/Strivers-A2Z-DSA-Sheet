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
    int maxDepth(TreeNode* root) {
        //base case
        if(root==NULL){
            return 0;
        }

        //height of left subtree
        int ht_left = maxDepth(root->left); 

        //height of right subtree
        int ht_right = maxDepth(root->right);

        int ht = max(ht_left, ht_right) + 1;

        return ht;
    }
};