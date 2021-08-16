#include <bits/stdc++.h>

using namespace std; 

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int j=low-1;
    for(int i=low;i<high;i++){
        if(arr[i]<pivot){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[high]);
    return j+1;
}

void quickSort(vector<int> &a, int low, int high){
    if(high>low){
        int part = partition(a,low,high);
        quickSort(a, low, part-1);
        quickSort(a, part+1,high);
    }
}

int maxSatisfaction(vector<int>& satisfaction) {
    
    
    quickSort(satisfaction,0,satisfaction.size()-1);
    
    vector<int> pos;
    vector<int> arr;
    int sum=0;
    for(int i:satisfaction){
        if(i>=0){
            pos.push_back(i);
            sum+=i;
        }
        else arr.push_back(i);
    }
    
    int s=0;
    for(int i=arr.size()-1;i>=0;i--){
        if(s-arr[i]<sum){
            s-=arr[i];
            pos.insert(pos.begin(),arr[i]);
        }
    }
    int summation=0;
    for(int i=0;i<pos.size();i++) summation+=pos[i]*(i+1);
    
    
    return summation;
}