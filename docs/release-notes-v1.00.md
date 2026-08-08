# Vibe Watch v1.00

The first contest-ready release of Vibe Watch, a wearable tactile control surface for AI-assisted Vibe Coding built around the M5Stack StopWatch.

## Highlights

- Six live AI-agent indicators with fast spring selection animation
- Transforming Agent and Action interface layers
- Physical orange NG and blue OK controls with visual rails
- Distinct square-wave approve/reject sounds and adjustable haptics
- Plan mode toggle, assistant action, and push-to-talk
- BLE HID pairing with success feedback and three device slots
- Animated VIBEWATCH startup, original NES-style jingle, and battery bar
- On-device sound volume, vibration strength, and state-change settings
- Modified M5Stack watch accessory mount for wrist use

## Install

Download `firmware.bin` from this release, or build and upload the source with PlatformIO:

```sh
python3 -m platformio run -e m5stack-stopwatch --target upload
```

See the [README](https://github.com/GOROman/vibewatch#readme) for the complete hardware, wrist-mount, pairing, and build instructions.
