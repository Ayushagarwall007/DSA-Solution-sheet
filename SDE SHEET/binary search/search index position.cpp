int searchInsert(vector<int>& arr, int m)
{

	int n=arr.size();
	if(arr[n-1]<=m)return n;
	int s=0;
	int e=n-1;
	int index=0;
	while(s<=e)
	{
		int mid=s+(e-s)/2;

		if(arr[mid]<=m)
		{
			index=mid+1;
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	return index;
}
