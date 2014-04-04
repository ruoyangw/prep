    int minCut(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s.size()<=1)
        return 0;
        bool v[s.size()][s.size()];              //if is palindrom from index in frist bracket to second
               int mins[s.size()];
        for(int i=0;i<s.size();i++){
        v[i][i]=true;
        mins[i]=i;
        }
       
        for(int i=0;i<s.size();i++){
         for(int j=0;j<=i;j++){
             v[j][i]=false;
            
                 if(s[i]==s[j] && (i-j<=2 || v[j+1][i-1])){
                     
                     v[j][i]=true;
                     if(j==0)
                     mins[i]=0;
                     else
                     mins[i]=min(mins[i],mins[j-1]+1);
                 }
             
         }      
        }
        return mins[s.size()-1];
    }