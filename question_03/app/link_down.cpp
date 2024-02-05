#include <iostream>
#include <EventHandler.h>

using namespace std;

int main()
{
    States current_state = process_event(SENDING_START, INTERFACE_NOK);
    cout << current_state << endl; // Expects LINK_DOWN - 1

    current_state = process_event(SENDING_CONFIG, INTERFACE_NOK);
    cout << current_state << endl; // Expects LINK_DOWN - 1

    current_state = process_event(KEEP_ALIVE, INTERFACE_NOK);
    cout << current_state << endl; // Expects LINK_DOWN - 1

    current_state = process_event(current_state, INTERFACE_NOK);
    cout << current_state << endl; // Expects LINK_DOWN - 1

    current_state = process_event(LINK_DOWN, INTERFACE_NOK);
    cout << current_state << endl; // Expects LINK_DOWN - 1

    current_state = process_event(LINK_DOWN, NOK_PACKAGE_RECEIVED);
    cout << current_state << endl; // Expects LINK_DOWN - 1

    current_state = process_event(LINK_DOWN, OK_PACKAGE_RECEIVED);
    cout << current_state << endl; // Expects LINK_DOWN - 1

    current_state = process_event(LINK_DOWN, TIMEOUT);
    cout << current_state << endl; // Expects LINK_DOWN - 1

    return 0;
}
