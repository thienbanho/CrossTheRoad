#pragma once
#include "Basic.h"
#include <iostream>
#include<io.h>
#include<fcntl.h>
#include<condition_variable>

using namespace std;

class UserInterface
{
public:

	static void Drawbox(int x, int y, int width, int height, int t_color, int b_color);	// Draw box with position, width height, color and background color


	static void DrawParrot(int x, int y, bool mode, int background_Color); //draw parrot
	static void DrawChicken(int x, int y, bool mode, int background_Color); //draw chicken
	static void DrawPenguin(int x, int y, bool mode, int background_Color); //draw penguin
	static void DrawBee(int x, int y, bool mode, int background_Color); //draw bee
	static void DrawDog(int x, int y, bool mode, int background_Color); //draw dog


	static void DrawBCar(int x, int y, bool mode, int background_Color); //draw blue car
	static void DrawRCar(int x, int y, bool mode, int background_Color); //draw red car
	static void DrawTruck(int x, int y, bool mode, int background_Color); //draw truck
	static void DrawTrain(int x, int y, bool mode, int background_Color); //draw train


	static void DrawReverseRCar(int x, int y, bool mode, int background_Color);
	static void DrawReverseBCar(int x, int y, bool mode, int background_Color);
	static void DrawReverseTruck(int x, int y, bool mode, int background_Color);

	static void DrawLeafRiver(int x, int y);

	static void TestColor(int x, int y, int color);
	static void DrawSafeLane(int x, int y, int background_Color);
	static void DrawRoadLane(int x, int y, int background_Color);
	static void DrawRiverLane(int x, int y, int background_Color);
	static void DrawTrainLane(int x, int y, int& background_Color); //dthien new train lane


	static void DrawVehicle_Right(int type, int x, int y, bool mode, int background_Color, int laneType);
	static void DrawBack_Right(int x, int y, int background_Color, int laneType);

	static void DrawMenuGame();
	static void DrawC(int x, int y, int background_Color);
	static void DrawR1(int x, int y, int background_Color);
	static void DrawO1(int x, int y, int background_Color);
	static void DrawS1(int x, int y, int background_Color);
	static void DrawS2(int x, int y, int background_Color);
	static void DrawI(int x, int y, int background_Color);
	static void DrawN(int x, int y, int background_Color);
	static void DrawG(int x, int y, int background_Color);
	static void DrawR2(int x, int y, int background_Color);
	static void DrawO2(int x, int y, int background_Color);
	static void DrawA(int x, int y, int background_Color);
	static void DrawD(int x, int y, int background_Color);

	static void DrawPlayButton(int x, int y, bool mode, int background_Color);
	static void DrawLoadButton(int x, int y, bool mode, int background_Color);
	static void DrawSettingButton(int x, int y, bool mode, int background_Color);
	static void DrawCreditsButton(int x, int y, bool mode, int background_Color);
	static void DrawExitButton(int x, int y, bool mode, int background_Color);

	static void Write(const string&, int, int, int, int);
};

