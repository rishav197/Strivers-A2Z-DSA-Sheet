/*
 */
class Solution {
public:
    void solve(TreeNode* root,vector<int> &ans,int lvl){
        //base case
        if(root==NULL){
            return;
        }

        //condition to enter into new level
        if(lvl==ans.size()){
            ans.push_back(root->val);
        }

        //call for right and left
        solve(root->right,ans,lvl+1);
        solve(root->left,ans,lvl+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        solve(root,ans,0);
        return ans;
    }
};