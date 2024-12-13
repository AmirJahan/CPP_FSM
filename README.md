# CPP_FSM

A C++ project demonstrating a centralized Finite State Machine (FSM) usage with a grid-based visualization using [Raylib](https://www.raylib.com/).

## Overview

This project visualizes a grid of nodes where each node can be in various states (Idle, Blocked, Exploring, Visited, Goal, Start). It demonstrates how to manage state transitions and visualize them using Raylib. The application includes a random grid generator and interactive state changes.

## Features

- **Grid Visualization**: A grid of nodes representing different states.
- **Finite State Machine**: Nodes transition between states such as Idle, Blocked, Exploring, Visited, Goal, and Start.
- **Visual Transitions**: Smooth color interpolation when nodes change states.
- **Random Generation**: Randomly generates blocked nodes and places Start/Goal nodes.

## Controls

- **`R`**: Restart / Regenerate the grid with new random blocked nodes and positions.
- **`B`**: Move the **Goal** node to a new random location. This triggers a visual transition from the old goal to the new one.

## Dependencies

- **C++ Compiler**: (e.g., g++, clang++) supporting C++14 or later.
- **Raylib**: A simple and easy-to-use library to enjoy videogames programming.

## Build Instructions

Ensure you have Raylib installed on your system.

### Using g++ (Terminal)

You can compile the project directly using `g++`. Example command:

```bash
g++ main.cpp Fsm.cpp -o fsm -lraylib -std=c++14
```

*Note: You may need to link additional libraries depending on your OS (e.g., `-lGL -lm -lpthread -ldl -lrt -lX11` on Linux).*

### Using Makefile

A `Makefile` is included in the repository. If correctly configured for your system, you can simply run:

```bash
make
```

## Code Structure

- **`main.cpp`**: Entry point of the application.
- **`Fsm.h` / `Fsm.cpp`**: Manages the main application loop, grid generation, and input handling.
- **`Node.h`**: Defines the `Node` structure, including state management (`NodeState` enum: Idle, Blocked, Exploring, Visited, Goal, Start) and visual rendering logic.