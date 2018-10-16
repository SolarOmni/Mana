#pragma once
#include <iostream>
#include <map>
#include "SDL.h"
#ifndef __TextureManager__
#define __TextureManager__

class TextureManager {

public:

	static TextureManager* Instance() {
		if (s_Instance == 0) {
			s_Instance = new TextureManager();
			return s_Instance;
		}
		else return s_Instance;
	}

	bool Load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void Draw(std::string id, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawRegion(std::string id, int p_srcX, int p_srcY, int p_Width, int p_Height, int p_destX, int p_destY, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager() {}
	~TextureManager() {}

	static TextureManager* s_Instance;
	std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif // !__TextureManager__
