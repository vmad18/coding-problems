vector<int> partitionLabels(string S) {
    
    vector<int> ans;
    int len=1;
    int last=S.find_last_of(S[0]);
    for(int i=0;i<S.size();i++){
        if(i==last){
            ans.push_back(len);
            len=0;
            if(i!=S.size()-1){
                last = S.find_last_of(S[i+1]);
                len++;
            }
        }else if(S.find_last_of(S[i])>last){
            last = S.find_last_of(S[i]);
            len++;
        }else{
            len++;  
        }
        
    }
    if(len-1>0){
        ans.push_back(len-1);
    }
    return ans;
}