#pragma once

/*!
 * Data struct with message fields.
 */
const int DATA_SIZE = 10;

struct DataMessage {
  unsigned int id; // 4 bytes
  short command; // 2 bytes
  float data; // 4 bytes
};
