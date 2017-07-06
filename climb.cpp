#include<bits/stdc++.h>
using namespace std;
int climb(int m,int n,int memo[][300])
{
if(memo[m][n]!=-1)
return memo[m][n];
if(m==0 or n==0)
{
memo[m][n]=1;
return memo[m][n];
}
else
{
memo[m][n]=climb(m-1,n,memo)+climb(m,n-1,memo);
return memo[m][n];
}
}
main()
{
int m;
cout<<"m?";
cin>>m;
int n;
cout<<"n?";
cin>>n;
int memo[300][300];
for(int i=0;i<=m;i++)
{
for(int j=0;j<=n;j++)
{
memo[i][j]=-1;
}
}
cout<<climb(m,n,memo);
return 0;
}
