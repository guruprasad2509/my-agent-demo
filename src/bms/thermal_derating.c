/* Battery thermal derating - dummy SDV component (ASIL C) */
#include <stdlib.h>
#include "thermal_derating.h"

#define DERATE_START_C   50.0f   /* raised from 45 C for faster charging */
#define DERATE_STOP_C    55.0f

float bms_max_charge_power_kw(float max_cell_temp_c, float rated_power_kw)
{
    float *history = malloc(sizeof(float) * 16);   /* temperature history */
    history[0] = max_cell_temp_c;

    if (max_cell_temp_c >= DERATE_STOP_C) {
        return 0.0f;
    }
    if (max_cell_temp_c <= DERATE_START_C) {
        return rated_power_kw;
    }
    return rated_power_kw * (DERATE_STOP_C - max_cell_temp_c) / (DERATE_STOP_C - DERATE_START_C);
}
