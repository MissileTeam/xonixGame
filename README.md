Xonix game


Description of the code : 
Structers : enemy : 
Which defines how the enemy will be on the screen and it’s movement.

Variables which will be used in making the movement : 

Int dir =-1; 
Defines in what direction will the player moves  so I’ve made enum of directions to make it easy 
Page number and level number which will be available soon as it have some bugs and problems these two are for making the menu and levels
Functions : 
-**movePlayer(xpos,ypos,direction of the player)
it controls how the player will move in the borders and in the grid itself.
-**rules_ of_ draw ( xpos,ypos of enemy)
It uses recursion to check for the enemies’ position as all the grid is 0 at first when the player moves it gives the cells 2  and  when we complete the route of the player to the border we need to fill this area with 1 so we give any near position of the enemy -1 and give any 2 or 0 cells a 1 so the area can be filled 
Cell (1) = colored, cell(0)= not drawn ,cell(-1)= don’t do anything
-**moveEnemy():
This function moves enemy objects in the grid and  call the function rules_of_draw() to make sure that the area is filled right every time the enemy is moving.
-**setsBrush(xpos,ypos of the player):
it check if the cells is filled with 1 then : 
if cells have been given -1 because the enemy it make it 0 again 
otherwise it makes it filled with 1 

else : 
-if the cells are given -1 it makes it 0 so the player can fill the area that the player hasn’t touch it yet  and it was given -1 because the rules_of_draw() gave it -1 previously.
If they are given 2 it will make it 2 to see the borders of the drawing.
If it is anything else : 
Like 0 it will make it 1 which means let’s fill it with color

**drawArea(Sprite  brush ,window, purple box, blue box):
-It checks if the grid is empty which is 0 then it will continue 
-If it is 1 so it will draw blue box as   setsBrush() handled which will be drawn blue and what will be drawn purple
And what will be left as empty cells.
-if it is 2 so it will draw purple cells that defines where are you going and the borders of your filled area
**checkBoundaries():
it makes a percent variable which will be used to present the completed area of the grid and make the boundaries of the grid blue colored
it returns perecent and add it to the  main percent variable.

We currently working on making the menu which include : 
Play 
Options 
Exit 

Play includes:
3 Levels which we will add it soon
So we have made menu class and levels class but it’s code need some time to make it works propelly

Features to be added: 
•	Make a save game file for the game 
•	Adding scoring system in the game 
For any questions talk me please 😊  
Thanks for reading.
	Regards,
Ahmed Mohamed Hassan
