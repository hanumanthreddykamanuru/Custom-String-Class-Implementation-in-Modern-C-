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
	char &operator [](int i)
	{
		return str[i];
	}
	friend istream& operator>>(istream& ,String &);
	friend ostream& operator<<(ostream&,String );
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
	friend char *my_strstr(const String &, const String &);

};
istream& operator>>(istream& in,String &s)
{
	in>>s.str;
	return in;
}
ostream& operator<<(ostream &out,String s)
{
	out<<s.str;
	return out;
}
char *my_strstr(const String &t1, const String &t2)
{
	char *s=t1.str;									//taking string 1 and 2 and implementing strstr same as in C
	char *d=t2.str;
	int i,j;
	for(i=0;s[i];i++)
	{
		if(s[i]==d[0])
		{
			for(j=0;d[j];j++)
			{
				if(s[i+j]!=d[j])
					break;
			}
			if(d[j]=='\0')
				return &s[i];
		}
	}
	return 0;
}
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
int op;
	while(1)
	{
		cout<<"Enter your choice"<<endl;
		cout<<"1.operators overlode 2.copy constructor 3.strcpy() 4.strncpy() 5.strcmp() 6.strncmp() 7.strcat() 8.strncat() 9.strrev() 10.strupper() 11.strlower() 12.strchr() 13.strrchr() 14.strstr() 15.strlen() 16.exit"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				{
					String s1,s2,s3;
					int a;
					cout<<"Enter First String: ";
					cin>>s1;
					cout<<"Enter Second String: ";
					cin>>s2;
					cout<<boolalpha<<(s1>s2)<<endl;
					cout<<boolalpha<<(s1<s2)<<endl;
					cout<<boolalpha<<(s1<=s2)<<endl;
					cout<<boolalpha<<(s1>=s2)<<endl;
					cout<<boolalpha<<(s1==s2)<<endl;
					cout<<boolalpha<<(s1!=s2)<<endl;
					cout<<"'+' & '=' Operator overloaded : ";
					s3=s1+s2;
					cout<<s3<<endl;
					cout<<"Enter index "<<endl;
					cin>>a;
					cout<<"Character is : "<<s1[a]<<endl;
					cout<<endl;
					break;
				}
					case 2:
				{
					String s1;
					cout<<"Enter a String: ";
					cin>>s1;
					String s2(s1);
					cout<<"Copy Constructor = "<<s2<<endl;
					cout<<endl;
					break;
				}
							case 3:
				{
					String s1,s2;
					cout<<"Enter a String: ";
					cin>>s1;
					my_strcpy(s2,s1);
					cout<<s2<<endl;
					break;
				}
case 4:
				{
					int n;
					String s1,s2,s3;
					cout<<"Enter a String: ";
					cin>>s1;
					cout<<"Enter number of charactor"<<endl;
					cin>>n;
					my_strncpy(s2,s1,n);
					cout<<s2<<endl;
					break;
				}
			case 5:
				{
					String s1,s2;
					cout<<"Enter First String: ";
					cin>>s1;
					cout<<"Enter Second String: ";
					cin>>s2;
					int cmp=my_strcmp(s1,s2);
					if(cmp==0)
						cout<<"equal"<<endl;
						else
							cout<<"not equal"<<endl;
					break;
				}
			case 6:
				{
					String s1,s2;
					int n;
					cout<<"Enter First String: ";
					cin>>s1;
					cout<<"Enter Second String: ";
					cin>>s2;
					cout<<"Enter number of charactor"<<endl;
					cin>>n;
					int cmp=my_strcmp(s1,s2);
					if(cmp==0)
						cout<<"equal"<<endl;
						else
							cout<<"not equal"<<endl;
					break;
				}
			case 7:
				{
					String s1,s2;
					cout<<"Enter First String: ";
					cin>>s1;
					cout<<"Enter Second String: ";
					cin>>s2;
					my_strcat(s1,s2);
					cout<<s1<<endl;
					break;
				}
			case 8:
				{
					String s1,s2;
					int n;
					cout<<"Enter First String: ";
					cin>>s1;
					cout<<"Enter Second String: ";
					cin>>s2;
					cout<<"Enter number of charactor"<<endl;
					cin>>n;
					my_strncat(s1,s2,n);
					cout<<s1<<endl;
					break;
				}
			case 9:
				{
					String s1;
					cout<<"Enter a String: ";
					cin>>s1;
					my_strrev(s1);
					cout<<s1<<endl;
					break;
				}
			case 10:
				{
					String s1;
					cout<<"Enter a String: ";
					cin>>s1;
					my_strupr(s1);
					cout<<s1<<endl;
					break;
				}
			case 11:
				{
					String s1;
					cout<<"Enter a String: ";
					cin>>s1;
					my_strlwr(s1);
					cout<<s1<<endl;
					break;
				}
			case 12:
				{
					String s1;
					char ch;
					cout<<"Enter a String: ";
					cin>>s1;
					cout<<"Enter a character"<<endl;
					cin>>ch;
					char *p=my_strchr(s1,ch);
					if(p)
						cout<<p[0]<<endl;
					else
						cout<<"Character not found"<<endl;
					break;
				}
			case 13:
				{
					String s1;
					char ch;
					cout<<"Enter a String: ";
					cin>>s1;
					cout<<"Enter a character"<<endl;
					cin>>ch;
					char *p=my_strchr(s1,ch);
					if(p)
						cout<<p[0]<<endl;
					else
						cout<<"Character not found"<<endl;
					break;
				}
			case 14:
				{
					String s1,s2;
					cout<<"Enter main String: ";
					cin>>s1;
					cout<<"Enter Sub String: ";
					cin>>s2;
					my_strstr(s1,s2);
					char *p=my_strstr(s1,s2);

if(p)
    cout<<p<<endl;
else
    cout<<"Substring not found"<<endl;
					break;
				}
			case 15:
				{
					String s1;
					cout<<"Enter a String: ";
					cin>>s1;
				cout<<my_strlen(s1)<<endl;
					break;
				}
			case 16:exit(0);
			default :cout<<"Unknown op"<<endl;
		}
	}
}
