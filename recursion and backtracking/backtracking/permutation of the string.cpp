for the given string find the permutation of the string using backtarcaking
#include<bits/stdc++.h>
using namespace std;
void printAll(int index, vector<int>&output,string &str)
{
    if(index==str.size())
    {
        output.push_back(str) ;
        return;
    }
    for(int j=index;j<str.size();j++)
    {
        swap(str[index],str[j]);
        printAll(j+1,output,str);
        swap(str[index],str[j]);
    }
}
int main()
{
    string str="abcd";
    int index=0;
    vector<string> output;
    printAll(index,output,str);
     
     
     cout<<"printing all the permutations of the string"<<endl;
     for(auto i:output)
     {
         cout<<i<<" "<<endl;
     }
}
