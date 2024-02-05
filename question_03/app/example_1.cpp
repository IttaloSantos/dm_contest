#include <iostream>
#include <cstdbool>
#include <cstring>

using namespace std;

enum class States
{
    INITIAL_STATE = 0,
    LINK_DOWN,
    SENDING_START,
    SENDING_CONFIG,
    KEEP_ALIVE
};

enum class Events
{
    INTERFACE_NOK,
    INTERFACE_OK,
    OK_PACKAGE_RECEIVED,
    NOK_PACKAGE_RECEIVED,
    TIMEOUT
};

class StateMachine
{
    private:
        

    protected:
        States state;

    public:
        StateMachine(States _state);
        ~StateMachine(){};

        States get_current_state(void);
        void   set_state(States _state);
};

StateMachine::StateMachine(States _state)
{
    this->state = _state;
}

States StateMachine::get_current_state(void)
{
    return this->state;
}

void StateMachine::set_state(States _state)
{
    this->state = _state;
}

/*
struct evt_package
{
    Events event;
    void   *data;
    int    data_size;
};

class EventHandler : public StateMachine
{
    private:
        evt_package package;

    public:
        EventHandler(evt_package *_evt_package);
        ~EventHandler(){};

        void set_event(evt_package *_evt_package);
        bool generate_event(void);
};

EventHandler::EventHandler(evt_package *_evt_package) : StateMachine::StateMachine(States::SENDING_START)
{
    // this->package.data 
}

void EventHandler::set_event(evt_package *_evt_package)
{

}

bool EventHandler::generate_event(void)
{
    switch (this->package.event)
    {
    case Events::INTERFACE_NOK:
        StateMachine::set_state(States::LINK_DOWN);
        break;
    case Events::INTERFACE_OK:
        StateMachine::set_state(States::SENDING_START);
        break;
    case Events::OK_PACKAGE_RECEIVED:
        StateMachine::set_state(States::LINK_DOWN);
        break;
    case Events::NOK_PACKAGE_RECEIVED:
        StateMachine::set_state(States::LINK_DOWN);
        break;
    case Events::TIMEOUT:
        StateMachine::set_state(States::LINK_DOWN);
        break;

    default:
        throw std::logic_error{"Invalid Event"};
        return false;
    }

transitions[LINK_DOWN][INTERFACE_NOK] = LINK_DOWN
transitions[LINK_DOWN][INTERFACE_OK] = SENDING_START
transitions[LINK_DOWN][OK_PACKAGE_RECEIVED] = 0
transitions[LINK_DOWN][NOK_PACKAGE_RECEIVED] = 0
transitions[LINK_DOWN][TIMEOUT] = 0

transitions[SENDING_START][INTERFACE_NOK] = LINK_DOWN
transitions[SENDING_START][INTERFACE_OK] = 0
transitions[SENDING_START][OK_PACKAGE_RECEIVED] = SENDING_CONFIG
transitions[SENDING_START][NOK_PACKAGE_RECEIVED] = SENDING_START
transitions[SENDING_START][TIMEOUT] = SENDING_START

transitions[SENDING_CONFIG][INTERFACE_NOK] = LINK_DOWN
transitions[SENDING_CONFIG][INTERFACE_OK] = 0
transitions[SENDING_CONFIG][OK_PACKAGE_RECEIVED] = KEEP_ALIVE
transitions[SENDING_CONFIG][NOK_PACKAGE_RECEIVED] = SENDING_CONFIG
transitions[SENDING_CONFIG][TIMEOUT] = SENDING_START

transitions[KEEP_ALIVE][INTERFACE_NOK] = LINK_DOWN
transitions[KEEP_ALIVE][INTERFACE_OK] = 0
transitions[KEEP_ALIVE][OK_PACKAGE_RECEIVED] = KEEP_ALIVE
transitions[KEEP_ALIVE][NOK_PACKAGE_RECEIVED] = SENDING_START
transitions[KEEP_ALIVE][TIMEOUT] = SENDING_START

    return true;
}
*/

int main()
{

    return 0;
}

namespace Action
{
    bool send_data(int *_data, int _data_size);
}

bool Action::send_data(int *_data, int _data_size)
{
    /*
        Send package to the slave.
        Code below is hypotetical.
    */

    string *data = new string[_data_size*sizeof(int)];

    memcpy(data, _data, _data_size);

    cout << data << endl;
    
    delete[] data;

    return true;
}