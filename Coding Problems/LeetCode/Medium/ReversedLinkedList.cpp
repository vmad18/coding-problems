ListNode* reverseBetween(ListNode* head, int left, int right) {
    vector<int> new_list;
    
    ListNode *temp = head;
    
    left-=1;
    right-=1;
    
    int c=0;
    while(temp!=NULL){
        if(left<=c&&right>=c){
            new_list.insert(new_list.begin()+left,temp->val);
            temp=temp->next;
        }else{
            new_list.push_back(temp->val);
            temp=temp->next;
        }
        c++;
    }
    
    ListNode *ll = new ListNode(new_list[0]);
    ListNode *hold = ll;
    for(int i=1;i<new_list.size();i++){
        hold->next=new ListNode(new_list[i]);
        hold = hold->next; 
    }
    return ll;
}