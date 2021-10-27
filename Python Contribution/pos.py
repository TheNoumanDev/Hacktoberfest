#Name: Saad Fareed

#Username: saadfareed

#Favorite Language: python

def position(inde):
    flag=False
    sentence= "my name is Saad fareed. I am student of Computer Science. I am from Session 18 and Section A."
    sentence=sentence.split(".")
    #print(sentence)
    for i in sentence:
        #print(i)
        if(inde==i):
            flag=True
            print(sentence.index(inde))
    return flag
print(position(" I am from Session 18 and Section A"))