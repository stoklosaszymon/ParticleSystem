#include "Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(1400, 1000), "SFML Application", sf::Style::Default)
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, particleSystem(std::make_unique<ParticleSystem>(100'000))
	, mView()
{
	mView.setCenter(sf::Vector2f(mWindow.getSize().x / 2, mWindow.getSize().y / 2));
	mView = mWindow.getDefaultView();
	mFont.loadFromFile("Media/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(30);
}

Game::~Game() {
	
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				mWindow.close();
			break;

			case sf::Event::MouseButtonPressed:
				particleSystem->btnPressed = true;
			break;

			case sf::Event::MouseButtonReleased:
				particleSystem->btnPressed = false;
			break;

			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Space) {
				particleSystem->artificialForce();
				}

			else if (event.key.code == sf::Keyboard::Up) {
				mView.move(0, -100);
			}

			else if (event.key.code == sf::Keyboard::Down) {
				mView.move(0, 100);;
			}

			else if (event.key.code == sf::Keyboard::Left) {
				mView.move(-100, 0);
			}

			else if (event.key.code == sf::Keyboard::Right) {
				mView.move(100, 0);
			}

			mWindow.setView(mView);
			}
			break;

		case sf::Event::MouseWheelMoved:
			auto mouseWheel = event.mouseWheel.delta;
			if ( mouseWheel < 0) {
				zoom += 100;
			}
			else {
				zoom -= 100;
			}

			mView.setSize(mWindow.getSize().x + zoom, mWindow.getSize().y + zoom);
			mWindow.setView(mView);
			break;
		}
	}
}



void Game::update(sf::Time elapsedTime)
{
	particleSystem->mousePosition = { float(sf::Mouse::getPosition(mWindow).x), float(sf::Mouse::getPosition(mWindow).y) };
	particleSystem->updatePosition(elapsedTime.asMilliseconds());
	particleSystem->mouseMove();
}

void Game::render()
{
	mWindow.clear();

	for (auto &particle : particleSystem->particles) {
		particle->draw(mWindow, sf::RenderStates::Default);
	}

	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us" + "\n" +
			"Number of particles = " + toString(particleSystem->particles.size()));
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}









