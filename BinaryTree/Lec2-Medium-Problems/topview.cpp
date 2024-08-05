/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        
        if(root==NULL){
            return ans;
        }
        
        map<int,int> nodes;
        queue<pair<Node*, int>> q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            
            pair<Node*, int> tmp = q.front();
            q.pop();
            
            Node* topNode = tmp.first;
            int hd = tmp.second;
            
        
            //processing apply (1:1 mapping)
            if(nodes.find(hd)==nodes.end()){
                nodes[hd] = topNode->data;
            }
            
            //check for Left and Right of the tree
            if(topNode->left){
                q.push(make_pair(topNode->left,hd-1));
            }
            
            if(topNode->right){
                q.push(make_pair(topNode->right,hd+1));
            }
        }
        
        //extracting final answer in the ans vector
        for(auto i : nodes){
            ans.push_back(i.second);
        }
        
        return ans;
    }

};
