# Project Details
This is a small little project I made when exploring more about raylib and raygui, it simply renders 3 cubes to the screen but I have implemented an Entity struct with various functions that can draw a 2D circle using raylib functions. The cubes rendered are rotated by matrices along various angles based on the ingame time passed. There are also "shadows" that rotate via sin and cos adjacent to their respective cubes. The program also displays, the fps, basic text, and sets the background. This project stands as an experimentation with Raylib in C/C++.

# Developer Information
i. draker
ii. developed on linux (ubuntu wsl)
iii. build tools: makefile
iv. libraries: raygui, raylib, raymath, rlgl (for 3d transformations)

# Build/Run
To build and run, do the following
1. make, you will see the few files being compiled
2. if no errors occur, then you know the program successfully compiled
3. run with 'make run' or './proj' and enjoy
4. feel free to mess around with the code, you can explore the entity struct I created and render some circles that can move with WASD, UHJK, or the arrow keys depending on what you want

# Extra information
I usually stick to a strictly object oriented approach style but for this little experimentation I decided to do a more C style while using C++ features I want. I tried my best to stick to best practices, but also, I'm simply learning and having fun so take it with a grain of salt. I hope you enjoy!

# Changes
Implemented proper camera movement functionality
1. W/S move forward backward along z axis
2. A/D move along x axis
3. Up and Down arrows, move along the y axis
4. Left and Right arrows, move cubes along the x axis
5. Removed unwanted code and added a button press for R to reset the camera to its default position if wanted.