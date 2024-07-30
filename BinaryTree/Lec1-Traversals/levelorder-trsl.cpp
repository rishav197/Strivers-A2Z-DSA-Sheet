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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        //base case
        if(root==NULL){
            return ans;
        }


        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> level;

        while(!q.empty()){
            
            TreeNode* topNode = q.front();
            q.pop();
        
            
            if(topNode==NULL){ //complete level has been traversed
                ans.push_back(level);
                level.clear();

                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{ //traversing at a level 

                level.push_back(topNode->val);

                if(topNode->left){
                    q.push(topNode->left);
                }
                if(topNode->right){
                    q.push(topNode->right);
                }
            }

        }

        return ans;
    }
};