CS210Portfolio

This folder contains my three CS 210 projects, primarily in C++, with one project having both C++ and Python.

CLOCK APP: 
- The goal of this project was to be able to write a C++ program to display a 12 and 24 hour clock to the screen and allow the user to add hours, minutes,
  or seconds to the clock and display the updated clock to the screen.
- I believe I could've made this code more efficient or simpler by using inheritance and polymorphism. I made separate classes for the 12 and 24 hour clocks, and there
  was a lot of repeat code in both sections, so if I were to re-work this code I would use inheritance and polymorphism to simplify the code and reuse the code for both
  clocks, but have the code behave differently whether I was calling it as the 12 hour clock or as the 24 hour clock.
- At the time, I was struggling to get inheritance or polymorphism concepts down, so I opted against it, but found there was a lot of repetitive code. The app works
  and behaves how it was intended, however there could be a lot less code if I had been able to successfully employe these principles of OOP. I also found the display
  formatting somewhat challenging. The clock format needed to be displayed as 01:01:01 instead of 1:1:1, for instance, so I solved this by setting the width of each
  variable in the display to 2, right aligning it, and then setting the fill to 0 so that the zeros filled in the space.
- This project was my first introduction to using objects and classes in C++ and I will be able to use this knowledge throughout my career, whether continuing to code
  in C++ in the future or other languages, practicing working with objects and classes and separating code into different files is going to be invaluable in the future.
- One feature that C++ uses is both the ".h" and ".cpp" separate files. This helps with maintainability, as you can look at the .h header file and get a list of all the
  different classes and variables that are defined within the class. This helps the program stay readable and organized and helps with being able to maintain or make 
  changes to the code since not everything is in one file, leading to difficulties in having to search through hundreds of lines of code. Instead, you can search by class
  to easily find what you are looking to change or maintain.
  
AIRGEAD BANKING APP:
- The goal of this project was to write a C++ program that let the user input an initial deposit amount, monthly deposit amount, annual interest rate, and number of years
  in order to compound the interest and calculate their ending balance after the user-specified number of years both with and without monthly deposit. 
- I employed classes and different files for each class to help with readability of the code, the header and class files were saved separately, as well as I made separate
  classes for the input menu, the compound interest with additional deposit, and the compounded interest without additional deposit.
- I would like to explore inheritance and polymorphism more with this program, as I didn't use it, but easily could have employed it to make it more simplified since there
  was a lot of duplicated code within the without and with additional deposit classes. 
- This app is very functional in terms of this could actually be used in my real life if I wanted to calculate interest and see the growth of an account. I could easily modify
  this app as well to customize it to different calculations, different interest (whether it compounds monthly, yearly, bi-annually, etc) and expand on this program very
  easily and make it even more applicable to different financial calculations. The concepts of OOP can also be translated into future programs and even other languages
  that I will learn throughout my career.

CORNER GROCER APP:
- The goal of this project was to read a data file list of groceries, sort through the data file and organize into frequency of item bought, and write a data file with these
  purchase frequencies listed. Another goal of this project was to use both C++ and Python and practice talking between two different programming languages.
- My python was very rusty for this program. I had to constantly look up python syntax and how to write things in python because I have gotten so used to Java, C++, and C#.
  Once I was able to find out the syntax of python, I found it very simple to write the functions and read the file, write the file, and sort the file (using a dictionary). 
- I thought this project was extremely important in my development as a programmer. It taught me how to interact between two different programming languages. Before this 
  project, I had only been writing programs in one language at a time. But I know that this is not how the real world works, and that there will be times where multiple
  programming languages are used to build apps or web pages or games because different languages have different advantages and disadvantages, and some languages are front-
  end and some more back-end. So, this lab gave me an introduction to being able to switch between two languages for a project, and for instance, in the future, this could
  be used to analyze and import data in a python environment, but have the rest of the program in a different programming language since python is a powerful tool for data
  analysis and simpler and shorter to write the program for the data analysis portion.
- I want to explore this concept of writing code in multiple languages and combining them into one program more, as I think that this will be invaluable to know in the
  future, and know that this program used different classes and separate files for the data, the python code, and the c++ code so it could easily be modified and maintained.
  
 
