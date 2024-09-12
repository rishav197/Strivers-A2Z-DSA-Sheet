
class Solution {
public:
    void solve(TreeNode* root, int &count, int k, int &ans){
        //base case
        if(root==NULL){
            return;
        }

        //LNR
        
        solve(root->left, count, k, ans);
        count++;
        if(count==k){
            ans=root->val;
        }
        solve(root->right, count, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=-1;

        solve(root, count, k, ans);   

        return ans;
    }
};