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
int matrix(int i,int j,int memo[][20],int p[])
{
if(memo[i][j]!=-1)
return memo[i][j];
if(i==j)
{
memo[i][j]=0;
return memo[i][j];
}
else
{
int a[20];
int u=1;
for(int k=i;k<j;k++)
{
a[u]=matrix(i,k,memo,p)+matrix(k+1,j,memo,p)+p[i-1]*p[k]*p[j];
u++;
}
memo[i][j]=min(a,u);
return memo[i][j];
}
}
main()
{
int n;
cout<<"Enter the number of matrices";
cin>>n;
int p[n+1];
cout<<"Enter the values of p";
for(int i=0;i<=n;i++)
{
cout<<"p"<<i<<"=";
cin>>p[i];
}
int ans;
int memo[20][20];
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
memo[i][j]=-1;
}}
ans=matrix(1,n,memo,p);
cout<<ans;
return 0;
}
