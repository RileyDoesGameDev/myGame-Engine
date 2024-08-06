#pragma once

//core
#include "Core/Etimer.h"
#include "Core/Eassert.h"
#include "Core/EFIle.h"




//**systems**
//renderer
#include "Renderer/Texture.h"
#include "Renderer/Renderer.h"
#include "Renderer/ParticleSystem.h"
#include "Renderer/Particle.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Model.h"

//input
#include "Input/Input.h"
//Audio
#include "Audio/Audio.h"
#include "Framework/Actor.h"

#include <fmod.hpp>
#include <memory>

// Resources





class Engine
{
public:
	Engine() = default;
	~Engine() = default;
	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }
	Time& GetTime () { return *m_time; }
	ParticleSystem& GetPS() { return *m_particleSystem; }
	bool Initialize();
	void Shutdown();
	void Update();
	bool IsQuit() const{ return quit; }
private:
	std::unique_ptr<Time> m_time;

	std::unique_ptr<ParticleSystem> m_particleSystem;
	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<Input> m_input;
	std::unique_ptr<Audio> m_audio;
	
	bool quit{ false };
};



