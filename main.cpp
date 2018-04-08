#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include "./src/LinkedList.hpp"
#include "./src/Node.hpp"
#include "./src/Aquarium.hpp"

const int GUPPY_VALUE = 15;
const int PIRANHA_VALUE = 30;
const int FISHFOOD_VALUE = 5;
const int FIRST_EGG_VALUE = 100;
const int SECOND_EGG_VALUE = 150;
const int THIRD_EGG_VALUE = 250;

int main( int argc, char* args[] )
{
    int gameState = 0;
    int money = 25;

    init();

    srand(time(0));

    //inisialisasi Aquarium
    Aquarium aquarium;
    aquarium.getSnail()->setMoney(&money);
    Coin::getListCoin() = &aquarium.getListCoin();
    FishFood::getListFishFood() = &aquarium.getListFishFood();
    Guppy::getListCoin() = &aquarium.getListCoin();
    Guppy::getListGuppy() = &aquarium.getListGuppy();
    Guppy::getListFishFood() = &aquarium.getListFishFood();
    Piranha::getListCoin() = &aquarium.getListCoin();
    Piranha::getListGuppy() = &aquarium.getListGuppy();
    Piranha::getListPiranha() = &aquarium.getListPiranha();
    Snail::getListCoin() = &aquarium.getListCoin();
    aquarium.getListGuppy().add(new Guppy());

    bool running = true;

    while (running) {

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        if (get_x_position() != 0) {
            bool getCoin = false;

            for (int i = 0; i < aquarium.getListCoin().getCount() && !getCoin; i++){
                if (aquarium.getListCoin().get(i).isIntersect(get_x_position(), get_y_position(), 1)) {
                    money += aquarium.getListCoin().get(i).getValue();
                    aquarium.getListCoin().remove(aquarium.getListCoin().get(i));
                    getCoin = true;
                }
            }

            if (!getCoin){
                if (money >= FISHFOOD_VALUE) {
                    aquarium.getListFishFood().add(new FishFood(get_x_position(), 0));  
                    money -= FISHFOOD_VALUE;
                }  
            }

            clear_x_position();
            clear_y_position();
        }

        for (auto keys : get_tapped_keys()) {
            switch(keys) {
                case SDLK_1 :
                    if (money >= GUPPY_VALUE) {
                        aquarium.getListGuppy().add(new Guppy());
                        money -= GUPPY_VALUE;
                    }
                    break;
                case SDLK_2 :
                    if (money >= PIRANHA_VALUE) {
                        aquarium.getListPiranha().add(new Piranha());
                        money -= PIRANHA_VALUE;
                    }
                    break;
                case SDLK_3 :
                    if ((gameState == 0) && (money >= FIRST_EGG_VALUE)) {
                        gameState = 1;
                        money -= FIRST_EGG_VALUE;
                    } else if ((gameState == 1) && (money >= SECOND_EGG_VALUE)) {
                        gameState = 2;
                        money -= SECOND_EGG_VALUE;
                    } else if ((gameState == 2) && (money >= THIRD_EGG_VALUE)) {
                        gameState = 3;
                        money -= THIRD_EGG_VALUE;
                    }
            };
        }

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        draw_text(to_string(money) , 25, 20, 20, 0, 0, 0);

        for (int i=0; i<aquarium.getListCoin().getCount(); i++){
            aquarium.getListCoin().get(i).move();
        }
        for (int i = 0; i < aquarium.getListFishFood().getCount(); i++) {
            aquarium.getListFishFood().get(i).move();
        }
        for (int i = 0; i < aquarium.getListGuppy().getCount(); i++) {
            aquarium.getListGuppy().get(i).move();
        }
        for (int i = 0; i < aquarium.getListPiranha().getCount(); i++) {
            aquarium.getListPiranha().get(i).move();
        }
        aquarium.getSnail()->move();
        update_screen();

        //check win
        if (gameState == 3) {
            running = false;
        }

        //check lose
        if ((money < GUPPY_VALUE) && (aquarium.getListGuppy().getCount() == 0) && (aquarium.getListPiranha().getCount() == 0)) {
            running = false;
        }
    }

    close();

    return 0;
}
