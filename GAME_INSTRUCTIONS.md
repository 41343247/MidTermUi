# Tic-Tac-Toe Game Instructions

## Overview
This is a Tic-Tac-Toe (井字棋/圈叉棋) game implemented using Qt with a 3x3 grid of QPushButtons.

## Features
- **3x3 Grid**: Nine pushbuttons arranged in a grid for gameplay
- **Two Players**: Players X and O take turns
- **Win Detection**: Automatically detects wins (rows, columns, diagonals)
- **Draw Detection**: Detects when the game ends in a draw
- **Status Display**: Shows whose turn it is and game results
- **Reset Function**: Reset button to start a new game

## How to Build
1. Make sure Qt is installed on your system
2. Open a terminal and navigate to the project directory
3. Run the following commands:
   ```bash
   qmake MidTermUi.pro
   make
   ```

## How to Play
1. Run the application
2. Player X starts first
3. Click any empty button to place your mark (X or O)
4. Players alternate turns
5. First player to get 3 in a row (horizontally, vertically, or diagonally) wins
6. If all 9 squares are filled with no winner, the game is a draw
7. Click "Reset Game" to start a new game

## Implementation Details
- **UI File**: `midtermui.ui` - Contains the 3x3 grid layout with 9 buttons plus reset button
- **Header File**: `midtermui.h` - Defines game state variables and methods
- **Implementation**: `midtermui.cpp` - Contains game logic including:
  - Button click handling
  - Win condition checking (8 possible winning patterns)
  - Draw detection
  - Game reset functionality

## Game Logic
The game checks for 8 possible winning patterns:
- 3 horizontal rows
- 3 vertical columns  
- 2 diagonals

When a player wins or the game draws, a message box displays the result.
