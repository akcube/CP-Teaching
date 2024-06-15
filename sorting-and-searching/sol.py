n=int(input())
final_answer={}
mappings={}
for _ in range(n):
	old,new=input().split()
	if old not in mappings:
		final_answer[old]=new
		mappings[new]=old
	else:
		final_answer[mappings[old]]=new
		mappings[new]=mappings[old]

l=[k+" "+v for k,v in final_answer.items()]
print(len(l))
for i in l:
	print(i)