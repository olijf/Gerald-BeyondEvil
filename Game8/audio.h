#include <SFML/Audio.hpp> 
#include <iostream>

#pragma once

class audio {
private:
	sf::Music music;
	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer_spawn;
	sf::SoundBuffer buffer_up;
	sf::Sound sound;
	sf::Sound sound_spawn;
	sf::Sound sound_up;
	
public:
	audio();
	~audio();

	void play_background_music();

	void spawn_swordsman();

	void spawn_archer();

	void spawn_horseman();

	void unit_down();

	void lumber_up();

	void farm_up();

	void mine_up();

	void we_are_under_attack();
};