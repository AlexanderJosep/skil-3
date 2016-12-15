#ifndef CONFIG_H
#define CONFIG_H

#include <string>

using namespace std;

namespace config {
    /* Snake Configuration */
    const long SNAKE_SLEEP_TIME = 100;
    const int SNAKE_CELL_SIZE = 24;
    const int SNAKE_BAR_OFFSET = 150;
    const string SNAKE_DEFAULT_STATUS = "Press any key to begin!";

    /* Pong Configuration */
    const int PONG_MIDDLE_SEPARATOR_SPACE = 10;
    const int PONG_MIDDLE_SEPARATOR_COUNT = 25;
    const int PONG_MIDDLE_SEPARATOR_WIDTH = 6;
    const int PONG_WINDOW_WIDTH = 800;
    const int PONG_WINDOW_HEIGHT = 600;
    const int PONG_BALL_WIDTH = 20;
    const int PONG_BALL_HEIGHT = 20;
    const int PONG_BALL_SPEED_X = 14;
    const int PONG_RACKET_HEIGHT = 100;
    const int PONG_RACKET_WIDTH = 15;
    const int PONG_SLEEP_TIME = 14;
    const int PONG_START_BAR_HEIGHT = 50;

    /* Entity Configuration */
    const int PERSON = 0;
    const int COMPUTER = 1;
    const int CONNECTION = 2;
    const int NUMBER_OF_MACHINES_TYPES = 4;
    const string MACHINE_TYPES[NUMBER_OF_MACHINES_TYPES] =  {"Mechanic", "Electronic", "Transistor", "Quantum"};

    /* Commands and organization */
    const int COMMANDS_LENGTH = 18;
    const int INSTRUCTIONS_LENGTH = 8;
    const int DISPLAY_PERSON_INSTRUCTIONS_LENGTH = 5;
    const int DISPLAY_COMPUTER_INSTRUCTIONS_LENGTH = 4;
    const char COMMANDS[COMMANDS_LENGTH] = {'d', 's', 'a', 'i', 'q', 'c', 'e', 'r', 'g', // Instructions
                               'o', 'n', 'g', 'b', 'd', // Organization persons
                               'o', 'n', 'y', 't'}; // Organization computers
    const string INSTRUCTIONS[INSTRUCTIONS_LENGTH] = {"'a' - to add person, computer or a connection to the list", "'c' - clears console",
                                    "'d' - display a organized list of persons, computers or connections", "'e' - to edit persons or computers",
                                    "'g' - starts a game of snake. HUGE UPDATE, DO TRY!",
                                    "'r' - remove a person, computer or a connection from a list",
                                    "'s' - search for persons, computers or connections", "'q' - if you want to quit"};
    const string DISPLAY_PERSON_INSTRUCTIONS[DISPLAY_PERSON_INSTRUCTIONS_LENGTH] = {"'b' - organize by birth year",
                                    "'d' - organize by death year", "'g' - organize by gender",
                                    "'n' - organize by names in alphabetical order",
                                    "'o' - no organization"};
    const string DISPLAY_COMPUTER_INSTRUCTIONS[DISPLAY_COMPUTER_INSTRUCTIONS_LENGTH] = {"'n' - organize by names in alphabetical order",
                                    "'t' - organize by type", "'y' - organize by year it was built", "'o' - no organization"};

}

#endif // CONFIG_H

