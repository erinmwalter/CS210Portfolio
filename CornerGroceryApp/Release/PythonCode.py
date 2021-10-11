import re
import string

#this block of code will open up the file in python
#and add to a dictionary that all other functions can use

groceryItemFreq = {}

groceryFile = open ('CS210_Project_Three_Input_File.txt')

for line in groceryFile:
    groceryItem = line.strip()
    if groceryItem in groceryItemFreq:
        groceryItemFreq[groceryItem] += 1
    else:
        groceryItemFreq[groceryItem] = 1

#this function will take the grocery dictionary and then write it to a file
def MakeGroceryList():
    with open('frequency.dat', 'w') as frequencyFile:
        for item in groceryItemFreq:
            print(item, " ", groceryItemFreq[item], end="\n", file = frequencyFile)

    frequencyFile.close()

#this function will display the entire grocery list with their frequencies
def DisplayGroceryList(): 
    print("\nGrocery List Frequency:")
    for item in groceryItemFreq:
        print(item, ": ", groceryItemFreq[item], end = "\n")

#this function will search through the grocery list and 
#return how many times an item was purchased in a day
def FindGroceryItem(userItem):
    itemFound = False;

    for item in groceryItemFreq:
        if (item == userItem):
            itemFound = True;
            break
    if(itemFound): 
       return groceryItemFreq[userItem]
    else:
        return -1
            

    return 0

groceryFile.close()
    
