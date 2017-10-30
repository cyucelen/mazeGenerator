# mazeGenerator
mazeGenerator uses ncurses library to render characters on terminal screen and uses Recursive Backtracker algorithm to generate the Maze.

### Changing the Grid Size
You can change the size of the maze by changing GRIDWIDTH and GRIDHEIGHT values in config.txt file. You can also change the speed of the rendering by the changing DELAY value in config.txt file.

### Installing Dependency to Compile this project

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
