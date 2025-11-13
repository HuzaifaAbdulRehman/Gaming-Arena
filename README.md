# Gaming Arena

A console-based gaming platform featuring three classic games implemented in C. This project was developed as a Programming Fundamentals lab project.

## Contributors / Group Members

- Saad Shakeel — 23k-0614  
- Abdul Moiz Hossain — 23k-0553  
- Huziafa Abdul Rehman — 23k-0782

## Description

Gaming Arena is an interactive command-line application that combines three popular games into one platform. Players can choose from Snake Water Gun (similar to Rock-Paper-Scissors), Hand Cricket, and Guess a Number.

## Features

- **Three Games in One Platform**
  - Snake Water Gun
  - Hand Cricket
  - Guess a Number

- **Multiple Game Modes**
  - Single-player (vs Computer)
  - Multiplayer (2-5 players)

- **Difficulty Levels**
  - Easy, Medium, and Hard modes for Guess a Number

- **User Rating System**
  - Feedback collection after gameplay

## Installation Steps

### Prerequisites
- GCC Compiler (MinGW for Windows, GCC for Linux/Mac)
- Terminal/Command Prompt

### Compilation

1. Clone the repository:
```bash
git clone https://github.com/HuzaifaAbdulRehman/Gaming-Arena.git
cd Gaming-Arena
```

2. Compile the main source file:
```bash
gcc pf_lab_project.c -o gaming_arena
```

3. Run the executable:
```bash
./gaming_arena
```

On Windows:
```bash
gaming_arena.exe
```

## Usage Instructions

### Main Menu
When you start the application, you'll be presented with the main menu:
- Press **S** for Snake Water Gun
- Press **H** for Hand Cricket
- Press **G** for Guess a Number

### Game 1: Snake Water Gun
A game similar to Rock-Paper-Scissors with the following rules:
- Snake drinks Water (Snake wins)
- Gun shoots Snake (Gun wins)
- Gun sinks in Water (Water wins)

**Game Modes:**
- **Single Player**: Play 5 rounds against the computer
- **Multiplayer**: Two players compete for 5 rounds

**Controls:**
- Choose **S** (Snake), **W** (Water), or **G** (Gun)

### Game 2: Hand Cricket
A number-based cricket simulation game.

**Rules:**
- Enter a number between 1 and 6
- If batting: Score runs by entering numbers; get out if your number matches the computer's
- If bowling: Get the computer out by matching their number

**Game Modes:**
- **Single Player**: Includes toss, batting, and bowling
- **Multiplayer**: 2-5 players compete for the highest batting score

### Game 3: Guess a Number
Try to guess a randomly generated number between 1 and 100.

**Difficulty Levels:**
- **Easy**: 20 attempts
- **Medium**: 10 attempts
- **Hard**: 5 attempts

The game provides hints (TOO HIGH/TOO LOW) after each guess.

## Technologies Used

- **Programming Language**: C
- **Standard Libraries**:
  - `stdio.h` - Input/Output operations
  - `stdlib.h` - Random number generation and memory allocation
  - `time.h` - Seeding random number generator
- **Compiler**: GCC (GNU Compiler Collection)

## Folder Structure

```
Gaming-Arena/
│
├── pf_lab_project.c                   # Main source file (complete game collection)
├── Guess a Number.c                   # Standalone number guessing game
│
├── PF Project Gaming Arena main folder/
│   └── Pf project Gaming Arena folder/
│       ├── Project Proposal.docx      # Project proposal document
│       └── pf project report.docx     # Detailed project report
│
├── Guess a number difficulty level.PNG  # Difficulty selection screenshot
├── Output.PNG                         # Game output examples
├── Outputf.PNG                        # Additional output examples
│
├── Project Report.docx                # Main project documentation
├── README.md                          # This file
└── .gitignore                         # Git ignore rules
```

## Game Screenshots

The repository includes several screenshot files demonstrating gameplay:
- `Output.PNG` - Game output examples
- `Outputf.PNG` - Additional output examples
- `Guess a number difficulty level.PNG` - Difficulty selection screen

## Notes

- All games include input validation to ensure valid user choices
- The random number generator is seeded using system time for true randomness
- Games can be replayed without restarting the application
- User ratings are collected at the end of each session

## Credits

**Developers:**
- Saad Shakeel — 23k-0614
- Abdul Moiz Hossain — 23k-0553
- Huziafa Abdul Rehman — 23k-0782

**Course:** Programming Fundamentals Lab Project

**Project Type:** Console-based Gaming Application

---

**Enjoy playing Gaming Arena! Your feedback helps us improve the gaming experience.**