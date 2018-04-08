#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include "./src/LinkedList.hpp"
#include "./src/Node.hpp"
#include "./src/Aquarium.hpp"


int main( int argc, char* args[] )
{
    init();

    srand(time(0));

    //inisialisasi Aquarium
    Aquarium aquarium;
    Coin::getListCoin() = &aquarium.getListCoin();
    FishFood::getListFishFood() = &aquarium.getListFishFood();
    Guppy::getListCoin() = &aquarium.getListCoin();
    Guppy::getListGuppy() = &aquarium.getListGuppy();
    Guppy::getListFishFood() = &aquarium.getListFishFood();
    Piranha::getListCoin() = &aquarium.getListCoin();
    Piranha::getListGuppy() = &aquarium.getListGuppy();
    Piranha::getListPiranha() = &aquarium.getListPiranha();
    Snail::getListCoin() = &aquarium.getListCoin();

    bool running = true;

    while (running) {

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        if (get_x_position() != 0) {
            aquarium.getListFishFood().add(new FishFood(get_x_position(), 0));
            clear_x_position();
        }

        for (auto keys : get_tapped_keys()) {
            switch(keys) {
                case SDLK_1 :
                    aquarium.getListGuppy().add(new Guppy());
                    break;
                case SDLK_2 :
                    aquarium.getListPiranha().add(new Piranha());
                    break;
                // case SDLK_3 :
                //     TODO : BELI TELOR SAMA DUIT
            };
        }

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        for (int i=0; i<aquarium.getListCoin().getCount(); i++){
            aquarium.getListCoin().get(i).move();
            // printf("%d : %f %f\n", i, aquarium.getListCoin()->get(i).getX(), aquarium.getListCoin()->get(i).getY());
        }
        for (int i = 0; i < aquarium.getListFishFood().getCount(); i++) {
            aquarium.getListFishFood().get(i).move();
        }
        for (int i = 0; i < aquarium.getListGuppy().getCount(); i++) {
            aquarium.getListGuppy().get(i).move();
            //draw_text(to_string(aquarium.getListGuppy().get(i).getHunger()), 18, 10, 10, 0, 0, 0);
        }
        for (int i = 0; i < aquarium.getListPiranha().getCount(); i++) {
            aquarium.getListPiranha().get(i).move();
        }

        aquarium.getSnail()->move();
        update_screen();
    }

    close();

    return 0;
}
