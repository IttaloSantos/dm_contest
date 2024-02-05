#include <iostream>
#include "Action.h"

bool Action::send_start(void)
{
    std::cout << "SENDING START" << std::endl;
    return true;
}

bool Action::send_config(void)
{
    std::cout << "SENDING CONFIG" << std::endl;
    return true;
}

bool Action::send_keep_alive(void)
{
    std::cout << "SENDING KEEP ALIVE" << std::endl;
    return true;
}