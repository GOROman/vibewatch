#include "sound.h"

#include <algorithm>

#include <Arduino.h>
#include <M5Unified.h>

namespace sound {
namespace {

constexpr int kBpm = 200;
constexpr int kNote32Ms = 60000 / kBpm / 8;
// The StopWatch speaker saturates earlier than the Cardputer speaker.
// Keep the original LLMCardputer square samples, but leave amplifier headroom.
constexpr std::uint8_t kSquareVolumePercent = 55;

struct Note {
    int frequency;
    int durationMs;
};

// Waveforms and melodies copied from GOROman's LLMCardputer src/sound.cpp.
constexpr std::uint8_t kSquareWave[] = {0, 0, 0, 0, 127, 127, 127, 127};

constexpr std::uint8_t kTriangleWave[] = {
    136, 136, 136, 136, 153, 153, 153, 153, 170, 170, 170, 170, 187, 187, 187, 187,
    204, 204, 204, 204, 221, 221, 221, 221, 238, 238, 238, 238, 255, 255, 255, 255,
    255, 255, 255, 255, 238, 238, 238, 238, 221, 221, 221, 221, 204, 204, 204, 204,
    187, 187, 187, 187, 170, 170, 170, 170, 153, 153, 153, 153, 136, 136, 136, 136,
    119, 119, 119, 119, 102, 102, 102, 102, 85,  85,  85,  85,  68,  68,  68,  68,
    51,  51,  51,  51,  34,  34,  34,  34,  17,  17,  17,  17,  0,   0,   0,   0,
    0,   0,   0,   0,   17,  17,  17,  17,  34,  34,  34,  34,  51,  51,  51,  51,
    68,  68,  68,  68,  85,  85,  85,  85,  102, 102, 102, 102, 119, 119, 119, 119,
};

constexpr Note kStartMelody[] = {
    {261, kNote32Ms}, {0, kNote32Ms}, {392, kNote32Ms}, {0, kNote32Ms},
    {294, kNote32Ms}, {0, kNote32Ms}, {440, kNote32Ms}, {-1, -1},
};

void playTriangleWave(float frequency, std::uint32_t durationMs) {
    if (frequency <= 0.0f) {
        M5.Speaker.stop(1);
        return;
    }
    M5.Speaker.tone(frequency, durationMs, 1, true, kTriangleWave, sizeof(kTriangleWave), false);
}

}  // namespace

void playSquare(float frequency, std::uint32_t durationMs, std::uint8_t volume) {
    if (volume == 0) {
        return;
    }
    const auto squareVolume = static_cast<std::uint8_t>(
        std::max(1U, (static_cast<unsigned>(volume) * kSquareVolumePercent + 50U) / 100U));
    M5.Speaker.setVolume(squareVolume);
    M5.Speaker.tone(frequency, durationMs, 0, true, kSquareWave, sizeof(kSquareWave), false);
}

void playTriangle(float frequency, std::uint32_t durationMs, std::uint8_t volume) {
    if (volume == 0) {
        return;
    }
    M5.Speaker.setVolume(volume);
    playTriangleWave(frequency, durationMs);
}

void playEffect(Effect effect, std::uint8_t volume, std::uint8_t tempoMultiplier) {
    if (volume == 0) {
        return;
    }
    tempoMultiplier = std::max<std::uint8_t>(1, tempoMultiplier);
    M5.Speaker.setVolume(volume);
    constexpr int kStartNoteCount = sizeof(kStartMelody) / sizeof(kStartMelody[0]) - 1;
    for (int i = 0; i < kStartNoteCount; ++i) {
        const int noteIndex = effect == Effect::Start ? i : kStartNoteCount - 1 - i;
        const auto& note = kStartMelody[noteIndex];
        const int durationMs = std::max(1, note.durationMs / tempoMultiplier);
        playTriangleWave(static_cast<float>(note.frequency), durationMs);
        delay(durationMs);
    }
}

}  // namespace sound
