# C++ Finite State Machine Visualization

A C++ educational project demonstrating Finite State Machine (FSM) implementation with interactive grid-based visualization using Raylib.

## Overview

This application creates a 10x20 grid of nodes where each node can transition between different states with smooth animated color changes. Watch state transitions happen in real-time as you interact with the grid.

## Features

- **Grid Visualization**: 10 rows × 20 columns of 50×50 pixel nodes
- **Six Node States** with distinct colors:
  | State | Color |
  |-------|-------|
  | Idle | White |
  | Blocked | Dark Gray |
  | Exploring | Yellow |
  | Visited | Light Gray |
  | Goal | Green |
  | Start | Blue |
- **Smooth Transitions**: 1-second linear color interpolation between states
- **Random Generation**: 20 blocked nodes placed randomly on restart
- **Interactive Controls**: Keyboard-driven grid manipulation

## Controls

| Key | Action |
|-----|--------|
| `R` | Restart - regenerate grid with new random positions |
| `B` | Move Goal node to new random location (animated) |
| `ESC` | Close application |

## Tech Stack

- **Language**: C++ (C++14 or later)
- **Graphics**: [Raylib](https://www.raylib.com/)
- **Build**: Makefile or direct g++ compilation
- **IDE**: VS Code (workspace config included)

## Project Structure

```
CPP_FSM/
├── main.cpp        # Entry point
├── Fsm.h           # FSM class header (grid constants, methods)
├── Fsm.cpp         # Main loop, grid generation, input handling
├── Node.h          # Node struct with state machine logic
├── Makefile        # Build configuration
└── .vscode/        # VS Code settings
```

## Building & Running

### Prerequisites
- C++ compiler (g++, clang++)
- Raylib library installed

### Using g++
```bash
g++ main.cpp Fsm.cpp -o fsm -lraylib -std=c++14
./fsm
```

### Using Makefile
```bash
make
./main
```

> **Note**: On Linux, you may need additional flags: `-lGL -lm -lpthread -ldl -lrt -lX11`

## How It Works

1. **Initialization**: Creates 1000×500 window at 60 FPS
2. **Grid Setup**: Places blocked, start, and goal nodes randomly
3. **Main Loop**: Renders nodes and handles keyboard input
4. **State Transitions**: Nodes animate smoothly using `LerpColor()` interpolation
5. **Reset**: Press `R` to regenerate with new random configuration

---

