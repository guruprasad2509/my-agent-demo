/* Battery thermal derating - dummy SDV component (ASIL C) */
#include "thermal_derating.h"

#define DERATE_START_C   45.0f
#define DERATE_STOP_C    55.0f

/* REQ-BMS-001, REQ-BMS-002, REQ-BMS-003 */
float bms_max_charge_power_kw(float max_cell_temp_c, float rated_power_kw)
{
    if (max_cell_temp_c < -40.0f || max_cell_temp_c > 125.0f) {
        return 0.0f; /* sensor fault */
    }
    if (max_cell_temp_c >= DERATE_STOP_C) {
        return 0.0f;
    }
    if (max_cell_temp_c <= DERATE_START_C) {
        return rated_power_kw;
    }
    return rated_power_kw * (DERATE_STOP_C - max_cell_temp_c) / (DERATE_STOP_C - DERATE_START_C);
}
