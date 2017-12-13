#include "StringHelper.h"
#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"
#include <memory>
#include <future>


class Game : private sf::NonCopyable
{
public:
	Game();
	~Game();
	void								run();

private:
	void								processEvents();
	void								update(sf::Time elapsedTime);
	void								render();
	void								updateStatistics(sf::Time elapsedTime);


	float								zoom;
	float								moveY;
	float								moveX;

	
private:
	static const sf::Time				TimePerFrame;

	sf::RenderWindow					mWindow;
	sf::View							mView;

	sf::Font							mFont;
	sf::Text							mStatisticsText;
	sf::Time							mStatisticsUpdateTime;
	
	std::unique_ptr<ParticleSystem>		particleSystem;


	std::size_t							mStatisticsNumFrames;
};
