/*
Copyright (c) 2018 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#include "runtime/alloc.h"
#include "runtime/thread.h"
#include "runtime/io.h"
#include "runtime/process.h"
#include "runtime/init_module.h"

namespace lean {
extern "C" LEAN_EXPORT void lean_initialize_runtime_module() {
    initialize_alloc();
    initialize_thread();
    initialize_process();
}
void initialize_runtime_module() {
    lean_initialize_runtime_module();
}
void finalize_runtime_module() {
    finalize_process();
    finalize_thread();
    finalize_alloc();
}
}
