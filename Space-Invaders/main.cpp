#include <iostream>
#include <SFML/Graphics.hpp>

class Player {
private:
    int playerScore = 0;
    int health = 3;
    int movementSpeed = 10;
    sf::Vector2f position = sf::Vector2f(100.0f, 100.0f);

public:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    
    // Public Getter & Setter methods
    int GetScore() const {
        return playerScore;
    }
    void SetScore(int newScore) {
        playerScore = newScore;
    }

    // Other methods
    void TakeDamage() {};
    void Move() {};
    void ShootBullets() {};
};

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    // Main loop to display the window and shapes
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Blue);

        // Render whatever is drawn
        window.display();
    }

    // Create a Player object
    Player player;

    // Access the private variable using the public getter
    std::cout << "Player Score: " << player.GetScore() << "\n";

    // Modify the variable using the public setter
    player.SetScore(100);

    // Access the modified variable using the public getter
    std::cout << "Player Modified Score: " << player.GetScore() << "\n";

    return 0;
}
