/*
 * Copyright (c) Shelly-HomeKit Contributors
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "mgos_hap_chars.hpp"
#include "shelly_switch.hpp"

namespace shelly {
namespace hap {

class Lock : public ShellySwitch {
 public:
  Lock(int id, Input *in, Output *out, PowerMeter *out_pm, Output *led_out,
       struct mgos_config_sw *cfg);
  virtual ~Lock();

  Status Init();

 private:
  HAPError HandleCurrentStateRead(
      HAPAccessoryServerRef *server,
      const HAPUInt8CharacteristicReadRequest *request, uint8_t *value);
  HAPError HandleTargetStateWrite(
      HAPAccessoryServerRef *server,
      const HAPUInt8CharacteristicWriteRequest *request, uint8_t value);
};

}  // namespace hap
}  // namespace shelly
