/*
File name: FinalProject.cpp
Compiler: MS Visual Studio 2019
Author:Yuliia Topalova, 040981104
Course: CST8219 C++ Programming C++ Programming - 21W_CST8219_304
Assignment: FinalProject
Date: 15.04.2021
Professor: Abdullah Kadri
*/
#include <nana/gui.hpp>
#include <nana/gui/timer.hpp>
#include <nana/gui/widgets/picture.hpp>
#include <nana/audio/player.hpp>
#include <nana/threads/pool.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;
using namespace nana;

void clicked(int a) {
    cout << "I flipped the card number: " << a << endl;
}

int main() {
    // declare variables
    int numClicks = 0;
    int current;
    int previous = 0; 
    int increment = 0; 
    int numRemaining = 20;
    
    // declare image variables
    nana::paint::image back;
    vector<paint::image> images(10);

    // declare audio variables
    nana::audio::player win("win.wav");
    nana::audio::player loss("loss.wav");

    // declare the threads pool
    nana::threads::pool pool(1);

    // setting up the main form of the game
    form fm { API::make_center(925, 600) };
    // window caption
    fm.caption("Yuliia Final Project");
    static nana::place place(fm);
    place.div("<Mycard grid=[5, 4] margin=[5, 110, 5, 150] gap=20>");
    drawing drawing(fm);

    // setting up the submitting name form of the game 
    form fmTwo { API::make_center(500, 500) };
    fmTwo.caption("Score Form");
    static nana::place placeTwo(fmTwo);
    placeTwo.div("vert<info><name><submit>");
    label display{ fmTwo, "Label" };
    textbox nameBox{ fmTwo, "Name" };
    button submit{ fmTwo, "Submit" };
    placeTwo["info"] << display;
    placeTwo["name"] << nameBox;
    placeTwo["submit"] << submit;

    static std::map<char, button*> cards;
    std::list<button> buttons;

    // creating a button for new game option
    button newGame(fm, rectangle{ 20, 150, 100, 50 });
    newGame.caption("New Game");

    // declare the back and front images for our play cards
    back = paint::image("back.bmp");
    images[0] = nana::paint::image("card0.bmp");
    images[1] = nana::paint::image("card1.bmp");
    images[2] = nana::paint::image("card2.bmp");
    images[3] = nana::paint::image("card3.bmp");
    images[4] = nana::paint::image("card4.bmp");
    images[5] = nana::paint::image("card5.bmp");
    images[6] = nana::paint::image("card6.bmp");
    images[7] = nana::paint::image("card7.bmp");
    images[8] = nana::paint::image("card8.bmp");
    images[9] = nana::paint::image("card9.bmp");

    // declares the vector of pointer images to compare two cards
    vector<paint::image*> imagePointers(20);
    imagePointers[0] = imagePointers[1] = &images[0];
    imagePointers[2] = imagePointers[3] = &images[1];
    imagePointers[4] = imagePointers[5] = &images[2];
    imagePointers[6] = imagePointers[7] = &images[3];
    imagePointers[8] = imagePointers[9] = &images[4];
    imagePointers[10] = imagePointers[11] = &images[5];
    imagePointers[12] = imagePointers[13] = &images[6];
    imagePointers[14] = imagePointers[15] = &images[7];
    imagePointers[16] = imagePointers[17] = &images[8];
    imagePointers[18] = imagePointers[19] = &images[9];

    // shuffle the card    
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(imagePointers.begin(), imagePointers.end(), default_random_engine(seed));

    label endLabel(fm, rectangle{ 0, 0, 200, 140 });
    endLabel.format(true);

    // looping through the cards
    for (current = 0; current < 20; current++) {
        buttons.emplace_front((fm).handle());

        // accessing the first element
        auto& card_btn = buttons.front();
        cards[current] = &card_btn;

        // flip the card
        cards[current]->icon(back);

        // place layout
        place["Mycard"] << card_btn;

        // saving the file after submit button is clicked
        submit.events().click(pool_push(pool, [&, current]() {
            ofstream outfile("FinalProjectScore\\" + nameBox.text() + ".txt");
            outfile << numClicks << endl;
            outfile << nameBox.text() << endl;
            outfile.close();
            fmTwo.hide();
            }));

        // event for the new game button
        newGame.events().click(pool_push(pool, [&, current]() {
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            shuffle(imagePointers.begin(), imagePointers.end(), default_random_engine(seed));
            
            for (int i = 0; i < 20; i++) {
                cards[i]->show();
                cards[i]->icon(back);
                cards[i]->enabled(true);
            }
            numClicks = 0;
            increment = 0;
            numRemaining = 20;
            previous = 0;
            endLabel.caption("");
            }));

        // track button event
        card_btn.events().click(pool_push(pool, [&, current]() {
            // show the front image od the card
            cards[current]->icon(*imagePointers[current]);
            // enable the card
            card_btn.enabled(false); 
            clicked(current);
            numClicks++, increment++; 

            // when the second card clicked
            if (increment == 2) {
                increment = 0;
                // pauses for 2 seconds
                chrono::seconds duration(2);
                // if match
                if (imagePointers[previous] == imagePointers[current]) {
                    cout << "Success! Cards Match" << endl;
                    win.play();
                    this_thread::sleep_for(duration);
                    cards[previous]->hide();
                    cards[current]->hide();
                    numRemaining -= 2;
                }
                //if nor match
                else { 
                    cout << "Cards do not Match" << endl;
                    loss.play();
                    this_thread::sleep_for(duration);
                    cards[previous]->icon(back);
                    cards[previous]->enabled(true);
                    cards[current]->icon(back);
                    cards[current]->enabled(true);
                }
            }

            // if no cards left
            if (numRemaining <= 0) {
                string text = "The amount of clicks to complete this game was: ";
                text += to_string(numClicks);
                endLabel.caption(text);
                win.play();

                placeTwo.collocate();
                fmTwo.show();
            }

            previous = current;
            }));
    }
    //show form
    place.collocate();
    fm.show();

    //start event loop
    exec();

    return 0;
}
