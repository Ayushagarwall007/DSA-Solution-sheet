class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        int l = 0, r = nums.size() - 1;
        
        while(l<=r){
            
            int mid = (l+r)/2;
            
            if(nums[mid]==target) return mid;
            
            if(nums[mid]>nums.back()){
               
                if(target>=nums[0] && target<=nums[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if(target>=nums[mid] && target<=nums.back()){
                    l = mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        
        return -1;
        
        
    }
};
