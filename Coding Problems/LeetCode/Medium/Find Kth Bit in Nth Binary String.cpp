string r(string str){
    string dupe = str;
    reverse(dupe.begin(),dupe.end());
    return dupe;
}

string invert(string str){
    string pool="";
    for(char i:str){
        if(i=='1'){
            pool+='0';
        }else{
            pool+='1';
        }
    }
    return pool;
}

char findKthBit(int n, int k) {
    string s = "0";
    for(int i=0;i<n;i++) s+="1"+r(invert(s));
    char val = s[k-1];
    return val;
}