#pragma once
#include "RenderComponent.h"


class TextComponent : public RenderComponent
{
public:
	TextComponent() = default;

	TextComponent(const TextComponent& other);


	CLASS_DECLARATION(TextComponent)
	CLASS_PROTOTYPE(TextComponent)


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