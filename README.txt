README

This is Punch Card- a program to help you clock out with exactly 40 hours.

This program has 2 options on the home page which can do 3 functions between them.


Functionality: 

Option 2 ("Calculate Today's Clockout") is simple- you enter the amount of time you worked before you took your lunch and the time you ended your lunch, and it outputs the time you need to clock out at to work exactly 8 hours.


Option 1 ("Calculate Friday Clockout") is multi-function. First you enter the amount of time you worked from Monday-Thursday. When it gets to Friday it'll ask you to enter in the time you worked before lunch, or 0:00 if you have yet to take your lunch.

If you enter 0:00 the program will ask you to enter how long (in minutes) you plan to take lunch. It'll then ask you when you clocked in, then using that it'll give you the theoretical time you need to clock out.

If you don't enter 0:00, you'll be asked when you ended your lunch, the program will then calculate when you need to clock out to achieve 40 hours for the whole week.



REQUIRED PROGRAMS and OS:
This program is written in C. I used Visual Studio, and that is the recommended program to run this. VSCode doesn't play nicely with C code, especially in windows. You might have problems downloading Visual Studio on your work laptop, so using a personal device might be necessary. There are other IDE that can run C that might work on a company provided laptop.

Also note this was written on a Windows machine. From experience "system("pause")" and "system("cls")" DO NOT WORK on Linux OS. I assume MacOS is the same, so comment out any of those if you aren't using windows (I put comments by them). There could be other hiccups with using a different OS I'm not aware of.

For use in Linux you'll have to create a makefile or combine everything into one .c file. 




Upcoming:
1. I plan on adding a display to show the number of hours worked and not just the time you need to clock out.

2. A table showing the time over/under 8 hours per day for the week. (why I kept the hours/minutes per day instead of adding it to a total minutes worked).

3. General optimizing and simplification changes to make the code shorter and easier to understand and modify.