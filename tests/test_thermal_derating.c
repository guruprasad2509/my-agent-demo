/* Unit tests - REQ-BMS-001, REQ-BMS-002 (REQ-BMS-003 not yet covered) */
#include <assert.h>
#include "../src/bms/thermal_derating.h"
int main(void) {
    assert(bms_max_charge_power_kw(25.0f, 150.0f) == 150.0f);
    assert(bms_max_charge_power_kw(50.0f, 150.0f) == 75.0f);
    assert(bms_max_charge_power_kw(60.0f, 150.0f) == 0.0f);
    return 0;
}
