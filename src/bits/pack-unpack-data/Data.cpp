#include "Data.h"

#include <cstring>
#include <climits>
#include <iostream>
#include <arpa/inet.h>
#include <bitset>
#include <type_traits>

// SFINAE for safety. Sue me for putting it in a macro for brevity on the function
#define IS_INTEGRAL(T) typename std::enable_if< std::is_integral<T>::value >::type* = 0

template<class T>
std::string integral_to_binary_string(T byte, IS_INTEGRAL(T))
{
    std::bitset<sizeof(T) * CHAR_BIT> bs(byte);
    return bs.to_string();
}

// Formatted output of ieee-754 representation of float
void show_ieee754 (float f)
{
    union {
        float f;
        uint32_t u;
    } fu = { .f = f };
    int i = sizeof f * CHAR_BIT;

    printf ("  ");
    while (i--)
        printf ("%d ", (fu.u >> i) & 0x1);

    putchar ('\n');
    printf (" |- - - - - - - - - - - - - - - - - - - - - - "
            "- - - - - - - - - -|\n");
    printf (" |s|      exp      |                  mantissa"
            "                   |\n\n");
}

Data::Data()
{
}

Data::~Data() {}

uint32_t Data::pack(char *buffer, const DataMessage &msg) const {
  // Pointer to move in buffer
  char *current = buffer;

  // Convert little endian (host endian) to big endian
  uint32_t be_32 = htonl(msg.id);
  // Save the field to buffer
  memcpy(current, &be_32, sizeof(be_32));
  current += sizeof(be_32);
  std::cout << integral_to_binary_string(be_32) << std::endl;

  uint16_t be_16 = htons(msg.command);
  memcpy(current, &be_16, sizeof(be_16));
  current += sizeof(be_16);
  std::cout << integral_to_binary_string(be_16) << std::endl;

  be_32 = htonl(*(uint32_t *)&msg.data);
  memcpy(current, &be_32, sizeof(be_32));
  current += sizeof(be_32);
  show_ieee754(msg.data);

  return (uint32_t)(current - buffer);
}

void Data::unpack(char *buffer, DataMessage &msg) {
  // Pointer to move in buffer
  char *current = buffer;

  uint32_t be_32 = 0;
  memcpy(&be_32, current, sizeof(be_32));
  msg.id = ntohl(be_32);
  current += sizeof(be_32);

  uint16_t be_16 = 0;
  memcpy(&be_16, current, sizeof(be_16));
  msg.command = ntohs(be_16);
  current += sizeof(be_16);

  be_32 = 0;
  memcpy(&be_32, current, sizeof(be_32));
  uint32_t le_32 = ntohl(be_32);
  msg.data = *(float *)&le_32;
  current += sizeof(be_32);
  show_ieee754(msg.data);
}
