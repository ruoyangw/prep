    bool search(int A[], int n, int target) {
            return  searchExist(A,0,n-1,target);
    }
    bool searchExist(int A[],int start,int end,int target){
        if(start>end)
        return false;
        int mid=(start+end)/2;
        if(A[mid]==target)
        return true;
        
        if(A[mid]<A[end]){  //the right part is sorted
            if(target<A[mid] || target> A[end]){  //target should be in the left part
                searchExist(A,start,mid-1,target);
            }
            else{        //target should be in right part
                searchExist(A,mid+1,end,target);
            }
        }else if(A[mid]>A[start]){   //the left part is sorted
            if(target>A[mid-1]||target<A[start]){     //target should be in the right part
                searchExist(A,mid+1,end,target);
            }else{
                
                searchExist(A,start,mid-1,target);
            }
            
        }else{      
            return searchExist(A,start,mid-1,target) || searchExist(A,mid+1,end,target);
            
            
            
        }
        
        
    }
};