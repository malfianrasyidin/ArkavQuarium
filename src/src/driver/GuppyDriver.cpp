// Guppy Driver
#include "../Guppy.hpp"

int main()
{
    Guppy guppy;

    /// Test Script
    cout << "Guppy isHungry(): " << guppy.isHungry() << endl;
    cout << "Guppy getRadius(): " << guppy.getRadius() << endl;
    cout << "Guppy getHunger(): " << guppy.getHunger() << endl;
    cout << "Guppy getState(): " << guppy.getState() << endl;
    cout << "Guppy getTimesEaten(): " << guppy.getTimesEaten() << endl;

}