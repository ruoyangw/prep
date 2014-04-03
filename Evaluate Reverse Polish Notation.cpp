    int evalRPN(vector<string> &tokens) {
        stack<int> mystack;
        int cur;
        int result;
        int a,b;
        for(int i=0;i<tokens.size();i++){
             if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" ){
                 b=mystack.top();mystack.pop();
                 a=mystack.top();mystack.pop();
                 if(tokens[i]=="+"){mystack.push(a+b);}
                 if(tokens[i]=="-"){mystack.push(a-b);}
                 if(tokens[i]=="*"){mystack.push(a*b);}
                 if(tokens[i]=="/"){mystack.push(a/b);}
             }else{
                 cur=atoi(tokens[i].c_str());
                 mystack.push(cur);
             }
        }
        return mystack.top();
        
    }