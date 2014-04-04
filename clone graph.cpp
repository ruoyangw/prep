     map<UndirectedGraphNode *,UndirectedGraphNode *> mymap;  //key is oldnode, value is newnode
    void copyNode(UndirectedGraphNode **newNode, UndirectedGraphNode * oldNode){
        *newNode=new UndirectedGraphNode(oldNode->label);
        (*newNode)->neighbors=oldNode->neighbors;
        mymap[oldNode]=(*newNode);
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        mymap.clear();
        
        if(node==NULL)
        return NULL;
        UndirectedGraphNode * newNode;
        stack<UndirectedGraphNode *> mystack;  
        copyNode(&newNode,node);
        mystack.push(newNode);
        UndirectedGraphNode * cur;
        UndirectedGraphNode * temp;
        vector<UndirectedGraphNode *> curv;
        while(!mystack.empty()){
            cur=mystack.top();
            mystack.pop();
            curv.clear();
            
            for(int i=0;i<cur->neighbors.size();i++){
                if(mymap.find(cur->neighbors[i])==mymap.end()){   // ive never seen this node b4
                    copyNode(&temp,cur->neighbors[i]);
                    mystack.push(temp);
                    curv.push_back(temp);
                }else{
                    curv.push_back(mymap[cur->neighbors[i]]);
                }       
            }
            cur->neighbors=curv;

        }
     return newNode;   
    }