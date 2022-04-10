#include "Rhine.h"

class Game : public Rhine::DXApp
{
public:
	Game()
	{

	}
	~Game()
	{

	}
};

Rhine::DXApp* Rhine::CreateDXApp()
{
	return new Game();
}