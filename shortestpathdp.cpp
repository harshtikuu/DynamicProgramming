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
int shortestpath(int adj[][20],int memo[],int v,int n)
{
if(memo[v]!=-1)
return memo[v];
if(v==1)
{
memo[v]=0;
return memo[v];
}
else
{
int u=1;
int a[30];
for(int i=1;i<=n;i++)
{
if(adj[i][v]!=0)
{
a[u]=shortestpath(adj,memo,i,n)+adj[i][v];
u++;
}
}
memo[v]=min(a,u);
return memo[v];
}}
main()
{
int n;
cout<<"enter the no of nodes";
cin>>n;
int adj[20][20];
int memo[n+1];
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
adj[i][j]=0;
}
memo[i]=-1;
}
while(true)
{
int a,b,wt;
cout<<"enter edge from "; cin>>a; if(a==99) break; cout<<"to"; cin>>b;
cout<<"enter wt";
cin>>wt;
adj[a][b]=wt;
}
cout<<shortestpath(adj,memo,n,n);
return 0;
}
