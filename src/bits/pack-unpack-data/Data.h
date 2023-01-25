#pragma once

#include <cstdint>
#include "DataMessage.h"

class Data {
public:
  explicit Data();
  virtual ~Data();
  uint32_t pack(char *buffer, const DataMessage &msg) const;
  void unpack(char *buffer, DataMessage &msg);
private:
};
