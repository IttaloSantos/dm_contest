#include <iostream>
#include <EventHandler.h>

using namespace std;

int main()
{
    States current_state = process_event(LINK_DOWN, INTERFACE_OK);
    cout << current_state << endl; // Expects SENDING_START - 2

    current_state = process_event(current_state, OK_PACKAGE_RECEIVED);
    cout << current_state << endl; // Expects SENDING_CONFIG - 3

    current_state = process_event(current_state, OK_PACKAGE_RECEIVED);
    cout << current_state << endl; // KEEP_ALIVE - 4

    current_state = process_event(current_state, OK_PACKAGE_RECEIVED);
    cout << current_state << endl; // KEEP_ALIVE - 4

    return 0;
}
