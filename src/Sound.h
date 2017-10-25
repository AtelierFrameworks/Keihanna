#pragma once
#include"ofMain.h"


class Sound
{
public:
	void setInstrument();
	void manage(int _inst, int _tone);
	void piano(int _tone);
	void xylophone(int _tone);
	void guitar(int _tone);
	void animal(int _tone);
	void magic(int _tone);

	ofSoundPlayer sound_piano[10];
	ofSoundPlayer sound_xylophone[10];
	ofSoundPlayer sound_guitar[10];
	ofSoundPlayer sound_animal[10];
	ofSoundPlayer sound_magic[10];

	char soundTitle[20];
};

