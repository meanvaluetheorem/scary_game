///////////////////////////////////////////////   띄어쓰기 줄바꾸기 금지   ///////////////////////////////////////////////
#include<stdio.h>
#include<bangtal.h>
#include<windows.h>
#include<math.h>
bool started = false, pick_kal = false, pick_key = false;
int x, y, look = 10, hit = 0, key_count = 0;
char key_input[1024];
SoundID scary_BGM;
SceneID sc_start, sc_front, sc_back, sc_right, sc_left, sc_up, sc_down, sc_roof, sc_scary, sc_keypan;
ObjectID obj, sb, rb, steb, eb, start_sc, light_1, light_2, key, kal, glasses, glasses_wire, keypan;
ObjectID wire_item, wire, blood;
ObjectID gamesc_front, gamesc_right, gamesc_left, gamesc_up, gamesc_down, gamesc_back, gamesc_roof;
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
void wire_see(bool shown) {
    if (shown == true) {
        showObject(wire);
    }
    else if (shown == false) {
        hideObject(wire);
    }
}
void starting(bool starter) {
    if (starter == true) { enterScene(sc_front);// playSound(scary_BGM); 
    }
    else enterScene(sc_start);
    started = starter;
}
void goscene(SceneID scene) {//sc_start, sc_front, sc_back, sc_right, sc_left, sc_up, sc_down, sc_roof, sc_scary, sc_keypan
    if (scene == sc_front){
        enterScene(sc_front);
        locateObject(look_right, sc_front, 470, 335);
        locateObject(look_left, sc_front, 0, 335);
        locateObject(look_up, sc_front, 215, 670);
        locateObject(look_down, sc_front, 215, 0);
        locateObject(wire, sc_front, 24, 0);
    }
    else if (scene == sc_back) {
        enterScene(sc_back);
        locateObject(look_right, sc_back, 470, 335);
        locateObject(look_left, sc_back, 0, 335);
        locateObject(look_up, sc_back, 215, 670);
        locateObject(look_down, sc_back, 215, 0);
        locateObject(wire, sc_back, 24, 0);
    }
    else if (scene == sc_right) {
        enterScene(sc_right);
        locateObject(look_right, sc_right, 470, 335);
        locateObject(look_left, sc_right, 0, 335);
        locateObject(look_up, sc_right, 215, 670);
        locateObject(look_down, sc_right, 215, 0);
        locateObject(wire, sc_right, 24, 0);
    }
    else if (scene == sc_left) {
        enterScene(sc_left);
        locateObject(look_right, sc_left, 470, 335);
        locateObject(look_left, sc_left, 0, 335);
        locateObject(look_up, sc_left, 215, 670);
        locateObject(look_down, sc_left, 215, 0);
        locateObject(wire, sc_left, 24, 0);
    }
    else if (scene == sc_up) {
        enterScene(sc_up);
        locateObject(look_down, sc_up, 215, 0);
        locateObject(wire, sc_up, 24, 0);
    }
    else if (scene == sc_down) {
        enterScene(sc_down);
        locateObject(look_up, sc_down, 215, 670);
        locateObject(wire, sc_down, 24, 0);
    }
    else if (scene == sc_roof) {
        enterScene(sc_roof);
        locateObject(wire, sc_roof, 24, 0);
    }
    else if (scene == sc_scary) {
        enterScene(sc_scary);
        locateObject(look_down, sc_scary, 215, 0);
        locateObject(wire, sc_scary, 24, 0);
    }
    else if (scene == sc_keypan) {
        enterScene(sc_keypan);
        locateObject(look_down, sc_keypan, 215, 0);
        locateObject(wire, sc_keypan, 24, 0);
    }

}
void keyboardControl(KeyCode code, KeyState state) {
    if (state == KeyState::KEY_PRESSED) {
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
        if (code == KeyCode::KEY_ENTER) {
            if (key_input == "1234")printf("   yes\n");
            else printf("   no\n");
            for (int k = 0; k < key_count + 1; k++)key_input[k] = 0;
            key_count = 0;
        }
        printf("   %s\n", key_input);
    }
}
void mouseControl(ObjectID pobj, int px, int py, MouseAction act) {
    x = px; y = py; obj = pobj;
    if (obj == sb) starting(true);
	else if (obj == wire_item) pickObject(wire_item);
	else if (obj == rb)   starting(false);
	else if (obj == eb || obj == steb)endGame();
	else if (started == true) {
        if (obj == blood) hideObject(blood);
		if (getHandObject() == glasses_wire)wire_see(true);
		else if (getHandObject() != glasses_wire)wire_see(false);
		if (obj == kal && pick_kal == false) { pickObject(kal); pick_kal = true; hit++; }
		else if (obj == kal && pick_kal == true) { pickObject(kal); }
		else if (31 > hit && hit >= 1 && obj == scary && getHandObject() == kal && pick_kal == true) hit += 10;
        if (hit == 31) { hideObject(scary); hideObject(small_scary); hit++; }
        else if (532 > hit && hit >= 32 && obj == light_1) hit += 100;
        if (hit == 532) { hideObject(light_1); hit++; }
        else if (5533 > hit && hit >= 533 && obj == light_2) hit += 1000;
        if (hit == 5533) { hideObject(light_2); hit++; }
        else if (obj == key && hit == 5534 && pick_key == false) { pickObject(key); pick_key = true; hit++; }
        else if (obj == key && hit == 5534 && pick_key == true) { pickObject(key); }
        else if (obj == roofin && hit == 5535 && getHandObject() == key) { hideObject(roofin); hit++; }
        else if (obj == roofin1 && hit == 5536) { hideObject(roofin1); hit++; }
        else if (obj == roofin2 && hit == 5537) { hideObject(roofin2); hit++; }
        else if (obj == roofin3 && hit == 5538) { hideObject(roofin3); hit++; }
        else if (obj == glasses) pickObject(glasses);
        else if (obj == small_scary || obj == no_scary) look += 1000;
        else if (obj == look_down7) look -= 1000;
        else if (obj == roofinf)look += 100;
        else if (obj == roofout)look -= 100;
        else if (obj == look_right) look = 100 * (look / 100) + 10 * (look / 10) + (look % 10 + 5) % 4;
        else if (obj == look_left) look = 100 * (look / 100) + 10 * (look / 10) + (look % 10 + 3) % 4;
        else if (obj == look_up) { if ((look % 100) / 10 != 2) look += 10; }
        else if (obj == look_down) { if ((look % 100) / 10 != 0) look -= 10; }
        if ((look % 10) % 4 == 0 && look / 10 == 1|| obj == scary || obj == empty_scary) goscene(sc_front);
        else if (look / 100 == 0 && (look % 10) % 4 == 1 && look / 10 == 1) goscene(sc_right);
        else if (look / 100 == 0 && (look % 10) % 4 == 2 && look / 10 == 1) goscene(sc_back);
        else if (look / 100 == 0 && (look % 10) % 4 == 3 && look / 10 == 1) goscene(sc_left);
        else if (look / 100 == 0 && look / 10 == 2) goscene(sc_up);
        else if (look / 100 == 0 && look / 10 == 0) goscene(sc_down);
        else if (look / 100 == 1) goscene(sc_roof);
        else if (look / 1000 == 1) goscene(sc_scary);
    }
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
        steb = Object("\\images\\end.png", sc_start, 368, 55, true);
        rb = Object("\\images\\restart.png", sc_front, 500, 55, true);
        eb = Object("\\images\\end.png", sc_front, 500, 25, true);
        gamesc_front = Object("\\images\\gamesc_front.png", sc_front, 0, 0, true);
        no_scary = Object("\\images\\no_scary.png", sc_front, 304, 396, true);
        small_scary = Object("\\images\\small_scary.png", sc_front, 304, 396, true);
        empty_scary = Object("\\images\\empty_scary.png", sc_scary, 0, 0, true);
        scary = Object("\\images\\scary.png", sc_scary, 0, 0, true);
        gamesc_right = Object("\\images\\gamesc_right.png", sc_right, 0, 0, true);
        gamesc_left = Object("\\images\\gamesc_left.png", sc_left, 0, 0, true);
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
        defineCombination( glasses,  wire_item,  glasses_wire);
        scary_BGM = playsound(scary_BGM, "", "\\sounds\\BGM.mp3", false, true);
    }
    startGame(sc_start);
}