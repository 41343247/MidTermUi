# MidTermUi - Tic-Tac-Toe Game

A Qt-based Tic-Tac-Toe (井字棋/圈叉棋) game application with a graphical user interface.

## Features

- 🎮 **Interactive 3x3 Grid**: Play using clickable pushbuttons
- 👥 **Two-Player Game**: Alternate between Player X and Player O
- 🏆 **Automatic Win Detection**: Detects all winning patterns (rows, columns, diagonals)
- 🤝 **Draw Detection**: Identifies when the game ends in a draw
- 🔄 **Reset Function**: Start a new game anytime
- 📊 **Status Display**: Shows current player turn and game results

## Build Requirements

- Qt 5.x or Qt 6.x
- C++17 compatible compiler
- qmake build system

## Building the Application

```bash
qmake MidTermUi.pro
make
./MidTermUi
```

## How to Play

1. Launch the application
2. Player X always starts first
3. Click any empty square to place your mark
4. Players alternate turns automatically
5. Win by getting 3 marks in a row (horizontal, vertical, or diagonal)
6. Click "Reset Game" to start over

## Documentation

- [GAME_INSTRUCTIONS.md](GAME_INSTRUCTIONS.md) - Detailed gameplay instructions
- [GAME_DESIGN.md](GAME_DESIGN.md) - Technical design and architecture

## Project Structure

```
MidTermUi/
├── main.cpp           # Application entry point
├── midtermui.h        # Main window header
├── midtermui.cpp      # Game logic implementation
├── midtermui.ui       # Qt Designer UI file
└── MidTermUi.pro      # Qt project file
```

## Implementation Highlights

- Clean separation of UI and game logic
- Efficient win condition checking (8 patterns)
- Proper Qt signal-slot connections
- Memory-safe pointer handling
- User-friendly interface with visual feedback
