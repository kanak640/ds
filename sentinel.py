rollNo=[20,1,4,7,2,18,32,12]
key=int(input("Enter number to search="))
n=len(rollNo)
last_element=rollNo[n-1]
rollNo[n-1]=key
found=False
i=0
while rollNo[i]!=key:
    i=i+1
    pos=0
    rollNo[n-1]=last_element
    if i<n-1 and rollNo[i]==key:
        found=True
        pos=i
        break
    else:
        found=False
if found:
    print("Element found at position=",pos+1)
else:
    print("Not found")