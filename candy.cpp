    int candy(vector<int> &ratings) {
        int *left=new int[ratings.size()];
        int *right=new int[ratings.size()];
        int *maxy=new int[ratings.size()];
        int result=0;
        
        left[0]=1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1])
            left[i]=left[i-1]+1;
            else
            left[i]=1;
        }
        
        right[ratings.size()-1]=1;
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                right[i]=right[i+1]+1;
            else
                right[i]=1;
        }
        
        
        for(int i=0;i<ratings.size();i++){
            maxy[i]=max(left[i],right[i]);
            result+=maxy[i];
        }
        return result;
    }