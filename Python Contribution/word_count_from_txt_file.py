'''
NOTE: Remember to keep the text file to be used, in the same directory as that of the code
'''

# taking input from user
name = input("Enter file name: ")
handle = open(name)

# initializing empty list and dictionary and storing texts from the file in them for further operation
list1 = []
counts = {}
for line in handle:
    line.strip()
    words = line.split()
    list1 = list1 + words
    for word in words:
        counts[word] = counts.get(word,0) + 1

# counting total number of words        
c = 0
for i in list1:
    c += 1

# displaying total number of words in the file
print("Total numer of words:",c)

# finding the most commonly used word and how many times it has been used
bigcount = None
bigword = None
for word,count in counts.items():
    if bigcount is None or count>bigcount:
        bigword = word
        bigcount = count

# displaying most commonly used word in the file and number of times it has been used
print("Most common word is:",'"',bigword,'"',"\nAnd it is written in the file",'"',bigcount,'"',"times")

'''
      ---:: OUTPUT ::---
>>> Enter file name: words.txt
Total numer of words: 210
Most common word is: " to " 
And it is written in the file " 16 " times

>>> Enter file name: test.txt
Traceback (most recent call last):
  File "main.py", line 2, in <module>
    handle = open(name)
FileNotFoundError: [Errno 2] No such file or directory: 'test.txt'
'''
