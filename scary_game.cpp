///////////////////////////////////////////////   띄어쓰기 줄바꾸기 금지   ///////////////////////////////////////////////
#include<stdio.h>
#include<bangtal.h>
#include<windows.h>
#include<math.h>
int x, y, look = 10, hit = 0, key_count = 0, scene_add = 0;
char key_input[4];
SoundID scary_BGM;
SceneID sc_start, sc_front, sc_back, sc_right, sc_left, sc_up, sc_down, sc_roof, sc_scary, sc_keypan;
ObjectID obj, sb, rb, eb, start_sc, light_1, light_2, key, kal, glasses, glasses_wire, keypan;
ObjectID wire_item, wire, blood, hammer, huge, win;
ObjectID gamesc_front, gamesc_right, gamesc_left, gamesc_up, gamesc_down, gamesc_back, gamesc_roof, numpan;
ObjectID look_right, look_left, look_up, look_down;
ObjectID look_down5, look_down7, look_up6, roofin, roofin1, roofin2, roofin3, roofinf, roofout, scary, small_scary, no_scary, empty_scary;
ObjectID Object(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) showObject(object);
	return object;
}
SoundID playsound(SoundID sound, const char* soundname, const char* soundfile, bool playing, bool loop) {
	sound = createSound(soundfile);
	if (playing == true) playSound(sound, loop);
	if (1) showMessage("CAUTION!!!\nBGM IS LOUD");
	return sound;
}
void starting(bool starter) {
	if (starter == true) {
		enterScene(sc_front);// playSound(scary_BGM); 
	}
	else enterScene(sc_start);
}
void goscene(SceneID scene) {
	enterScene(scene);
	locateObject(eb, scene, 500, 25);
	locateObject(rb, scene, 500, 55);
	locateObject(wire, scene, 24, 0);
	showObject(rb);
	if (scene == sc_start) {
		scene_add = 0;
		locateObject(eb, scene, 368, 55);
		hideObject(rb);
	}
	else if (scene == sc_front || scene == sc_back || scene == sc_right || scene == sc_left) {
		if (scene == sc_front)scene_add = 1;
		else if (scene == sc_back)scene_add = 2;
		else if (scene == sc_right)scene_add = 3;
		else if (scene == sc_left)scene_add = 4;
		locateObject(look_right, scene, 470, 335);
		locateObject(look_left, scene, 0, 335);
		locateObject(look_up, scene, 215, 670);
		locateObject(look_down, scene, 215, 0);
	}
	else if (scene == sc_up) {
		scene_add = 5;
		locateObject(look_down, scene, 215, 100);
	}
	else if (scene == sc_scary) {
		scene_add = 6;
		locateObject(look_down, scene, 215, 0);
	}
	else if (scene == sc_keypan) {
		scene_add = 7;
		locateObject(look_down, scene, 215, 256);
	}
	else if (scene == sc_down) {
		scene_add = 8;
		locateObject(look_up, scene, 215, 570);
	}
	else if (scene == sc_roof) scene_add = 9;
}
void keyboardControl(KeyCode code, KeyState state) {
	if (state == KeyState::KEY_PRESSED && (obj == numpan || obj == keypan)) {
		if (code == KeyCode::KEY_0) key_input[key_count] = '0';
		else if (code == KeyCode::KEY_1) key_input[key_count] = '1';
		else if (code == KeyCode::KEY_2) key_input[key_count] = '2';
		else if (code == KeyCode::KEY_3) key_input[key_count] = '3';
		else if (code == KeyCode::KEY_4) key_input[key_count] = '4';
		else if (code == KeyCode::KEY_5) key_input[key_count] = '5';
		else if (code == KeyCode::KEY_6) key_input[key_count] = '6';
		else if (code == KeyCode::KEY_7) key_input[key_count] = '7';
		else if (code == KeyCode::KEY_8) key_input[key_count] = '8';
		else if (code == KeyCode::KEY_9) key_input[key_count] = '9';
		key_count++;
		if (key_count == 4) {
			if (key_input[0] == '5' && key_input[1] == '3' && key_input[2] == '7' && key_input[3] == '6') { showMessage("DORE OPENED\n"); showObject(win); }
			else showMessage("WRONG PASSWORD!!!\n");
			key_count = 0;
		}
	}
}
void mouseControl(ObjectID pobj, int px, int py, MouseAction act) {
	x = px; y = py; obj = pobj;
	if (getHandObject() == glasses_wire)showObject(wire);
	else if (getHandObject() != glasses_wire)hideObject(wire);
	if (obj == sb) goscene(sc_front);
	else if (obj == rb) goscene(sc_start);
	else if (obj == eb)endGame();
	else if (obj == win)endGame();
	else if (obj == wire_item) pickObject(wire_item);
	else if (obj == glasses) pickObject(glasses);
	else if (obj == key) pickObject(key);
	else if (obj == kal) pickObject(kal);
	else if (obj == hammer) pickObject(hammer);
	else if (obj == huge) pickObject(huge);
	else if (obj == blood && getHandObject() == huge) hideObject(blood);
	else if (obj == blood) showObject(huge);
	else if (obj == numpan) goscene(sc_keypan);
	else if (obj == look_down && scene_add <= 4) goscene(sc_down);
	else if (obj == look_up && scene_add <= 4 || obj == roofout) goscene(sc_up);
	else if (obj == look_right && scene_add == 4 || obj == look_left && scene_add == 3 || obj == look_down && (scene_add == 5 || scene_add == 6 || scene_add == 7) || obj == look_up && scene_add == 8) goscene(sc_front);
	else if (obj == look_right && scene_add == 1 || obj == look_left && scene_add == 2) goscene(sc_right);
	else if (obj == look_right && scene_add == 2 || obj == look_left && scene_add == 1) goscene(sc_left);
	else if (obj == look_right && scene_add == 3 || obj == look_left && scene_add == 4) goscene(sc_back);
	else if (obj == roofinf) goscene(sc_roof);
	else if (obj == small_scary || obj == no_scary) goscene(sc_scary);
	else if (obj == scary && getHandObject() == kal && hit < 2) hit++;
	else if (obj == scary && getHandObject() == kal && hit == 2) { hideObject(scary); hideObject(small_scary); }
	else if (obj == light_1 && getHandObject() == hammer && hit >= 2 && hit < 6) hit++;
	else if (obj == light_1 && getHandObject() == hammer && hit == 6) hideObject(light_1);
	else if (obj == light_2 && getHandObject() == hammer && hit >= 6 && hit < 10) hit++;
	else if (obj == light_2 && getHandObject() == hammer && hit == 10) hideObject(light_2);
	else if (obj == roofin && getHandObject() == key)  hideObject(roofin);
	else if (obj == roofin1) hideObject(roofin1);
	else if (obj == roofin2) hideObject(roofin2);
	else if (obj == roofin3) hideObject(roofin3);
}
int main() {
	setKeyboardCallback(keyboardControl);
	setMouseCallback(mouseControl);
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
		sc_keypan = createScene("", "\\images\\sc.png");
		start_sc = Object("\\images\\start_sc.png", sc_start, 0, 0, true);
		sb = Object("\\images\\start.png", sc_start, 38, 55, true);
		eb = Object("\\images\\end.png", sc_start, 368, 55, true);
		rb = Object("\\images\\restart.png", sc_front, 500, 55, true);
		gamesc_front = Object("\\images\\gamesc_front.png", sc_front, 0, 0, true);
		no_scary = Object("\\images\\no_scary.png", sc_front, 304, 396, true);
		small_scary = Object("\\images\\small_scary.png", sc_front, 304, 396, true);
		empty_scary = Object("\\images\\empty_scary.png", sc_scary, 0, 0, true);
		hammer = Object("\\images\\hammer.png", sc_scary, 0, 0, true);
		huge = Object("\\images\\huge.png", sc_scary, 370, 0, false);
		scary = Object("\\images\\scary.png", sc_scary, 0, 0, true);
		gamesc_right = Object("\\images\\gamesc_right.png", sc_right, 0, 0, true);
		gamesc_left = Object("\\images\\gamesc_left.png", sc_left, 0, 0, true);
		numpan = Object("\\images\\numpan.png", sc_left, 31, 305, true);
		gamesc_back = Object("\\images\\gamesc_back.png", sc_back, 0, 0, true);
		blood = Object("\\images\\blood.png", sc_back, 31, 283, true);
		gamesc_up = Object("\\images\\gamesc_up.png", sc_up, 0, 0, true);
		roofinf = Object("\\images\\roofinf.png", sc_up, 151, 181, true);
		roofin3 = Object("\\images\\roofin3.png", sc_up, 151, 181, true);
		roofin2 = Object("\\images\\roofin2.png", sc_up, 151, 181, true);
		roofin1 = Object("\\images\\roofin1.png", sc_up, 151, 181, true);
		roofin = Object("\\images\\roofin.png", sc_up, 151, 181, true);
		key = Object("\\images\\key.png", sc_up, 438, 144, true);
		light_1 = Object("\\images\\light.png", sc_up, 13, 122, true);
		light_2 = Object("\\images\\light.png", sc_up, 420, 121, true);
		gamesc_down = Object("\\images\\gamesc_down.png", sc_down, 0, 0, true);
		kal = Object("\\images\\kal.png", sc_down, 131, 229, true);
		gamesc_roof = Object("\\images\\gamesc_roof.png", sc_roof, 0, 0, true);
		roofout = Object("\\images\\roofout.png", sc_roof, 112, 88, true);
		glasses = Object("\\images\\glasses.png", sc_roof, 422, 180, true);
		wire_item = Object("\\images\\wire_item.png", sc_roof, 422, 380, true);
		glasses_wire = Object("\\images\\glasses_wire.png", sc_roof, 422, 580, false);
		keypan = Object("\\images\\keypan.png", sc_keypan, 0, 0, true);
		look_right = Object("\\images\\look_right.png", sc_front, 470, 335, true);
		look_left = Object("\\images\\look_left.png", sc_front, 0, 335, true);
		look_up = Object("\\images\\look_up.png", sc_front, 215, 670, true);
		look_down = Object("\\images\\look_down.png", sc_front, 215, 0, true);
		wire = Object("\\images\\gamesc_wire.png", sc_front, 24, 0, false);
		win = Object("\\images\\win.png", sc_front, 0, 0, false);
		defineCombination(glasses, wire_item, glasses_wire);
		scary_BGM = playsound(scary_BGM, "", "\\sounds\\BGM.mp3", false, true);
	}
	startGame(sc_start);
}