vector<int> findDuplicates(vector<int>& nums) {
    vector<int> cnts(nums.size(), 0);
    vector<int> dupes;
    for(int i:nums){
        if(cnts[i-1]){
            dupes.push_back(i);
            cnts[i-1]=-1; 
        }else if(cnts[i-1]>=0){    
            cnts[i-1]++;
        }
    }
    return dupes; 
}