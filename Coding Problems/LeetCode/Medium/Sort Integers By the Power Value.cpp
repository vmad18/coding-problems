int powerValue(int num, map<int, int> &memo){
    int total=0;
    if(num==1){
        return 0;
    }else if(memo.count(num)){
        return memo[num];
    }else if(num%2==0){
        int v = powerValue(num/2, memo)+1;
        total+=v;
    }else{
        int v = powerValue(3*num+1, memo)+1;
        total+=v;
    }
    
    memo[num] = total;
    
    return total;
}
    
int getKth(int lo, int hi, int k) {
    map<int, int> memo;
    vector<int> nums;
    vector<int> vals;
    
    
    for(int i=lo;i<=hi;i++){
        nums.push_back(i);
        vals.push_back(powerValue(i,memo));
    }

    for(int i=0;i<vals.size();i++){
        for(int j=0;j<vals.size()-i-1;j++){
            if(vals[j]>vals[j+1]){
                int temp = vals[j];
                vals[j] = vals[j+1];
                vals[j+1] = temp;

                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    
    return nums[k-1];
    
}