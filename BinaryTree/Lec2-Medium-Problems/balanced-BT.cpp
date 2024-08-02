/*
approach-1 : without using pair of (IsBalanced=bool, height=int)
tc -> O(N^2), sc -> O(ht)
*/
class Solution {
public:
    int ht(TreeNode* root){
        //base case 
        if(root==NULL){
            return 0;
        }

        int htlst = ht(root->left);
        int htrst = ht(root->right);

        return max(htlst, htrst) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        //base case 
        if(root==NULL){
            return true;
        }

        bool ltAns = isBalanced(root->left);
        bool rtAns = isBalanced(root->right);

        bool diff = abs(ht(root->left) - ht(root->right)) <= 1;

        if(ltAns and rtAns and diff){
            return true;
        }
        else{
            return false;
        }
    }
};


/*approach-2: using a pair of (isBalanced=bool, height=int)
tc -> O(N), sc -> O(ht)
*/
class Solution {
public:
    pair<bool,int> isBalancedFast(TreeNode* root){
        //base case 
        if(root==NULL){
            pair<bool,int> p = {true,0};
            return p;
        }

        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);

        bool diff = abs(left.second - right.second) <= 1;

        bool ltAns = left.first;
        bool rtAns = right.first;

        pair<bool,int> ans;
        ans.second = max(left.second, right.second)+1;

        if(ltAns and rtAns and diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        
        return isBalancedFast(root).first;
    }
};