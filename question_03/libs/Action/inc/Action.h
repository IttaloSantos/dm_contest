#ifndef ACTION_H
#define ACTION_H

#include <cstdbool>

namespace Action
{
    bool send_start(void);
    bool send_config(void);
    bool send_keep_alive(void);
}

#endif