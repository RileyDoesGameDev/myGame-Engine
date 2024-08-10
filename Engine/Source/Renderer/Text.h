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
	~Text();

	void SetFont(res_t<Font> font) { m_font = font; }
	bool Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, int x, int y);

private:
	res_t<Font> m_font;
	SDL_Texture* m_texture{ nullptr };
};