////////////////////////////////////////////////   띄어쓰기 줄바꾸기 금지   ////////////////////////////////////////////////g
#include<stdio.h>
#include<bangtal.h>
bool brighter = false;
int hit = 0, key_count = -1, scene_add = 0, key_input[4] = { 0, }, ending_y = -1400;
float chong_tang_time = 0.05f, hammer_tang_time = 0.08f, ending_speed = 0.005f;
SoundID scary_BGM, gun_fire, glass_broken, button_sound, key_sound, wrong_sound, win_sound;
TimerID time_chong, time_hammer, ending_time;
SceneID sc_start, sc_front, sc_back, sc_right, sc_left, sc_up, sc_down, sc_roof, sc_scary, sc_keypan1, sc_keypan2, sc_win;
ObjectID sb, pb, eb, start_sc, light_1, light_2, key, chong, son_chong, chong_tang, glasses, glasses_wire, keypan1, keypan2;
ObjectID wire_item, wire, blood, empty_blood, hammer, son_hammer, hammer_tang, huge, win, look_right, look_left, look_up, look_down;
ObjectID ending, gamesc_front, gamesc_right, gamesc_left, gamesc_up, gamesc_down, gamesc_back, gamesc_roof, numpan1, numpan2;
ObjectID roofin, roofin1, roofin2, roofin3, roofinf, roofout, scary, small_scary, no_scary, empty_scary, num[4];
ObjectID Object(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) showObject(object);
	return object;
}
SoundID playsound(SoundID sound, const char* soundname, const char* soundfile, bool loop) {
	sound = createSound(soundfile);
	if (loop == true) playSound(sound, true);
	else playSound(sound, false);
	return sound;
}
void goscene(SceneID scene) {
	enterScene(scene);
	locateObject(son_chong, scene, 300, 0);
	locateObject(chong_tang, scene, 300, 0);
	locateObject(son_hammer, scene, 400, 0);
	locateObject(hammer_tang, scene, 250, -100);
	locateObject(eb, scene, 650, 25);
	locateObject(pb, scene, 650, 60);
	locateObject(wire, scene, 24, 0);
	showObject(pb);
	if (scene == sc_start) { scene_add = 0; locateObject(eb, scene, 368, 55); hideObject(pb); }
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
	else if (scene == sc_up) { scene_add = 5; locateObject(look_down, scene, 215, 100); }
	else if (scene == sc_scary) { scene_add = 6; locateObject(look_down, scene, 215, 0); }
	else if (scene == sc_keypan1) { scene_add = 7; locateObject(look_down, scene, 215, 256); }
	else if (scene == sc_down) { scene_add = 8; locateObject(look_up, scene, 215, 570); }
	else if (scene == sc_roof) scene_add = 9;
	else if (scene == sc_keypan2) { scene_add = 10; locateObject(look_down, scene, 215, 256); }
}
void bang() { hideObject(son_chong); gun_fire = playsound(gun_fire, "", "\\sounds\\gun_fire.mp3", false); showObject(chong_tang); startTimer(time_chong); }
void bbak() { hideObject(son_hammer); glass_broken = playsound(glass_broken, "", "\\sounds\\glass_broken.mp3", false); showObject(hammer_tang); startTimer(time_hammer); }
void winwin() { enterScene(sc_win); stopSound(scary_BGM); locateObject(eb, sc_win, 650, 25); win_sound = playsound(win_sound, "", "\\sounds\\win_sound.mp3", false); startTimer(ending_time); }
void timerControl(TimerID timer) {
	if (timer == time_chong) { hideObject(chong_tang); showObject(son_chong); setTimer(time_chong, chong_tang_time); }
	else if (timer == time_hammer) { hideObject(hammer_tang); showObject(son_hammer); setTimer(time_hammer, hammer_tang_time); }
	else if (timer == ending_time && ending_y < 0) { ending_y++; locateObject(ending, sc_win, 0, ending_y); setTimer(ending_time, ending_speed); startTimer(ending_time); }
	else if (timer == ending_time && ending_y == 0) { ending_y = -1400; locateObject(ending, sc_win, 0, ending_y); setTimer(ending_time, ending_speed); startTimer(ending_time); }
}
void keyboardControl(KeyCode code, KeyState state) {
	if (state == KeyState::KEY_PRESSED && (scene_add == 7 || scene_add == 10)) button_sound = playsound(button_sound, "", "\\sounds\\elevator.mp3", false);
	if (state == KeyState::KEY_PRESSED && (scene_add == 7 || scene_add == 10) && code != KeyCode::KEY_BACKSPACE && key_count < 3) {
		button_sound = playsound(button_sound, "", "\\sounds\\elevator.mp3", false);
		key_count++;
		if (code == KeyCode::KEY_1) key_input[key_count] = 1;
		else if (code == KeyCode::KEY_2) key_input[key_count] = 2;
		else if (code == KeyCode::KEY_3) key_input[key_count] = 3;
		else if (code == KeyCode::KEY_4) key_input[key_count] = 4;
		else if (code == KeyCode::KEY_5) key_input[key_count] = 5;
		else if (code == KeyCode::KEY_6) key_input[key_count] = 6;
		else if (code == KeyCode::KEY_7) key_input[key_count] = 7;
		else if (code == KeyCode::KEY_8) key_input[key_count] = 8;
		else if (code == KeyCode::KEY_9) key_input[key_count] = 9;
		else key_count--;
		for (int k = 0; k < 4; k++) {
			if (scene_add == 7 && key_count == k) {
				if (key_input[key_count] == 1)num[k] = Object("\\images\\num1.png", sc_keypan1, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 2)num[k] = Object("\\images\\num2.png", sc_keypan1, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 3)num[k] = Object("\\images\\num3.png", sc_keypan1, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 4)num[k] = Object("\\images\\num4.png", sc_keypan1, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 5)num[k] = Object("\\images\\num5.png", sc_keypan1, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 6)num[k] = Object("\\images\\num6.png", sc_keypan1, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 7)num[k] = Object("\\images\\num7.png", sc_keypan1, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 8)num[k] = Object("\\images\\num8.png", sc_keypan1, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 9)num[k] = Object("\\images\\num9.png", sc_keypan1, 200 + 25 * key_count, 434, true);
			}
			else if (scene_add == 10 && key_count == k) {
				if (key_input[key_count] == 1)num[k] = Object("\\images\\num1.png", sc_keypan2, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 2)num[k] = Object("\\images\\num2.png", sc_keypan2, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 3)num[k] = Object("\\images\\num3.png", sc_keypan2, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 4)num[k] = Object("\\images\\num4.png", sc_keypan2, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 5)num[k] = Object("\\images\\num5.png", sc_keypan2, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 6)num[k] = Object("\\images\\num6.png", sc_keypan2, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 7)num[k] = Object("\\images\\num7.png", sc_keypan2, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 8)num[k] = Object("\\images\\num8.png", sc_keypan2, 200 + 25 * key_count, 434, true);
				else if (key_input[key_count] == 9)num[k] = Object("\\images\\num9.png", sc_keypan2, 200 + 25 * key_count, 434, true);
			}
		}
		if (key_count == 3) if (key_input[0] == 5 && key_input[1] == 4 && key_input[2] == 9 && key_input[3] == 1) winwin(); else { showMessage("WRONG PASSWORD!!!\n"); wrong_sound = playsound(wrong_sound, "", "\\sounds\\wrong_sound.mp3", false); }
	}
	if (state == KeyState::KEY_PRESSED && code == KeyCode::KEY_BACKSPACE && key_count > -1 && (scene_add == 7 || scene_add == 10)) { hideObject(num[key_count]); key_count--; }
}
void mouseControl(ObjectID obj, int x, int y, MouseAction act) {
	if (getHandObject() == hammer) { showObject(son_hammer); if (obj == light_1 || obj == light_2) bbak(); }
	else if (getHandObject() != hammer) hideObject(son_hammer);
	if (getHandObject() == chong) { showObject(son_chong); if (obj == scary) bang(); }
	else if (getHandObject() != chong) hideObject(son_chong);
	if (getHandObject() == glasses) hideObject(empty_blood);
	else if (getHandObject() == glasses_wire) showObject(wire);
	else if (getHandObject() != glasses_wire) hideObject(wire);
	if (obj == sb) goscene(sc_front);
	else if (obj == pb) goscene(sc_start);
	else if (obj == eb)endGame();
	else if (obj == win)showObject(ending);
	else if (obj == ending)endGame();
	else if (obj == wire_item) pickObject(wire_item);
	else if (obj == glasses) pickObject(glasses);
	else if (obj == glasses_wire) pickObject(glasses_wire);
	else if (obj == key) pickObject(key);
	else if (obj == chong) pickObject(chong);
	else if (obj == hammer) pickObject(hammer);
	else if (obj == huge) pickObject(huge);
	else if (obj == blood && getHandObject() == huge) hideObject(blood);
	else if (obj == blood) showObject(huge);
	else if (obj == numpan1) goscene(sc_keypan1);
	else if (obj == numpan2) goscene(sc_keypan2);
	else if (obj == look_down && scene_add <= 4) goscene(sc_down);
	else if (obj == look_up && scene_add <= 4 || obj == roofout) goscene(sc_up);
	else if (obj == look_right && scene_add == 4 || obj == look_left && scene_add == 3 || obj == look_down && (scene_add == 5 || scene_add == 6 || scene_add == 7 || scene_add == 10) || obj == look_up && scene_add == 8) goscene(sc_front);
	else if (obj == look_right && scene_add == 1 || obj == look_left && scene_add == 2) goscene(sc_right);
	else if (obj == look_right && scene_add == 2 || obj == look_left && scene_add == 1) goscene(sc_left);
	else if (obj == look_right && scene_add == 3 || obj == look_left && scene_add == 4) goscene(sc_back);
	else if (obj == roofinf) goscene(sc_roof);
	else if (obj == small_scary || obj == no_scary) goscene(sc_scary);
	else if (obj == scary && getHandObject() == chong && hit < 2) hit++;
	else if (obj == scary && getHandObject() == chong && hit == 2) { hideObject(scary); showMessage("OUT OF AMMO!!!"); hideObject(small_scary); }
	else if (obj == light_1 && getHandObject() == hammer && hit >= 2 && hit < 6) hit++;
	else if (obj == light_1 && getHandObject() == hammer && hit == 6) hideObject(light_1);
	else if (obj == light_2 && getHandObject() == hammer && hit >= 6 && hit < 10) hit++;
	else if (obj == light_2 && getHandObject() == hammer && hit == 10) hideObject(light_2);
	else if (obj == light_1)  showObject(hammer);
	else if (obj == roofin && getHandObject() == key) { hideObject(roofin); key_sound = playsound(key_sound, "", "\\sounds\\key.mp3", false); }
	else if (obj == roofin1) hideObject(roofin1);
	else if (obj == roofin2) hideObject(roofin2);
	else if (obj == roofin3) hideObject(roofin3);
}
int main() {
	setTimerCallback(timerControl);
	setKeyboardCallback(keyboardControl);
	setMouseCallback(mouseControl);
	sc_start = createScene("", "\\images\\sc.png");
	sc_front = createScene("", "\\images\\sc.png");
	sc_back = createScene("", "\\images\\sc.png");
	sc_right = createScene("", "\\images\\sc.png");
	sc_left = createScene("", "\\images\\sc.png");
	sc_up = createScene("", "\\images\\sc.png");
	sc_down = createScene("", "\\images\\sc.png");
	sc_scary = createScene("", "\\images\\sc.png");
	sc_roof = createScene("", "\\images\\sc.png");
	sc_keypan1 = createScene("", "\\images\\sc.png");
	sc_keypan2 = createScene("", "\\images\\sc.png");
	sc_win = createScene("", "\\images\\sc.png");
	start_sc = Object("\\images\\start_sc.png", sc_start, 0, 0, true);
	sb = Object("\\images\\start.png", sc_start, 38, 55, true);
	eb = Object("\\images\\end.png", sc_start, 368, 55, true);
	pb = Object("\\images\\pause.png", sc_front, 650, 60, true);
	gamesc_front = Object("\\images\\gamesc_front.png", sc_front, 0, 0, true);
	numpan2 = Object("\\images\\numpan2.png", sc_front, 420, 316, true);
	no_scary = Object("\\images\\no_scary.png", sc_front, 304, 396, true);
	small_scary = Object("\\images\\small_scary.png", sc_front, 304, 396, true);
	empty_scary = Object("\\images\\empty_scary.png", sc_scary, 0, 0, true);
	hammer = Object("\\images\\hammer.png", sc_scary, 0, 0, false);
	huge = Object("\\images\\huge.png", sc_scary, 370, 0, false);
	scary = Object("\\images\\scary.png", sc_scary, 0, 0, true);
	gamesc_right = Object("\\images\\gamesc_right.png", sc_right, 0, 0, true);
	gamesc_left = Object("\\images\\gamesc_left.png", sc_left, 0, 0, true);
	numpan1 = Object("\\images\\numpan1.png", sc_left, 31, 305, true);
	gamesc_back = Object("\\images\\gamesc_back.png", sc_back, 0, 0, true);
	blood = Object("\\images\\blood.png", sc_back, 31, 283, true);
	empty_blood = Object("\\images\\empty_blood.png", sc_back, 0, 0, true);
	gamesc_up = Object("\\images\\gamesc_up.png", sc_up, 0, 0, true);
	roofinf = Object("\\images\\roofinf.png", sc_up, 151, 181, true);
	roofin3 = Object("\\images\\roofin3.png", sc_up, 151, 181, true);
	roofin2 = Object("\\images\\roofin2.png", sc_up, 151, 181, true);
	roofin1 = Object("\\images\\roofin1.png", sc_up, 151, 181, true);
	roofin = Object("\\images\\roofin.png", sc_up, 151, 181, true);
	key = Object("\\images\\key.png", sc_up, 438, 400, true);
	light_1 = Object("\\images\\light.png", sc_up, 13, 122, true);
	light_2 = Object("\\images\\light.png", sc_up, 420, 121, true);
	gamesc_down = Object("\\images\\gamesc_down.png", sc_down, 0, 0, true);
	chong = Object("\\images\\chong.png", sc_down, 131, 229, true);
	son_chong = Object("\\images\\son_chong.png", sc_down, 300, 0, false);
	chong_tang = Object("\\images\\chong_tang.png", sc_down, 300, 0, false);
	son_hammer = Object("\\images\\son_hammer.png", sc_scary, 400, 0, false);
	hammer_tang = Object("\\images\\hammer_tang.png", sc_scary, 250, -100, false);
	gamesc_roof = Object("\\images\\gamesc_roof.png", sc_roof, 0, 0, true);
	roofout = Object("\\images\\roofout.png", sc_roof, 175, 60, true);
	glasses = Object("\\images\\glasses.png", sc_roof, 415, 163, true);
	wire_item = Object("\\images\\wire_item.png", sc_roof, 171, 280, true);
	glasses_wire = Object("\\images\\glasses_wire.png", sc_roof, 422, 580, false);
	keypan1 = Object("\\images\\keypan.png", sc_keypan1, 0, 0, true);
	keypan2 = Object("\\images\\keypan.png", sc_keypan2, 0, 0, true);
	look_right = Object("\\images\\look_right.png", sc_front, 470, 335, true);
	look_left = Object("\\images\\look_left.png", sc_front, 0, 335, true);
	look_up = Object("\\images\\look_up.png", sc_front, 215, 670, true);
	look_down = Object("\\images\\look_down.png", sc_front, 215, 0, true);
	wire = Object("\\images\\gamesc_wire.png", sc_front, 24, 0, false);
	win = Object("\\images\\win.png", sc_win, 0, 0, true);
	ending = Object("\\images\\ending.png", sc_win, 0, ending_y, false);
	defineCombination(glasses, wire_item, glasses_wire);
	scary_BGM = playsound(scary_BGM, "", "\\sounds\\BGM.mp3", true);
	time_chong = createTimer(chong_tang_time);
	time_hammer = createTimer(hammer_tang_time);
	ending_time = createTimer(ending_speed);
	startGame(sc_start);
}