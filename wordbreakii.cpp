    void update(int i,set<string> validOnes[],string s,unordered_set<string> &dict){
        if(dict.find(s.substr(0,i+1))!=dict.end()){
            validOnes[i].insert(s.substr(0,i+1));
        }
        string temp;
        for(int j=0;j<i;j++){
            if(validOnes[j].size()>0 && dict.find(s.substr(j+1,i-j))!=dict.end()){
                   for(auto x: validOnes[j]){
                       temp=x+" "+s.substr(j+1,i-j);
                       validOnes[i].insert(temp);
                   }
            }
        }
    }
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
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       
       
        vector<string> cur;
        if(s.length()==0 || dict.size()==0){
            return cur;
        }
         set<string> * validOnes = new set<string>[s.length()];
         bool* valid=new bool[s.length()];
         for(int i=0;i<s.length();i++){
            check(i,valid,s,dict);
        
         }
         if(!valid[s.length()-1])
         return cur;
        for(int i=0;i<s.length();i++){

            update(i,validOnes,s,dict);
        }
        
        for(auto x: validOnes[s.length()-1]){
            cur.push_back(x);
        }
        return cur;
    }