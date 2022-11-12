//
// Created by imsanskar on 2020-01-10.
//


#include "Game.h"
#include "MainMenuState.h"

// for later use maybe
#if 0
void Game::getBestMove() {
    std::unordered_map<int64_t, int32_t> valueFunction;
    Node node;
    node.state = board.getBoardEncoding();

    Board evaluationBoard;
    evaluationBoard.decodeBoard(node.state);
    int max_iter = 10000;

    int itr = 0;
    
    std::vector <std::pair<int, std::vector<Cell>>> moves;
    if (tigerTurn) {
        moves = board.getTigerMoves();
    } else {
        moves = board.getGoatMoves(goat);
    }

    // flag to indicate turn in simulation, cause OOP sucks 
    bool is_tiger_turn = tigerTurn;
    bool goat_chosen = 0;
    std::vector <uint64_t> exploredState;
    while (itr < max_iter) {
        while (true) {
            if (is_tiger_turn) {
                // tiger section
                std::vector <std::pair<int, std::vector<Cell>>> moves = board.getTigerMoves();
                auto it = moves.begin();
                while (it != moves.end()){
                    if (it->second.size() == 0) {
                        it = moves.erase(it++);
                    } else {
                        it++;
                    }
                }
                
                int random_tiger = rand() % moves.size();
                std::pair<int, std::vector<Cell>> tiger = moves[random_tiger];
                int random_move = rand() % tiger.second.size();
                evaluationBoard.moveTiger(tiger.first, tiger.second[random_move]);
                Node *child_node = new Node;
                child_node->state = evaluationBoard.getBoardEncoding();
                child_node->parent = &node;
                is_tiger_turn = false;
                node.child = child_node;
                exploredState.push_back(child_node->state);
            } else {
                // goat section
                if (goat_chosen < 20) {
                    std::vector <Cell> emptyCells = board.getEmptyCells();  
                    evaluationBoard.placeGoat(emptyCells[rand() % emptyCells.size()], goat[evaluationBoard.numberOfGoatPlaced]);
                    evaluationBoard.numberOfGoatPlaced++;
                    evaluationBoard.numberOfGoatPlaced++;
                } else {
                    moves = board.getGoatMoves(goat);
                    auto it = moves.begin();
                    //checks if the the move if goat eating move
                    if(board.eatGoat(&goat[0])) {
                        evaluationBoard.goatEaten++;
                    }
                    while (it != moves.end()){
                        if (it->second.size() == 0) {
                            it = moves.erase(it++);
                        } else {
                            it++;
                        }
                    }
                    
                    int random_goat = rand() % moves.size();
                    std::pair<int, std::vector<Cell>> chosen_goat = moves[random_goat];
                    int random_move = rand() % chosen_goat.second.size();

                    evaluationBoard.moveGoat(goat[chosen_goat.first], chosen_goat.second[random_move]);
                }
                is_tiger_turn = true;
                Node *child_node = new Node;
                child_node->state = evaluationBoard.getBoardEncoding();
                child_node->parent = &node;
                is_tiger_turn = false;
                node.child = child_node;
                exploredState.push_back(child_node->state);
            }

            if (evaluationBoard.isGameOver()) {
                break;
            }
        }
    }
}
#endif


Game::Game(uint16_t width, uint16_t height): game_data(width, height), main_menu(&game_data) {
    // main_menu = new MainMenuState(&game_data);
    game_data.state_machine.push_state(&main_menu);
    game_data.state_machine.get_current_state()->init();
}
