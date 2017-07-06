#include<bits/stdc++.h>
using namespace std;
int max(int a[],int n){
int m=0;
for(int i=1;i<n;i++)
{
if(a[i]>m)
m=a[i];
}
return m;
}
int rodcut(int memo[],int cost[],int l)
{
if(memo[l]!=-1)
return memo[l];
if(l==0)
{
memo[l]=0;
return memo[l];
}
else
{
int a[30];
int u=1;
for(int i=1;i<=l;i++)
{
if(cost[i]!=-1)
{
a[u]=cost[i]+rodcut(memo,cost,l-i);
u++;
}
}
memo[l]=max(a,u);
return memo[l];
}}
main()
{
int l;
cout<<"Enter length of rod";
cin>>l;
int cost[l+1];
int memo[l+1];
cost[0]=0;
cout<<"Enter cost for lengths -1 for no cost"<<endl;
for(int i=1;i<=l;i++){
cout<<"Cost of length "<<i;
cin>>cost[i];
memo[i]=-1;
}
memo[0]=-1;
cout<<rodcut(memo,cost,l);
return 0;
}
