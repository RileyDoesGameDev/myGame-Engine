#pragma once
#include "RenderComponent.h"
#include "Renderer/Texture.h"
#include "Framework/Object.h"
class TextureComponent : public RenderComponent
{
public:
	CLASS_DECLARATION(TextureComponent)
	CLASS_PROTOTYPE(TextureComponent)

	void Initialize() override;
	void Update(float dt) override;
	void draw(Renderer& renderer) override;

public:
	std::string textureName;
	Rect Source; 
	res_t <Texture> texture;

};