#ifndef CORE_CODEGEN_X86_H
#define CORE_CODEGEN_X86_H

#include "codegen.h"
#include "../assembler/assembler.h"
#include "../assembler/assembler-ia32.h"

namespace zz {
namespace x86 {

class CodeGen : public CodeGenBase {
public:
  CodeGen(TurboAssembler *turbo_assembler) : CodeGenBase(turbo_assembler) {
  }

  void JmpNear(uint32_t address);
};

} // namespace x86
} // namespace zz

#endif