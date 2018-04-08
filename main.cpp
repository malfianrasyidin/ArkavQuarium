#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include "./src/LinkedList.hpp"
#include "./src/Node.hpp"
#include "./src/Aquarium.hpp"

const double speed = 50; // pixels per second

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

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    bool running = true;

    double prevtime = time_since_start();

    aquarium.getListGuppy().add(new Guppy());

    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        // for (auto key : get_pressed_keys()) {
        //     switch (key) {
        //     case SDLK_UP:
        //         cy -= speed * sec_since_last;
        //         break;
        //     case SDLK_DOWN:
        //         cy += speed * sec_since_last;
        //         break;
        //     case SDLK_LEFT:
        //         cx -= speed * sec_since_last;
        //         break;
        //     case SDLK_RIGHT:
        //         cx += speed * sec_since_last;
        //         break;
        //     }
        // }

        // // Proses masukan yang bersifat "tombol"
        // for (auto key : get_tapped_keys()) {
        //     switch (key) {
        //     // r untuk reset
        //     case SDLK_r:
        //         cy = SCREEN_HEIGHT / 2;
        //         cx = SCREEN_WIDTH / 2;
        //         break;
        //     // x untuk keluar
        //     case SDLK_x:
        //         running = false;
        //         break;
        //     }
        // }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }

        // if (aquarium.getListCoin().getCount() < 3){
        //     aquarium.getListCoin().add(new Coin(rand()%640,20,rand() % 20));
        // }

        if (get_x_position() != 0) {
            aquarium.getListFishFood().add(new FishFood(get_x_position(), 0));
            clear_x_position();
        }

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        // draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        for (int i=0; i<aquarium.getListCoin().getCount(); i++){
            aquarium.getListCoin().get(i).move();
            // printf("%d : %f %f\n", i, aquarium.getListCoin()->get(i).getX(), aquarium.getListCoin()->get(i).getY());
        }
        for (int i = 0; i < aquarium.getListFishFood().getCount(); i++) {
            aquarium.getListFishFood().get(i).move();
        }
        for (int i = 0; i < aquarium.getListGuppy().getCount(); i++) {
            aquarium.getListGuppy().get(i).move();
            draw_text(to_string(aquarium.getListGuppy().get(i).getHunger()), 18, 10, 10, 0, 0, 0);
        }

        aquarium.getSnail()->move();
        //draw_image("ikan.png", cx, cy);
        update_screen();
    }

    close();

    return 0;
}
