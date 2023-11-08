Exercise 2 - PACMAN

Contributors:
Evitar Davidiyan
Shir Yadid 

This exercise focuses on creating the classic game of Pac-Man, with an emphasis on designing various complex classes.

Files we've created:
- Pacman.h: Definition of the Pac-Man class.
- Pacman.cpp: Implementation of functions suitable for Pac-Man, including getters and setters.
- Deamon.h: Definition of the Deamon class (Ghosts).
- Deamon.cpp: Implementation of functions suitable for the Deamon class.
- Board.h: Definition of the Board class.
- Board.cpp: Implementations of functions related to the game board.
- GameController.h: Definition of the GameController class responsible for running the game.
- GameController.cpp: Definition of relevant functions to initiate and operate the game.

Key Data Structures:
- In the Board class, we used vectors to store the contents of the board.txt file.

Overview:
The GameController class manages the game, bridging the interactions between the other classes. Data will flow into it, and it will distribute the information to the various classes for proper functioning. The Board class holds the game board as a matrix and vector and contains the positions of all the objects, particularly the Deamons (Ghosts) which will initially be positioned as threats.

Notable Algorithms:
- Ghost Movement Algorithm: When Pac-Man is in normal mode, the Deamons try to approach him, tracking his position and moving toward it. If Pac-Man is above them, they move up, and if he's to the left, they move left, and so on. However, when Pac-Man is in Super mode, the Deamons try to flee from him, enabling the player to catch them.

Known Issues:

Notes:

