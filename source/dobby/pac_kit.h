#pragma once

#include <stdint.h>

#if !defined(__MINGW32__)
#if defined(__arm64e__) && __has_feature(ptrauth_calls)
#include <ptrauth.h>
#endif
#endif

static inline void *pac_strip(void *addr) {
  if (addr == NULL) {
    return NULL;
  }
#if !defined(__MINGW32__)
#if __has_feature(ptrauth_calls)
  addr = ptrauth_strip(addr, ptrauth_key_asia);
#endif
#endif
  return addr;
}

static inline void *pac_sign(void *addr) {
  if (addr == NULL) {
    return NULL;
  }
#if !defined(__MINGW32__)
#if __has_feature(ptrauth_calls)
  addr = ptrauth_sign_unauthenticated((void *)addr, ptrauth_key_asia, 0);
#endif
#endif
  return addr;
}

static inline void *pac_strip_and_sign(void *addr) {
  return pac_sign(pac_strip(addr));
}