/*
Copyright (c) 2013 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#include <string>
#include "runtime/exception.h"
#include "runtime/thread.h"

namespace lean {
throwable::throwable(char const * msg):m_msg(msg) {}
throwable::throwable(std::string const & msg):m_msg(msg) {}
throwable::~throwable() noexcept {}
char const * throwable::what() const noexcept { return m_msg.c_str(); }

stack_space_exception::stack_space_exception(char const * component_name):
    m_msg("") {
}

memory_exception::memory_exception(char const * component_name):
    m_msg("") {
}

char const * heartbeat_exception::what() const noexcept {
    return "(deterministic) timeout";
}
}
