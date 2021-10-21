#David Bousson
#11/12/2020
#lab 8




#Declared variable
another1 = 0 #sentinal control for loop
count = 0 #used in for loop to print results
x = 0  #used for counter
per = str("")
listper = [] #list to allow for as many or few inputs as desired
listcust = []
mail = 0
cust = 0

#class
class person:

    def __init__(self,person):
        self.__name = str(person)
        self.__address = 0
        self.__phone = str()

    def determineaddress(self):
        self.__address = input("Enter address:")

    def determinephone(self):
        self.__phone = int(input("Enter phone number:"))


    def getname(self):
        return self.__name
    def getaddress(self):
        return self.__address
    def getphone(self):
        return self.__phone


#subclass
class customer(person):
    
    def __init__(self,custnum):
        self.__custnum = int(custnum)
        self.__mail = bool

    def determinemail(self):
        mail = int(input("Press 1 to be removed from mail list, all other inputs will keep you on:"))
        if mail == 1: 
            self.__mail = False
        else:
            self.__mail = True


    def getcustnum(self):
        return self.__custnum
    def getmail(self):
        return self.__mail


#program loop to add people
def main():

    another1 = int(input("Press 1 to add customer to database:"))

    #Loop to input as many people as desired
    while another1 == 1:
        
        #kept getting errors and declaring these global made them go away????
        global x
        global listper

        #stored people all to one list
        per = input("Enter name:")
        listper.append(per)
        listper[x] = person(per)
        listper[x].determineaddress()
        listper[x].determinephone()
        
        cust = int(input("Enter customer number:"))
        listcust.append(cust)
        listcust[x] = customer(cust)
        listcust[x].determinemail()
        
        
        #counter to separate list and insure data isnt written over itself
        x = x + 1
        another1 = int(input("Press 1 to add another person to the data base:"))
        print("")
        
    #reset x instead of making a new variable for loop
    x = 0
    #spacer between input and then loop to print data
    print("")
    for count in range(len(listper)):
        print("Name: ", listper[x].getname())
        print("Address: ", listper[x].getaddress())
        print("Phone number: ", listper[x].getphone())
        print("Customer number: ", listcust[x].getcustnum())
        print("On mailing list: ", listcust[x].getmail())
        print("")
        
        x = x + 1
        count = count + 1

        
main()

#This program is basically parallel lists and classes, i couldnt figure out how
#to take in data and tie the classes together. The example we were given is just
#everything input from the program and the program prints the vehicle info

