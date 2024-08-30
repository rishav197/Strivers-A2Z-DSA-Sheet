
class Solution {
  public:
    Node* createParentMapping(Node* root, int target, map<Node*,Node*> &nodeToParent){
        queue<Node*> q;
        q.push(root);
        
        nodeToParent[root]=NULL;
        Node* targetNode=NULL;
        
        while(!q.empty()){
            Node* topNode = q.front();
            q.pop();
            
            //target node
            if(topNode->data==target){
                targetNode=topNode;
            }
            
            if(topNode->left){
                nodeToParent[topNode->left]=topNode;
                q.push(topNode->left);
            }
            
            if(topNode->right){
                nodeToParent[topNode->right]=topNode;
                q.push(topNode->right);
            }
        }
        
        return targetNode;
    }
    
    int burnTree(Node* root, map<Node*,Node*> &nodeToParent){
        queue<Node*> q;
        q.push(root);
        
        map<Node*,bool> visited;
        visited[root]=true;
        
        int ans=0;
  
        
        while(!q.empty()){
            
            int size=q.size();
            bool flag=0;

            //process neighbouring nodes (Parent,left,Right child)
            for(int i=0; i<size; i++){
                Node* topNode = q.front();
                q.pop();
                
                //check for left child
                if(topNode->left and !visited[topNode->left]){
                    flag=1;
                    q.push(topNode->left);
                    visited[topNode->left]=1;
                }
                //check for right child
                if(topNode->right and !visited[topNode->right]){
                    flag=1;
                    q.push(topNode->right);
                    visited[topNode->right]=1;
                }
                
                //check for Parent
                if(nodeToParent[topNode] and !visited[nodeToParent[topNode]]){
                    flag=1;
                    q.push(nodeToParent[topNode]);
                    visited[nodeToParent[topNode]]=1;
                }
            }
            
            if(flag==1){
                ans+=1;
            }
        }
        
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        
        return ans;
    }
};