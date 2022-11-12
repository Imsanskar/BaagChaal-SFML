#include "state.h"

void StateMachine::push_state(StateRef state, bool _is_replacing) {
    is_replacing = _is_replacing;
    new_state = state;
    is_adding = true;
    process_state_changes();
} 


void StateMachine::remove_state() {
    is_removing = true;
    process_state_changes();
} 

void StateMachine::process_state_changes() {
    if (is_removing) {
        int size = states.size();
        if (size > 0) {
            states.pop();
            if (size > 1) {
                states.top()->resume();
            }
        }
        is_removing = false;
    }
    if (is_adding) {
        bool is_empty = states.empty();
        if (is_replacing && !is_empty) {
            states.pop();
        } else if(!is_empty) {
            states.top()->pause();
        }
        states.push(new_state);
        states.top()->init();
        is_adding = false;   
    }
}

StateRef StateMachine::get_current_state() {
    if (states.empty()) {
        return nullptr;
    }
    return states.top();
}