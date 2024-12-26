# 🎮 so_long

**so_long** is a small 2D game project developed as part of the 42 School curriculum. This project focuses on creating a simple game using a graphics library to practice event handling, rendering, and basic game logic.

---

## 🛠️ Features

### **Mandatory Part**
- Implements a 2D game where the player navigates a character through a map to collect collectibles and reach an exit.
- Key features:
  - **Map Parsing**: Reads the game map from a `.ber` file.
  - **Player Movement**: Allows the player to move in four directions using keyboard inputs.
  - **Collectibles**: Requires the player to collect all items before reaching the exit.
  - **Game Over Conditions**: Handles win and loss conditions.
- Uses **MLX42** for rendering and event handling.

### **Bonus Part**
- **Enemy AI**: Adds enemies to the map that move and challenge the player.
- **Animations**: Implements animations for the player and collectibles.
- **Enhanced Map Features**:
  - Support for larger maps with scrolling.
  - Additional tile types for varied gameplay.
- **HUD and Score Display**: Displays the player's score and remaining collectibles.

---

## 🎯 Objectives

- Learn to use a graphics library for rendering.
- Develop an understanding of event handling and game loops.
- Enhance problem-solving skills by parsing and validating game maps.
- Practice memory management and error handling in a dynamic environment.

---

## 🚀 Usage

### Compilation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/so_long.git
   ```
2. Compile the game:
   ```bash
   make
   ```

### Running the Game
Run the program with the following syntax:
```bash
./so_long path/to/map.ber
```
Example:
```bash
./so_long maps/level1.ber
```

### Controls
- **W/A/S/D**: Move the player up, left, down, and right.
- **ESC**: Exit the game.

---

## 🗺️ Map Format
- The map must be a `.ber` file containing the following elements:
  - `1`: Wall
  - `0`: Empty space
  - `P`: Player start position
  - `C`: Collectibles
  - `E`: Exit
- The map must be rectangular, surrounded by walls, and contain at least one player, one exit, and one collectible.

Example:
```
111111
1P0C01
1000E1
111111
```

---

## 📜 License

This project is part of the 42 School curriculum. All rights reserved.

