#ifndef AIPATH_H
#define AIPATH_H

#include <raylib.h>
#include <vector>
#include <string>
#include <float.h>
#include <stdio.h>
#include "Node.h"

using namespace std;

class Fsm
{
public:
    #define ROWS 10
    #define COLS 20
    #define NODE_SIZE 50

    vector<vector<Node>> grid;

    void Main();
    void Start();
    void UpdateAndDraw();

    Node* GetRandomNode();
    Node* GetGoalNode();
};

#endif
