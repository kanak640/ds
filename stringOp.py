def longest_word(str):
    words=str.split()
    for a in words:
        longest=words[0]
        if len(a)>len(longest):
          longest=a
    print("longest word in string=",longest)
def frequncy(str,char):
    count=0
    for a in str:
      if char==a:
         count=count+1
    print("frequency of ",char," is ",count)
def palindrome(str):
   temp=str[::-1]
   if(str==temp):
      print("String is palindrome")
   else :
      print("string is not palindrome")
def apperance(str,substr):
   index=str.find(substr)
   if index!=-1:
      print("substring is found")
   else:
      print("String appeared at index=",index)
def word_count(str):
   words=str.split()
   wordc={}
   for a in words:
      if a==wordc:
         wordc[a]+=1
      else :
         wordc[a]=1
   for word,count in wordc.items():
     print(word,"comes",count," times")
str="i am girl"
ch='i'
frequncy(str,ch)
longest_word(str)
palindrome(str)
apperance(str,"am")
word_count(str)