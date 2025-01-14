# cub3d_42

## What I learned from this project: ✅
- How raycasting works
- Rendering 3d environments
- How to write optimised code

    (1920x1080 @ 60fps on an i5 7500)

## Images: 📷
A screenshot of the player in a maze, inspired by the style of doom
![image](https://github.com/user-attachments/assets/b1a8fd58-7e51-4f5c-93f4-1c4e2244dfa4)

![image](https://github.com/user-attachments/assets/d75f062a-031e-4b48-9aba-52b477059bf3)

The minimap, which shows the orienatation of the player, as well as the blocks around them.
This was accomplished without using any sprites.

![image](https://github.com/user-attachments/assets/6acde4fd-f864-4583-9ee6-0dfc6886a037)

## Project Goal: 🎯
For this project, we had to build [a raycaster](https://lodev.org/cgtutor/raycasting.html) in C, where the player is able to move and look around a 3D world. This is accomplished with the help of MLX42 to manage i/o and to convert PNGs to a 2D int array. Everything else is made from scratch, such as:
- Parsing a map file
- Handeling movement
- Rendering the game
- Rendering the minimap. 

### Parsing 
Our map consists of a grid of squares, which can be open '0', a wall '1' or nothing ' '. To protect the player from staring into nothingness, all open tiles should be surrounded by either more open tiles or a wall. There should also be a player spawn, which is indicated by the direction the player is looking at.
An example of a valid map, where the player starts of looking north:
```
11111
10001
10N01
11111
```

Above the map, you'll need to set the colour of the floor and ceiling with a custom RGB value.
How to set a valid floor and ceiling colour:
```
C 255,0,0     // Red
F 100,100,100 // Gray
```

Finally, the textures of the walls should also be set (also above the map). This can be done by providing a relative path to every PNG file
An example of how the textures should be set:
```
NO ./sprites/wall1.png
EA ./sprites/wall2.png
SO ./sprites/wall3.png
WE ./sprites/wall4.png
```

### Movement
These are all the inputs our game uses:
```
WASD:             Move the player
Shift:            Sprint
Escape:           Quit the game
Left/right arrow: Rotates camera
Tab:              Toggles mouse on/off
Mouse:            Rotates camera
```
