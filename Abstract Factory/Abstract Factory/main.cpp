#include <iostream>
#include <SFML/Graphics.hpp>

/// <summary>
/// 
/// </summary>

class DrawAPI
{
public:
	virtual void Draw() = 0;
};

class DrawImplement : public DrawAPI
{
public:
	void Draw()
	{
		std::cout << "draw api" << std::endl;
	}
};

class Character
{
public:

};

class Player : public Character
{
public:
	Player(DrawAPI* api) { this->api = api; };

private:
	DrawAPI* api;
};


int main()
{

	return 0;
}