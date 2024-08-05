//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector <int> ans;
        if(root==NULL){
            return ans;
        }
        
        map<int,int> nodes;
        queue<pair<Node*, int>> q;
        
        q.push(make_pair(root, 0));
        
        //start of LOT
        while(!q.empty()){
            pair<Node*, int> tmp = q.front();
            q.pop();
            
            Node* topNode = tmp.first;
            int hd = tmp.second;
            
            //processing 
            nodes[hd] = topNode->data;
            
            //call for Left and Right of the Tree
            if(topNode->left){
                q.push(make_pair(topNode->left, hd-1));
            }
            if(topNode->right){
                q.push(make_pair(topNode->right, hd+1));
            }
            
        }
        
        //extracting answer to the ans vector
        for(auto i : nodes){
            ans.push_back(i.second);
        }
        
        
        return ans;
    }
};