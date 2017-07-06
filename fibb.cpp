#include<bits/stdc++.h>
using namespace std;
 unsigned long  fibb(int n)
{
int a[n];
a[0]=1;
a[1]=1;
for(int i=2;i<n;i++)
{
a[i]=a[i-1]+a[i-2];
}
return a[n-1];
}
main()
{
int n;
cin>>n;
cout<<fibb(n);
return 0;}

