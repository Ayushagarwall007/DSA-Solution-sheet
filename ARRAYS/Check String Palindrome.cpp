// Given the String check weather that String is a Palindrome String or not
// You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and 
//   ignore the symbols and whitespaces.
char toLowerCase(char ch){

   if(ch >= 'a' && ch <='z'){

       return ch;

   }

   else{

       char temp = tolower(ch);

       return temp;

   }

}

 

 

// check palindrome or not 

 

bool checkPalindrome(string s)

{

    int i=0;

   int j=s.size()-1;

   

   while(i<=j){

       

       if (isalnum(s[i]) == 0)

           i++;

       else if (isalnum(s[j]) == 0)

           j--;

       

       else if(toLowerCase(s[i]) != toLowerCase(s[j]))

           return false;

       

       else{

           i++;

           j--;

       }

           

       

   }

   

   return true;

}
