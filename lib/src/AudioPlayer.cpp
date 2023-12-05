//
// Created by Alex Chen on 12/5/23.
//

#define MINIAUDIO_IMPLEMENTATION
#include "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/lib/stb/minaudio.h"
#include "../include/AudioPlayer.h"
#include <iostream>

AudioPlayer::AudioPlayer() : engine(new ma_engine), ownsEngine(true) {
    ma_result result = ma_engine_init(NULL, engine);
    if (result != MA_SUCCESS) {
        std::cerr << "Failed to initialize audio engine." << std::endl;
        delete engine;
        engine = nullptr;
        // Handle error appropriately
    }
}

AudioPlayer::AudioPlayer(ma_engine* engine) : engine(engine), ownsEngine(false) {
    if (this->engine == nullptr) {
        this->engine = new ma_engine;
        ma_result result = ma_engine_init(NULL, this->engine);
        if (result != MA_SUCCESS) {
            std::cerr << "Failed to initialize audio engine." << std::endl;
        }
        ownsEngine = true;
    }
}

AudioPlayer::~AudioPlayer() {
    if (ownsEngine) {
        ma_engine_uninit(engine);
        delete engine;
    }
}


void AudioPlayer::play(const std::string& filePath) {
    ma_engine_play_sound(engine, filePath.c_str(), NULL);
}

void AudioPlayer::setVolume(float volume) {
    ma_engine_set_volume(engine, volume);
}