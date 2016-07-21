# Boxpop solver

**ABOUT THE GAME**

Its gameplay is based on the *“knight’s tour”* challenge in chess which requires a single knight to touch every square of the chess board one time each. Players will use the knight’s L-shaped movement to pop boxes on variously sized grids, aiming to pop every box as if they were completing a knight’s tour.

**PREREQUISITES**

You will need to have the sfml "LibLapin" installed and also the application "Boxpop" developped by FreshPlanet Inc.

**HOW TO :**

`make re`

`make clean`

`./boxpop`

> You will first need to recreate the map that you want to solve.

> Then press *spacebar* and put the starting point on the desired slot.

> Finally, press *enter* to begin the solving.
*(You can change the speed of the resolution by increasing the number in main.c line 174)*.

**Limitation**

Due to the fact that the algorithm is based on *backtracking*, the resolution of a map with more than 42 boxes takes too much time and can't be complete. 

**PICTURE**

![Boxpop](http://nsa38.casimages.com/img/2016/07/21/160721033203391654.jpg)
