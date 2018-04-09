#include "oop.hpp"
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include "./src/LinkedList.hpp"
#include "./src/Node.hpp"
#include "./src/Aquarium.hpp"
#include <string>

const int GUPPY_VALUE = 15;
const int PIRANHA_VALUE = 30;
const int FISHFOOD_VALUE = 5;
const int FIRST_EGG_VALUE = 100;
const int SECOND_EGG_VALUE = 150;
const int THIRD_EGG_VALUE = 250;

void load_file(string filename, Aquarium& aquarium, int* eggstate) {
    //load from file
    string buff;
    double x, y;
    int count, value, hunger, state, eat;
    ifstream loadfile (filename);

    if (loadfile.is_open()) {
        //remove default guppy
        aquarium.getListGuppy().remove(aquarium.getListGuppy().get(0));

        //load eggstate
        getline(loadfile, buff);
        if (buff == "EGGSTATE") {
            getline(loadfile, buff);
            *eggstate = stoi(buff);
        }

        // load snail
        getline(loadfile, buff);
        if (buff == "SNAIL") {
            getline(loadfile, buff);
            x = stod(buff);
            aquarium.getSnail()->setX(x);
            getline(loadfile, buff);
            y = stod(buff);
            aquarium.getSnail()->setY(y);
        }

        //load coin
        getline(loadfile,buff);
        if (buff == "COIN") {
            getline(loadfile, buff);
            count = stoi(buff);
            for (int i = 0; i < count; i++) {
                getline(loadfile, buff);
                x = stod(buff);
                getline(loadfile, buff);
                y = stod(buff);
                getline(loadfile, buff);
                value = stoi(buff);
                aquarium.getListCoin().add(new Coin(x, y, value));
            }
        }


        //load fishfood
        getline(loadfile, buff);
        if (buff == "FISHFOOD") {
            getline(loadfile, buff);
            count = stoi(buff);
            //cout << "tot\n";
            for (int i = 0; i < count; i++) {
                getline(loadfile, buff);
                x = stod(buff);
                getline(loadfile, buff);
                y = stod(buff);
                aquarium.getListFishFood().add(new FishFood(x, y));
            }
        }

        //load guppy
        getline(loadfile, buff);
        if (buff == "GUPPY") {
            getline(loadfile, buff);
            count = stoi(buff);
            for (int i = 0; i < count; i++) {
                getline(loadfile, buff);
                x = stod(buff);
                getline(loadfile, buff);
                y = stod(buff);
                getline(loadfile, buff);
                hunger = stoi(buff);
                getline(loadfile, buff);
                state = stoi(buff);
                getline(loadfile, buff);
                eat = stoi(buff);

                Guppy *tempGuppy = new Guppy();
                tempGuppy->setX(x);
                tempGuppy->setY(y);
                tempGuppy->setHunger(hunger);
                tempGuppy->setState(state);
                tempGuppy->setTimesEaten(eat);

                aquarium.getListGuppy().add(tempGuppy);
            }
        }

        //load piranha
        getline(loadfile, buff);
        if (buff == "PIRANHA") {
            getline(loadfile, buff);
            count = stoi(buff);
            for (int i = 0; i < count; i++) {
                getline(loadfile, buff);
                x = stod(buff);
                getline(loadfile, buff);
                y = stod(buff);
                getline(loadfile, buff);
                hunger = stoi(buff);

                Piranha *tempPiranha = new Piranha();
                tempPiranha->setX(x);
                tempPiranha->setY(y);
                tempPiranha->setHunger(hunger);

                aquarium.getListPiranha().add(tempPiranha);
            }
        }

        loadfile.close();
    }
}

void save_file(string filename, Aquarium& aquarium, int eggstate) {

    ofstream savefile (filename);
    if (savefile.is_open()) {
        
        savefile << "EGGSTATE\n";
        savefile << eggstate << endl;

        savefile << "SNAIL\n";
        savefile << aquarium.getSnail()->getX() << endl;
        savefile << aquarium.getSnail()->getY() << endl;

        savefile << "COIN\n";
        savefile << aquarium.getListCoin().getCount() << endl;
        for (int i = 0; i < aquarium.getListCoin().getCount(); i++){
            savefile << aquarium.getListCoin().get(i).getX() << endl;
            savefile << aquarium.getListCoin().get(i).getY() << endl;
            savefile << aquarium.getListCoin().get(i).getValue() << endl;
        }

        savefile << "FISHFOOD\n";
        savefile << aquarium.getListFishFood().getCount() << endl;
        for (int i = 0; i < aquarium.getListFishFood().getCount(); i++) {
            savefile << aquarium.getListFishFood().get(i).getX() << endl;
            savefile << aquarium.getListFishFood().get(i).getY() << endl;
        }

        savefile << "GUPPY\n";
        savefile << aquarium.getListGuppy().getCount() << endl;
        for (int i = 0; i < aquarium.getListGuppy().getCount(); i++) {
            savefile << aquarium.getListGuppy().get(i).getX() << endl;
            savefile << aquarium.getListGuppy().get(i).getY() << endl;
            savefile << aquarium.getListGuppy().get(i).getHunger() << endl;
            savefile << aquarium.getListGuppy().get(i).getState() << endl;
            savefile << aquarium.getListGuppy().get(i).getTimesEaten() << endl;
        }

        savefile << "PIRANHA\n";
        savefile << aquarium.getListPiranha().getCount() << endl;
        for (int i = 0; i < aquarium.getListPiranha().getCount(); i++) {
            savefile << aquarium.getListPiranha().get(i).getX() << endl;
            savefile << aquarium.getListPiranha().get(i).getY() << endl;
            savefile << aquarium.getListPiranha().get(i).getHunger() << endl;
        }

        savefile << "END\n";

        savefile.close();
    }

}

int main( int argc, char* args[] )
{
	init();
	srand(time(0));
  
    int eggstate = 1;
    int money = 1000;

	bool running = true;
    bool pause = false;
    bool quit = false;

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

    //main menu
    draw_image("bg.png",545,360);
    draw_text("MENU" , 200, 275, 200, 255, 255, 255);
    draw_text("PLAY", 100, 400, 380, 255, 255, 255);
    update_screen();

    while(running) {
        handle_input();

        //load file
        for (auto keys : get_tapped_keys()) {
            if (keys == SDLK_1) {
                load_file("save.txt", aquarium, &eggstate);
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
		//sstream eggstate
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
			// buy guppy
            money -= GUPPY_VALUE;
			aquarium.getListGuppy().add(new Guppy());
			clear_x_position();
			clear_y_position();

		} else if (get_x_position() < 235 && get_x_position() > 160 && money >= PIRANHA_VALUE){
			// buy piranha
            money -= PIRANHA_VALUE;
			aquarium.getListPiranha().add(new Piranha());
			clear_x_position();
			clear_y_position();

		} else if(get_x_position() > 255 && get_x_position() < 333){
			// buy egg
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
                        save_file("save.txt", aquarium, eggstate);
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

		// Gambar ikan di posisi yang tepat.
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
    
        //check win
        if (eggstate == 4) {
            running = false;
        }

        //check lose
        if ((money < GUPPY_VALUE) && (aquarium.getListGuppy().getCount() == 0) && (aquarium.getListPiranha().getCount() == 0)) {
            running = false;
        }       
    }

    running = true;

    //win screen
    if (eggstate == 4) {
        clear_screen();
        draw_image("bg.png",545,360);
        draw_text("WIN", 100, 400, 380, 255, 255, 255);
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
        draw_image("bg.png",545,360);
        draw_text("LOSE", 100, 400, 380, 255, 255, 255);
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
