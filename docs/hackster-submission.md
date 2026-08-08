# Vibe Watch — Hackster Submission Kit

## Title

**Vibe Watch: A Tactile Controller for Vibe Coding**

## Elevator Pitch

A wearable M5Stack controller for monitoring AI agents, approving actions, toggling Plan mode, and using push-to-talk.

## Project Story

### Why I Built It

Running multiple AI-agent sessions in parallel has become normal in Vibe Coding. That creates a new interaction problem: I want to know the instant a task finishes, select the right session, and speak the next prompt without searching across windows or returning to the keyboard.

After purchasing an OpenAI Codex Micro, I was inspired by the idea of dedicated hardware for AI coding. I wanted to explore whether the same interaction could become smaller, more glanceable, and more expressive. The round M5Stack StopWatch already combines a touchscreen, physical buttons, speaker, vibration motor, Bluetooth, and battery in one compact controller. I also adapted M5Stack's M5Stick watch accessory kit into a wrist mount, making agent status and voice input immediately available while moving around. Together, they became the natural foundation for Vibe Watch.

### The Experience

Vibe Watch starts with a fading animated identity, an original NES-style chiptune, and a battery bar that grows to the measured charge level. It immediately feels like a purpose-built product rather than a generic development board.

The main Agent layer places six live agent indicators around the round display. Their color, brightness, and animation reflect host-provided state. Tapping an agent—or using the physical button—moves the selection ring with a fast spring animation. The motion overshoots slightly and settles onto the target, making navigation feel physical and readable.

Pressing both hardware buttons changes the interface into the Action layer: **FAST, NG, OK, PLAN, and AI**. Colored rails visually connect the real buttons to the on-screen NG and OK controls. The left orange button rejects; the right blue button approves. Their distinct descending and ascending square-wave sounds make the result recognizable without looking at the display. PLAN is a visible toggle, while the large center control remains available for push-to-talk.

Settings keep the experience personal without adding desktop configuration. Users can select one of three Bluetooth device identities, pair the controller, set sound volume, adjust vibration strength, and enable or disable haptics for agent-state changes. Preferences survive a restart.

### What Makes It Different

Vibe Watch is not a macro pad with a decorative screen. The complete M5Stack controller participates in the interaction:

- The circular touchscreen turns six concurrent agents into a spatial interface.
- The physical buttons provide eyes-free approve/reject decisions.
- Bluetooth Low Energy HID carries controls and live visual state wirelessly.
- The speaker uses distinct square- and triangle-wave feedback, including an original chiptune startup.
- The vibration motor confirms touch and can signal state changes silently.
- The battery and compact enclosure make the interface portable.

The result is a tiny AI cockpit whose UI, sound, motion, and haptics all communicate the same state.

### Hardware Used

| Hardware | Quantity | Purpose |
|---|---:|---|
| M5Stack StopWatch | 1 | ESP32-S3 controller, round touchscreen, buttons, speaker, haptics, BLE, and battery |
| M5Stack Watch Accessory Kit for M5Stick Series | 1 | Nylon strap and modified Watch Mount Accessory |
| High-strength double-sided tape | 1 piece | Attaches the modified mount to the StopWatch |
| macOS computer with Bluetooth | 1 | AI coding host |

### Wrist-Mount Modification

The official watch kit is designed for rectangular M5Stick devices. I repurposed its plastic Watch Mount Accessory as a flat adapter plate for the round StopWatch:

1. Remove the plastic mount from the strap and keep it separate from the StopWatch while cutting.
2. Use flush cutters or small nippers to cut away the raised M5Stick retaining hooks, removing a little material at a time.
3. Remove burrs and sharp edges until the mounting face is flat.
4. Clean and completely dry the mount and the rear of the StopWatch.
5. Cut high-strength double-sided tape so it remains inside the mount footprint and does not obstruct buttons, connectors, or openings.
6. Center the mount on the rear of the StopWatch, press firmly, and wait for the tape manufacturer's specified bonding time.
7. Reinstall the nylon strap and pull-test the assembly before wearing it.

This minimal modification preserves the StopWatch case while adding a practical wearable form. The fabrication photos show the unmodified kit parts, removal of the retaining hooks, and the finished adhesive-mounted assembly.

### How the M5Stack Controller Is Used

The M5Stack StopWatch is the entire product interface. Its ESP32-S3 runs the firmware, stores preferences, renders every animation, samples battery state, drives audio and vibration, reads touch and hardware buttons, and maintains the BLE HID connection. This is a deliberate use of the controller as an integrated human–AI interface—not as a passive display attached to another microcontroller.

### Build Instructions

Install PlatformIO Core, then clone and build the public repository:

```sh
git clone https://github.com/GOROman/vibewatch.git
cd vibewatch
python3 -m platformio run
```

Connect the StopWatch and upload:

```sh
python3 -m platformio run --target upload
```

Open Settings on Vibe Watch, choose a device slot, tap **PAIR**, and connect to `Vibe Watch #n` in macOS Bluetooth settings.

Source code and automated build status: <https://github.com/GOROman/vibewatch>

### Impact

Vibe Watch removes tiny but frequent interruptions from AI-assisted coding. It keeps multi-agent status visible, turns approval into an immediate physical decision, and makes voice input accessible without searching through desktop UI. The same approach can extend beyond coding to accessibility tools, creative software, multi-agent operations, and any workflow where attention is more valuable than screen space.

## 60-Second Demo Script

Record in a quiet space so the startup chiptune and OK/NG sounds are audible. Keep the computer screen and device in the same frame whenever possible.

### Production Setup

- **Camera:** DJI OSMO Pocket 4P
- **Editor:** CapCut
- Record landscape at 4K/30 fps; use 1/60 shutter if manual exposure is available.
- Lock white balance, exposure, and focus before each close-up so the round display does not pulse or shift color.
- Capture a separate quiet take of the startup, OK, and NG sounds, then preserve those real sounds in the edit.
- Edit on a 16:9 timeline. Prefer clean cuts over effects, keep captions to six words or fewer, and export a 1080p or 4K H.264 MP4.

| Time | Shot | Action / Message |
|---:|---|---|
| 0–5 s | Tight hero shot | Power on: show the VIBEWATCH fade, chiptune, and animated battery bar. |
| 5–12 s | Device plus host | Show six live agent colors. Caption: “Six agents, one glance.” |
| 12–19 s | Tight device shot | Cycle 1–6 with the physical button; capture the spring selection motion. |
| 19–27 s | Fingers and device | Press both buttons to transform into the Action layer. |
| 27–36 s | Top half close-up | Press left NG, then right OK. Capture colored rails, white active state, distinct sounds, and vibration movement. |
| 36–43 s | Bottom control close-up | Tap PLAN twice so the toggle visibly changes. |
| 43–51 s | Center control and host | Hold push-to-talk and show the host responding. |
| 51–57 s | Settings close-up | Sweep SE volume and Vibe strength; show the state-change Vibe checkbox. |
| 57–60 s | Clean hero shot | End on Agent view with caption: “Vibe Watch — stay in the flow.” |

## Photo Checklist

Use a clean background and avoid screen reflections. A phone camera is sufficient if exposure is locked on the display.

1. Hero image: use [`docs/images/vibe-watch-hero.jpg`](images/vibe-watch-hero.jpg), the finished 4:3 wrist shot.
2. Straight-on Agent layer showing all six numbered controls.
3. Action layer showing FAST, NG, OK, PLAN, AI, and both colored hardware links.
4. Settings screen showing sound, vibration strength, and state-change haptics.
5. Fabrication sequence: kit parts, cutting the retaining hooks, double-sided tape, and the completed rear mount.
6. Vibe Watch beside the coding host to establish scale and wireless use.
7. Startup frame with VIBEWATCH v1.0 and the battery progress bar.

## Final Submission Checklist

- Upload the hero image first; it must remain readable as a small card thumbnail.
- Embed the 60-second demo near the top of the Hackster story.
- Add at least four supporting photos with one-sentence captions.
- Link <https://github.com/GOROman/vibewatch> and confirm its build badge is green.
- Set the Hackster project to **Public / Discoverable** and 100% complete.
- Submit the published Hackster URL through the official M5Stack form before the deadline.
