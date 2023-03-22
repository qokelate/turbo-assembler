#ifndef CORE_CODEGEN_ARM_H
#define CORE_CODEGEN_ARM_H

#include "codegen.h"
#include "../assembler/assembler.h"
#include "../assembler/assembler-arm.h"

namespace zz {
namespace arm {

class CodeGen : public CodeGenBase {
public:
  CodeGen(TurboAssembler *turbo_assembler) : CodeGenBase(turbo_assembler) {
  }

  void LiteralLdrBranch(uint32_t address);
};

} // namespace arm
} // namespace zz

#endif