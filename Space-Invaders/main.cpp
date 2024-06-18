#include <iostream>

#include "Header/GameService.h"

using namespace std;

/*
class Player {
private:
    int playerHealth = 3;
    int playerSpeed = 2;
    sf::Vector2f playerPosition = sf::Vector2f(100.0f, 500.0f);
    int playerScore = 0;

public:
    Player() {
        cout << "Default Constructor called for Player!\n";
    };

    Player(int initialHealth, int speed) {
        playerHealth = initialHealth;
        playerSpeed = speed;

        cout << "Player Object is created using custom constructor with Initial Health: " << initialHealth << " and Speed: " << speed << ".\n";
    }
    ~Player() { 
        cout << "Player Object with Speed " << playerSpeed << " is getting destroyed.\n";
    }

    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    
    // Public Getter & Setter methods
    int GetScore() const {
        return playerScore;
    }
    void SetScore(int newScore) {
        playerScore = newScore;
    }

    int GetSpeed() const {
        return playerSpeed;
    }

    sf::Vector2f GetPosition() const {
        return playerPosition;
    }

    // Other methods
    void TakeDamage() {};
    void Move(float offsetX) {
        playerPosition.x += offsetX;
    };
    void ShootBullets() {};
};

*/

int main()
{
    /*
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    // Create a Player object
    Player player(5, 2);

    player.playerTexture.loadFromFile("assets/textures/player_ship.png"); // Load the player ship texture

    player.playerSprite.setTexture(player.playerTexture);  // Set the player sprite variable 

    // Main loop to display the window and shapes
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.Move(-1.0 * player.GetSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.Move(1.0 * player.GetSpeed());
        }

        // Clear the window
        window.clear(sf::Color::Blue);

        player.playerSprite.setPosition(player.GetPosition()); // Set the position of the player sprite

        window.draw(player.playerSprite);    // Draw the player sprite

        // Render whatever is drawn
        window.display();
    }
    */

    GameService* gameService = new GameService();

    gameService->Ignite();

    while (gameService->IsRunning())
    {
        // Handle events
        sf::Event event;
        while (gameService->GetGameWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gameService->GetGameWindow()->close();
        }
        gameService->Update();
        gameService->Render();
    }

    return 0;
}
