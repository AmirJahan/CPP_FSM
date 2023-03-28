#include "Fsm.h"
#include <vector>
#include <iostream>

using namespace std;

void Fsm::Main()
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

Node* Fsm::GetRandomNode()
{
    int randRow = GetRandomValue(0, (int)(grid.size()) - 1);
    int randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);
    while (grid[randRow][randCol].currentState == NodeState::Blocked ||
           grid[randRow][randCol].currentState == NodeState::Goal ||
           grid[randRow][randCol].currentState == NodeState::Start)
    {
        randRow = GetRandomValue(0, (int)(grid.size()) - 1);
        randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);
    }
    return &grid[randRow][randCol];
}

Node* Fsm::GetGoalNode()
{
    for (int i = 0; i < (int)(grid.size()); i++)
    {
        for (int j = 0; j < (int)(grid[i].size()); j++)
        {
            if (grid[i][j].currentState == NodeState::Goal)
                return &grid[i][j];
        }
    }
    return nullptr;
}

void Fsm::Start()
{
    grid.clear();
    for (int row = 0; row < ROWS; row++)
    {
        float y = NODE_SIZE * row;
        vector<Node> rowNodes;
        for (int col = 0; col < COLS; col++)
        {
            float x = NODE_SIZE * col;
            Node node = { row, col, Vector2{x, y} };
            node.SetState(NodeState::Idle);
            rowNodes.push_back(node);
        }
        grid.push_back(rowNodes);
    }

    for (int i = 0; i < 20; i++)
        GetRandomNode()->SetState(NodeState::Blocked);

    GetRandomNode()->SetState(NodeState::Start);
    GetRandomNode()->SetState(NodeState::Goal);
}

void Fsm::UpdateAndDraw()
{
    for (int i = 0; i < (int)(grid.size()); i++)
    {
        for (int j = 0; j < (int)(grid[i].size()); j++)
        {
            grid[i][j].Draw();
        }
    }

    if (IsKeyPressed(KEY_R))
    {
        Start();
    }

    if (IsKeyPressed(KEY_B))
    {
        if (GetGoalNode()->isTransitioning)
            return;

        GetGoalNode()->SetState(NodeState::Idle, true);
        GetRandomNode()->SetState(NodeState::Goal, true);
    }
}
