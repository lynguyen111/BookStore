#pragma once

#include "core/custom/CustomString.h"
namespace pbl2::model {

custom::CustomString canonicalBookStatus(const custom::CustomString &status);
custom::CustomString availabilityStatusForQuantity(int quantity);
bool isAvailabilityStatus(const custom::CustomString &status);

}  // namespace model
