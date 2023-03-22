#pragma once

#include "CodeBufferBase.h"

class CodeBuffer : public CodeBufferBase {
public:
  CodeBuffer() : CodeBufferBase() {
  }

public:
  void FixBindLabel(int offset, int32_t disp) {
    Store(offset, disp);
  }
};