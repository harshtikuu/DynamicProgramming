#include<bits/stdc++.h>
using namespace std;
int maxprofit(int i,int maxwt,int val[],int wt[],int memo[][40])
{
if(memo[i][maxwt]!=-1)
return memo[i][maxwt];
if(i==0 or maxwt==0)
{
memo[i][maxwt]=0;
return memo[i][maxwt];
}
if(wt[i]>maxwt)
{
memo[i][maxwt]=maxprofit(i-1,maxwt,val,wt,memo);
return memo[i][maxwt];
}
else
{
memo[i][maxwt]=max(val[i]+maxprofit(i-1,maxwt-wt[i],val,wt,memo),maxprofit(i-1,maxwt,val,wt,memo));
return memo[i][maxwt];
}
}
main()
{
int n;
cout<<"No of items";
cin>>n;
int wt[n+1], val[n+1];
for(int i=1;i<=n;i++)
{
cout<<"Weight of item"<<i;
cin>>wt[i];
cout<<"Value of item "<<i;
cin>>val[i];
}
int maxwt;
cout<<"Maximum Weight";
cin>>maxwt;
int memo[n+1][40];
for(int i=0;i<=n;i++)
{
for(int j=0;j<=maxwt;j++)
{
memo[i][j]=-1;
}
}
cout<<maxprofit(n,maxwt,val,wt,memo);
return 0;
}


