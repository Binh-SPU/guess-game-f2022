#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

enum Temperature {FREEZING, COLD, WARM, HOT};

Temperature GetTemperature(int magic, int guess, int max);

int main() {
//    cout << RAND_MAX << endl;
    srand(time(0));
    int magic, guess, cont = 1, max, difference;
    double percentage;

    while (cont == 1){
        cout << "Up to what number you wanna guess? ";
        cin >> max;
        magic = rand() % max + 1;
        cerr << magic << endl;
        cout << "Please Guess a number" << endl;
        for (int curTry = 0; curTry < 3; ++curTry) {
            cout << "Attempt #" << curTry + 1 << ": ";
            cin >> guess;
            if (guess == magic){
                cout << "You win!" << endl;
                break;
            }else if (curTry < 2){
                cout << "Try again!" << endl;
                difference = magic - guess;
                percentage = static_cast<double>(abs(difference)) / max;
                if (percentage > 0.75) {
                    cout << "Freeze" << endl;
                }
                else if (percentage > 0.5) {
                    cout << "Cold" << endl;
                }
                else if (percentage > 0.25) {
                    cout << "Warm" << endl;
                }
                else {
                    cout << "Hot" << endl;
                }
            }
        }
        if (guess != magic){
            cout << "Looooooooser" << endl;
        }
        cout << "Wanna go again? [0 for no]";
        cin >> cont;

    }

    return 0;
}
