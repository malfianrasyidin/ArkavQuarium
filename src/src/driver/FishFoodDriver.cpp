/// Driver FishFood
#include "../FishFood.hpp"

int main()
{
    FishFood fishFood(10.0, 10.0);

    /// Test Script
    cout << "fishFood x position: " << fishFood.getX() << endl;
    cout << "fishFood y position: " << fishFood.getY() << endl;
    cout << "fishFood radius: " << fishFood.getRadius() << endl;

    return 0;
}