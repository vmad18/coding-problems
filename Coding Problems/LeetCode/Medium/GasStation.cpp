int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int index=0;
    int g=0;
    int c=0;
    int prev=0;
    for(int i=0;i<gas.size();i++){
        g+=gas[i];
        c+=cost[i];
        gas[i]+=prev;
        prev=gas[i]-cost[i];
        if(prev<0){
            index=i+1;
            prev=0;
        }
    }
    return g<c ? -1 : index;
}