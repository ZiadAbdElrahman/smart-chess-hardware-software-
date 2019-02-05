Chess arduino controlled board with c++ user interface

Names 
Kareem ashraf yahia
Eman mohamed awad
Roula hani hassan
Amina ahmed mohammed
Ziad abd Elrahman mohamed   the team leader

Table of Contents
The hardware system:	3
Components used:	3
Hardware mechanism:	5
Software program development:	7
Console program:	7
Serially communicating data between the visual studio and the arduino	8
Adding the GUI feature to the program:	8

   


The hardware system:
Components used:
An Arduino uno

2 stepper motors

2 drives

1 relay 

An electromagnet

A breadboard

Connecting wires

A power supply

Wood and acrylic for the body

Angle brackets

6 roller bearings

4 metallic bars to support motors

2 sliding gates for motors


Hardware mechanism:
In order to save time and finish the project before the deadline, the team got specialized where two were concerned with the hardware work and three for the software work.
The team searched for the best structure that is both economical and efficient and came out the final body that we see in the figure below.

The two stepper motors were used to allow movement in the x and y directions in order to be able to reach the desired chess piece. The first stepper is placed on the base while the second stepper is placed above a long wooden piece and it slides among the two metallic bars that supports it. The electromagnet was then added above the second stepper.  There is a slot on either side of the body to allow the metallic bars to move smoothly with the first stepper. 
After assembling the components, the team was concerned with connecting the steppers and electromagnet with the Arduino uno. A driver was used for each stepper.   A driver is a micro-stepping driver for controlling bipolar stepper motors which has built-in translator for easy operation. This means that we can control the stepper motor with just 2 pins from our controller, or one for controlling the rotation direction and the other for controlling the steps. 
The schematic diagram of Arduino, driver and motor  connection:

Then, the team searched for a way to connect the electromagnet as well. And a relay was used to link the electromagnet with the Arduino. We can control high voltage electronic devices using relays. A Relay is actually a switch which is electrically operated by an electromagnet. The electromagnet is activated with a low voltage, for example 5 volts from a microcontroller and it pulls a contact to make or break a high voltage circuit. 


Software program development:
Console program:
In order to develop the game we had to search and fully understand the logic and the rules of the chess game. We wanted to create a user vs computer game. So, we started by creating a simple chess console board and starting adding and developing its function gradually. 
The first program simply allowed the user to entre the moves, then it translates those moves to way to reach the correct piece position in the 2D array then swap the pieces . 
Following that, after studying the chess and each piece’s rules, we had to define the conditions that validate the user’s input.
After we got the validations and movements right, we started studying and searching for a simple chess algorithm to implement (our program applies a beginner’s difficulty level). We successfully found support as well and were able to write an algorithm that allows the computer to check and look out for the best move and best piece of its available pieces on board. 
The algorithm works as follows:
There is a loop that passes over the computer’s pieces available on board, then follows a series of conditions to concider each of its possible legal moves. We give a score to each move then compare at the end and choose the move with the highest score. Then another piece is checked and its best move is saves then compared with the previously checked piece. The piece with the highest score is then chose. 
Serially communicating data between the visual studio and the arduino
Our idea merged the electronics and structured programming projects. So the main game is created on visual studio and the moves of the user and the computer are serially communicated to the Arduino in order to move the steppers and other components on the real board and move the desired piece.
So, in order to communicate the data we searched for a way to programme that. We found a library that helped us communicate the data easily. We converted the moves to a string and saved them in a dynamic array in order to send it to the Arduino in the allowed format. In the Arduino ide we sliced/ detokenized the string to variables in order to subtract them and measure the distance the steppers had to move in the y and x directions.  We also defined an initial position for the steppers to compare with in order to force the steppers to reach the right piece’s position.





Adding the GUI feature to the program:
Simple SFML Chess having  2 levels : 
-Beginner (simple logical algorithm)
- Advanced (STOCKFISH! algorithm)
Basic chess logic, with promotion of castling  Can be played without connecting to network. In this case, it is in single-player mode, against a basic computer ai  Can be playing over the stockfish algorithm , with 2 instances of the game.  

Basic Chess Logic : Set up the chess board and pieces to start the game. Had to code the logic for valid and legal movements of each chess piece on the board. All of this followed the normal rules of chess for each piece. Also had to do checks for whether a player is in check  or checkmate. If he is in check, then as per usual, he can move any piece as long as it brings him out of check, else it is considered invalid. If he is in checkmate, then game over.   However, I did  manage to set up promotions of pawns to other pieces, I was able to implement castling .




Stockfish:
An UCI compatible open source chess engine developed by Tord Romstad, Marco Costalba, Joona Kiiski, and Gary Linscott[1] . Marco forked the project from version 2.1 of Tord's strong engine Glaurung, first announced by Marco in November 8, 2008 [2] , and in early 2009 Joona's Smaug, a further Glaurung 2.2 derivative, was incorporated [3] . Starting out among the top twenty engines, Stockfish has quickly climbed in strength. The name "Stockfish" reflects the ancestry of the engine. Tord is Norwegian and Marco Italian, and there is a long history of stockfish trade from Norway to Italy (to Marco's home town of Vicenza, in fact). Stockfish also references another famous "little fish", Rybka.

