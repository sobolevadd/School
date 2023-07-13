#include <iostream>

using namespace std;

int ChooseRPS();
int Computer();
void Clear();

int main() 
{

    
}


int ChooseRPS() {
    char choose = '0';
    cout << "Please choose 1 for rock, 2 for paper, 3 for scissors, 0 for ending the game" << endl;
    cin >> choose;
    if (choose == 0)
    {
        cout << "You've choosen to end the game" << endl;
    } else if (choose == 1){
        cout << "You've choosen the rock!" << endl;
    } else if (choose == 2){
        cout << "You've choosen the paper!" << endl;
    } else if (choose == 3){
         cout << "You've choosen scissors!" << endl;
    } else {
        Clear();
        cout << choose << " is an incorrect input! Please try again!" << endl;
        choose = ChooseRPS();
    }
    return choose;
}
    
int Computer(){

    int choose = (rand() % 3) + 1;
    if (choose == 1){
        cout << "Computer choosed rock!" << endl;
    } else if (choose == 2){
        cout << "Computer choosed paper! " << endl;
    } else {
        cout << "Computer choosed scissors!" << endl;
    }
    return choose;
}
    

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}