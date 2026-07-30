#include<iostream>
using namespace std;
class string
{
	char *str;
	public:
	string()										//Constructor
	{
		str=new char[1];
		str[0]='\0';
	}
	string(const char *t)							//Parameterized Constructor
	{
		str=new char[strlen(t)+1];
		strcpy(str,t);
	}
	string(string &t)								//Copy Constructor
	{
		str=new char[strlen(t.str)+1];
		strcpy(str,t.str);
	}
	~string()										//Destructor
	{
		delete []str;
	}
}
int main()
{
}

