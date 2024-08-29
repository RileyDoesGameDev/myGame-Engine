#pragma once
#include <fmod.hpp>
#include <map>
#include <string>

class Audio
{
public:
	Audio() = default;
	~Audio() = default;

	bool Initialize();
	void Shutdown();
	void Update();
	
	
	friend class AudioSource;
	friend class AudioClip;

	bool AddSound( const std::string& name);
	bool PlaySound(std::string& name);
private:
	FMOD::System* m_audio{ nullptr };
	std::map<std::string, FMOD::Sound*> m_sounds;


};