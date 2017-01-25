#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

/// <summary>
/// Written by Peter Lowe
/// Jan 2017
/// 
/// 24/1/17 7:00 - 9:30  2:30
/// 25/1/17 16:00- 
/// </summary>

#include "Game.h"


int main()
{
	Game game;
	game.run();
	return EXIT_SUCCESS;
}