/*
approach : Using pair of (diameter,height) to reduce its time to O(N)
tc - O(N), sc - O(N)
*/

class Solution {
public:
    pair<int,int> diameterFast(TreeNode* root){
        //base case (diameter=0, height=0)
        if(root==NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> ltAns = diameterFast(root->left); //call for lt Subtree
        pair<int,int> rtAns = diameterFast(root->right); //call for rt Subtree

        int option1 = ltAns.first;
        int option2 = rtAns.first;

        int option3 = ltAns.second + rtAns.second + 1;
   
        pair<int,int> ans;
        ans.first = max(max(option1, option2), option3); //for diameter
        ans.second = max(ltAns.second, rtAns.second) + 1; //for height

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = diameterFast(root).first - 1; //due to definition of diameter (hint. edges of longest path)
        return diameter;
    }
};