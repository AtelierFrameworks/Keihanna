#include "Sound.h"


void Sound::setInstrument(){
	for (int i = 0; i < 10; i++) {
		sprintf(soundTitle, "piano%d.mp3", i);
		sound_piano[i].load(soundTitle);
		sprintf(soundTitle, "xylophone%d.mp3", i);
		sound_xylophone[i].load(soundTitle);
		sprintf(soundTitle, "guitar%d.mp3", i);
		sound_guitar[i].load(soundTitle);
		sprintf(soundTitle, "animal%d.mp3", i/2);
		sound_animal[i].load(soundTitle);
		sprintf(soundTitle, "magic%d.mp3", i/2);
		sound_magic[i].load(soundTitle);
	}
}

void Sound::manage(int _inst,int _tone){
	switch (_inst) {
	case 0:
		piano(_tone);
		break;
	case 1:
		xylophone(_tone);
		break;
	case 2:
		guitar(_tone);
		break;
	case 3:
		animal(_tone);
		break;
	case 4:
		magic(_tone);
		break;
	}
}

void Sound::piano(int _tone) {
	sound_piano[_tone].play();
}
void Sound::xylophone(int _tone) {
	sound_xylophone[_tone].play();
}
void Sound::guitar(int _tone) {
	sound_guitar[_tone].play();
}
void Sound::animal(int _tone) {
	sound_animal[_tone].play();
}
void Sound::magic(int _tone) {
	sound_magic[_tone].play();
}

