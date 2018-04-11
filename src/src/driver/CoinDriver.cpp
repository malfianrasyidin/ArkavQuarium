/// Driver Coin
#include "../Coin.hpp"

int main(){
    Coin coin(10.0, 10.0, 10);

    /// Test Script
    cout << "Coin x position: " << coin.getX() << endl;
    cout << "Coin y position: " << coin.getY() << endl;
    cout << "Coin value: " << coin.getValue() << endl;
    cout << "Coin radius: " << coin.getRadius() << endl;

    return 0;
}