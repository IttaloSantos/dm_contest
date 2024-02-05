#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <map>
#include "Config.h"

class StateMachine
{
    private:
        std::map<int, std::map<int, int>> transitions;
        States state;

        void init_state_transitions(void);

    public:
        StateMachine(States _state = INITIAL_STATE);
        ~StateMachine(){};

        void   set_state(States _state);
        States get_current_state(void);
        States get_next_state(Events new_event);
};

#endif