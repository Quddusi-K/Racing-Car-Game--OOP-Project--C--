# Multiplayer Car Racing Game

## Overview

This is a **Multiplayer Car Racing Game** built using the **SFML (Simple and Fast Multimedia Library)**. The game features a racing environment where players can control their cars, collect coins, and compete for the highest score. It includes realistic animations, sound effects, and a smooth user experience.

### Game Logic and Architecture

The game leverages the **State Design Pattern** to manage different states like game start, gameplay, and game over. Each component is modularized into separate classes such as `Road`, `Rotate`, `Score`, and `Sound`. This approach ensures scalability and maintainability.

Key highlights:

- **State Management:** The game transitions smoothly between different states using flags and clock-based timing.
- **Collision Detection:** Detects collisions between the player's car and collectible coins to trigger score updates and sound effects.
- **Dynamic Assets:** Uses SFML's sprite and texture classes to render game objects dynamically.

---

## Features

1. **Multiplayer Support:**
   - Two players can play simultaneously.

2. **Realistic Animations:**
   - Rotating coins.
   - Dynamic movement of cars and the road.

3. **Score System:**
   - Players can collect coins to increase their score.

4. **Sound Effects:**
   - Includes sounds for collecting coins, starting the game, and ending the game.

5. **Seamless Gameplay:**
   - Smooth road scrolling and collision detection.

---

## How to Compile and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/Quddusi-K/Racing-Car-Game--OOP-Project--C--/tree/Sound_Background
   ```

2. Navigate to the project directory:

   ```bash
   cd Racing-Car-Game--OOP-Project--C--
   ```

3. Compile the project:

   ```bash
   g++ main.cpp Road.cpp Rotate.cpp Score.cpp Sound.cpp -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -o car-racing
   ```

4. Run the game:

   ```bash
   ./car-racing
   ```

---

## Gameplay Instructions

1. **Controls:**
   - Player 1:
     - Move left: `A`
     - Move right: `D`
   - Player 2:
     - Move left: `Left Arrow`
     - Move right: `Right Arrow`

2. **Objective:**
   - Avoid obstacles and collect coins to score points.

3. **Winning Condition:**
   - The player with the highest score wins.

---

## File Structure

```
.
├── main.cpp          // Entry point of the game
├── Road.hpp          // Road class declaration
├── Road.cpp          // Road class implementation
├── Rotate.hpp        // Rotate class declaration
├── Rotate.cpp        // Rotate class implementation
├── Score.hpp         // Score class declaration
├── Score.cpp         // Score class implementation
├── Sound.hpp         // Sound class declaration
├── Sound.cpp         // Sound class implementation
├── Assets/           // Contains textures, sounds, and fonts
│   ├── PNG/          // Road and coin textures
│   ├── Sound/        // Audio files for the game
│   └── font/         // Fonts used for text rendering
└── README.md         // Project documentation
```

---

## Assets Used

1. **Textures:**
   - Road and coin textures are stored in the `Assets/PNG/` folder.

2. **Sounds:**
   - Coin collection, game start, and game over sounds are stored in the `Assets/Sound/` folder.

3. **Fonts:**
   - The `press2p.ttf` font used for displaying scores is stored in the `Assets/font/` folder.

---

## Future Enhancements

1. Add more player support.
2. Introduce new levels with increased difficulty.
3. Add obstacles and power-ups.
4. Implement a menu system.

---

## Contributing

Contributions are welcome! If you'd like to improve this project:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add feature-name"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a pull request.

---

## Acknowledgments

- **SFML Library** for providing an intuitive multimedia framework.
- Inspiration from classic arcade racing games.

---

**Enjoy Racing!**

