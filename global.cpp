#include "global.h"

// variables for global usage
const float FPS = 60.0;
const int WIDTH = 600;
const int HEIGHT = 900;

const int MIDDLE = WIDTH / 2;
const int LEFT = MIDDLE - 180;
const int RIGHT = MIDDLE + 180;

ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;

ALLEGRO_SAMPLE*song = NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instance;
ALLEGRO_SAMPLE*song11 = NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instance11;
ALLEGRO_SAMPLE*song12= NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instance12;
ALLEGRO_SAMPLE*song13= NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instance13;
ALLEGRO_SAMPLE*bubblee= NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instancebubble;
ALLEGRO_SAMPLE*coinn=NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instancecoin;
ALLEGRO_SAMPLE*starrr=NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instancestar;
ALLEGRO_SAMPLE*click=NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instanceclick;
ALLEGRO_SAMPLE*fir=NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instancefire;
ALLEGRO_SAMPLE*nos=NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instancenose;

GIF *win_gif;
GIF *lose_gif;

ALLEGRO_DISPLAY*display = NULL;
ALLEGRO_FONT *font = NULL;
bool judge_next_window = false;
bool* mouse_state;// Mouse position.
bool pause = false;

int next = 0;
int score;
char s[20];
int coin = 0;
char c[20];
int level = 3;
char l[20];

int nowchar = 1;
bool longneck = false;
bool penguin = false;
bool dog = false;

int nowitem = 0;
bool hat = false;
bool butterfly = false;
bool cry = false;
bool thunder = false;

bool bubble=false;
bool star=false;

MovableObject chara;
MovableObject nose[100];
MovableObject fire[6];

int mouse_x, mouse_y;


