#include<stdio.h>
#include<bangtal.h>
#include<windows.h>
#include<math.h>
int x, y, look = 10;
SceneID sc_front, sc_back, sc_right, sc_left, sc_up, sc_down;
ObjectID obj, sb, rb, rbb, eeb, eb, startsc, scary;
ObjectID gamesc_front, gamesc_right, gamesc_left, gamesc_up, gamesc_down, gamesc_back;
ObjectID look_right1, look_left1, look_up1, look_down1;
ObjectID look_right2, look_left2, look_up2, look_down2;
ObjectID look_right3, look_left3, look_up3, look_down3;
ObjectID look_right4, look_left4, look_up4, look_down4;
ObjectID look_right5, look_left5, look_down5;
ObjectID look_right6, look_left6, look_up6;
ObjectID Object(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) {
		showObject(object);
	}
	return object;
}
void mouseCallback(ObjectID pobj, int px, int py, MouseAction act) {
	x = px; y = py; obj = pobj;
	if (obj == eb || obj == eeb)endGame();
	else if (305 <= x && x <= 350 && 397 <= y && y <= 547) showObject(scary);
	else if (obj == scary) hideObject(scary);
	else if (obj == look_right1 || obj == look_left1 || obj == look_up1 || obj == look_down1 || obj == look_right2 || obj == look_left2 || obj == look_up2 || obj == look_down2 || obj == look_right3 || obj == look_left3 || obj == look_up3 || obj == look_down3 || obj == look_right4 || obj == look_left4 || obj == look_up4 || obj == look_down4 || obj == look_right5 || obj == look_left5 || obj == look_down5 || obj == look_right6 || obj == look_left6 || obj == look_up6) {
		if (obj == look_right1 || obj == look_right2 || obj == look_right3 || obj == look_right4 || obj == look_right5 || obj == look_right6) {
			look = 10 * (look / 10) + (look % 10 + 5) % 4;
		}
		else if (obj == look_left1 || obj == look_left2 || obj == look_left3 || obj == look_left4 || obj == look_left5 || obj == look_left6) {
			look = 10 * (look / 10) + (look % 10 + 3) % 4;
		}
		else if (obj == look_up1 || obj == look_up2 || obj == look_up3 || obj == look_up4 || obj == look_up6) {
			if (look / 10 != 2) look += 10;
		}
		else if (obj == look_down1 || obj == look_down2 || obj == look_down3 || obj == look_down4 || obj == look_down5) {
			if (look / 10 != 0) look -= 10;
		}
		if ((look % 10) % 4 == 0 && look / 10 == 1) {
			enterScene(sc_front);
		}
		else if ((look % 10) % 4 == 1 && look / 10 == 1) {
			enterScene(sc_right);
		}
		else if ((look % 10) % 4 == 2 && look / 10 == 1) {
			enterScene(sc_back);
		}
		else if ((look % 10) % 4 == 3 && look / 10 == 1) {
			enterScene(sc_left);
		}
		else if (look / 10 == 2) {
			enterScene(sc_up);
		}
		else if (look / 10 == 0) {
			enterScene(sc_down);
		}
	}
}
int main() {
	setMouseCallback(mouseCallback);
	//씬
	{
		sc_front = createScene("", "\\images\\sc.png");
		sc_back = createScene("", "\\images\\sc.png");
		sc_right = createScene("", "\\images\\sc.png");
		sc_left = createScene("", "\\images\\sc.png");
		sc_up = createScene("", "\\images\\sc.png");
		sc_down = createScene("", "\\images\\sc.png");
	}
	//벽
	{
		gamesc_front = Object("\\images\\gamesc_front.png", sc_front, 0, 0, true);
		gamesc_right = Object("\\images\\gamesc_right.png", sc_right, 0, 0, true);
		gamesc_left = Object("\\images\\gamesc_left.png", sc_left, 0, 0, true);
		gamesc_back = Object("\\images\\gamesc_back.png", sc_back, 0, 0, true);
		gamesc_up = Object("\\images\\gamesc_up.png", sc_up, 0, 0, true);
		gamesc_down = Object("\\images\\gamesc_down.png", sc_down, 0, 0, true);
	}
	//화살표
	{
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
		look_right5 = Object("\\images\\look_right.png", sc_up, 450, 325, true);
		look_left5 = Object("\\images\\look_left.png", sc_up, 0, 325, true);
		look_down5 = Object("\\images\\look_down.png", sc_up, 225, 100, true);
		look_right6 = Object("\\images\\look_right.png", sc_down, 450, 325, true);
		look_left6 = Object("\\images\\look_left.png", sc_down, 0, 325, true);
		look_up6 = Object("\\images\\look_up.png", sc_down, 225, 550, true);
	}
	//sb = Object("\\images\\start.png", sc, 500, 45, true);
	//rb = Object("\\images\\restart.png", sc, 500, 45, false);
	//eeb = Object("\\images\\end.png", sc, 500, 10, true);
	//eb = Object("\\images\\end.png", sc, 500, 5, true);
	//rbb = Object("\\images\\restartt.png", sc, 500, 0, false);
	//scary = Object("\\images\\scary.png", sc, 0, 0, false);
	startGame(sc_front);
}