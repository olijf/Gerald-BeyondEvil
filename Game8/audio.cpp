#include "audio.h"

audio::audio() {
	music.setVolume(22);
	music.setLoop(true);
}

audio::~audio(){}

void audio::play_background_music(){
	if(!music.openFromFile("Sounds/Glorious_morning.ogg")){
		std::cout << "can't find Glorious_morning.ogg";
	}
	music.play();
}

void audio::spawn_swordsman(){
	sound_spawn.resetBuffer();
	if(!buffer_spawn.loadFromFile("Sounds/Sword_spawn.wav")){
		std::cout << "can't find Sword_spawn.wav";
	}
	sound_spawn.setBuffer(buffer_spawn);
	sound_spawn.play();
}

void audio::spawn_archer(){
	sound_spawn.resetBuffer();
	if(!buffer_spawn.loadFromFile("Sounds/Archer_spawn.wav")){
		std::cout << "can't find Archer_spawn.wav";
	}
	sound_spawn.setBuffer(buffer_spawn);
	sound_spawn.play();
}

void audio::spawn_horseman(){
	sound_spawn.resetBuffer();
	if(!buffer_spawn.loadFromFile("Sounds/Horse_spawn.wav")){
		std::cout << "can't find Horse_spawn.wav";
	}
	sound_spawn.setBuffer(buffer_spawn);
	sound_spawn.play();
}

void audio::unit_down(){
	sound.resetBuffer();
	if(!buffer.loadFromFile("Sounds/Unit_down.wav")){
		std::cout << "can't find Unit_down.wav";
	}
	sound.setBuffer(buffer);
	sound.play();
}

void audio::lumber_up(){
	sound_up.resetBuffer();
	if(!buffer_up.loadFromFile("Sounds/Axe.wav")){
		std::cout << "can't find Axe.wav";
	}
	sound_up.setBuffer(buffer_up);
	sound_up.play();
}

void audio::farm_up(){
	sound_up.resetBuffer();
	if(!buffer_up.loadFromFile("Sounds/Scythe.wav")){
		std::cout << "can't find Scythe.wav";
	}
	sound_up.setBuffer(buffer_up);
	sound_up.play();
}

void audio::mine_up(){
	sound_up.resetBuffer();
	if(!buffer_up.loadFromFile("Sounds/Pickaxe.wav")){
		std::cout << "can't find Pickaxe.wav";
	}
	sound_up.setBuffer(buffer_up);
	sound_up.play();
}

void audio::we_are_under_attack(){
	sound_up.resetBuffer();
	if(!buffer_up.loadFromFile("Sounds/We_are_under_attack.wav")){
		std::cout << "can't find We_are_under_attack.wav";
	}
	sound_up.setBuffer(buffer_up);
	sound_up.play();
}