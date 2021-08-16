string baseNeg2(int N) {
    string result = "";
    
    
    if(N==0) return "0";
    
    
    while(N!=0){
        int r = N%-2;
        N/=-2;
        if(r<0){
            r-=-2;
            N+=1;
        }
        result = to_string(r) + result;
    }
    return result;
}