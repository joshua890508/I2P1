#include "charater.h"

bool A,D;

typedef struct character
{
    int x,y; // the position of image
    int width, height; // the width and height of image
    bool dir; // left: false, right: true
    ALLEGRO_BITMAP *img_move;
}Character;
Character chara;

void character_init(){
    // load character images
    chara.img_move = al_load_bitmap("./image/char_move1.png");
    // initial the geometric information of character
    chara.width = al_get_bitmap_width(chara.img_move);
    chara.height = al_get_bitmap_height(chara.img_move);
    chara.x = 190;
    chara.y = 550;
    chara.dir = false;
}

void charater_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_KEY_UP )
        if( event.keyboard.keycode == ALLEGRO_KEY_P )
        {
            judge_next_window = true;
            next = SCENE_PAUSE;
        }
    if( event.type == ALLEGRO_EVENT_KEY_UP )
        if( event.keyboard.keycode == ALLEGRO_KEY_A )
            A = true;
        else if( event.keyboard.keycode == ALLEGRO_KEY_D )
            D = true;
}
void charater_update(){
    // use the idea of finite state machine to deal with different state
    if( A ){
        chara.dir = false;
        if(chara.x>35)chara.x -= 180;
        A = false;
    }else if( D ){
        chara.dir = true;
        if(chara.x<335)chara.x += 180;
        D = false;
    }
}
void character_draw(){
    // with the state, draw corresponding image
    if( chara.dir )
        al_draw_bitmap(chara.img_move, chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
    else
        al_draw_bitmap(chara.img_move, chara.x, chara.y, 0);
}
void character_destory(){
    al_destroy_bitmap(chara.img_move);
}
