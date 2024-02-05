#include <iostream>

//! Uncomment line 3 and comment line 4 to use original function
//#include "original_function.h"
#include "correct_function.h"

#define SHOW_PACKET

static void show_packet(int *packet, int length);

int main(int argc, char const *argv[])
{
    //! packet size >= length + header_length
    int packet[200] = {0x45, 0x32, 0x44, 0x15};
    int length[1]   = {4};

    std::cout << "Packet length: " << *length << std::endl;

    static const int header_length = 12;
    int header[header_length] = {0x80, 0x52, 0x66, 0x61, 0x77, 0x52, 
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    std::cout << "Header length: " << header_length << std::endl;

    bool result = insert_header(packet, length, header, header_length);

    if(!result)
    {
        std::cout << "insert header function failed!" << std::endl;
        return 1;
    }

    std::cout << "Final Packet length: " << *length << std::endl;

#ifdef SHOW_PACKET
    show_packet(packet, *length);
#endif

    return 0;
}

static void show_packet(int *packet, int length)
{
    for(int i = 0; i < length; i++) std::cout << std::hex << packet[i] << " ";
    std::cout << std::endl;
}