#include <bits/stdc++.h> 
void solve(int ind, string temp, string &str,int n, vector<string>&ans)
{
	if(ind==n)
	{
		if(temp.size()>0)ans.push_back(temp);
		return;
	}
	solve(ind+1,temp+str[ind],str,n,ans);
	solve(ind+1,temp,str,n,ans);
}
vector<string> subsequences(string str){
	
	int n=str.size();
	vector<string>ans;
	solve(0,"",str,n,ans);
	return ans;
	
}
