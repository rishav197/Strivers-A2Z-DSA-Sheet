
class Solution {
public:
    int findMxPathSum(TreeNode* root, int &mxSum){
        //base case 
        if(root==NULL){
            return 0;
        }

        int left = findMxPathSum(root->left,mxSum);
        int right = findMxPathSum(root->right,mxSum);

        int ltAns = max(0, left); //Max path sum in the left subtree
        int rtAns = max(0, right); //Max path sum in the right subtree


        //combo sum (left and right)
        mxSum = max(mxSum, ltAns + rtAns + root->val);

        //Final answer
        return max(ltAns, rtAns)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int mxSum = INT_MIN;
        findMxPathSum(root,mxSum);
        return mxSum;
    }
};