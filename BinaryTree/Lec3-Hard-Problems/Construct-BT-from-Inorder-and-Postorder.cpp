
class Solution {
public:
    void createMapping(vector<int> inorder, map<int,int> &nodeToIdx, int n){
        for(int i=0; i<n; i++){
            nodeToIdx[inorder[i]]=i;
        }
    }
    
    TreeNode* solve(vector<int> inorder, vector<int> postorder, int &idx, int inorderSt, int inorderEd, int n, map<int,int> &nodeToIdx){
        //base case
        if(idx<0 or inorderSt>inorderEd){
            return NULL;
        }
        
        int element = postorder[idx--];
        TreeNode* root = new TreeNode(element);
        int pos = nodeToIdx[element];
        
        //recursive calls (Call for Right and Left)
        root->right = solve(inorder,postorder,idx,pos+1,inorderEd,n,nodeToIdx);
        root->left = solve(inorder,postorder,idx,inorderSt,pos-1,n,nodeToIdx);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOrderidx = n-1;
        map<int,int> nodeToIdx;
        
        //create node to idx mapping
        createMapping(inorder, nodeToIdx, n);
        TreeNode* ans = solve(inorder, postorder, postOrderidx, 0, n-1, n, nodeToIdx);
        return ans;
    }
};