#pragma once

#include "core/custom/CustomString.h"
#include "core/custom/DynamicArray.h"

namespace pbl2::core {

class IdGenerator {
public:
    static custom::CustomString nextId(const custom::DynamicArray<custom::CustomString> &existing,
                                       const custom::CustomString &prefix,
                                       int width = 4);
};

}  // namespace pbl2::core

