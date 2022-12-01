#include<iostream> 
#include<string.h> 
using namespace std; 
class string1 
{      	
	char str[50];      	
	int len;      	
    public: 
        string1(){}          
            string1(char *c)          
            {              	
            strcpy(str,c); 
            len=strlen(c);          
            }          
            string1 operator + (string1 s2);          
            int operator < (string1 s2);          
            void display(); 
}; 
string1 string1::operator + (string1 s2) 
{      	
	string1 temp;      	
	temp.len=len+s2.len; 
	strcpy(temp.str,str);      	
	strcat(temp.str,s2.str);      	
    return temp; 
} 

int string1::operator < (string1 s2) 
{ 
 	if(len<s2.len)  	
	 return 1;  	
	 else 
 	return 0; 
} 
void string1::display() 
{ 
 	cout<<str<<endl; 
} 
   
int main() 
{ 
 	char str[50];  	
	cout<<"Enter 1st string : ";  	
	cin>>str; 
 	string1 s1(str);  	
	cout<<"Enter 2nd string : ";  	
	cin>>str; 
 	string1 s2(str);  	
	string1 s3;  	
	s3=s1+s2; 
 	cout<<"\ns1 = ";
	s1.display();  	
	cout<<"\ns2 = ";
	s2.display();  	
	cout<<"\ns3 = s1 + s2 = "; 
	s3.display(); 
 	 
 	if(s1<s2) 
 	{ 
		cout<<"\nString with smaller length : "; 
		s1.display(); 
 	} 
 	else 
 	{ 
		cout<<"\nString with smaller length : "; 
		s2.display(); 
 	} 
    cout << endl;
 	return 0; 
} 