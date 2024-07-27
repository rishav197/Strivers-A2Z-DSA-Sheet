/* tc->O(n), sc->O(n)*/

class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root==NULL){
            return result;
        }

        //queue
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);

            //level processing
            for(int i=0; i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                //normal insert or reverse insert
                int idx = leftToRight ? i:size-i-1;
                ans[idx] = frontNode->val;

                if(frontNode->left){ //if there's left child then add it to the queue
                    q.push(frontNode->left);
                }
                if(frontNode->right){//if there's right child then add it to the queue
                    q.push(frontNode->right);
                }
            }

            //direction change karni h
            leftToRight = !leftToRight;

            result.push_back(ans);
        }
        
        return result;
    }
};