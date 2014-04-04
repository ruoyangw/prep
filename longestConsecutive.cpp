    int longestConsecutive(vector<int> &num) {
        map<int,int> mymap;
        for(int i=0;i<num.size();i++){
            mymap[num[i]]=0;
        }
        int max=-1,count=0;
        for(int i=0;i<num.size();i++){
            count=0;
            if(mymap.find(num[i])!=mymap.end() && mymap[num[i]]==0 ){
                search(mymap,num[i],count);
                if(count>max)
                max=count;
            }
        }
        return max;
    }
    
    void search(map<int,int> &mymap,int n,int &count){
        count++;
        mymap[n]=1;
        if(mymap.find(n+1)!=mymap.end() && mymap[n+1]==0){
            search(mymap,n+1,count);
        }
        if(mymap.find(n-1)!=mymap.end()&& mymap[n-1]==0){
            search(mymap,n-1,count);
        }
        
        
    }
	