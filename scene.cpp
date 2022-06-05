#include "scene.h"

enum {
	SCENE_MENU = 1,
	SCENE_GAME = 2,
	SCENE_ABOUT = 3,
    SCENE_HOWTOPLAY = 4,
    SCENE_STORE = 5,
    SCENE_ITEM = 6,
    SCENE_WIN = 7,
    SCENE_PAUSE = 8,
    SCENE_GAMEOVER = 9,
};

int mouse_x, mouse_y;
ALLEGRO_FONT *font = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *ABOUT = NULL;

void menu_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_KEY_UP )
        if( event.keyboard.keycode == ALLEGRO_KEY_ENTER )
            judge_next_window = true;
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            mouse_state[event.mouse.button] = true;
			on_mouse_down(event.mouse.button, event.mouse.x, event.mouse.y);
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouse_state[event.mouse.button] = false;
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        if (event.mouse.dx != 0 || event.mouse.dy != 0) {
            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
        }
    }
}
void about_process(ALLEGRO_EVENT event){
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            mouse_state[event.mouse.button] = true;
			on_mouse_down(event.mouse.button, event.mouse.x, event.mouse.y);
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouse_state[event.mouse.button] = false;
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        if (event.mouse.dx != 0 || event.mouse.dy != 0) {
            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
        }
    }
}
void store_process(ALLEGRO_EVENT event){
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            mouse_state[event.mouse.button] = true;
			on_mouse_down(event.mouse.button, event.mouse.x, event.mouse.y);
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouse_state[event.mouse.button] = false;
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        if (event.mouse.dx != 0 || event.mouse.dy != 0) {
            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
        }
    }
}

bool pnt_in_rect(int px, int py, int x, int y, int w, int h) {
	if (px < w && py > y) {
        if(px > x && py < h) return true;
        else return false;
	}
	else return false;
}

void on_mouse_down(int btn, int x, int y) {
	if (btn == 1) {
        if (window == SCENE_MENU)
        {
            if (pnt_in_rect(x, y, 350, 470, 495, 520)){
                judge_next_window = true;
                next=SCENE_GAME;
            }else if (pnt_in_rect(x, y, 350, 550, 475, 600)){
                judge_next_window = true;
                next=SCENE_ABOUT;
            }else if (pnt_in_rect(x, y, 330, 630, 530, 685)){
                judge_next_window = true;
                next=SCENE_HOWTOPLAY;
            }else if (pnt_in_rect(x, y, 350, 720, 480, 780)){
                judge_next_window = true;
                next=SCENE_STORE;
            }
        }
        else if (window == SCENE_ABOUT||window == SCENE_HOWTOPLAY)
        {
            if (pnt_in_rect(x, y, 0, 0, 600, 900)){
                judge_next_window = true;
                next=SCENE_MENU;
            }
        }
        else if (window == SCENE_STORE)
        {
            if (pnt_in_rect(x, y, 0, 0, 285, 280)){
                judge_next_window = true;
                next=SCENE_MENU;
            }else if (pnt_in_rect(x, y, 285, 280, 383, 330)){
                judge_next_window = true;
                next=SCENE_ITEM;
            }
        }
	}
}


void menu_init(){
    background = al_load_bitmap("./image/Menu (2).jpg");
}
void menu_draw(){
    al_draw_bitmap(background, 0, 0, 0);
}
void menu_destroy(){
    al_destroy_bitmap(background);
}

void game_scene2_init(){
    character_init();
}
void game_scene2_draw(){
    background = al_load_bitmap("./image/stage.jpg");
    al_draw_bitmap(background, 0, 0, 0);
    character_draw();
}
void game_scene2_destroy(){
    al_destroy_bitmap(background);
    character_destory();
}

void game_scene3_init(){
    ABOUT = al_load_bitmap("./image/about.jpg");
}
void game_scene3_draw(){
    al_draw_bitmap(ABOUT, 0, 0, 0);
}
void game_scene3_destroy(){
    al_destroy_bitmap(ABOUT);
}

void game_scene4_init(){
    ABOUT = al_load_bitmap("./image/Howtoplay.jpg");
}
void game_scene4_draw(){
    al_draw_bitmap(ABOUT, 0, 0, 0);
}
void game_scene4_destroy(){
    al_destroy_bitmap(ABOUT);
}

void game_scene5_init(){
    ABOUT = al_load_bitmap("./image/Store (1).jpg");
}
void game_scene5_draw(){
    al_draw_bitmap(ABOUT, 0, 0, 0);
}
void game_scene5_destroy(){
    al_destroy_bitmap(ABOUT);
}

void game_scene6_init(){
    ABOUT = al_load_bitmap("./image/ITEM.jpg");
}
void game_scene6_draw(){
    al_draw_bitmap(ABOUT, 0, 0, 0);
}
void game_scene6_destroy(){
    al_destroy_bitmap(ABOUT);
}