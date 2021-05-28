///////////////////////////////////////////////   띄어쓰기 줄바꾸기 금지   /////////////////////////////////////////////////
#include<stdio.h>
#include<bangtal.h>
#include<windows.h>
#include<math.h>
bool started = false;
int x, y, look = 10, hit = 0;
SceneID sc_start, sc_front, sc_back, sc_right, sc_left, sc_up, sc_down, sc_roof, sc_scary;
ObjectID obj, sb, rb, steb, eb, start_sc, light_1, light_2, key;
ObjectID gamesc_front, gamesc_right, gamesc_left, gamesc_up, gamesc_down, gamesc_back, gamesc_roof;
ObjectID look_right1, look_left1, look_up1, look_down1, look_right2, look_left2, look_up2, look_down2, look_right3, look_left3, look_up3, look_down3, look_right4, look_left4, look_up4, look_down4;
ObjectID look_down5, look_down7, look_up6, roofin, roofin1, roofin2, roofin3, roofin4, roofout, scary, small_scary, no_scary, empty_scary;
ObjectID Object(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) {
		showObject(object);
	}
	return object;
}
void starting(bool starter) {
	if (starter == true) enterScene(sc_front);
	else enterScene(sc_start);
	started = starter;
}
void mouseCallback(ObjectID pobj, int px, int py, MouseAction act) {
	x = px; y = py; obj = pobj;
	if (obj == sb) starting(true);
	else if (obj == rb) starting(false);
	else if (obj == eb || obj == steb)endGame();
	else if (started == true) {
		if (obj == key) { hit += 10000; hideObject(key); }
		else if (obj == roofin && hit >= 10000) hideObject(roofin);
		else if (obj == roofin1) hideObject(roofin1);
		else if (obj == roofin2) hideObject(roofin2);
		else if (obj == roofin3) hideObject(roofin3);
		else if (obj == small_scary || obj == no_scary) look += 200;
		else if (obj == look_down7) look -= 200;
		else if (obj == roofin4)look += 100;
		else if (obj == roofout)look -= 100;
		else if (obj == look_right1 || obj == look_right2 || obj == look_right3 || obj == look_right4) look = 100 * (look / 100) + 10 * (look / 10) + (look % 10 + 5) % 4;
		else if (obj == look_left1 || obj == look_left2 || obj == look_left3 || obj == look_left4) look = 100 * (look / 100) + 10 * (look / 10) + (look % 10 + 3) % 4;
		else if (obj == look_up1 || obj == look_up2 || obj == look_up3 || obj == look_up4 || obj == look_up6) { if ((look % 100) / 10 != 2) look += 10; }
		else if (obj == look_down1 || obj == look_down2 || obj == look_down3 || obj == look_down4 || obj == look_down5) { if ((look % 100) / 10 != 0) look -= 10; }
		else if (obj == light_1 && hit >= 3)hit += 10;
		else if (obj == light_2 && hit >= 40)hit += 100;
		if ((look % 10) % 4 == 0 && look / 10 == 1) enterScene(sc_front);
		else if (look / 100 == 0 && (look % 10) % 4 == 1 && look / 10 == 1) enterScene(sc_right);
		else if (look / 100 == 0 && (look % 10) % 4 == 2 && look / 10 == 1) enterScene(sc_back);
		else if (look / 100 == 0 && (look % 10) % 4 == 3 && look / 10 == 1) enterScene(sc_left);
		else if (look / 100 == 0 && look / 10 == 2) enterScene(sc_up);
		else if (look / 100 == 0 && look / 10 == 0) enterScene(sc_down);
		else if (look / 100 == 1) enterScene(sc_roof);
		else if (look / 100 == 2) { enterScene(sc_scary); if (obj == scary) hit++; }
		if (hit % 10 >= 3) { hideObject(scary); hideObject(small_scary); }
		if (hit % 100 >= 40)hideObject(light_1);
		if (hit % 1000 >= 400)hideObject(light_2);
	}
}
int main() {
	setMouseCallback(mouseCallback);
	{
		sc_start = createScene("", "\\images\\sc.png");
		sc_front = createScene("", "\\images\\sc.png");
		sc_back = createScene("", "\\images\\sc.png");
		sc_right = createScene("", "\\images\\sc.png");
		sc_left = createScene("", "\\images\\sc.png");
		sc_up = createScene("", "\\images\\sc.png");
		sc_down = createScene("", "\\images\\sc.png");
		sc_scary = createScene("", "\\images\\sc.png");
		sc_roof = createScene("", "\\images\\sc.png");
		start_sc = Object("\\images\\start_sc.png", sc_start, 0, 0, true);
		sb = Object("\\images\\start.png", sc_start, 38, 75, true);
		steb = Object("\\images\\end.png", sc_start, 158, 75, true);
		rb = Object("\\images\\restart.png", sc_front, 500, 45, true);
		eb = Object("\\images\\end.png", sc_front, 500, 75, true);
		gamesc_front = Object("\\images\\gamesc_front.png", sc_front, 0, 0, true);
		no_scary = Object("\\images\\no_scary.png", sc_front, 304, 396, true);
		small_scary = Object("\\images\\small_scary.png", sc_front, 304, 396, true);
		empty_scary = Object("\\images\\empty_scary.png", sc_scary, 0, 0, true);
		scary = Object("\\images\\scary.png", sc_scary, 0, 0, true);
		gamesc_right = Object("\\images\\gamesc_right.png", sc_right, 0, 0, true);
		gamesc_left = Object("\\images\\gamesc_left.png", sc_left, 0, 0, true);
		gamesc_back = Object("\\images\\gamesc_back.png", sc_back, 0, 0, true);
		gamesc_up = Object("\\images\\gamesc_up.png", sc_up, 0, 0, true);
		roofin4 = Object("\\images\\roofin4.png", sc_up, 151, 181, true);
		roofin3 = Object("\\images\\roofin3.png", sc_up, 151, 181, true);
		roofin2 = Object("\\images\\roofin2.png", sc_up, 151, 181, true);
		roofin1 = Object("\\images\\roofin1.png", sc_up, 151, 181, true);
		roofin = Object("\\images\\roofin.png", sc_up, 151, 181, true);
		key = Object("\\images\\key.png", sc_up, 438, 144, true);
		light_1 = Object("\\images\\light.png", sc_up, 13, 122, true);
		light_2 = Object("\\images\\light.png", sc_up, 420, 121, true);
		gamesc_down = Object("\\images\\gamesc_down.png", sc_down, 0, 0, true);
		gamesc_roof = Object("\\images\\gamesc_roof.png", sc_roof, 0, 0, true);
		roofout = Object("\\images\\roofout.png", sc_roof, 112, 88, true);
		look_right1 = Object("\\images\\look_right.png", sc_front, 450, 325, true);
		look_left1 = Object("\\images\\look_left.png", sc_front, 0, 325, true);
		look_up1 = Object("\\images\\look_up.png", sc_front, 225, 650, true);
		look_down1 = Object("\\images\\look_down.png", sc_front, 225, 0, true);
		look_right2 = Object("\\images\\look_right.png", sc_right, 450, 325, true);
		look_left2 = Object("\\images\\look_left.png", sc_right, 0, 325, true);
		look_up2 = Object("\\images\\look_up.png", sc_right, 225, 650, true);
		look_down2 = Object("\\images\\look_down.png", sc_right, 225, 0, true);
		look_right3 = Object("\\images\\look_right.png", sc_left, 450, 325, true);
		look_left3 = Object("\\images\\look_left.png", sc_left, 0, 325, true);
		look_up3 = Object("\\images\\look_up.png", sc_left, 225, 650, true);
		look_down3 = Object("\\images\\look_down.png", sc_left, 225, 0, true);
		look_right4 = Object("\\images\\look_right.png", sc_back, 450, 325, true);
		look_left4 = Object("\\images\\look_left.png", sc_back, 0, 325, true);
		look_up4 = Object("\\images\\look_up.png", sc_back, 225, 650, true);
		look_down4 = Object("\\images\\look_down.png", sc_back, 225, 0, true);
		look_down5 = Object("\\images\\look_down.png", sc_up, 225, 100, true);
		look_up6 = Object("\\images\\look_up.png", sc_down, 225, 550, true);
		look_down7 = Object("\\images\\look_down.png", sc_scary, 225, 0, true);
	}
	startGame(sc_start);
}