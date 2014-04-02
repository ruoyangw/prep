    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> mymap;
        int a,b;
        int p,q;
        p=-1;q=-1;
        vector<int> result;
        for(int i=0;i<numbers.size();i++){
            mymap[numbers[i]]=target-numbers[i];
        }
        bool same;
        for(auto x:mymap ){
            if(mymap.find(x.second)!=mymap.end()){
                if(target!=2*x.first){
                    a=x.first;b=x.second;
                    same=false;
                    break;
                }else{
                    if(occurance(numbers,x.first)==2){
                        a=x.first;b=x.second;
                        same=true;
                        break;
                    }
                }
            }
            
        }
        if(!same){
            for(int i=0;i<numbers.size();i++){
                if(numbers[i]==a)
                p=i;
                if(numbers[i]==b)
                q=i;
            }
        }
        if(same){
            for(int i=0;i<numbers.size();i++){
                if(numbers[i]==a && p==-1){
                p=i;
                continue;
                }
                if(numbers[i]==b && q==-1)
                q=i;
            }
        }
        if(p>q){
            int c=p;
            p=q;
            q=c;
        }
        result.push_back(p+1);
        result.push_back(q+1);
        return result;
    }
    int occurance(vector<int> numbers,int t){
        int oc=0;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==t)
            oc++;
        }
        return oc;
    }