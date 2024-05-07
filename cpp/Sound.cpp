#include "Sound.h"

Sound::Sound() {
    music.setVolume(30);
    music.setLoop(false);
}

Sound::~Sound() {
    music.stop();
}

void Sound::loadMusic(const std::string& filename) {
    if (!music.openFromFile(filename)) {
    }
}


float Sound :: getVolume() const  {
    return this->volume;
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


void Sound::setVolume(int volume1) {
    volume = volume1;
}
