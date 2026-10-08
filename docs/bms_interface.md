# Battery Management System (BMS) Interface Documentation

This document provides a concise reference for the signals defined in the **BMS specification** (`spec/bms.vspec`).  For each signal we list:
- **Signal name** (as it appears on the vehicle data bus)
- **Type** – whether the signal is a *sensor* (produced by the BMS) or an *actuator* (set by other ECUs)
- **Unit** – the physical unit of the value
- **Meaning** – a short description of what the value represents.

## Signal Catalog

| Signal (full name) | Type | Unit | Meaning |
|--------------------|------|------|---------|
| `Vehicle.Powertrain.TractionBattery.Temperature.Max` | **sensor** | °C (celsius) | Highest cell temperature measured in the traction battery pack. |
| `Vehicle.Powertrain.TractionBattery.StateOfCharge.Current` | **sensor** | % (percent) | Current state‑of‑charge of the traction battery pack. |
| `Vehicle.Powertrain.TractionBattery.Charging.MaxPower` | **actuator** | kW | Maximum charging power that the BMS permits. This value is calculated by the thermal‑derating algorithm and is written back to the charger to limit its power output. |

## Relationship of `Charging.MaxPower` to Requirements

The **`Charging.MaxPower`** actuator directly implements the three high‑level requirements that govern safe charging under thermal constraints (see `docs/requirements.md`).

| Requirement | Description | How `Charging.MaxPower` satisfies it |
|-------------|-------------|--------------------------------------|
| **REQ‑BMS‑001** | *Charging power shall be derated linearly from 45 °C to 55 °C cell temperature.* | The thermal‑derating algorithm computes a scaling factor based on the current maximum cell temperature (`Temperature.Max`). When the temperature is between 45 °C and 55 °C, `Charging.MaxPower` is reduced linearly from the nominal maximum (e.g., 100 kW) down to 0 kW. |
| **REQ‑BMS‑002** | *Charging shall stop (0 kW) at or above 55 °C.* | Once `Temperature.Max` reaches 55 °C (or higher), the algorithm sets `Charging.MaxPower` to **0 kW**, effectively commanding the charger to stop. |
| **REQ‑BMS‑003** | *Invalid temperature readings (below –40 °C or above 125 °C) shall be treated as a sensor fault and charging stopped.* | If `Temperature.Max` falls outside the valid range, the BMS flags a sensor fault and forces `Charging.MaxPower` to **0 kW**, ensuring that charging is halted regardless of any previous derating. |

In summary, **`Charging.MaxPower` is the actionable output of the BMS thermal‑derating logic**.  By continuously updating this actuator based on the measured maximum cell temperature, the BMS enforces the safety envelope defined by REQ‑BMS‑001, REQ‑BMS‑002, and REQ‑BMS‑003.

---
*Document generated on 2026‑10‑08.*