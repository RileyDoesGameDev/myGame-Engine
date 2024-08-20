#pragma once
#include <SDL_ttf.h>
#include <string>
#include "Color.h"
#include "Font.h"
#include "Renderer.h"

class Text
{
public:
	Text() = default;
	Text(res_t<Font> font) : m_font{ font } {}
	~Text() = default;

	void SetFont(res_t<Font> font) { m_font = font; }
	bool Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, float x, float y, float angle = 0);
	res_t<Texture> GetTexture() { return m_texture; }
private:
	res_t<Font> m_font;
	res_t<Texture> m_texture{ nullptr };
	
};