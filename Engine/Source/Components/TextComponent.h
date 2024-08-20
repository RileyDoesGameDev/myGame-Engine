#pragma once
#include "RenderComponent.h"

class TextComponent : public RenderComponent
{
	CLASS_DECLARATION(TextComponent)
	// Inherited via RenderComponent
	void Initialize() override;
	void Update(float dt) override;
	void draw(Renderer& renderer) override;

	void SetText(std::string text);

public:
	std::string text;
	std::string fontName;
	int fontSize = 8;
	Color color{ 1,1,1,1, };

private:
	std::unique_ptr<class Text> m_text;
	bool textChanged = true;
};