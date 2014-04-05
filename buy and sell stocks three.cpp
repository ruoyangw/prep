    int maxProfit(vector<int> &prices,int start,int end) {
        if(prices.size()<=1 || end-start<=0)
        return 0;
        int low=prices[start];
        int high=prices[start];
        int profit=0; 
        for(int i=start;i<=end;i++){
            if(prices[i]>high){
                high=prices[i];
                if(high-low>profit){
                    profit=high-low;
                }
            }else if(prices[i]<low){
                low=prices[i]; 
                high=prices[i];
            }
        }
        return profit;
    }
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(prices.size()<=1){return 0;}
        int res=0;
        int profit;
        for(int i=1;i<prices.size();i++){
            if(prices[i+1]>prices[i]){
            profit=maxProfit(prices,0,i)+maxProfit(prices,i,prices.size()-1);
            if(profit>res)
            res=profit;
            }
        }
        
        return max(res,maxProfit(prices,0,prices.size()-1));
        
    }