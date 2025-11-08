#pragma once

#include "core/custom/DynamicArray.h"
#include "core/custom/CustomString.h"

namespace pbl2::core {

using Row = custom::DynamicArray<custom::CustomString>;
using Table = custom::DynamicArray<Row>;

}  // namespace pbl2::core

