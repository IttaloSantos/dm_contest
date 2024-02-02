#include "original_function.h"

//! Uncomment to run

// char *insert_header(int *packet, int *length)
// {
//     int i;
//     char header[12] = { 0x80, 0x52, 0x66, 0x61, 0x77, 0x52 };
//     /* os outros 6 são 0 */

//     if (packet == NULL || length == NULL)
//     {
//         return NULL;
//     }

//     for (i=0; i < *length; i++)
//         packet[i+3] = packet[i];
    
//     for (i=0; i < 12; i++)
//         packet[i] = header[i];
    
//     *length += 12;
    
//     return packet;
// }