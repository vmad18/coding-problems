vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    map<int,queue<int>> a;

    vector<vector<int>> ans;

    vector<int> hold;

    for(int i=0;i<groupSizes.size();i++) a[groupSizes[i]].push(i);

    for(auto i:a){
        while(!i.second.empty()){
            hold.push_back(i.second.front());
            i.second.pop();
            if(hold.size()==i.first){
                ans.push_back(hold);
                hold.clear();
            }
        }
    }
    return ans;
}