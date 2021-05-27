#include<stdio.h>
#include<bangtal.h>
#include<windows.h>
#include<math.h>
int x, y, look = 10;
SceneID sc;
ObjectID obj, sb, rb, rbb, eeb, eb, startsc, look_right, look_left, look_up, look_down, gamesc_front, gamesc_right, gamesc_left, gamesc_up, gamesc_down, gamesc_back, scary;
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
	else if (obj == look_right || obj == look_left || obj == look_up || obj == look_down) {
		if (obj == look_right) {
			look = 10 * (look / 10) + (look % 10 + 5) % 4;
		}
		else if (obj == look_left) {
			look = 10 * (look / 10) + (look % 10 + 3) % 4;
		}
		else if (obj == look_up && look / 10 != 2) {
			look += 10;
		}
		else if (obj == look_down && look / 10 != 0) {
			look -= 10;
		}
		if (look % 4 == 0 && look / 10 == 1) {
			hideObject(gamesc_up);
			hideObject(gamesc_down);
			hideObject(gamesc_right);
			hideObject(gamesc_left);
			hideObject(gamesc_back);
			showObject(gamesc_front);
		}
		else if (look % 4 == 1 && look / 10 == 1) {
			hideObject(gamesc_up);
			hideObject(gamesc_down);
			hideObject(gamesc_front);
			hideObject(gamesc_left);
			hideObject(gamesc_back);
			showObject(gamesc_right);
		}
		else if (look % 4 == 3 && look / 10 == 1) {
			hideObject(gamesc_up);
			hideObject(gamesc_down);
			hideObject(gamesc_front);
			hideObject(gamesc_right);
			hideObject(gamesc_back);
			showObject(gamesc_left);
		}
		else if (look % 4 == 2 && look / 10 == 1) {
			hideObject(gamesc_up);
			hideObject(gamesc_down);
			hideObject(gamesc_front);
			hideObject(gamesc_right);
			hideObject(gamesc_left);
			showObject(gamesc_back);
		}
		else if (look / 10 == 2) {
			showObject(gamesc_up);
			hideObject(gamesc_down);
			hideObject(gamesc_front);
			hideObject(gamesc_right);
			hideObject(gamesc_left);
			hideObject(gamesc_back);
		}
		else if (look / 10 == 0) {
			hideObject(gamesc_up);
			showObject(gamesc_down);
			hideObject(gamesc_front);
			hideObject(gamesc_right);
			hideObject(gamesc_left);
			hideObject(gamesc_back);
		}
	}
}
int main() {
	setMouseCallback(mouseCallback);
	sc = createScene("", "\\images\\sc.png");
	//startsc = Object("\\images\\startsc.png", sc, 0, 0, true);
	gamesc_front = Object("\\images\\gamesc_front.png", sc, 0, 0, true);//앞벽
	gamesc_right = Object("\\images\\gamesc_right.png", sc, 0, 0, false);//오른쪽벽
	gamesc_left = Object("\\images\\gamesc_left.png", sc, 0, 0, false);//왼쪽벽
	gamesc_back = Object("\\images\\gamesc_back.png", sc, 0, 0, false);//뒷벽
	gamesc_up = Object("\\images\\gamesc_up.png", sc, 0, 0, false);//윗벽
	gamesc_down = Object("\\images\\gamesc_down.png", sc, 0, 0, false);//아랫벽
	look_right = Object("\\images\\look_right.png", sc, 450, 325, true);
	look_left = Object("\\images\\look_left.png", sc, 0, 325, true);
	look_up = Object("\\images\\look_up.png", sc, 225, 650, true);
	look_down = Object("\\images\\look_down.png", sc, 225, 0, true);
	sb = Object("\\images\\start.png", sc, 500, 45, true);
	rb = Object("\\images\\restart.png", sc, 500, 45, false);
	//eeb = Object("\\images\\end.png", sc, 500, 10, true);
	eb = Object("\\images\\end.png", sc, 500, 5, true);
	//rbb = Object("\\images\\restartt.png", sc, 500, 0, false);
	scary = Object("\\images\\scary.png", sc, 0, 0, false);
	startGame(sc);
}