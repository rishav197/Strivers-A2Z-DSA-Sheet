/* tc -> O(N), sc -> O(N)
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> rslt(size);

            //level process
            for(int idx=0; idx<size; idx++){
                TreeNode* topNode = q.front();
                q.pop();

                //normal insert or reverse insert 
                int indx = leftToRight ? idx : size-1-idx;
                rslt[indx] = topNode->val;

                if(topNode->left){
                    q.push(topNode->left);
                }
                if(topNode->right){
                    q.push(topNode->right);
                }

            }

            //Need to change the direction
            leftToRight = !leftToRight;

            ans.push_back(rslt);
        }

        return ans;
    }
};