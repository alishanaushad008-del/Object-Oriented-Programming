#include <iostream>
#include <cstdlib>  // Required for rand() and srand()
#include <ctime>    // Required for time()

using namespace std;

class HittingGame {
private:
    int totalPlayers;
    int myTeamScore;
    int enemyTeamScore;

public:
    // Constructor to initialize the game state
    HittingGame() {
        myTeamScore = 0;
        enemyTeamScore = 0;
        
        // Randomly generate total players (Let's stick to a range of 1-5 for simplicity)
        totalPlayers = (rand() % 5) + 1; 
    }

    // Main function to run the game logic
    void play() {
        cout << "Total No. Of Players in your team: " << totalPlayers << endl << endl;

        for (int i = 0; i < totalPlayers; i++) {
            cout << "Pair of numbers:" << endl;

            // Generate pairs of numbers
            // Using a small range (1-5) so matches happen frequently, 
            // similar to the screenshot logic.
            int number1 = (rand() % 5) + 1;
            int number2 = (rand() % 5) + 1;

            cout << "Number1: " << number1 << endl;
            cout << "Number2: " << number2 << endl;

            // Logic: If numbers match, you hit them. If not, they hit you.
            if (number1 == number2) {
                cout << "Enemy got hit by your team!" << endl;
                myTeamScore++;
            } else {
                cout << "You got hit by the enemy team!" << endl;
                enemyTeamScore++;
            }
            cout << endl; // Empty line for formatting
        }

        showFinalResult();
    }

    // Helper function to display the winner
    void showFinalResult() {
        if (myTeamScore > enemyTeamScore) {
            cout << "Game Over! You won" << endl;
        } else if (enemyTeamScore > myTeamScore) {
            cout << "Game Over! Enemy won" << endl;
        } else {
            cout << "Game Over! It's a Draw" << endl;
        }
    }
};

int main() {
    // Seed the random number generator so numbers change every time the program runs
    srand(time(0));

    // Create the game object
    HittingGame game;
    
    // Start the game
    game.play();

    return 0;
}