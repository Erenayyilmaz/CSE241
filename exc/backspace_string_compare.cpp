#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		vector <char> new_str, new_str2;    
        long unsigned int i = 0;

		while (s[i])
		{
			if (s[i] != '#')
				new_str.push_back(s[i]);
			else if (i)
				new_str.pop_back();
			i++;
		}
		i = 0;
		while (t[i])
		{
			if (t[i] != '#')
				new_str2.push_back(t[i]);
			else if (i)
				new_str2.pop_back();
			i++;
		}
//		return (new_str2 == new_str);
		bool a = (new_str2 == new_str);
		delete [] new_str;
		delete [] new_str_2;
		return (a);
	}
};