rollNo=[10,2,7,15,12]
key=int(input("Enter element to search="))
n=len(rollNo)
no1=0
no2=1
no3=no1+no2
found=False
while no3<n:
    no1=no2
    no2=no3
    no3=no1+no2
offset=-1
while no3>1:
    i=min(offset+no1,n-1)
    if rollNo[i]<key:
        no3=no2
        no2=no1
        no1=no3-no2
        offset=i
    elif rollNo[i]>key:
        no3=no1
        no2=no2-no1
        no1=no3-no2
    else :
        found=True
        break
if no2 and offset+1<n and rollNo[offset+1]==key:
    found=True
if found:
    print("roll no is found")
else :
    print("roll no not found")