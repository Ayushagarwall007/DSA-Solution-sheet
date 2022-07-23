// Let the input string be “i like this program very much”. The function should change the string to “much very program this like i”
  

// APPROACH 01 BRUTE'S FORCE APPROACH

#include <bits/stdc++.h>
using namespace std;
void reverseWords(string s)
{
	
	
	vector<string> tmp;
	string str = "";
	for (int i = 0; i < s.length(); i++)
	{
		
		if (s[i] == ' ')
		{
			tmp.push_back(str);
			str = "";
		
		else
			str += s[i];
	}

	tmp.push_back(str);

	int i;
	for (i = tmp.size() - 1; i > 0; i--)
		cout << tmp[i] << " ";
	cout << tmp[0] << endl;
}
int main()
{
	string s = "i like this program very much";
	reverseWords(s);
	return 0;
}

  
//  APPROACH 02
  
  
  #include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string reverse_words(string s)
{
	int left = 0, i = 0, n = s.size();

	while (s[i] == ' ')
		i++;

	left = i;

	while (i < n) {
		if (i + 1 == n || s[i] == ' ') {
			int j = i - 1;
			if (i + 1 == n)
				j++;

			while (left < j)
				swap(s[left++], s[j--]);

			left = i + 1;
		}
		if (i > left && s[left] == ' ')
			left = i;

		i++;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{

	string str = "Be a game changer the world is already "
				"full of players";

	str = reverse_words(str);

	cout << str;

	return 0;
}
