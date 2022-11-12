#pragma once
#include <stack>

struct State {
    virtual void init() = 0;
    virtual void handle_input() = 0;
    virtual void update() = 0;
    virtual void render (float dt) = 0;
    virtual void resume() {};
    virtual void pause() {};
};


typedef State* StateRef;
struct StateMachine {
    std::stack<StateRef> states;
    StateRef new_state;

    bool is_removing;
    bool is_replacing;
    bool is_adding;

    void push_state(StateRef state, bool _is_replacing = true);
    void process_state_changes();
    void remove_state();
    StateRef get_current_state();
};