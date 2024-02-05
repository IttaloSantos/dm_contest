#include "correct_function.h"
#include <cstring>

bool insert_header(int *packet, int *length, int *header, int header_length)
{
    bool result = packet == NULL || length == NULL || 
                  header == NULL || header_length == 0 ? false
                                                       : true;
    if(!result) return result;

    /* It is assumed that there is sufficient memory allocated for packet 
    to add header in it */
    std::memcpy(packet+header_length, packet, *length*sizeof(int));
    std::memcpy(packet, header, header_length*sizeof(int));

    *length += header_length;

    return result;
}