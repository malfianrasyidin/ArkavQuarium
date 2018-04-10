#include <math.h>
#include <sstream>
#include <iostream>
#include <stdlib.h>

#include "oop.hpp"
#include "./src/LinkedList.hpp"
#include "./src/Node.hpp"
#include "./src/Aquarium.hpp"
#include "filestream.hpp"

const int GUPPY_VALUE = 15;
const int PIRANHA_VALUE = 30;
const int FISHFOOD_VALUE = 5;
const int FIRST_EGG_VALUE = 100;
const int SECOND_EGG_VALUE = 150;
const int THIRD_EGG_VALUE = 250;

int main( int argc, char* args[] )
{
	init();
	srand(time(0));
  
    int eggstate = 3;
    int money = 25;

	bool running = true;
    bool pause = false;
    bool quit = false;

    /// Inisialisasi Aquarium
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

    /// Main Menu
    draw_image("menu.jpg",545,360);
    draw_text("PLAY", 100, 400, 380, 255, 255, 255);
    update_screen();

    while(running) {
        handle_input();

        /// Membaca data dari file
        for (auto keys : get_tapped_keys()) {
            if (keys == SDLK_1) {
                load_file("save.txt", aquarium, &eggstate, &money);
            }
        }
        if (get_x_position() != 0) {
            running = false;
            clear_x_position();
            clear_y_position();
        }
        if (quit_pressed()) {
            running = false;
            quit = true;
        }
    }
    
    if (!quit) {
        running = true;
    }


	while (running) {
		/// sstream eggstate
		stringstream eggpic;
		eggpic << "egg" << eggstate << ".png";
    
		handle_input();
		if (quit_pressed()) {
			running = false;
		}

		if (get_x_position() != 0 && get_y_position() > 100) {
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
                  aquarium.getListFishFood().add(new FishFood(get_x_position(), 105));  
                  money -= FISHFOOD_VALUE;
              }  
            }

            clear_x_position();
            clear_y_position();

		} else if (get_x_position() < 120 && get_x_position() > 35 && money >= GUPPY_VALUE){
			/// Membeli Guppy
            money -= GUPPY_VALUE;
			aquarium.getListGuppy().add(new Guppy());
			clear_x_position();
			clear_y_position();

		} else if (get_x_position() < 235 && get_x_position() > 160 && money >= PIRANHA_VALUE){
			/// Membeli Piranha
            money -= PIRANHA_VALUE;
			aquarium.getListPiranha().add(new Piranha());
			clear_x_position();
			clear_y_position();

		} else if(get_x_position() > 255 && get_x_position() < 333){
			/// Membeli Egg
			if (eggstate == 1 && money >= FIRST_EGG_VALUE){
                money -= FIRST_EGG_VALUE;
                eggstate++;
    		} else if (eggstate == 2 && money >= SECOND_EGG_VALUE) {
                money -= SECOND_EGG_VALUE;
				eggstate++;
            } else if (eggstate == 3 && money >= THIRD_EGG_VALUE) {
                money -= THIRD_EGG_VALUE;
                eggstate++;
            }

			clear_x_position();
			clear_y_position();

	   } else if (get_x_position() > 935 && get_x_position() < 1000) {
            pause = true;
            clear_x_position();
            clear_y_position();

            clear_screen();
            draw_image("bg.png",545,360);
            draw_text("PAUSE", 100, 400, 380, 255, 255, 255);
            update_screen();

            while (pause) {
                handle_input();

                for (auto key : get_tapped_keys()) {
                    if (key == SDLK_1) {
                        save_file("save.txt", aquarium, eggstate, money);
                    }
                }

                if (get_x_position() != 0) {
                    pause = false;
                    clear_x_position();
                    clear_y_position();
                }

                if (quit_pressed()) {
                    pause = false;
                    running = false;
                }
            }
       }

		/// Menggambar ikan di posisi yang tepat
		clear_screen();
		draw_image("bg.png",545,360);
		draw_image(eggpic.str(),295,40);
        draw_text(to_string(money) , 25, 940, 55, 255, 255, 255);
        draw_text("PAUSE" , 25, 940, 8, 255, 255, 255);

		for (int i=0; i< aquarium.getListCoin().getCount(); i++){
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
    
        /// Mengecek kondisi menang
        if (eggstate == 4) {
            running = false;
        }

        /// Mengecek kondisi kalah
        if ((money < GUPPY_VALUE) && (aquarium.getListGuppy().getCount() == 0) && (aquarium.getListPiranha().getCount() == 0)) {
            running = false;
        }       
    }

    running = true;

    /// Tampilan kondisi menang
    if (eggstate == 4) {
        clear_screen();
        draw_image("win.jpg",545,360);
        draw_text("WIN", 100, 400, 180, 255, 255, 255);
        update_screen();

        while (running) {
            handle_input();

            if (get_x_position() != 0 || quit_pressed()) {
                running = false;
                clear_x_position();
                clear_y_position();
            }
        }
    } else {
        clear_screen();
        draw_image("lose.jpg",545,360);
        draw_text("LOSE", 100, 400, 180, 255, 255, 255);
        update_screen();

        while (running) {
            handle_input();

            if (get_x_position() != 0 || quit_pressed()) {
                running = false;
                clear_x_position();
                clear_y_position();
            }
        }
    }

	close();
	return 0;
}
