int findDuplicate(vector<int>& nums) {
    vector<int> m(nums.size()-1); 
    for(int i:nums){
        m[i-1]++;
        if(m[i-1]>1){
            return i;
        }
    }
    return -1;
}