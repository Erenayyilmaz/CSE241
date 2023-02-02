#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class MyString
{
private:
	string str;
	unsigned int len;
public:
	MyString(string s);
	MyString();
	friend ostream & operator << (ostream &out, const MyString &c);
	friend istream & operator >> (istream &in,  MyString &c);
	friend MyString operator+(MyString str1, string s);
	friend MyString operator+(MyString str1, MyString str2);
	char& operator[](int);

};


MyString::MyString()
{

}

MyString::operator+(MyString str1, string	s)
{
	MyString	tmp;
	tmp.str.resize(str1.str.len() + s.lenght());
	strcat(tmp.str, str1.str);
	strcat(tmp.str, s);
	//tmp = str1 + s;
	return (tmp);
}

MyString::MyString(string s)
{
	int	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	len = i;
}


int main()
{
	MyString s1, s2("abc");//max 1k char


	return 0;
}

