#include <SFML/Graphics.hpp>

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Shapes");

    // Define a green circle
    sf::CircleShape circle(50); // Radius of 50 pixels
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(100, 250); // Position on the window

    // Define a red square
    sf::RectangleShape square(sf::Vector2f(100, 100)); // Size 100x100 pixels
    square.setFillColor(sf::Color::Red);
    square.setPosition(350, 250); // Position on the window

    // Define a blue triangle
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(100, 0));
    triangle.setPoint(2, sf::Vector2f(50, 100));
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(600, 250); // Position on the window

    // Create Image Texture and sprite
    sf::Texture outscal_texture;
    outscal_texture.loadFromFile("assets/textures/outscal_logo.png");
    sf::Sprite outscal_sprite;
    outscal_sprite.setTexture(outscal_texture);
    outscal_sprite.setPosition(350, 0); // Position
    outscal_sprite.setRotation(45); // Rotation in degrees
    outscal_sprite.setScale(0.4, 0.4); // Scale factor

    // Create Text
    sf::Font font;
    font.loadFromFile("assets/fonts/OpenSans.ttf");
    sf::Text text("SFML is Awesome!!", font, 50);
    text.setPosition(200, 500); // Position
    text.setFillColor(sf::Color::White);

    // Main loop to display the window and shapes
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the shapes
        window.draw(circle);
        window.draw(square);
        window.draw(triangle);

        // Draw the sprite
        window.draw(outscal_sprite);

        // Draw the text
        window.draw(text);

        // Render whatever is drawn
        window.display();
    }

    return 0;
}
