#include<iostream>
using namespace std;
int main()
{
 string crc,msg,encoded="";
 cout<<"Enter the Dataword :";
 cin>>msg;
 cout<<"Enter The Generator Polynomial : ";
 cin>>crc;
 encoded+=msg;
 int n=crc.length();
 int m=msg.length();
 for (int i=1;i<=n-1;i++)
 {
   encoded+='0';
 }
 cout<<"Modified Message :"<<encoded;
 for(int i=0;i<=encoded.length()-n;)
        {
           for(int j=0;j<n;j++)
                encoded[i+j]=encoded[i+j]==crc[j]?'0':'1';
           for(;i<encoded.length()&&encoded[i]=='0';i++);

        }
 string y="";
 y+=encoded.substr(encoded.length()-n+1);
 cout<<"\nChecksum : "<<y;
 string a1="";
 a1+=msg;
 a1+=y;
 cout<<"\nTransmitted Codeword : "<<a1;
 string a;
 cout<<"\nEnter The Recieved Codeword :";
 cin>>a;
 for(int i=0;i<=a.length()-n;)
        {
   for(int j=0;j<n;j++)
                a[i+j]=a[i+j]==crc[j]?'0':'1';
           for(;i<a.length()&&a[i]=='0';i++);

        }
 string b=a.substr(a.length()-n+1);
 for(int i=0;i<b.length();i++)
        if (b[i]!='0')
                {
                        cout<<"\nError in Transmission";
                        cout<<"\nChecksum : "<<b;
                        return 0;
                 }
  cout<<"\nNo Error in Transmission";
  cout<<"\nChecksum : "<<b<<"\n";

  return 0;
}