#pragma once
#include "Framework/Game.h"
#include "Events/EventSystem.h"

#include <memory>

class RythmGame : public Game
{
public:
	RythmGame() = default;
	RythmGame(Engine* engine) : Game{ engine } {}

	// Inherited via Game
	bool Initialize() override;
	void Shutdown() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;


private:
	std::unique_ptr<class Scene> m_scene;



};