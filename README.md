# Space Invaders Game

## Overview

Welcome to the modern twist on the classic Space Invaders game! This project is a culmination of my journey in game development, leveraging C++, SFML, and the MVC architecture to create an engaging and fun gaming experience. Dive into a world where you fend off waves of enemies, collect power-ups, and enjoy smooth animations and graphics.

## Features

- **Modern Visuals**: Enhanced graphics and animations.
- **Classic Gameplay**: Traditional Space Invaders mechanics with new twists.
- **Power-ups**: Various power-ups like health boosts, rapid fire, and shields.
- **Advanced Collision Detection**: Sophisticated collision detection mechanisms.
- **Sound Integration**: Immersive sound effects.

## Learning Outcomes

- **MVC Architecture**: Implemented Model-View-Controller for scalable and maintainable code.
- **Animation and Graphics**: Integrated smooth animations and high-quality graphics.
- **Event Handling**: Responsive and intuitive controls.
- **Object-Oriented Design**: Strengthened understanding of OOP concepts.
- **Game Loop and State Management**: Ensured smooth transitions and gameplay.
- **UI/UX Design**: Created intuitive and engaging user interfaces.

## Project Structure

### Model
- **PlayerModel**: Manages player state and attributes.
- **EnemyModel**: Manages enemy state and attributes.
- **BulletModel**: Maintains bullet state and attributes.
- **PowerupModel**: Maintains power-up state and attributes.
- **BunkerModel**: Maintains bunker state and attributes.

### View
- **PlayerView**: Renders the player.
- **EnemyView**: Renders the enemies.
- **BulletView**: Renders the bullets.
- **PowerupView**: Renders the power-ups.
- **BunkerView**: Renders the bunkers.
- **GameplayView**: Renders the game state.
- **UI Elements**: Includes **ImageView**, **ButtonView**, **TextView**, and **UIView**.

### Controller
- **PlayerController**: Handles player-specific actions and state.
- **EnemyController**: Handles enemy-specific actions and state.
- **BulletController**: Manages bullet-specific actions and state.
  - Specialized controllers: **FrostBulletController**, **LaserBulletController**, **TorpedoController**.
- **PowerupController**: Manages power-up-specific actions and state.
  - Specialized controllers: **OutscalBombController**, **RapidFireController**, **ShieldController**, **TripleLaserController**.
- **BunkerController**: Manages bunker-specific actions and state.
- **GameplayController**: Controls the gameplay logic.
- **UI Controllers**: **MainMenuUIController**, **GameplayUIController**, **SplashScreenUIController**.

### Services
- **GraphicService**: Manages game window and rendering operations.
- **TimeService**: Provides timing and delta-time calculations.
- **EventService**: Handles user input and game events.
- **GameplayService**: Manages core gameplay mechanics.
- **PlayerService**: Manages player-related logic.
- **EnemyService**: Manages enemy-related logic.
- **BulletService**: Manages bullet-related logic.
- **ElementService**: Manages game elements like bunkers.
- **PowerupService**: Manages power-up logic.
- **CollisionService**: Handles collision detection.
  - **ICollider**: Interface for collision detection.
- **UIService**: Manages UI components.
- **AnimationService**: Manages animations.
  - **AnimationSystem**: Core animation system.
    - **AnimationSystemConfig**: Configuration for the animation system.
- **SoundService**: Manages sound effects and music playback.

## How to Play

1. Clone the repository:
    ```bash
    git clone https://github.com/123rishiag/Space-Invaders.git
    cd space-invaders
    ```

2. Build the project using your preferred C++ compiler.

3. Make sure you have SFML installed. You can install SFML using your package manager or from [SFML's official website](https://www.sfml-dev.org/).

4. Run the executable to start the game.

5. Use the keyboard and mouse to control your spaceship, shoot enemies, and collect power-ups.

## Video Demo

[Watch the Video Demo](https://www.loom.com/share/8a682123ab30439f880c1bfcc3e8fa20?sid=acd33274-b28b-472b-b5da-2dc92c35e738)