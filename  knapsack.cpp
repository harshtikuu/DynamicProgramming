#include<bits/stdc++.h>
using namespace std;
int rmax(int x,int y)
{
if(x>y)
return x;
else
return y;
}
void additem(int add[],int c[][100],int wt[],int x,int y)
{
if(x==0 or y==0)
return;
if(c[x][y]==c[x-1][y])
{
additem(add,c,wt,x-1,y);
}
else
{
//add[x]=1;
cout<<"add item"<<x<<endl;
additem(add,c,wt,x-1,y-wt[x]);
}
}
class item
{
public:
int wt;
int val;
};
main()
{
cout<<"No of items";
int n;
cin>>n;
item it[n+1];
int wt[n+1];
for(int i=1;i<=n;i++)
{
cout<<"Value of item"<<i;
cin>>it[i].val;
cout<<"Weight of item "<<i;
cin>>it[i].wt;
wt[i]=it[i].wt;
}
cout<<"Maximum weight";
int max;
cin>>max;
int c[n+1][100];
for(int i=0;i<n+1;i++)
{
c[i][0]=0;
}
for(int i=0;i<max+1;i++)
{
c[0][i]=0;
}
for(int i=1;i<=n;i++){
for(int j=1;j<=max;j++)
{
if(it[i].wt>j)
{
c[i][j]=c[i-1][j];
}
else
{
c[i][j]=rmax(it[i].val+c[i-1][j-it[i].wt],c[i-1][j]);
}
}}
int add[n+1];
for(int i=0;i<=n;i++)
{
for(int j=0;j<=max;j++)
{
cout<<c[i][j]<<"  ";
}add[i]=0;
cout<<endl;
}
additem(add,c,wt,n,max);
/*for(int i=1;i<=n;i++)
{
if(add[i]==1)
cout<<"Add item"<<i<<endl;
}*/
return 0;
}
