# so_long (MLX42)

**so_long** is a small 2D tile-based game written in C as part of the 42 / Codam curriculum.  
The goal is to load a `.ber` map, render it with textures, move the player on a grid, collect all collectibles, and exit the level.

This implementation uses **MLX42** (a modern MiniLibX alternative) and includes bonus-style features such as:
- an **enemy tile** (`X`) that ends the game on contact,
- **directional player sprites** (up/down/left/right),
- a **step counter** displayed in the window.

---

## 🎮 Gameplay

### Objective
- Collect **all** collectibles (`C`)
- Then reach the exit (`E`) to win

### Tiles
- `1` — Wall (blocked)
- `0` — Floor (walkable)
- `P` — Player start (exactly one)
- `C` — Collectible (at least one)
- `E` — Exit (exactly one)
- `X` — Enemy (instant game over on contact)

### Controls
- `W` — move up
- `A` — move left
- `S` — move down
- `D` — move right
- `ESC` — quit
- Window close button — quit

---

## 📦 Build & Run

### Requirements
- C compiler (`cc`)
- `cmake`
- GLFW / OpenGL dependencies required by MLX42 (platform-dependent)

### Build

    make

The Makefile will:
1. Build `MLX42/` via CMake
2. Build `libft/`
3. Link everything into the final executable: `so_long`

### Run

    ./so_long maps/map.ber

---

## 🗺️ Map format (`.ber`)

Maps are plain text files made of characters listed above.

Validation implemented in this project:
- The map must be **rectangular**
- The map must be surrounded by **walls** (`1`) on all borders
- Must contain:
  - exactly **one** player (`P`)
  - exactly **one** exit (`E`)
  - at least **one** collectible (`C`)

> Note: This implementation validates structure and required elements.  
> (Path solvability validation is not shown in the provided files.)

---

## 🧱 Project structure

All game logic lives in `bonus/` (this repository builds the bonus-style version as `so_long`).

### Entry point
- `bonus/main_bonus.c`
  - Checks arguments (`./so_long <map_file>`)
  - Reads + validates the map
  - Initializes MLX42 window
  - Loads textures
  - Renders the map and player
  - Hooks keyboard & close events
  - Frees resources on exit

### Map reading & parsing
- `bonus/read_map_bonus.c`, `bonus/read_map_bonus_2.c`
  - Reads the entire file into memory
  - Splits it into lines
  - Builds `t_map_data` with `map`, `width`, `height`

### Map validation
- `bonus/valid_map.c`
  - `check_walls` — borders must be `1`
  - `check_player_and_exit` — exactly one `P` and one `E`
  - `check_collectibles` — at least one `C`
  - `check_rectangular` — all lines must have equal length

### Rendering
- `bonus/render_map_bonus.c`
  - Draws the tilemap (walls/floor/collectibles/exit/enemy)
  - Draws the player sprite depending on last move direction
  - Renders the step counter overlay

### Input & movement
- `bonus/key_pressed_bonus.c`
  - Tracks key press/release states
  - `ESC` or window close -> quit

- `bonus/move_player_bonus.c`
  - Computes next position
  - Checks collisions:
    - wall -> blocked
    - collectible -> collected
    - enemy -> game over
  - Updates steps and redraws
  - Checks win condition (standing on `E` with 0 collectibles left)

### Textures
- `bonus/load_textures_bonus.c`, `bonus/load_textures_bonus_2.c`
  Loads PNG textures from `textures/`:
  - wall, floor, collectible, exit, enemy
  - player sprites (up/down/left/right)

- `bonus/free_textures_bonus.c`, `bonus/free_textures_bonus_2.c`
  Properly frees MLX42 textures on exit.

### Helpers / utilities
- `bonus/utils_bonus.c`
  - `print_error` — prints message and exits
  - `check_collision` — handles walls/collectibles/enemy
  - `update_steps_display` — updates the "Steps: N" overlay

- `bonus/ft_utils.c`
  Small string helpers used in file reading/parsing.

---

## ⚙️ How it works (high-level)

1. **Load map**
   - Read `.ber` into a string buffer
   - Split into lines -> `char **map`

2. **Validate map**
   - Rectangular shape
   - Wall borders
   - Exactly 1 player and 1 exit
   - At least 1 collectible

3. **Initialize game**
   - Create MLX42 window
   - Load PNG textures
   - Count collectibles and find player start position

4. **Render**
   - Draw each tile as an image
   - Draw player sprite based on last direction
   - Update on-screen step text after each move

5. **Game loop**
   - WASD moves the player
   - `C` decreases collectible count
   - `X` ends the game immediately
   - `E` ends the game only after collecting all `C`

---

## ▶️ Example maps

### Basic

    111111
    1P0C01
    100001
    1C0E01
    111111

### With enemy (`X`)

    111111
    1P0C01
    100001
    1CXE01
    111111

---

## 🧠 What I learned

- Working with a lightweight graphics framework (MLX42)
- Parsing and validating a grid-based map format
- Managing resources (textures, images, memory) safely
- Implementing basic game loop logic (movement, collisions, win/lose states)
- Designing a simple but structured project architecture in C
