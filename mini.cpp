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
	friend int my_strlen(const String &);
	friend void my_strrev(String &);
	friend void my_strupr(String &);
	friend void my_strlwr(String &);
	friend int my_strcmp(const String &, const String &);
	friend char * my_strchr(const String &, char);
	friend char * my_strrchr(const String &, char);
};
char * my_strrchr(const String &t, char ch)
{
    char *p = NULL;
    for(int i = 0; t.str[i] != '\0'; i++)
    {
        if(t.str[i] == ch)
            p = &t.str[i];
    }
    return p;
}

char * my_strchr(const String &t, char ch)
{
    for(int i = 0; t.str[i] != '\0'; i++)
    {
        if(t.str[i] == ch)
            return &t.str[i];
    }

    return 0;
}

int my_strlen(const String &t)
{
	int i = 0;
	while(t.str[i] != '\0')
		i++;
	return i;
}
void my_strrev(String &t)
{
	char *p=t.str,*q=t.str;
	while(*q)
		q++;
	q--;
	char temp;
	while(p<q)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;
		q--;
	}
}
int my_strcmp(const String &t1, const String &t2)
{
	int i = 0;
	while(t1.str[i] != '\0' && t2.str[i] != '\0')
	{
		if(t1.str[i] != t2.str[i])
			return t1.str[i] - t2.str[i];
		i++;
	}
	return t1.str[i] - t2.str[i];
}
void my_strupr(String &t)
{
	for(int i = 0; t.str[i] != '\0'; i++)
	{
		if(t.str[i] >= 'a' && t.str[i] <= 'z')
			t.str[i] = t.str[i] - 32;
	}
}
void my_strlwr(String &t)
{
	for(int i = 0; t.str[i] != '\0'; i++)
	{
		if(t.str[i] >= 'A' && t.str[i] <= 'Z')
			t.str[i] = t.str[i] + 32;
	}
}
int main()
{
	String s1("Vector"),s2(s1),s3;
	char ch='V';
	s3=s1+s2;
	cout<<"my_strcmp "<<my_strcmp(s1,s2)<<endl;
	s3.getstring();
	my_strrev(s1);
	s1.getstring();
	my_strupr(s1);
	s1.getstring();
	my_strlwr(s1);
	s1.getstring();
	char *p=my_strrchr(s3,ch);
	if(p)
		cout<<"found"<<endl;
		else
		cout<<" not found"<<endl;
	cout << my_strlen(s3) << endl;
	cout << boolalpha;
	cout << "s1==s2 : " << (s1 == s2) << endl;
	cout << "s1!=s2 : " << (s1 != s2) << endl;
	cout << "s1<s2  : " << (s1 < s2) << endl;
	cout << "s1>s2  : " << (s1 > s2) << endl;
	cout << "s1<=s2 : " << (s1 <= s2) << endl;
	cout << "s1>=s2 : " << (s1 >= s2) << endl;

}

