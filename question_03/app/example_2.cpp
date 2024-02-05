#include <iostream>
#include <cstdbool>
#include <map>

#define NUMBER_OF_STATES 5
#define NUMBER_OF_EVENTS 5

using namespace std;

enum States
{
    INITIAL_STATE = 0,
    LINK_DOWN,
    SENDING_START,
    SENDING_CONFIG,
    KEEP_ALIVE
};

enum Events
{
    INTERFACE_NOK,
    INTERFACE_OK,
    OK_PACKAGE_RECEIVED,
    NOK_PACKAGE_RECEIVED,
    TIMEOUT
};

static bool is_event_valid(Events event);
static bool is_state_valid(States state);

namespace Action
{
    bool send_start(void);
    bool send_config(void);
    bool send_keep_alive(void);
}

class StateMachine
{
    private:
        map<int, map<int, int>> transitions;
        States state;

        void init_state_transitions(void);

    public:
        StateMachine(States _state = INITIAL_STATE);
        ~StateMachine(){};

        void   set_state(States _state);
        States get_current_state(void);
        States get_next_state(Events new_event);
};

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

int main()
{

    return 0;
}

States process_event(States current_state, Events new_event)
{
    if(!is_state_valid(current_state) || !is_event_valid(new_event)) throw std::logic_error{"Invalid state!"};
    //! TODO: How to call constructor just once?
    StateMachine StateMachine(current_state);
    
    States next_state = StateMachine.get_next_state(new_event);

    switch (next_state)
    {
    case INITIAL_STATE:
        cout << "INITIAL_STATE" << endl;
        break;
    case LINK_DOWN:
        cout << "LINK_DOWN" << endl;
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

bool Action::send_start(void)
{
    cout << "Start sent!" << endl;
    return true;
}

bool Action::send_config(void)
{
    cout << "Config sent!" << endl;
    return true;
}

bool Action::send_keep_alive(void)
{
    cout << "Keep Alive sent!" << endl;
    return true;
}