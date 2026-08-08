#pragma once

#include <cstdint>

namespace llmcardputer_sound {

enum class Effect {
    Start,
    StartReverse,
};

void playSquare(float frequency, std::uint32_t durationMs, std::uint8_t volume);
void playEffect(Effect effect, std::uint8_t volume, std::uint8_t tempoMultiplier = 1);

}  // namespace llmcardputer_sound
