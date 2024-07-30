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
    void postOrderTrsl(TreeNode* root, vector<int> &ans){
        //base case
        if(root==NULL){
            return;
        }

        postOrderTrsl(root->left, ans); //call left subtree
        postOrderTrsl(root->right, ans); //call right subtree
        ans.push_back(root->val); //storing answer
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        postOrderTrsl(root, ans);
        return ans;
    }
};