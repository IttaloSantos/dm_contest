#include <iostream>
#include <EventHandler.h>

using namespace std;

int main()
{
    States next_state = process_event(INITIAL_STATE, INTERFACE_OK);

    cout << next_state << endl;

    return 0;
}
