 // CONTAINER WITH MOST WATER CPP
class Solution {
public:
    int maxArea(vector<int>& h) {
        
        int l = 0;
        int r = h.size()-1;
        int ans=0;
        while(l<r){
            ans=max(ans,min(h[l],h[r])*(r-l));
            if(h[l]>h[r]) r--;
            else l++;
        }
        return ans;
        
    }
};
Footer
© 2022 GitHub, Inc.
