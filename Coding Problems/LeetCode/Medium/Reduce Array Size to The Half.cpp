int minSetSize(vector<int>& arr) {
    
    long int n = arr.size();
    
    map<int, int> m;
    
    vector<int> pool; 
    
    for(int i:arr) m[i] += 1;
    
    for(auto i=m.begin();i!=m.end();i++) pool.push_back(i->second);
    
    sort(pool.begin(),pool.end());
    
    
    int steps=0;
    
    while(n>arr.size()/2){
        n-=pool[pool.size()-1];
        pool.erase(pool.begin()+pool.size()-1);
        steps++;
    }
    return steps;
}