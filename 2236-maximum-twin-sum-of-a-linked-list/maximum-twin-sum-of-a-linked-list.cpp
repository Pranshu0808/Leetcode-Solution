class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>arr;
        ListNode*temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        int maxtwinsum = 0;

        for(int i=0 ;i<n ;i++){
            int sum = arr[i]+arr[n-1-i];
            maxtwinsum = max(maxtwinsum , sum);
        }
return maxtwinsum;
    }
};