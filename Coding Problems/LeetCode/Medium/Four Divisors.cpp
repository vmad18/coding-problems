int sumFourDivisors(vector<int>& nums) {
    int sum=0;
    
    for(int i:nums){
        int count=0;
        int s=0;
        for(int j=1;j<=sqrt(i);j++){
            if(i%j==0){
                if(i/j == j){ 
                    count++;
                    s+=j;
                }
                else{
                    count+=2;
                    s+=j+(i/j);
                }
            }
            if(count>4) break;
        }
        if(count==4) sum+=s;
    }
    return sum;
}