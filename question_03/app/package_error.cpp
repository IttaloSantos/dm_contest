#include <iostream>
#include <EventHandler.h>

using namespace std;

int main()
{
    States current_state = process_event(SENDING_START, NOK_PACKAGE_RECEIVED);
    cout << current_state << endl; // Expects SENDING_START - 2

    current_state = process_event(SENDING_CONFIG, NOK_PACKAGE_RECEIVED);
    cout << current_state << endl; // Expects SENDING_CONFIG - 3

    current_state = process_event(KEEP_ALIVE, NOK_PACKAGE_RECEIVED);
    cout << current_state << endl; // Expects SENDING_START - 2

    current_state = process_event(LINK_DOWN, NOK_PACKAGE_RECEIVED);
    cout << current_state << endl; // LINK DOWN - 1

    return 0;
}
