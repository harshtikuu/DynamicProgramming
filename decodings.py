s=[]
while True:
	i=input()
	if i=='0':
		break
	s.append(i)
def decodings(x,l):
	if l in d:
		return d[l]
	if l=0:
		return 1;
	if l==1:
		if s[0]=='0':
			return 0
		else:
			return 1
	if s[l-1]!='0':
		if s[l-2]=='0':
			return 0;
		else:
			if int(x[l-2:l])<=26:
				d[l]=decodings(x,l-1)+decodings(x,l-2)
				return d[l]
			else:
				d[l]=decodings(x,l-1)
				return d[l]
	else:
		d[l]=D=

for x in s:
	d={}
	l=len(x)
	print(decodings(x,l))