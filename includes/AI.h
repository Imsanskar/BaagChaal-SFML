//
// Created by imsanskar on 2020-02-27.
//

#ifndef BAAGCHAAL_AI_H
#define BAAGCHAAL_AI_H

#include <vector>
#include "Loadboard.h"

class Node
{
public:
    static int depth;
    Board board;
    Goat goat[20];
    int tigerChosen;

    int value;
    bool turn;
    int cellIndex,initCell;
    std::vector<Node> child{};

    Node(int depth,Board _board,Goat *_goat,bool turn,int goatsInHand);
};

int minimax(Node &,int ,bool ,int ,int );

class AI
{
private:
    static int INF;
    int goatsInHand;
    Board board;
    Goat goat[20];
    int bestCellIndex,initCellIndex;
    int depth;
    int tigerChosen;
    Cell initCell,bestCell;
public:
    AI(Board *_board,int depth,Goat *_goat,int goatsInHand);
    int miniMax(bool isMax,int depth=0,int _alpha=-INF,int _beta=-INF);
    Cell bestGoatMove();
    void bestTigerMove(Board *_board);
};

#endif //BAAGCHAAL_AI_H
