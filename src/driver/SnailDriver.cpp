// Snail Driver
#include "../Snail.hpp"

int main (){
    Snail snail(10.0, 10.0);

    /// Test Script
    cout << "Snail x position: " << snail.getX() << endl;
    cout << "Snail y position: " << snail.getY() << endl;
    cout << "Snail radius: " << snail.getRadius() << endl;
}