#include<bits/stdc++.h>
using namespace std;
int func(vector< vector<int> > &memo,string s,int i,int j)
{
if(memo[i][j]!=-1)
return memo[i][j];
if(i==j)
{
memo[i][j]=1;
return memo[i][j];
}
if(s[i]==s[j])
{
if(i+1==j)
{
memo[i][j]=2;
return memo[i][j];
}
else
{
memo[i][j]=2+func(memo,s,i+1,j-1);
return memo[i][j];
}
}
else
{
memo[i][j]=max(func(memo,s,i+1,j),func(memo,s,i,j-1));
return memo[i][j];
}
}
main()
{
string s;
cout<<"Enter the string";
cin>>s;
const int l=s.length();
vector< vector<int> > memo(l,vector<int>(l,-1));
cout<<func(memo,s,0,l-1);
return 0;
}
