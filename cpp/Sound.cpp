#include "Sound.h"

Sound::Sound() {
    music.setVolume(100); 
    music.setLoop(false); 
}

Sound::~Sound() {
    stop();
}

void Sound::loadMusic(const std::string& filename) {
    if (!music.openFromFile(filename)) {
    }
}

void Sound::play() {
    music.play();
}

void Sound::pause() {
    music.pause();
}

void Sound::stop() {
    music.stop();
}

void Sound::setLoop(bool loop) {
    music.setLoop(loop);
}
