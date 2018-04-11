#ifndef _FILESTREAM_HPP
#define _FILESTREAM_HPP

#include <string>
#include <fstream>
#include "./src/Aquarium.hpp"

using namespace std;

void load_file(string filename, Aquarium& aquarium, int* eggstate, int* money) {
    //load from file
    string buff;
    double x, y;
    int count, value, hunger, state, eat;
    ifstream loadfile (filename);

    if (loadfile.is_open()) {
        //load money
        getline(loadfile, buff);
        if (buff == "MONEY") {
            getline(loadfile, buff);
            *money = stoi(buff);
        }

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

void save_file(string filename, Aquarium& aquarium, int eggstate, int money) {

    ofstream savefile (filename);
    if (savefile.is_open()) {
        
    	savefile << "MONEY\n";
        savefile << money << endl;

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

#endif
