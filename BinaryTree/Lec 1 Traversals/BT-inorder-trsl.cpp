/* tc -> O(N)
*/
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
    void inOrderTrsl(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }

        inOrderTrsl(root->left, ans); //call left subtree
        ans.push_back(root->val); //storing answer
        inOrderTrsl(root->right, ans); //call right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inOrderTrsl(root,ans);
        return ans;
    }
};