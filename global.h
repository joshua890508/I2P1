#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#define GAME_TERMINATE -1
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
enum {
	SCENE_MENU = 1,
	SCENE_GAME = 2,
	SCENE_ABOUT = 3,
    SCENE_HOWTOPLAY = 4,
    SCENE_STORE = 5,
    SCENE_ITEM = 6,
    SCENE_PAUSE = 7,
    SCENE_WIN = 8,
    SCENE_LOSE = 9,
};

typedef struct
{
    int x,y; // the position of image
    int w,h; // the width and height of image
    int v;// velocity
	bool hidden;// Should we draw this object on the screen.
    bool dir; // left/down: false, right/up: true
    int type;//nose or coin
    ALLEGRO_BITMAP *img_move;
}MovableObject;
extern MovableObject chara;
extern MovableObject nose[50];
// note that you can't assign initial value here!
extern const float FPS;
extern const int WIDTH;
extern const int HEIGHT;

extern const int LEFT;
extern const int MIDDLE;
extern const int RIGHT;
extern bool judge_next_window;
extern int next;
extern int score;
extern char s[20000];
extern int coin;
extern char c[20000];
extern int window;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *fps;
extern ALLEGRO_SAMPLE*song;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instance;
extern ALLEGRO_SAMPLE*song2;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instance2;
extern ALLEGRO_DISPLAY*display;
extern ALLEGRO_FONT *font;
extern bool* mouse_state;
extern bool pause;

extern int nowchar;
extern bool longneck;
extern bool penguin;
extern bool dog;

extern bool nowitem[4];
extern bool hat;
extern bool butterfly;
extern bool cry;
extern bool thunder;
#endif
