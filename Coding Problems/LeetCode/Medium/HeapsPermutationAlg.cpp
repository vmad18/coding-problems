#include <bits/stdc++.h>

using namespace std; 

void swap(int &a, int &b){
    int t = b;
    b = a;
    a = t;
}

void heaps(vector<int> &vec, int size, vector<vector<int>> &perms){
    if (size == 1) {
        perms.push_back(vec); 
        return;
    }

    for (int i = 0; i < size; i++) {
        heaps(vec, size - 1, perms);
        
        if (size % 2) swap(vec[0], vec[size - 1]);
        else swap(vec[i], vec[size - 1]);
    }
}


vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> perms; 
    heaps(nums, nums.size(), perms);
    return perms; 
}