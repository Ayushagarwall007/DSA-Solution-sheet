// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
//   We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

class Solution {
public:
bool isAllocation_possible(vector<int>& weights, int days,int max_weight)
{
int day=1,current_weight=0;
for(int i=0;i<weights.size();i++)
{
if(current_weight + weights[i]>max_weight)
{
day++;
if(day>days)
return false;
current_weight=weights[i];
}
else{
current_weight+=weights[i];
}
}
return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int res=INT_MIN;
    if(days>weights.size())
        return -1;
    
    int l=*max_element(weights.begin(), weights.end());   
    int h=accumulate(weights.begin(), weights.end(), 0);   // adding each element of array weights
    
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(isAllocation_possible(weights,days,mid))
        {
            res=mid;
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return res;
    
}
};


};
