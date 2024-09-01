
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        long int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            int size=q.size();
            long int min = q.front().second;
            long int first,last;

            //process nodes at each level
            for(int idx=0; idx<size; idx++){
                long int cur_idx = q.front().second - min;
                TreeNode* topNode = q.front().first;
                q.pop();

                if(idx==0){
                    first=cur_idx;
                }
                if(idx==size-1){
                    last=cur_idx;
                }

                //left
                if(topNode->left){
                    q.push({topNode->left, 2*cur_idx+1});
                }
                //right
                if(topNode->right){
                    q.push({topNode->right, 2*cur_idx+2});
                }

            }
            //update answer
            ans=max(ans, last-first+1);

        }  

        return ans; 
    }
};