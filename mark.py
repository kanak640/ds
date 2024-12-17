from collections import Counter
def average(marks):
    valid=[]
    for mark in marks:
        if mark==-1:
          continue
        else:
          valid.append(mark)
    if valid:
       return sum(valid)/len(valid)  
    else :
       return 0
def highest_lowest(marks):
    valid=[]
    for mark in marks:
        if mark==-1:
          continue
        else:
          valid.append(mark)
    if valid:
       return max(valid),min(valid)
    else:
       return 0
def high_frequency(marks):
    valid=[]
    for mark in marks:
        if mark==-1:
          continue
        else:
          valid.append(mark)
    if valid:
       frequency=Counter(valid)
       most_common=frequency.most_common(1)[0]
       return most_common
def absent(marks):
    absent=0
    for mark in marks:
        if mark==-1:
          absent=absent+1
    return absent
marks=[10,65,-1,76,-1,10,65,65]
a=average(marks)  
print("Average=",a)    
high,low=highest_lowest(marks)
print("highest marks=",high)
print("lowest marks=",low)  
fr=high_frequency(marks)
print("frequency=",fr)
ab=absent(marks)
print("Absent students=",ab)