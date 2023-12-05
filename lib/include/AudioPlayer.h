//
// Created by Alex Chen on 12/5/23.
//

#ifndef BATTLESHIP_FINALPROJECT_AUDIOPLAYER_H
#define BATTLESHIP_FINALPROJECT_AUDIOPLAYER_H


#include <string>
#include "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/lib/stb/minaudio.h"


class AudioPlayer {
public:
    AudioPlayer();
    AudioPlayer(ma_engine* engine);
    ~AudioPlayer();

    void play(const std::string& filePath);
    void setVolume(float volume);

private:
    ma_engine* engine;  // Pointer to an engine
    bool ownsEngine;    // Indicates whether this object owns the engine
};




#endif //BATTLESHIP_FINALPROJECT_AUDIOPLAYER_H
