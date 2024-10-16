#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
using namespace std;
using namespace sf;
using namespace sfp;
int main()
{
	// Create our window and world with gravity 0,1
	RenderWindow window(VideoMode(800, 600), "Bounce");
	World world(Vector2f(0, 1));
	// Create the ball
	PhysicsCircle ball;
	ball.setCenter(Vector2f(300, 100));
	ball.applyImpulse(Vector2f(.2,0));
	ball.setRadius(20);
	world.AddPhysicsBody(ball);
	// Create the floor
	PhysicsRectangle floor;
	floor.setSize(Vector2f(800, 20));
	floor.setCenter(Vector2f(400, 590));
	floor.setStatic(true);
	world.AddPhysicsBody(floor);
	int thudCount(0);
	floor.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		thudCount++;
		cout << "thud " << thudCount << endl;
		
	};
	//Create ceiling
	PhysicsRectangle ceiling;
	ceiling.setSize(Vector2f(800, 20));
	ceiling.setCenter(Vector2f(400, 10));
	ceiling.setStatic(true);
	world.AddPhysicsBody(ceiling);
	ceiling.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		thudCount++;
		cout << "thud " << thudCount << endl;

	};
	//Create side1
	PhysicsRectangle side1;
	side1.setSize(Vector2f(20, 600));
	side1.setCenter(Vector2f(10, 300));
	side1.setStatic(true);
	world.AddPhysicsBody(side1);
	side1.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		thudCount++;
		cout << "thud " << thudCount << endl;
		
	};
	//Create side2
	PhysicsRectangle side2;
	side2.setSize(Vector2f(20, 600));
	side2.setCenter(Vector2f(790, 300));
	side2.setStatic(true);
	world.AddPhysicsBody(side2);
	side2.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		thudCount++;
		cout << "thud " << thudCount << endl;
		
	};
	//Create center
	PhysicsRectangle center;
	center.setSize(Vector2f(100, 100));
	center.setCenter(Vector2f(400, 300));
	center.setStatic(true);
	world.AddPhysicsBody(center);
	int bangCount(0);
	center.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		bangCount++;
		cout << "bang " << bangCount << endl;
		
	};
	Clock clock;
	Time lastTime(clock.getElapsedTime());
	while (true) {
		// calculate MS since last frame
		Time currentTime(clock.getElapsedTime());
		Time deltaTime(currentTime - lastTime);
		int deltaTimeMS(deltaTime.asMilliseconds());
		if (deltaTimeMS > 0) {
			world.UpdatePhysics(deltaTimeMS);
			lastTime = currentTime;
		}
		if (bangCount == 3) {
			exit(0);
		}
		window.clear(Color(0, 0, 0));
		window.draw(ball);
		window.draw(floor);
		window.draw(ceiling);
		window.draw(side1);
		window.draw(side2);
		window.draw(center);
		window.display();
	}
}
