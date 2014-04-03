    void check(int i,bool can[],const string & s,unordered_set<string> &dict){
       if(dict.find(s.substr(0,i+1))!=dict.end()){
           can[i]=true;
           return;
       }
       
       for(int j=1;j<=i;j++){
           if(can[j-1] && dict.find(s.substr(j,i-j+1))!=dict.end()){
               can[i]=true;
               return;
           }
       }
    }
    
    bool wordBreak(string s, unordered_set<string> &dict) {        
        if(dict.find(s)!=dict.end()){
                return true;
        }
        bool *can=new bool[s.size()];
		for(int i=0;i<s.size();i++)
			can[i]=false;
        for(int i=1;i<=s.size();i++){
            check(i-1,can,s,dict);
            if(can[i-1] && dict.find(s.substr(i))!=dict.end()){
               return true;
            }
        }
        return can[s.size()-1];
    }