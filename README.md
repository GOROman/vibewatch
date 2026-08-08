# Vibe Watch

**A tactile companion for AI-assisted Vibe Coding, built with the M5Stack StopWatch.**

Vibe Watch moves frequent AI-agent controls from the computer screen to a small wireless device. Select an agent, approve or reject an action, invoke the assistant, or use push-to-talk without leaving the creative flow.

## Why Vibe Watch?

Vibe Coding feels best when ideas, code, and feedback move continuously. Searching for small on-screen controls breaks that rhythm.

Vibe Watch keeps the essential interactions within reach:

- **Glance** at the state of six AI agents.
- **Tap** an agent or action directly.
- **Speak** through a large push-to-talk button.
- **Feel and hear** immediate confirmation.

It is a compact “AI cockpit” for the desk.

## Circular UI

The interface was designed around the round M5Stack StopWatch display instead of adapting a rectangular desktop layout.

Six agent buttons orbit the center microphone. An animated ring travels around the dial to show the current selection, while live colors make every agent easy to recognize at a glance.

The microphone remains large and central because voice is the quickest way to add context while coding.

## Two Interaction Layers

### Agent Layer

The outer ring displays agents 1–6. Tap an agent to select it, or use the left physical button to move through agents without touching the screen.

### Action Layer

Press both physical buttons together and the outer ring transforms into **FAST, OK, NG, SPLIT, and AI**.

The physical buttons sit directly above OK and NG, creating a simple spatial relationship: left approves, right rejects. Common decisions can be made without looking away from the code.

## Multisensory Feedback

Every important action combines three forms of feedback:

- **Visual** — color, motion, selection rings, and clear layer changes
- **Audio** — short sounds confirm presses and push-to-talk state
- **Haptic** — vibration confirms input without requiring another glance

The result feels immediate and physical rather than like another remote screen.

## Key Controls

| Interaction | Result |
|---|---|
| Tap 1–6 | Select an AI agent |
| Press both physical buttons | Switch Agent / Action layers |
| Tap FAST / OK / NG / SPLIT / AI | Trigger an action |
| Press left / right in Action layer | Approve / reject |
| Hold the center microphone | Push-to-talk |

## Hardware and Build

Vibe Watch uses one [M5Stack StopWatch](https://docs.m5stack.com/en/core/StopWatch). No additional sensor, module, or custom PCB is required.

```sh
python3 -m platformio run
python3 -m platformio run --target upload
```

After flashing, open the device settings, tap **PAIR**, and connect to `Vibe Watch #n` from macOS Bluetooth settings.

## Disclaimer

This is an independent experimental compatibility project. Third-party manufacturer and model names are intentionally shown as `**********`. It is not official M5Stack firmware.
