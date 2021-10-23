length = 0
width = 0

length = int(input("Enter length of Shape : "))
width = int(input("Enter Width of Shape : "))

if length != 0 and width != 0 :
    if length == width:
        print("This is Square")
    else:
        print("This is NOT a Square")

else :
    print("It's not a Shape")
