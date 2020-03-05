#include <utility>
#include "../includes/AI.h"



//sadly mini max algorithm doesnot work
int AI::INF;
AI::AI(Board *_board, int _depth, Goat *_goat,int _goatsInHand)
{
    bestCellIndex=0;
    goatsInHand=_goatsInHand;
    board=*_board;
    depth=_depth;
    for(int i=0;i<20;i++)
    {
        goat[i]=_goat[i];
    }
}

Cell AI::bestGoatMove()
{
    miniMax(false,0,-10000000,10000000);
    return board.cell[bestCellIndex];
}

int AI::miniMax(bool isMax, int _depth, int alpha, int beta) {
    if (_depth==10)
    {
        return board.evaluateBoard(10);
    }
    if (isMax)
    {
        int maxValue=-10000000;
        for(int i=0;i<4;i++)
        {
            initCell=board.tiger[i].getSpot();
            std::vector<Cell>possibleMoves=board.getPossibleMoves(initCell);
            std::vector<Cell>goatEatenMoves=board.getGoatEatenMoves();
            if(goatEatenMoves.empty())
            {
                for(auto &moves:possibleMoves)
                {
                    int initIndex=board.getCellIndex(board.tiger[i].getSpot());
                    board.initCell=board.cell[initIndex];
                    board.cell[initIndex].setState(EMPTY);
                    board.tiger[i].setPosition(moves.getCoord().x,moves.getCoord().y);
                    int finalIndex=board.getCellIndex(moves);
                    board.finalCell=board.cell[finalIndex];
                    board.cell[finalIndex].setState(TIGER);
                    int value=miniMax(false,_depth+1,alpha,beta);
                    if(value>maxValue)
                    {
                        maxValue=value;
                        alpha=std::max(maxValue,alpha);
                        if(_depth==0)
                        {
                            tigerChosen=i;
                            initCellIndex=initIndex;
                            bestCellIndex=finalIndex;
                        }
                        if(alpha>=beta)
                            break;
                    }
                }
            }
            else
            {
                for(auto &moves:goatEatenMoves)
                {
                    int initIndex=board.getCellIndex(board.tiger[i].getSpot());
                    board.initCell=board.cell[initIndex];
                    board.cell[initIndex].setState(EMPTY);
                    board.tiger[i].setPosition(moves.getCoord().x,moves.getCoord().y);
                    int finalIndex=board.getCellIndex(moves);
                    board.finalCell=board.cell[finalIndex];
                    board.cell[finalIndex].setState(TIGER);
                    int value = miniMax(false, _depth + 1, alpha, beta);
                    if (value > maxValue)
                    {
                        maxValue = value;
                        alpha = std::max(maxValue, alpha);
                        if (_depth == 0)
                        {
                            tigerChosen=i;
                            initCellIndex=initIndex;
                            bestCellIndex=board.getCellIndex(moves);
                        }
                        board.cell[initCellIndex].setState(EMPTY);
                        if (alpha >= beta)
                            break;
                    }
                }
            }
        }
        return maxValue;
    }
    else
    {
        int bestValue=10000000;
        if(0 < goatsInHand)
        {
            goatsInHand--;
            std::vector<Cell> possiblePlacements;
            for(auto & i : board.cell)
            {
                if(i.getState()==EMPTY)
                {
                    possiblePlacements.push_back(i);
                }
            }
            for(auto &moves:possiblePlacements)
            {
                goat[20-goatsInHand].setPosition(moves.getCoord().x,moves.getCoord().y);
                int index=board.getCellIndex(moves);
                board.cell[index].setState(GOAT);
                int value=miniMax(true,_depth+1,alpha,beta);
                moves.setState(EMPTY);
                beta=std::min(beta,value);
                if(value<bestValue)
                {
                    bestValue=value;
                    beta=std::min(beta,value);
                    if(_depth==0)
                    {
                        bestCellIndex=board.getCellIndex(moves);
                        bestCell = moves;
                        bestCellIndex = board.getCellIndex(moves);
                    }
                }
                if(alpha>=beta)
                    break;
            }
        }
        else
        {
             for(auto &_goat:goat)
             {
                 if(_goat.getState()==Dead)
                     continue;
                 initCell=_goat.getSpot();
                 std::vector<Cell>possibleMoves=board.getPossibleMoves(initCell);
                 for(auto &moves:board.goatEatenMoves)
                 {
                     _goat.setPosition(moves.getCoord().x, moves.getCoord().y);
                     moves.setState(GOAT);
                     int value = miniMax(true, _depth + 1, alpha, beta);
                     if (value < bestValue)
                     {
                         bestValue = value;
                         beta = std::min(bestValue, alpha);
                         bestCellIndex=board.getCellIndex(moves);
                         if (_depth == 0)
                         {
                             bestCell = initCell;
                         }
                         moves.setState(EMPTY);
                         _goat.setPosition(initCell.getCoord().x, initCell.getCoord().y);
                         initCell.setState(EMPTY);
                         if (alpha >= beta)
                             break;
                     }
                 }
             }
        }
        return  bestValue;
    }
}

void AI::bestTigerMove(Board *_board)
{
    miniMax(true,0,-100000,100000);
    _board->initCell=_board->cell[initCellIndex];
    _board->finalCell=_board->cell[bestCellIndex];
    _board->cell[initCellIndex].setState(EMPTY);
    _board->tiger[tigerChosen].setPosition(_board->cell[bestCellIndex].getCoord().x,_board->cell[bestCellIndex].getCoord().y);
}


Node::Node(int _depth, Board _board,Goat *_goat,bool _turn,int goatsInHand)
{
    board=std::move(_board);
    for(int i=0;i<20;i++)
    {
        goat[i]=_goat[i];
    }
    turn = _turn;
    if(_depth==0)
    {
        value=board.evaluateBoard(10);
    }
    else
    {
        if(turn)
        {
            for(int i=0;i<4;i++)
            {
                Cell spot=board.tiger[i].getSpot();
                std::vector<Cell> moves=board.getPossibleMoves(spot);
                if(board.goatEatenMoves.empty())
                {
                    for(auto move:moves)
                    {
                        int initIndex=board.getCellIndex(board.tiger[i].getSpot());
                        board.cell[initIndex].setState(EMPTY);
                        board.tiger[i].setPosition(move.getCoord().x,move.getCoord().y);
                        int finalIndex=board.getCellIndex(move);
                        board.cell[finalIndex].setState(TIGER);
                        tigerChosen = i;
                        cellIndex = finalIndex;
                        initCell = board.getCellIndex(move);
                        child.emplace_back(_depth-1,board,&goat[0],false,goatsInHand);
                    }
                }
                else
                {
                    for(auto move:board.goatEatenMoves)
                    {
                        int initIndex=board.getCellIndex(board.tiger[i].getSpot());
                        board.initCell=board.cell[initIndex];
                        board.cell[initIndex].setState(EMPTY);
                        board.tiger[i].setPosition(move.getCoord().x,move.getCoord().y);
                        int finalIndex=board.getCellIndex(move);
                        board.finalCell=board.cell[finalIndex];
                        board.cell[finalIndex].setState(TIGER);
                        cellIndex = finalIndex;
                        tigerChosen = i;
                        initCell = board.getCellIndex(move);
                        child.emplace_back(_depth-1,board,&goat[0],false,goatsInHand);
                    }
                }
            }
        }
        else
        {
            if(goatsInHand>0)
            {
                std::vector<Cell> moves;
                for(auto &move:board.cell)
                {
                    if(move.getState()==EMPTY)
                    {
                        goat[20-goatsInHand].setPosition(move.getCoord().x,move.getCoord().y);
                        int finalIndex=board.getCellIndex(move);
                        board.cell[finalIndex].setState(GOAT);
                        cellIndex = finalIndex;
                        child.emplace_back(_depth - 1, board, &goat[0], false, goatsInHand-1);
                    }
                }
            }
            else
            {
                for(int i=0;i<20;i++)
                {
                    if(goat[i].getState()==Dead)
                    {
                        continue;
                    }
                    Cell spot = goat[i].getSpot();
                    std::vector<Cell> moves = board.getPossibleMoves(spot);
                    if (board.goatEatenMoves.empty())
                    {
                        for (auto move:moves) {
                            int initIndex = board.getCellIndex(goat[i].getSpot());
                            board.cell[initIndex].setState(EMPTY);
                            goat[i].setPosition(move.getCoord().x, move.getCoord().y);
                            int finalIndex = board.getCellIndex(move);
                            board.cell[finalIndex].setState(GOAT);
                            cellIndex = finalIndex;
                            child.emplace_back(_depth - 1, board, &goat[0], false, 0);
                        }
                    }
                }
            }
        }
    }
}



int minimax(Node &node,int depth,bool isMaximizingPlayer,int alpha,int beta)
{
    if(node.child.empty())
    {
        return node.value;
    }
    int value,bestValue;
    if(isMaximizingPlayer)
    {
        bestValue=-10000000;
        for(auto &child:node.child)
        {
            value=minimax(child,depth+1,false,alpha,beta);
            bestValue=std::max(value,bestValue);
            if(bestValue==value  and depth==0)
            {
                node.cellIndex=child.cellIndex;
                node.tigerChosen=child.tigerChosen;
            }
            alpha=std::max(alpha,bestValue);
            if(beta<=alpha)
                break;
        }
    }
    else
    {
        bestValue = 10000000;
        for ( auto& child : node.child ) {
            value = minimax(child, depth + 1, true, alpha, beta);
            bestValue = std::min(bestValue, value);
            if (bestValue == value && depth == 0)
                node.cellIndex = child.cellIndex;
            beta = std::min(beta, bestValue);
            if (beta <= alpha)
                break;
            return bestValue;
        }
    }
}