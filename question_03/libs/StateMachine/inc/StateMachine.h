#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <map>
#include "Config.h"

class StateMachine
{
    private:
        std::map<int, std::map<int, int>> transitions;
        States state;
        static StateMachine *p_instance;

        StateMachine();
        void init_state_transitions(void);

    public:
        StateMachine(const StateMachine& obj) = delete;

        static StateMachine *get_instance(void)
        {
            if(p_instance != NULL) return p_instance;
            p_instance = new StateMachine();
            return p_instance;
        }

        void   set_state(States _state);
        States get_current_state(void);
        States get_next_state(Events new_event);
};

#endif