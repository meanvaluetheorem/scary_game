//scary_game
#include<stdio.h>
#include<bangtal.h>
#include<windows.h>
#include<math.h>
int x, y;
SceneID sc;
ObjectID obj, sb, rb, rbb, eeb, eb, startsc, gamesc1, scary;
ObjectID Object(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) {
		showObject(object);
	}
	return object;
}
void scaryscary() {
	showObject(scary);
}
void notscary() {
	hideObject(scary);
}
void mouseCallback(ObjectID pobj, int px, int py, MouseAction act) {
	x = px; y = py; obj = pobj;
	if (obj == eb || obj == eeb)endGame();
	else if (305 <= x && x <= 350 && 397 <= y && y <= 547) scaryscary();
	else if (obj == scary) notscary();
}
int main() {
	setMouseCallback(mouseCallback);
	sc = createScene("", "\\images\\sc.png");
	//startsc = Object("\\images\\startsc.png", sc, 0, 0, true);
	gamesc1 = Object("\\images\\gamesc1.png", sc, 0, 0, true);
	sb = Object("\\images\\start.png", sc, 500, 45, true);
	rb = Object("\\images\\restart.png", sc, 500, 45, false);
	//eeb = Object("\\images\\end.png", sc, 500, 10, true);
	eb = Object("\\images\\end.png", sc, 500, 5, true);
	//rbb = Object("\\images\\restartt.png", sc, 500, 0, false);
	scary = Object("\\images\\scary.png", sc, 0, 0, false);
	startGame(sc);
}//존경감사요