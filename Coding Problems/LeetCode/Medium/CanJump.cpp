bool canJump(vector<int>& nums) {
    int n= nums.size()-1;
    
    for(int i=0;i<nums.size();i++){
        if(i==n) return true;
        if(nums[i]==0) return false;
        int currmin = (n - i) - nums[i];
        int point = n-currmin;
        
        if(currmin<=0) return true;
        for(int x=i;x<i+nums[i];x++){
            if(((n-x)-nums[x]) < currmin){
                if(((n-x)-nums[x])<=0) return true;
                currmin = (n-x)-nums[x];
                point = x;
            }
        }
        i=point-1;
    }
    return false;
}