#include<bits/stdc++.h>
using namespace std;
int min(int a[],int n){
int m=1000000;
for(int i=1;i<n;i++)
{
if(a[i]<m)
m=a[i];
}
return m;
}
int minjumps(int reachable[][30],int memo[],int n){
if(memo[n]!=-1)
return memo[n];
if(n==1)
{
memo[n]=0;
return memo[n];
}
else
{
int a[20];
int u=1;
for(int i=1;i<n;i++)
{
if(reachable[i][n]==1)
{
a[u]=1+minjumps(reachable,memo,i);
u++;
}
}
memo[n]=min(a,u);
return memo[n];
}
}
main()
{
int a[30];
int n;
cin>>n;
cout<<"Enter the values";
for(int i=1;i<=n;i++)
{
cin>>a[i];
}
int reachable[n+1][30];
int memo[n+1];
for(int i=1;i<=n;i++)
{
memo[i]=-1;
for(int j=1;j<=n;j++)
{
if(i>j or j>i+a[i])
reachable[i][j]=0;
else if(i==j)
reachable[i][j]=1;
else if(j<=i+a[i])
reachable[i][j]=1;
}
}
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
cout<<reachable[i][j]<<"  ";
}
cout<<"\n";
}
cout<<minjumps(reachable,memo,n);
return 0;
}
