// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 class Solution {
public:
string multiply(string num1, string num2) {
    int n=num1.size();
    int m=num2.size();
    string s;
    
    //  Corner Cases //
    if(num1.size()==1 && num1[0]=='0')
    {
        return "0";
    }
    if(num2.size()==1 && num2[0]=='0')
     {
        return "0";
    }
    if(num1.size()==1 && num1[0]==1)
        return num2;
    
    if(num2.size()==1 && num2[0]==1)
        return num1;
    
    
    // Corner Cases //
   
    
    vector<int> nums1,nums2;
    for(int i=n-1;i>=0;i--)
        nums1.push_back(num1[i] -'0');  // converting string to int

    for(int i=m-1;i>=0;i--)
        nums2.push_back(num2[i] -'0');  // converting string to int

    
    // Here the strings are reversed basically 
    // it is more convinient now to multiply these 2 arrays;

    int a[n+m];
    for(int i=0;i<n+m;i++)
        a[i]=0;
    
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           a[i+j] += nums1[i]*nums2[j];   // Multiplication of the 2 vectors.
           a[i+j+1] += a[i+j]/10;
           a[i+j]%=10;
       }
   }
    
    
    
    
    for(int i=n+m-1; i>=0;i--)
    s.push_back(a[i]+'0');     // convertin the int vector string again and reversing it at the same time.
    
  
    
    if(s[0] =='0'){           // Removing the leading zeroes if any; 
    int i=0;                  
    while(s[i]=='0')
        i++;
    
    s.erase(s.begin(),s.begin()+i);}
    
    return s;
	}
};
