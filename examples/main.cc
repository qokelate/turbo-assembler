#include <unistd.h>

#include "../source/core/assembler/assembler-all.h"

#if __MINGW32__
#include <windows.h>

#endif

static void common_closure_bridge_handler()
{
#if __MINGW32__
    MessageBoxA(NULL, "text 1111", "title 222", MB_OK);
#endif
}

int main(int argc, char const *argv[])
{
    void *v1 = NULL;

#if __MINGW32__
    v1 = VirtualAlloc(NULL, 500, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    printf("VirtualAlloc() ==> %p\n", v1);
#endif

#if TARGET_ARCH_X64
    using namespace zz::x64;
    TurboAssembler turbo_assembler_((void *)v1);
#define _ turbo_assembler_.
#define __ turbo_assembler_.GetCodeBuffer()->

    auto pushfq = (uint8_t *)"\x9c";
    auto popfq = (uint8_t *)"\x9d";

    // save flags register
    __ EmitBuffer(pushfq, 1);
    // align rsp 16-byte
    _ sub(rsp, Immediate(8, 32));

    _ mov(rsp, rbp);

    // general register
    _ sub(rsp, Immediate(16 * 8, 32));
    _ mov(Address(rsp, 8 * 0), rax);
    _ mov(Address(rsp, 8 * 1), rbx);
    _ mov(Address(rsp, 8 * 2), rcx);

    __ EmitBuffer(popfq, 1);

    _ CallFunction(zz::ExternalReference((void *)common_closure_bridge_handler));

    _ RelocBind();

    auto v2 = _ GetRealizedAddress();

    auto len = __ GetBufferSize();
    memcpy(v1, __ GetBuffer(), len);
#undef _
#undef __

    printf("%p, %p, %zu\n", v1, v2, len);

    sleep(1);
    auto p2 = (decltype(common_closure_bridge_handler) *)v1;
    p2();
#endif

#if TARGET_ARCH_IA32

    using namespace zz::x86;
    TurboAssembler turbo_assembler_((void *)v1);
#define _ turbo_assembler_.
#define __ turbo_assembler_.GetCodeBuffer()->

    auto pushfq = (uint8_t *)"\x9c";
    auto popfq = (uint8_t *)"\x9d";

    // save flags register
    __ EmitBuffer(pushfq, 1);
    // align rsp 16-byte
    _ sub(esp, Immediate(8, 32));

    _ mov(esp, ebp);

    // general register
    _ sub(esp, Immediate(16 * 8, 32));
    _ mov(Address(esp, 8 * 0), eax);
    _ mov(Address(esp, 8 * 1), ebx);
    _ mov(Address(esp, 8 * 2), ecx);

    __ EmitBuffer(popfq, 1);

    _ CallFunction(zz::ExternalReference((void *)common_closure_bridge_handler));

    _ RelocBind();

   auto v2 = _ GetRealizedAddress();

    auto len = __ GetBufferSize();
    memcpy(v1, __ GetBuffer(), len);
#undef _
#undef __

    printf("%p, %p, %zu\n", v1, v2, len);

    sleep(1);
    auto p2 = (decltype(common_closure_bridge_handler) *)v1;
    p2();
#endif

    sleep(100);
    return 0;
}

