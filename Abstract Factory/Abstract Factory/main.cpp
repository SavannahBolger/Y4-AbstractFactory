#include <iostream>
#include <SFML/Graphics.hpp>

/// <summary>
/// 
/// </summary>

class DrawAPI
{
public:
	DrawAPI() {};
	~DrawAPI() {};
	virtual void Draw() = 0;
};

class DrawImpl : public DrawAPI
{
public:
	void Draw()
	{
		std::cout << "Draw Impl" << std::endl;
	}
};

class Character
{
public:
	Character() {};
	~Character() {};
	virtual void Draw() = 0;
};

class Player : public Character
{
public:
	Player(DrawAPI* api) { this->api = api; };
	void Draw() { api->Draw(); }
private:
	DrawAPI* api;
};

int main()
{
	DrawAPI* api = new DrawImpl();
	Character* character = new Player(api);
	character->Draw();
	std::cin.get();

	system("pause");
	return 0;
}