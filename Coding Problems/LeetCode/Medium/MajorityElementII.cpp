vector<int> majorityElement(vector<int>& nums) {
    map<int,int> m;
    int s = nums.size()/3;
    int t=0; 
    vector<int> ans; 
    for(int i:nums){
        m[i]++;
        if(m[i]>s){
            ans.push_back(i);
            m[i] = INT_MIN;
            t++;
        }
    }
    return ans; 
}