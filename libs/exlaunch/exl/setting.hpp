#pragma once

#include "exl/common.hpp"

#define EXL_MODULE_NAME "exlaunch"


namespace exl::setting {
    /* How large the fake .bss heap will be. */
    constexpr size_t HeapSize = 0x5000;

    /* How large the JIT area will be for hooks. */
    constexpr size_t JitSize = 0x5000;

    /* How large the area will be inline hook pool. */
    constexpr size_t InlinePoolSize = 0x5000;

    /* Sanity checks. */
    static_assert(ALIGN_UP(JitSize, PAGE_SIZE) == JitSize, "");
    static_assert(ALIGN_UP(InlinePoolSize, PAGE_SIZE) == JitSize, "");
}