#include "Ai.h"
#include <vector>
#include <iostream>

using namespace std;


void Ai::Main()
{
    InitWindow(1000, 500, "AI - Pathfinding");

    Start();

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        UpdateAndDraw();

        EndDrawing();
    }

    CloseWindow();
}

Node* Ai::GetRandomNode()
{
    int randRow = GetRandomValue(0, (int)(grid.size()) - 1);
    int randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);
    while (grid[randRow][randCol].currentState == NodeState::Blocked || 
            grid[randRow][randCol].currentState == NodeState::Goal ||
            grid[randRow][randCol].currentState == NodeState::Start) // UPDATE
    {
        randRow = GetRandomValue(0, (int)(grid.size()) - 1);
        randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);
    }
    return &grid[randRow][randCol];
}


Node* Ai::GetGoalNode()
{
    for (int i = 0; i < (int)(grid.size()); i++)
        for (int j = 0; j < (int)(grid[i].size()); j++)
            if (grid[i][j].currentState == NodeState::Goal)
                return &grid[i][j];
    return nullptr;
}




void Ai::Start()
{
    grid.clear();
    for (int row = 0; row < ROWS; row++)
    {
        float y = NODE_SIZE * row;
        vector<Node> rowNodes;
        for (int col = 0; col < COLS; col++)
        {
            float x = NODE_SIZE * col;
            Node node = { row, col, Vector2{x, y} }; // FSM
            node.SetState(NodeState::Idle); // FSM
            rowNodes.push_back(node);
        }
        grid.push_back(rowNodes);
    }


    for (int i = 0; i < 20; i++)
        GetRandomNode()->SetState(NodeState::Blocked); // FSM
    
    // START
    GetRandomNode()->SetState(NodeState::Start); // FSM

    GetRandomNode()->SetState(NodeState::Goal); // FSM
}

void Ai::UpdateAndDraw()
{
    for (int i = 0; i < (int)(grid.size()); i++)
        for (int j = 0; j < (int)(grid[i].size()); j++)
            grid[i][j].Draw();



        // Check if the "R" key is pressed
    if (IsKeyPressed(KEY_R)) { Start(); } // RESTART

    // Get a new random node and make it the next goal
    if (IsKeyPressed(KEY_B)) 
    {
        if (GetGoalNode()->isTransitioning) return;


        GetGoalNode()->SetState(NodeState::Idle, true); // FSM

        GetRandomNode()->SetState(NodeState::Goal, true); // FSM

        // This setup was done because we don't have a call back for when the 
        // goal node has been done with transition
        // at that point, we should push the new goal into it

    }
}





