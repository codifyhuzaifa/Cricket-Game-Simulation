# Cricket Game Simulation 🏏

Welcome to my **Cricket Game Simulation** project! This is my first programming project, where I’ve created a fun and interactive simulation of a cricket game using C++.

## Features ✨
- Simulates a complete cricket match between two customizable teams.
- Allows users to:
  - Input team names and select players.
  - Decide match parameters like overs and player roles.
  - Simulate toss decisions and innings.
- Tracks key stats:
  - Runs, wickets, extras, and overs.
  - Individual player performances (runs scored, wickets taken, strike rate, economy).
- Generates a detailed match summary saved in a `matchsummary.txt` file.
- Simple and intuitive console-based interface.

## How It Works 🚀
1. **Team Setup**:
   - Input team names and player details.
2. **Match Settings**:
   - Specify the number of overs and simulate the toss.
3. **Gameplay**:
   - Input ball-by-ball actions such as runs, wickets, or extras.
   - Real-time score updates and player statistics.
4. **Match Result**:
   - View the match summary, including top batsmen, bowlers, and the winner.

## Technologies Used 🛠️
- **Programming Language**: C++
- **Libraries**:
  - `<iostream>`: For input and output.
  - `<fstream>`: For saving match summaries.
  - `<string>`: For managing player names and team data.

## Getting Started 🖥️
1. Clone this repository: https://github.com/huzaifa1947/CEP.git
2. Navigate to the project directory: cd CEP
3. Compile the code using a C++ compiler: g++ cricket_game.cpp -o cricket_game
4. Run the program: ./cricket_game

## Usage Instructions 📚
- Follow the prompts in the console to set up the match.
- Input ball-by-ball events (e.g., runs, wickets, extras).
- At the end of the match, check the console output and `matchsummary.txt` for detailed results.

## Example Events 🎯
- `0`: Dot ball
- `1`: Single run
- `4`: Boundary (Four)
- `6`: Six
- `7`: Wicket
- `8`: No Ball (Free Hit)
- `9`: Wide Ball

## Planned Improvements 🚀
- Adding advanced cricket rules like powerplays and fielding restrictions.
- Implementing a graphical user interface (GUI) for better interactivity.
- Saving match states for resuming interrupted games.

Feel free to explore, fork, or contribute to this repository. Happy coding! 🎉



