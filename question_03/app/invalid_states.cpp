#include <iostream>
#include <EventHandler.h>

using namespace std;

int main()
{
    States current_state = process_event(SENDING_START, INTERFACE_OK);
    cout << current_state << endl; // Current_state doesn't change

    current_state = process_event(SENDING_CONFIG, INTERFACE_OK);
    cout << current_state << endl; // Current_state doesn't change

    current_state = process_event(KEEP_ALIVE, INTERFACE_OK);
    cout << current_state << endl; // Current_state doesn't change

    int test = 0xff;

    // Program will throw error
    current_state = process_event(current_state, (Events)test);

    return 0;
}
