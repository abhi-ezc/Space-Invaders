# Space Invaders (Clone)

A classic arcade-style game inspired by the legendary Space Invader, developed using SFML. The game involves controlling a spaceship to shoot down waves of alien invaders while avoiding their attacks.

## Table of Contents

- [Installation](#installation)
- [Gameplay](#gameplay)
- [Controls](#controls)
- [Features](#features)
- [Contributing](#contributing)
- [License](#license)
- [Credits](#credits)

## Installation

### Prerequisites

- **SFML**: Ensure that SFML is installed on your system. You can download it from [SFML's official website](https://www.sfml-dev.org/download.php).

### Building the Game

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/abhi-ezc/Space-Invaders.git
   cd space-invaders
   ```

2. **Compile the Game**:

   Depending on your system, you can use a compatible compiler. For example, using g++:

   ```bash
   g++ -o SpaceInvader main.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```

3. **Run the Game**:

   ```bash
   ./SpaceInvader
   ```

## Gameplay

In Space Invader Clone, you control a spaceship at the bottom of the screen, tasked with defending against waves of descending alien invaders. Your goal is to destroy all the aliens before they reach the bottom of the screen. Each level increases in difficulty as the aliens move faster and shoot more frequently.

## Controls

- **Left Arrow / A**: Move the spaceship left.
- **Right Arrow / D**: Move the spaceship right.
- **Space**: Shoot a laser.
- **Esc**: Pause the game or exit.

## Features

- **Classic Arcade Gameplay**: Relive the nostalgia of the original Space Invader.
- **Multiple Levels**: Increasing difficulty with each level.
- **Power-ups**: Collect power-ups to enhance your spaceship's capabilities.
- **High Score Tracking**: Compete to beat your best score.

## Contributing

Contributions are welcome! If you'd like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b my-branch-name`.
3. Make your changes and commit them: `git commit -m 'My changes'`.
4. Push to the branch: `git push origin my-branch-name`.
5. Submit a pull request.

Please ensure your code follows the project's coding standards and includes appropriate tests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Credits

- **Developer**: Abhinav MK(abhinavchendayad@gmail.com)
- **Special Thanks**: To the SFML community and all contributors to the project.
