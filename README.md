# Vibe Watch

**A tactile companion for AI-assisted Vibe Coding, built with the M5Stack StopWatch.**

## Description

Vibe Watch moves frequent AI-agent controls from the computer screen to a small wireless device. Select an agent, approve or reject an action, invoke the assistant, or use push-to-talk without leaving the creative flow.

## Why Vibe Watch?

Vibe Coding feels best when ideas, code, and feedback move continuously. Searching for small on-screen controls breaks that rhythm.

After purchasing an OpenAI Codex Micro, I was inspired by dedicated hardware for AI coding. I believed a round touchscreen, direct controls, animation, sound, and haptics could create an even more compact and glanceable experience. That challenge became Vibe Watch: a small “AI cockpit” for the desk.

## Demo

The final Hackster page will include device photos and a short video showing:

- Live agent colors and the animated selection ring
- Switching between Agent and Action layers
- One-touch approval and rejection
- Push-to-talk with visual, sound, and haptic feedback

## Functionality and Execution

The working prototype handles an animated Vibe Watch startup with a short jingle, Bluetooth pairing with success feedback, six live agent states, animated selection, layer switching, action controls, push-to-talk, sound, vibration, and battery reporting. The firmware builds reproducibly with PlatformIO on the ESP32-S3-based StopWatch.

## Creativity and Originality

Unlike a conventional macro pad, Vibe Watch uses the entire M5Stack StopWatch as a multisensory AI interface. Six agent buttons orbit a large center microphone, while live colors and an animated ring make state and selection easy to recognize at a glance.

## Two Interaction Layers

The Agent layer displays agents 1–6. Tap one to select it, or use the left physical button to move through them.

Press both physical buttons together and the ring transforms into **FAST, OK, NG, SPLIT, and AI**. The buttons sit directly above OK and NG, creating a simple spatial relationship: left approves, right rejects.

## Multisensory Feedback

Every important action combines **visual** color and motion, **audio** confirmation, and **haptic** feedback. In Settings, users can adjust vibration strength and independently enable sound or vibration when any of the six agent states changes. The result feels immediate and physical rather than like another remote screen.

## Impact and Usefulness

Vibe Watch reduces small but repeated interruptions during AI-assisted coding. It keeps status visible, makes approval decisions nearly instant, and lets voice input happen without searching through the desktop UI. The same interaction model could inspire accessible controllers for other multi-agent and creative tools.

## Key Controls

| Interaction | Result |
|---|---|
| Tap 1–6 | Select an AI agent |
| Press both physical buttons | Switch Agent / Action layers |
| Tap FAST / OK / NG / SPLIT / AI | Trigger an action |
| Press left / right in Action layer | Approve / reject |
| Hold the center microphone | Push-to-talk |

## Hardware Used

| Item | Quantity | Role |
|---|---:|---|
| [M5Stack StopWatch](https://docs.m5stack.com/en/core/StopWatch) | 1 | Main controller and complete user interface |
| USB-C cable | 1 | Firmware upload and charging |
| macOS computer with Bluetooth | 1 | AI coding host |

No additional sensor, module, or custom PCB is required.

## How the M5Stack Controller Is Used

The M5Stack StopWatch is the heart of the project—not a passive display or accessory. Its ESP32-S3 runs the firmware and wireless connection. The round touchscreen presents six agents and the action layer; the physical buttons provide eyes-free shortcuts; the speaker and vibration motor confirm input; and the battery makes the experience portable.

All interaction happens directly on the StopWatch, turning the controller into a self-contained physical interface for Vibe Coding.

## Build Instructions

Install PlatformIO Core, clone this repository, and build the firmware:

```sh
python3 -m platformio run
```

Connect the M5Stack StopWatch over USB-C and upload it:

```sh
python3 -m platformio run --target upload
```

After flashing, open the device settings, tap **PAIR**, and connect to `Vibe Watch #n` from macOS Bluetooth settings.

## License

[MIT License](LICENSE)

## References

- [OpenAI Codex Micro — official documentation](https://learn.chatgpt.com/docs/features/codex-micro)

## Disclaimer

This is an independent experimental compatibility project inspired by OpenAI Codex Micro. Third-party manufacturer and model values in the firmware are intentionally shown as `**********`. It is not official firmware from OpenAI or M5Stack.
