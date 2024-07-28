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
    void preOrderTrsl(TreeNode* root, vector<int> &ans){
        if(root==NULL){ //base case
            return;
        }

        // cout<<root->val<<endl;
        ans.push_back(root->val); //storing answer in a ans vector
        preOrderTrsl(root->left,ans); //call left subtree
        preOrderTrsl(root->right,ans); //call right subtree
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }

        preOrderTrsl(root,ans);
        return ans;    
    }
};