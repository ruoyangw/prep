   
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string> > >results;
         vector<vector<string> > one;
        if(s.length()==0)
        return one;
        bool v[s.size()][s.size()];              //if is palindrom from index in frist bracket to second
      //  int mins[s.size()];
        for(int i=0;i<s.size();i++){
        v[i][i]=true;
        }
       
        for(int i=0;i<s.size();i++){
            one.clear();
             for(int j=0;j<=i;j++){
                 v[j][i]=false;
                 if(s[i]==s[j] && (i-j<=2 || v[j+1][i-1])){
                     v[j][i]=true;
                     if(j==0){
                      vector<string> whole;
                      whole.push_back(s.substr(0,i+1));
                      one.push_back(whole);
                        }
                     else{
                         vector<string> temp;
                       for(int k=0;k<results[j-1].size();k++){
                           temp=results[j-1][k];
                           temp.push_back(s.substr(j,i-j+1));
                           one.push_back(temp);
                       }

                     }
                 }
             }
             results.push_back(one);
        }
       
     return results[s.length()-1];   
    }
    