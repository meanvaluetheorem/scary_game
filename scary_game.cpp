#include<stdio.h>
#include<bangtal.h>
#include<windows.h>
#include<math.h>
int x, y, look=0;
SceneID sc;
ObjectID obj, sb, rb, rbb, eeb, eb, startsc, look_right, look_left, gamesc_front, gamesc_right, gamesc_left, gamesc_up, gamesc_down, gamesc_back, scary;
ObjectID Object(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) {
		showObject(object);
	}
	return object;
}//
void mouseCallback(ObjectID pobj, int px, int py, MouseAction act) {
	x = px; y = py; obj = pobj;
	if (obj == eb || obj == eeb)endGame();
	else if (305 <= x && x <= 350 && 397 <= y && y <= 547) showObject(scary);
	else if (obj == scary) hideObject(scary);
	else if (obj == look_right||obj == look_left) {
		if (obj == look_right) {
			look++;
		}
		else if (obj == look_left) {
			look--;
		}
		if (look % 4 == 0) {
			hideObject(gamesc_right);
			hideObject(gamesc_left);
			hideObject(gamesc_back);
			showObject(gamesc_front);
		}
		else if (look % 4 == 1) {
			hideObject(gamesc_front);
			hideObject(gamesc_left);
			hideObject(gamesc_back);
			showObject(gamesc_right);
		}
		else if (look % 4 == 3) {
			hideObject(gamesc_front);
			hideObject(gamesc_right);
			hideObject(gamesc_back);
			showObject(gamesc_left);
		}
		else if (look % 4 == 2) {
			hideObject(gamesc_front);
			hideObject(gamesc_right);
			hideObject(gamesc_left);
			showObject(gamesc_back);
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
	gamesc_up = Object("\\images\\gamesc_up.png", sc, 0, 0, false);//윗벽
	gamesc_down = Object("\\images\\gamesc_down.png", sc, 0, 0, false);//아랫벽
	gamesc_back = Object("\\images\\gamesc_back.png", sc, 0, 0, false);//뒷벽
	look_right = Object("\\images\\look_right.png", sc, 450, 295, true);
	look_left = Object("\\images\\look_left.png", sc, 0, 295, true);
	sb = Object("\\images\\start.png", sc, 500, 45, true);
	rb = Object("\\images\\restart.png", sc, 500, 45, false);
	//eeb = Object("\\images\\end.png", sc, 500, 10, true);
	eb = Object("\\images\\end.png", sc, 500, 5, true);
	//rbb = Object("\\images\\restartt.png", sc, 500, 0, false);
	scary = Object("\\images\\scary.png", sc, 0, 0, false);
	startGame(sc);
}