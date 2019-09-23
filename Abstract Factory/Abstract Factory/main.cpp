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
private:
};

class Player : public Character
{
public:
	Player(DrawAPI* api) { this->api = api; };
	void Draw() { api->Draw(); }
private:
	DrawAPI* api;
	Character* character;
};

int main()
{
	DrawAPI* api = new DrawImpl();
	/*for (size_t i = 0; i < 5; i++)
	{
		Character* character = new Player(api);
		character->Draw();
		std::cout << character << std::endl;
	}*/
	std::vector<Character*> characters;
	for (int i = 0; i < 5; i++)
	{
		characters.push_back(new Player(api));
	}
	for (int i = 0; i < 5; i++)
	{
		characters[i]->Draw();
		std::cout << characters[i] << std::endl;
	}
	system("pause");
	return 0;
}