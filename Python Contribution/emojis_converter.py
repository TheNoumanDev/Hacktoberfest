#Name: Javeria Ehsan

#Username: jjavv

#Favorite Language: Python-C++-MATLAB
  
  #emoji converter
message= input(">")
words = message.split(" ")
emojis = {
    "happy": "😊",
    "sad": "😒",
    "loved": "💕",
    "celebrating": "🎉",
    "cool": "😎",
    "surprised": "🎁",
    "hungry": "🍕",
    "late": "🧭",
    "dance": "💃"

}
output = ""
for items in words:
    output += emojis.get(items,items) + " "

print(output)
