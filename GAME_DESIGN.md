# Tic-Tac-Toe Game Design

## UI Layout

```
┌─────────────────────────────────┐
│     Player X's Turn             │  ← Status Label
├─────────────────────────────────┤
│                                 │
│    ┌───┬───┬───┐               │
│    │ 0 │ 1 │ 2 │               │  ← 3x3 Grid
│    ├───┼───┼───┤               │    of Push
│    │ 3 │ 4 │ 5 │               │    Buttons
│    ├───┼───┼───┤               │
│    │ 6 │ 7 │ 8 │               │
│    └───┴───┴───┘               │
│                                 │
│    ┌─────────────────┐         │
│    │   Reset Game    │         │  ← Reset Button
│    └─────────────────┘         │
└─────────────────────────────────┘
```

## Game Flow

1. **Start**: Player X goes first
2. **Player Turn**: Current player clicks an empty button
3. **Mark Placement**: Button displays "X" or "O"
4. **Win Check**: System checks for winning pattern
5. **Result**: 
   - If win: Display winner and show message
   - If draw: Display draw message
   - If no result: Switch player and continue
6. **Reset**: Click reset button to start new game

## Win Patterns

```
Horizontal:          Vertical:           Diagonal:
0-1-2                0-3-6               0-4-8
3-4-5                1-4-7               2-4-6
6-7-8                2-5-8
```

## Code Structure

### Files:
- `main.cpp` - Application entry point
- `midtermui.h` - Header with class definition
- `midtermui.cpp` - Implementation with game logic
- `midtermui.ui` - Qt Designer UI file with layout

### Key Variables:
- `isPlayerX` - Tracks current player (true=X, false=O)
- `moveCount` - Counts total moves (for draw detection)
- `gameOver` - Flag to prevent moves after game ends
- `buttons[9]` - Array of button pointers for easy access

### Key Functions:
- `handleButtonClick()` - Processes player moves
- `checkWinner()` - Verifies win/draw conditions
- `resetGame()` - Clears board and restarts
- `updateStatus()` - Updates status label text
