#David Bousson
#9/23/2020
#war program

import random
#variables
name1 = str()
name2 = str()
card1 = int()
card2 = int()
count1 = int()
count2 = int()


#collect names
name1 = input("Player 1 enter your name:")
name2 = input("Player 2 enter your name:")

#start loop
while count1 < 10:
    #i tried to do an or statement in the while line but
    #my program ran until both had at least 10, as if it was an and statement
    #this line was my fix
    #a few days later i am realizing i could have done an AND statement and have both be less than 10
    #This code is a mess but it works haha
    if count2 == 10:
        break
   
    #"Draw" yor card
    card1 = random.randint(1,13)
    card2 = random.randint(1,13)
    
    #if statement to declair winner
    if card1 == card2:
        print(name1,"'s number was ", card1,sep="")
        print(name2,"'s number was ", card2,sep="")
        print("It's a draw")
        print("")
    elif card1 > card2:
        print(name1,"'s number was ", card1,sep="")
        print(name2,"'s number was ", card2,sep="")
        print(name1, "wins this round")
        count1 = count1 + 1
        print("")
    elif card1 < card2:
        print(name1,"'s number was ", card1,sep="")
        print(name2,"'s number was ", card2,sep="")
        print(name2, "wins this round")
        count2 = count2 + 1
        print("")

#end of program summary
print(name1,"'s score was ", count1,sep="")
print(name2,"'s score was ", count2,sep="")
if count1 > count2:
    print(name1, "wins!")
if count1 < count2:
    print(name2, "wins!")











        
