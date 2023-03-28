#include <raylib.h>
#include <vector>
#include <string>
#include <float.h>
#include <stdio.h>

using namespace std;

enum class NodeState
{
    Idle,
    Blocked,
    Exploring,
    Visited,
    Goal,
    Start
};

struct Node
{
    int row, col;
    Vector2 position;
    Color fillColor = RAYWHITE, outlineColor = LIGHTGRAY;

    Color idleColor = RAYWHITE;
    Color blockedColor = DARKGRAY;
    Color exploringColor = YELLOW;
    Color visitedColor = LIGHTGRAY;
    Color goalColor = GREEN;
    Color startColor = BLUE;

    string costText = "";

    float gCost = FLT_MAX;
    float hCost = FLT_MAX;
    float fCost = FLT_MAX;

    Node* parent = nullptr;

    NodeState currentState = NodeState::Idle;
    NodeState nextState = NodeState::Idle;

    float transitionTime = 0.0f;
    bool isTransitioning = false;
    Color targetColor;

    Node(int row = 0, int col = 0, Vector2 position = {})
    {
        this->row = row;
        this->col = col;
        this->position = position;
    }

    void Draw()
    {
        DrawRectangleV(position, Vector2{ 50, 50 }, fillColor);
        DrawRectangleLines(position.x, position.y, 50, 50, outlineColor);

        if (isTransitioning)
            Update(GetFrameTime());

        if (gCost < 1000000)
            costText = to_string(static_cast<int>(gCost));

        int textHeight = 20;
        int textWidth = MeasureText(costText.c_str(), textHeight);
        Vector2 textPosition = { position.x + 25 - textWidth / 2, position.y + 25 - textHeight / 2 };
        DrawText(costText.c_str(), textPosition.x, textPosition.y, 20, BLACK);
    }

    void Reset()
    {
        parent = nullptr;

        gCost = FLT_MAX;
        hCost = FLT_MAX;
        fCost = FLT_MAX;

        currentState = NodeState::Idle;
    }

    bool atSameSpot(const Node& other) const
    {
        return this->row == other.row && this->col == other.col;
    }

    Color GetColorForState(NodeState state)
    {
        switch (state)
        {
            case NodeState::Idle:
                return idleColor;
            case NodeState::Blocked:
                return blockedColor;
            case NodeState::Exploring:
                return exploringColor;
            case NodeState::Visited:
                return visitedColor;
            case NodeState::Goal:
                return goalColor;
            case NodeState::Start:
                return startColor;
            default:
                return RAYWHITE;
        }
    }

    void SetState(NodeState newState, bool transit = false)
    {
        if (currentState == newState || isTransitioning)
            return;

        if (transit)
        {
            nextState = newState;
            transitionTime = 0.0f;
            targetColor = GetColorForState(nextState);
            isTransitioning = true;
        }
        else
        {
            currentState = newState;
            fillColor = GetColorForState(currentState);
        }
    }

    Color LerpColor(Color start, Color end, float t)
    {
        return Color {
            (unsigned char)(start.r + t * (end.r - start.r)),
            (unsigned char)(start.g + t * (end.g - start.g)),
            (unsigned char)(start.b + t * (end.b - start.b)),
            (unsigned char)(start.a + t * (end.a - start.a))
        };
    }

    void Update(float deltaTime)
    {
        transitionTime += deltaTime;

        float t = transitionTime / 1.0f;

        if (t >= 1.0f)
        {
            currentState = nextState;
            GetColorForState(currentState);
            isTransitioning = false;
        }
        else
        {
            fillColor = LerpColor(fillColor, targetColor, t);
        }
    }
};
