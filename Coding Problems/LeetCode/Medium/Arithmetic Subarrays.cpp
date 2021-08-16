void swap(int &a, int &b){
    int temp = b;
    b=a;
    a=temp;
}

int partition(vector<int> &arr, int l, int h){
    int pivot = arr[h];
    int j = l-1;
    
    for(int i=l;i<h;i++){
        if(arr[i]<pivot){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    
    swap(arr[j+1],arr[h]);
    return j+1;
}

void quickSort(vector<int> &arr, int l, int h){
    if(l<h){
        int p = partition(arr, l, h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> ans;
    
    for(int i=0;i<l.size();i++){
        vector<int> temp(nums.cbegin()+l[i],nums.cbegin()+r[i]+1);
        quickSort(temp,0,temp.size()-1);
        int val=temp[1]-temp[0];
        for(int j=1;j<temp.size();j++){
            if(temp[j]-temp[j-1]!=val){
                ans.push_back(false);
                break;
            }else if(j==temp.size()-1){
                ans.push_back(true);
            }
        }
    }
    return ans;
}