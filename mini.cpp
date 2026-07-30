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
	friend void my_strcpy(String &, const String &);
	friend void my_strncpy(String &, const String &, int);
	friend int my_strcmp(const String &, const String &);
	friend int my_strncmp(const String &, const String &,int );
	friend char * my_strchr(const String &, char);
	friend char * my_strrchr(const String &, char);
	friend void my_strcat(String &, const String &);
	friend void my_strncat(String &, const String &, int);

};
void my_strncat(String &dest, const String &src,int n)
{
    int srclen = my_strlen(src);
    int destlen= my_strlen(dest);
	if(n<srclen)
		srclen=n;
    char *temp = new char[srclen + destlen + 1];
    int i, j;
    for(i = 0; i <destlen; i++)
        temp[i] = dest.str[i];
    for(j = 0; j < srclen; j++)
        temp[i + j] = src.str[j];
    temp[i + j] = '\0';
    delete[] dest.str;
    dest.str = temp;
}
void my_strcat(String &dest, const String &src)
{
    int srclen = my_strlen(src);
    int destlen= my_strlen(dest);
    char *temp = new char[srclen + destlen + 1];
    int i, j;
    for(i = 0; i <destlen; i++)
        temp[i] = dest.str[i];
    for(j = 0; j < srclen; j++)
        temp[i + j] = src.str[j];
    temp[i + j] = '\0';
    delete[] dest.str;
    dest.str = temp;
}
void my_strncpy(String &dest, const String &src,int n)
{
	delete[] dest.str;
	int length=my_strlen(src);
	if(n<length)
		length=n;
	dest.str = new char[length + 1];
	int i;
	for(i = 0;i<length; i++)
		dest.str[i] = src.str[i];
	dest.str[i] = '\0';
}
void my_strcpy(String &dest, const String &src)
{
	delete[] dest.str;
	dest.str = new char[my_strlen(src) + 1];
	int i;
	for(i = 0; src.str[i] != '\0'; i++)
		dest.str[i] = src.str[i];
	dest.str[i] = '\0';
}
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
int my_strncmp(const String &t1, const String &t2,int n)
{
	int i = 0;
	while(i<n && t1.str[i] != '\0' && t2.str[i] != '\0')
	{
		if(t1.str[i] != t2.str[i])
			return t1.str[i] - t2.str[i];
		i++;
	}
	if(i==n)
		return 0;
	return t1.str[i] - t2.str[i];
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
	my_strncat(s3,s1,1);
	s3.getstring();
	cout<<"my_strcmp "<<my_strcmp(s1,s2)<<endl;
	cout << boolalpha;
	cout << "s1==s2 : " << (s1 == s2) << endl;
	cout << "s1!=s2 : " << (s1 != s2) << endl;
	cout << "s1<s2  : " << (s1 < s2) << endl;
	cout << "s1>s2  : " << (s1 > s2) << endl;
	cout << "s1<=s2 : " << (s1 <= s2) << endl;
	cout << "s1>=s2 : " << (s1 >= s2) << endl;

}

