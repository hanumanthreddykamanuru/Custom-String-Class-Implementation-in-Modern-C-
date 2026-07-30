#include<iostream>
#include<cstring>
using namespace std;
class String
{
	char *str;
	public:
	String()										// Constructor
	{
		str=new char[1];
		str[0]='\0';
	}
	String(const char *t)							// Parameterized Constructor
	{
		str=new char[strlen(t)+1];
		strcpy(str,t);
	}
	String(const String &t)								// Copy Constructor
	{
		str=new char[strlen(t.str)+1];
		strcpy(str,t.str);
	}
	~String()										// Destructor
	{
		delete []str;
	}
	void getstring()								// get string function
	{
		cout<<"String : "<< str <<endl;
	}

	String& operator=(const String &t)					// Operator =
	{
		if(this!=&t)
		{
			delete[]str;
			str=new char[strlen(t.str)+1];
			strcpy(str,t.str);
		}
		return *this;
	}
	String operator+(String &t)
	{
		String temp;
		delete []temp.str;
		temp.str=new char[strlen(str)+strlen(t.str)+1];
		strcpy(temp.str,str);
		strcat(temp.str,t.str);
		return temp;
	}
	bool operator==(String &t)						// Operator ==
	{
		return (strcmp(str,t.str)==0);
	}
	bool operator!=(String &t)						// Operator !=
	{
		return (strcmp(str,t.str)!=0);
	}
	bool operator<(String &t)						// Operator <
	{
		return (strcmp(str,t.str)<0);
	}
	bool operator>(String &t)						// Operator >
	{
		return (strcmp(str,t.str)>0);
	}
	bool operator<=(String &t)						// Operator <=
	{
		return (strcmp(str,t.str)<=0);
	}
	bool operator>=(String &t)						// Operator >=
	{
		return (strcmp(str,t.str)>=0);
	}
};
int main()
{
	String s1("Vector"),s2(s1),s3;
	s3=s1+s2;
	s3.getstring();
	cout << boolalpha;
	cout << "s1==s2 : " << (s1 == s2) << endl;
	cout << "s1!=s2 : " << (s1 != s2) << endl;
	cout << "s1<s2  : " << (s1 < s2) << endl;
	cout << "s1>s2  : " << (s1 > s2) << endl;
	cout << "s1<=s2 : " << (s1 <= s2) << endl;
	cout << "s1>=s2 : " << (s1 >= s2) << endl;

}

