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
    SCENE_LEVELUP = 10,
    SCENE_TARGET = 11,
    SCENE_HOWTOPLAY2 = 12,
};

typedef struct
{
    float x,y; // the position of image
    float w,h; // the width and height of image
    float v;// velocity
	bool hidden;// Should we draw this object on the screen.
    bool dir; // left/down: false, right/up: true
    int type;//nose=0 or coin=1
    ALLEGRO_BITMAP *img_move;
}MovableObject;
extern MovableObject chara;
extern MovableObject nose[100];
extern MovableObject fire[6];

// note that you can't assign initial value here!
extern const float FPS;
extern const int WIDTH;
extern const int HEIGHT;

extern const int LEFT;
extern const int MIDDLE;
extern const int RIGHT;

extern int window;
extern bool judge_next_window;

extern int next;
extern int score;
extern char s[20];
extern int coin;
extern char c[20];
extern int level;
extern char l[20];

extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *fps;

extern ALLEGRO_SAMPLE*song;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instance;
extern ALLEGRO_SAMPLE*song11;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instance11;
extern ALLEGRO_SAMPLE*song12;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instance12;
extern ALLEGRO_SAMPLE*song13;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instance13;
extern ALLEGRO_SAMPLE*bubblee;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instancebubble;
extern ALLEGRO_SAMPLE*coinn;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instancecoin;
extern ALLEGRO_SAMPLE*starrr;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instancestar;
extern ALLEGRO_SAMPLE*click;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instanceclick;
extern ALLEGRO_SAMPLE*fir;
extern ALLEGRO_SAMPLE_INSTANCE*sample_instancefire;

extern ALLEGRO_DISPLAY*display;
extern ALLEGRO_FONT *font;
extern bool* mouse_state;
extern bool pause;

extern int nowchar;
extern bool longneck;
extern bool penguin;
extern bool dog;

extern int nowitem;
extern bool hat;
extern bool butterfly;
extern bool cry;
extern bool thunder;

extern bool bubble;
extern bool star;

void on_mouse_down(int btn, int x, int y);
bool pnt_in_rect(int px, int py, int x, int y, int w, int h);
extern int mouse_x, mouse_y;
#endif
