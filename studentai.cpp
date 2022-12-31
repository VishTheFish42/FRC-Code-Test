
#include "micromouseserver.h"
#include <iostream>
#include <unistd.h>

void microMouseServer::studentAI()
{
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/

    // determine which way to turn
        // if can turn right then turn right
    if (!isWallRight()) {
        turnRight();
    }
    else { // otherwise if can only turn left then turn left
        if (isWallForward() && !isWallLeft()) {
            turnLeft();
        }
        else if (isWallForward() && isWallLeft() && isWallRight()) { // otherwise if you're at a dead end then make a u-turn
            turnLeft();
            turnLeft();
        }
    }

    moveForward(); // move forward after the turn

    // condition to check if the mouse has entered something that could be a 2x2 square
        // only 8 possibilities of how mouse can enter the end zone but only two possibilities of circling the square
            // OPTION 1: finish the square with left turns
            // OPTION 2: finish the square with right turns

    // OPTION 1
    if (!isWallLeft() && isWallRight() && !isWallForward()) {
        for (int i = 0; i < 3; i++) {
            moveForward();
            turnLeft();

            if (!(!isWallLeft() && isWallRight() && !isWallForward())) {
                turnLeft();
                if (i == 0) {
                    for (int j = i; j != -1; j--) {
                        moveForward();
                        turnLeft();
                    }
                    turnLeft();
                }
                else {
                    for (int j = i; j != -1; j--) {
                        moveForward();
                        turnRight();
                    }
                    turnRight();
                }
                break;
            }

            if (i == 2) {
                foundFinish();
            }
        }
    }
    // OPTION 2
    else if (isWallLeft() && !isWallRight() && !isWallForward()) {
        for (int i = 0; i < 3; i++) {
            moveForward();
            turnRight();

            if (!(isWallLeft() && !isWallRight() && !isWallForward())) {
                turnRight();
                if (i == 0) {
                    for (int j = i; j != -1; j--) {
                        moveForward();
                        turnRight();
                    }
                    turnRight();
                }
                else {
                    for (int j = i; j != -1; j--) {
                        moveForward();
                        turnLeft();
                    }
                    turnLeft();
                }
                break;
            }

            if (i == 2) {
                foundFinish();
            }
        }
    }

    // usleep(900000);
}
