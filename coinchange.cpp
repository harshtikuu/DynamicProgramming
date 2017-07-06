#include<bits/stdc++.h>
using namespace std;
int mincoins(int memo[][200],int den[],int n,int change)
{
if(memo[n][change]!=-1)
return memo[n][change];
if(n==0)
{
memo[n][change]=100000;
return memo[n][change];
}
if(change==0)
{
memo[n][change]=0;
return memo[n][change];
}
else
{
if(den[n]>change)
{
memo[n][change]=mincoins(memo,den,n-1,change);
return memo[n][change];
}
else
{
memo[n][change]=min(mincoins(memo,den,n-1,change),1+mincoins(memo,den,n,change-den[n]));
return memo[n][change];
}
}
}
main()
{
int n;
cout<<"Enter the number of coins";
cin>>n;
int den[n+1];
for(int i=1;i<=n;i++)
{
cout<<"Denomination of coin"<<i;
cin>>den[i];
}
int change;
cout<<"Enter the change";
cin>>change;
int memo[n+1][200];
for(int i=0;i<=n;i++)
{
for(int j=0;j<=change;j++)
{
memo[i][j]=-1;
}}
int ans=mincoins(memo,den,n,change);
if(ans==100000)
{
cout<<"Not possible"<<endl;
return 0;
}
cout<<"Minimum coins reqd = "<<ans<<endl;
return 0;
}


