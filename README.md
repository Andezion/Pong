# Pong on SFML
This is simple Pong-game for two players.
## Table of contents
* [General info](#general-info)
* [Gameplay](#gameplay)
* [Technologies](#technologies)
* [Features](#features)
* [Setup](#setup)

## General info
I used SFML for graphics, sound, text and user-computer processing. I created templates of rectangles (players) and a ball, in addition I added a sound when the ball is kicked. At the same time used Audacity to correct the sound. 

![Start menu](./Photo/2.jpg)

The mechanism of bouncing from walls or from players is very simple, as soon as there is a coincidence of extreme coordinates of objects - the ball changes its speed to diametrically opposite with the preservation of all laws of physics.

![Game](./Photo/1.jpg)

The game has an initial window where you can select an action, namely start play, restart, speed up, slow down or exit. The player score is highlighted at the bottom, and resets to zero on restart. As for the text, the template was taken the most usual, the main thing is that it was readable.

## Gameplay

https://github.com/Andezion/Pong/assets/115638748/5c83b3cb-e929-4fa9-a40d-c42e674a9300

## Technologies
Project is created with:
* SFML-2.6.0 for for visuals and game logic
* Audacity to adjust and change the sound
* The Bible for courage

## Features
First we have two auxiliary functions to check for field edge and collision. 
After that, we load texts, create instructions and basic objects, sounds and variables.

Then we check if the game has started - we start moving the object we created earlier - the ball, checking if it has crossed any fields of the screen.
In case of collision we change the direction and play the sound:
```
if (cheking_hitting(round, rect1) || cheking_hitting(round, rect2))
{
	spdX = -spdX;

	sound.play();
}
```
Then we process the keys pressed by our players and display the score.
If the game hasn't started yet, we show text/instructions to the players.
	
## Setup
To run this project, install it locally using npm:
```
sudo apt-get update
sudo apt-get install libsfml-dev
```
