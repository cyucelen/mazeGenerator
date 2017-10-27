# mazeGenerator
mazeGenerator uses ncurses library to render characters on terminal screen and uses Recursive Backtracker algorithm to generate the Maze.

### Changing the Grid Size
You can change the size of the maze by changing GRIDWITH and GRIDHEIGHT variables in global.cpp file and compile. (Default 20x20)

### Installing Dependency for Compile this project

If you want to compile this project, you should first install ncurses library by using this command: <br />
`sudo apt-get install libncurses5-dev libncursesw5-dev`

### Compiling

Use -lncurses flag for compiling this project.
##### Example : 
`g++ global.cpp Cell.cpp main.cpp -o mazeGenerator -lncurses`

### Running

To run the mazeGenerator : <br />
`./mazeGenerator`

##### HAVE FUN!
