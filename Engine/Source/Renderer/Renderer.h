#pragma once
#include<SDL.h>
#include<string>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <memory>
#include "Math/Rect.h"
class Texture;

class Renderer
{
public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();

	bool CreateWindow(std::string title, int width, int height);
	void BegineFrame();
	void EndFrame();
	void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	int GetWidth()const { return m_width; }
	int GetHeight() const{ return m_height; }
	friend class Text;
	void DrawLine(int x1, int y1, int x2, int y2);
	void DrawLine(float x1, float y1, float x2, float y2);
	void DrawPoint(int x, int y);
	void DrawPoint(float x, float y);
	void DrawRect(int x, int y, int w, int h);
	void DrawRect(float x, float y, float w, float h);
	friend class Texture;

	void DrawTexture(std::weak_ptr<Texture>texture, float x, float y, float angle); 
	void DrawTexture(std::weak_ptr<Texture>texture, const struct Transform& transform, bool hflip = false);
	void DrawTexture(std::weak_ptr<Texture>texture, const struct Transform& transform, Rect& source,bool hflip = false);

private:
	SDL_Renderer* m_renderer = nullptr;
	SDL_Window* m_window = nullptr;
	int m_width = 0;
	int m_height = 0;
};
