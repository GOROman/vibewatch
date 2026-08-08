# Vibe Watch

Turn an M5Stack StopWatch into **Vibe Watch**, a tactile companion for AI-assisted **Vibe Coding**.

This experimental firmware makes the StopWatch appear to a supported AI coding desktop app as a compatible Bluetooth Low Energy HID device. Its round touchscreen, two physical buttons, speaker, vibration motor, and battery become a compact control surface for selecting AI agents, approving or rejecting actions, invoking the AI assistant, and using push-to-talk without breaking coding flow.

## Why I Built It

Vibe Coding is fast when ideas, code, and feedback stay in one continuous loop. Reaching for small on-screen controls interrupts that loop, especially when several agents are working at once.

The StopWatch solves this with a dedicated physical interface:

- Six agents are always visible around the circular display.
- A moving selection ring makes the active agent immediately recognizable.
- A second action layer provides FAST, OK, NG, SPLIT, and AI controls.
- The center of the display is a large push-to-talk microphone button.
- Physical buttons provide eyes-free approval, rejection, agent switching, and voice control.
- Sound and vibration confirm every action without requiring another glance at the computer.

The result is a small, wireless “AI cockpit” for the desk: glance, tap, speak, and keep creating.

## What Makes It Special

- **Purpose-built for Vibe Coding** — common AI-agent actions become immediate physical gestures.
- **A circular UI designed for the hardware** — the interface follows the StopWatch bezel instead of copying a rectangular desktop UI.
- **Two interfaces in one** — press both physical buttons to switch the outer ring between Agent and Action layers.
- **Rich feedback** — animated selection, RGB status, sound effects, and haptics communicate state at a glance.
- **No custom desktop bridge** — the device communicates directly through BLE HID and a vendor JSON-RPC transport.
- **Portable and rechargeable** — all controls run on the self-contained M5Stack StopWatch.

## Features

- BLE HID over GATT (HOGP)
- Compatible VID/PID, PnP ID, vendor usage page, and report descriptors
- HID Report IDs 1, 2, 3, and 6 with Report Reference descriptors
- 63-byte vendor JSON-RPC transport over Report ID 6
- `device.status` and `sys.version` support
- Six-agent status visualization from `v.oai.thstatus`
- Outer-ring color and animation updates from `v.oai.rgbcfg`
- `host.focused_app` request handling
- Touch controls for Agent events `AG00` through `AG05`
- Action controls for `ACT06` through `ACT09` and `ACT12`
- Push-to-talk using `ACT10` and `ACT11`
- Three selectable BLE identities: `Vibe Watch #1` through `#3`
- Bond reset and BLE re-pairing from the settings screen
- Persistent sound-effect volume setting
- Real battery level and charging state through Battery Service and `device.status`
- Animated high-visibility UI, sound feedback, and vibration feedback

## Controls

| StopWatch interaction | Vibe Coding action |
|---|---|
| Tap outer buttons 1–6 | Select/send Agent events `AG00`–`AG05` |
| Press both physical buttons | Switch the outer ring between Agent and Action layers |
| Tap FAST / OK / NG / SPLIT / AI | Send `ACT06`–`ACT09` / `ACT12` |
| Left physical button in Action layer | Send OK (`ACT07`) |
| Right physical button in Action layer | Send NG (`ACT08`) |
| Hold the center microphone | Push-to-talk (`ACT10` + `ACT11`) |
| Short-press left physical button | Advance to the next agent |
| Long-press right physical button | Push-to-talk (`ACT10` + `ACT11`) |
| Short-press right physical button | Invoke the AI assistant (`ACT12`) |
| Tap the lower-left settings icon | Open Bluetooth identity, pairing, and volume settings |

## Hardware

- [M5Stack StopWatch](https://docs.m5stack.com/en/core/StopWatch)
  - ESP32-S3 controller
  - 1.3-inch round capacitive touchscreen
  - Two physical buttons
  - Speaker
  - Vibration motor
  - Battery and charging circuit
- A macOS computer with Bluetooth

No additional sensor, module, or custom PCB is required.

## Software

- Arduino framework
- [M5Unified](https://github.com/m5stack/M5Unified)
- [NimBLE-Arduino](https://github.com/h2zero/NimBLE-Arduino)
- [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
- PlatformIO Core
- A supported AI coding desktop app for macOS

## How the M5Stack Controller Is Used

The StopWatch is the complete user interface and wireless controller, not just an enclosure or accessory. The ESP32-S3 runs the BLE HID protocol, JSON-RPC transport, input handling, UI rendering, audio, haptics, battery reporting, preferences, and pairing workflow. The circular touchscreen presents the live agent state received from the host, while the hardware buttons provide low-latency controls that can be used without looking away from the code.

## Build and Flash

Install PlatformIO Core, clone this repository, and build the firmware:

```sh
python3 -m platformio run
```

Connect the StopWatch over USB and flash it:

```sh
python3 -m platformio run --target upload
```

To view the serial log:

```sh
python3 -m platformio device monitor
```

## Pairing

1. Flash the firmware and restart the StopWatch.
2. Tap the settings icon at the lower left of the screen.
3. Select `#1`, `#2`, or `#3`, then tap `PAIR`. The firmware clears the existing bond and restarts automatically.
4. On macOS, open **System Settings → Bluetooth** and connect to the selected `Vibe Watch #n` device.
5. Allow Input Monitoring permission for the AI coding desktop app.
6. Confirm that the external-controller controls appear in the app settings.

After changing the HID Report Map or Device Information, remove the device from macOS Bluetooth settings and pair it again. macOS caches the BLE GATT structure and bond information.

## Project Structure

```text
include/
  vibe_hid.h               HID report map and identifiers
  llmcardputer_sound.h     Sound-effect declarations
src/
  main.cpp                 BLE protocol, UI, input, pairing, and battery logic
  llmcardputer_sound.cpp   Push-to-talk sound effects
platformio.ini             PlatformIO build configuration and dependencies
```

## Current Status

The core interaction loop is implemented and runs on the M5Stack StopWatch: pairing, host communication, six-agent display, agent/action switching, approvals, rejection, AI-assistant invocation, push-to-talk, sound, haptics, and battery reporting.

## Disclaimer

This is an independent experimental compatibility project. Third-party manufacturer and model names are intentionally shown as `**********`. It is not official M5Stack firmware. Before commercial distribution, verify all applicable trademark, product-name, VID/PID, and protocol-compatibility requirements.

## References

- [M5Stack StopWatch documentation](https://docs.m5stack.com/en/core/StopWatch)
