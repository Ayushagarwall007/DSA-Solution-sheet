// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
class Solution {
public:
	bool judgeSquareSum(long long int c) {

		long int root=sqrt(c);
		cout<<"root is "<<root<<endl;
		if(root*root==c)
			return true;

		for(int i=0;i<=root;i++)
		{   
			int start=0;
			int end=root;
			while(start<=end)
			{   
				long long int mid=start+(end-start)/2;
				if(i*i+mid*mid==c)
				{ 
					cout<<"nums: "<<mid<<" "<<i<<endl;
					return true;
				}
				else if(i*i+mid*mid<c)
					start=mid+1;
				else
					end=mid-1;       
			}
		}
		return false;

	}
};
