#include<bits/stdc++.h>
using namespace std;
int rmax(int x,int y)
{
if(x>y)
return x;
else
return y;
}
main()
{
string s1,s2;
cout<<"String 1";
cin>>s1;
cout<<"String 2";
cin>>s2;
char str1[20],str2[20];
int k=1;
for(int i=0;i<s1.length();i++)
{
str1[k]=s1[i];
k++;
}
k=1;
for(int i=0;i<s2.length();i++)
{
str2[k]=s2[i];
k++;
}
int c[30][30];
int l1=s1.length();
int l2=s2.length();
for(int i=0;i<=l1;i++)
{
c[i][0]=0;
}
for(int j=0;j<=l2;j++)
{
c[0][j]=0;
}
for(int i=1;i<=l1;i++)
{
for(int j=1;j<=l2;j++)
{
if(str1[i]==str2[j])
{
c[i][j]=c[i-1][j-1]+1;
}
else
{
c[i][j]=rmax(c[i-1][j],c[i][j-1]);
}
}}
print(c);
return 0;
}
