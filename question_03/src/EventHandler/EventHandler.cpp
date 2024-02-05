#include <iostream>
#include "Config.h"
#include "StateMachine.h"
#include "Action.h"

static bool is_event_valid(Events event);
static bool is_state_valid(States state);

States process_event(States current_state, Events new_event)
{
    if(!is_state_valid(current_state) || !is_event_valid(new_event)) throw std::logic_error{"Invalid state!"};

    StateMachine StateMachine(INITIAL_STATE);

    States next_state = StateMachine.get_next_state(new_event);

    switch (next_state)
    {
    case INITIAL_STATE:
        std::cout << "INITIAL_STATE" << std::endl;
        break;
    case LINK_DOWN:
        std::cout << "LINK_DOWN" << std::endl;
        break;
    case SENDING_START:
        Action::send_start();
        break;
    case SENDING_CONFIG:
        Action::send_config();
        break;
    case KEEP_ALIVE:
        Action::send_keep_alive();
        break;

    default:
        throw std::logic_error{"Invalid state!"};
    }

    return next_state;
}

/*####################################################################################

                                PRIVATE FUNCTIONS

#####################################################################################*/

static bool is_event_valid(Events event)
{
    bool is_valid = false;

    for(int i = INTERFACE_NOK; i < NUMBER_OF_EVENTS; i++)
    {
        is_valid = event == i;
        if(is_valid) return is_valid;
    }

    return is_valid;
}

static bool is_state_valid(States state)
{
    bool is_valid = false;

    for(int i = INITIAL_STATE; i < NUMBER_OF_STATES; i++)
    {
        is_valid = state == i;
        if(is_valid) return is_valid;
    }

    return is_valid;
}
