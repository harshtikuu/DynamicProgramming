t=int(input())
for i in range(t):
	n,k=map(int,input().split())
	l=list(map(int,input().split()))
	l.insert(0,0)
	d={}
	for i in range(1,k+1):
		if l[i]!=-1:
			d[i]=l[i]
	memo={}
	def mincost(k):
		li=[]
		if k in memo:
			return memo[k]
		if k==0:
			memo[k]=0
			return memo[k]
		elif k<0:
			return 100000
		else:
			for key in d.keys():
				li.append(d[key]+mincost(k-key))
			memo[k]=min(li)
			return memo[k]
	if mincost(k)>=100000:
		print (-1)
	else:
		print(mincost(k))