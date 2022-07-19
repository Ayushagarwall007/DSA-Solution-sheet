// Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/listrepresents the length of each board.
//   Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under a constraint that any painter will only paint 
// the continuous sections of boards.
bool isValid(vector<int> &boards, int k,int mid,int n)
{
    int painter=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(boards[i]>mid)return false;
        sum=sum+boards[i];
        if(sum>mid)
        {
            painter++;
            sum=boards[i];
        }
    }
    return painter<=k;
    
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int start =0;
    int sum=0;
    int n= boards.size();
    for(int i=0;i<n;i++)
    {
        sum=sum+boards[i];
    }
    int end=sum;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isValid(boards,k,mid,n))
        end=mid-1;
        else
        {
            start=mid+1;
        }
    }
    return start;
}
