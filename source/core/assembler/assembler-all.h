//
// Created by sma11case on 2023/3/22.
//

#ifndef DOBBY_SOURCE_CORE_ASSEMBLER_ASSEMBLER_ALL_H
#define DOBBY_SOURCE_CORE_ASSEMBLER_ASSEMBLER_ALL_H

#include "assembler.h"


#if TARGET_ARCH_IA32
#include "assembler-ia32.h"
#elif TARGET_ARCH_X64
#include "assembler-x64.h"
#elif TARGET_ARCH_ARM64
#include "assembler-arm64.h"
#elif TARGET_ARCH_ARM
#include "assembler-arm.h"
#elif TARGET_ARCH_PPC
#include "src/ppc/assembler-ppc.h"
#elif TARGET_ARCH_MIPS
#include "src/mips/assembler-mips.h"
#elif TARGET_ARCH_MIPS64
#include "src/mips64/assembler-mips64.h"
#elif TARGET_ARCH_S390
#include "src/s390/assembler-s390.h"
#else
#error Unknown architecture.
#endif

#endif //DOBBY_SOURCE_CORE_ASSEMBLER_ASSEMBLER_ALL_H
