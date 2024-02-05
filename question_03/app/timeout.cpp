#include <iostream>
#include <EventHandler.h>

using namespace std;

int main()
{
    States current_state = process_event(LINK_DOWN, TIMEOUT);
    cout << current_state << endl; // Expects LINK_DOWN - 1

    current_state = process_event(SENDING_START, TIMEOUT);
    cout << current_state << endl; // Expects SENDING_START - 2

    current_state = process_event(SENDING_CONFIG, TIMEOUT);
    cout << current_state << endl; // Expects SENDING_START - 2

    current_state = process_event(KEEP_ALIVE, TIMEOUT);
    cout << current_state << endl; // Expects SENDING_START - 2

    return 0;
}
