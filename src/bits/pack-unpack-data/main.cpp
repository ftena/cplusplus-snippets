#include <iostream>
#include "Data.h"

void printData(const DataMessage &msg) {
  std::cout << "cs_message_id: " << msg.id << std::endl;
  std::cout << "message_sender: " << msg.command << std::endl;
  std::cout << ": " << msg.data << std::endl;
}

int main(int argc, char *argv[]) {
  char buffer[DATA_SIZE]; // buffer with message size

  DataMessage msg_to_pack;
  msg_to_pack.id = 1;
  msg_to_pack.command = 100;
  msg_to_pack.data = 0.5;
  Data data; // class to pack/unpack data

  // Pack the message
  printData(msg_to_pack);
  uint32_t packet_size = data.pack(buffer, msg_to_pack);

  // Unpack the message  
  DataMessage msg_to_unpack;
  data.unpack(buffer, msg_to_unpack);
  printData(msg_to_unpack);

  return 0;
}
