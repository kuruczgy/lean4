/*
Copyright (c) 2021 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura, Mac Malone
*/
#include "runtime/io.h"
#include "runtime/object.h"
#include "runtime/exception.h"
#include "runtime/load_dynlib.h"

namespace lean {
void load_dynlib(std::string path) {
    abort();
}

/* loadDynlib : System.FilePath -> IO Unit */
extern "C" LEAN_EXPORT obj_res lean_load_dynlib(b_obj_arg path, obj_arg) {
    return io_result_mk_error("not implemented");
}
}
