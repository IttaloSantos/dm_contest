#include <iostream>
#include "Action.h"

bool Action::send_start(void)
{
    std::cout << "Start sent!" << std::endl;
    return true;
}

bool Action::send_config(void)
{
    std::cout << "Config sent!" << std::endl;
    return true;
}

bool Action::send_keep_alive(void)
{
    std::cout << "Keep Alive sent!" << std::endl;
    return true;
}