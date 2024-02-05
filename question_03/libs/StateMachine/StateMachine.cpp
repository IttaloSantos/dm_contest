#include "StateMachine.h"

StateMachine::StateMachine(States _state)
{
    this->state = _state;
    StateMachine::init_state_transitions();
}

void StateMachine::init_state_transitions(void)
{
    if(!this->transitions.empty()) return;

    for(int i = 1; i < NUMBER_OF_STATES; i++)
    {
        for(int j = 0; j < NUMBER_OF_EVENTS; j++)
        {
            bool link_down  = j == INTERFACE_NOK;
            bool send_start = (i == LINK_DOWN && j == INTERFACE_OK) ||
                              (i != LINK_DOWN && j == TIMEOUT)      ||
                              (i != LINK_DOWN && i != SENDING_CONFIG && j == NOK_PACKAGE_RECEIVED);
            bool send_config = (i == SENDING_START  && j == OK_PACKAGE_RECEIVED) || 
                               (i == SENDING_CONFIG && j == NOK_PACKAGE_RECEIVED);
            bool send_ka     = (i != LINK_DOWN && i != SENDING_START && j == OK_PACKAGE_RECEIVED);

            if(link_down)        this->transitions[i][j] = LINK_DOWN;
            else if(send_start)  this->transitions[i][j] = SENDING_START;
            else if(send_config) this->transitions[i][j] = SENDING_CONFIG;
            else if(send_ka)     this->transitions[i][j] = KEEP_ALIVE;
        }
    }
}

States StateMachine::get_current_state(void)
{
    return this->state;
}

void StateMachine::set_state(States _state)
{
    this->state = _state;
}

States StateMachine::get_next_state(Events new_event)
{
    States current_state = StateMachine::get_current_state();
    return (States)this->transitions[current_state][new_event];
}
