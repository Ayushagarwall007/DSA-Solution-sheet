// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
//   We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 class Solution {
public:
    bool check(int mid,vector<int>& weights,int days){
        int c=1,sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid){
                return false;
            }
            if(sum+weights[i]>mid){
                c++;
                sum=weights[i];
            }
            else{
                sum+=weights[i];
            }
            
        }
        return c<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,v;
        for(auto i:weights){
            sum+=i;
        }
        int i=*max_element(weights.begin(),weights.end()),j=sum;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(check(mid,weights,days)){
                v=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return v;
    }
};
