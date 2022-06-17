#include "charater.h"

bool A,D;

void character_init(){
    // load character images
    if(nowchar == 1)chara.img_move = al_load_bitmap("./image/elephant.png");
    else if(nowchar == 2)chara.img_move = al_load_bitmap("./image/longneck.jpg");
    else if(nowchar == 3)chara.img_move = al_load_bitmap("./image/penguin.jpg");
    else if(nowchar == 4)chara.img_move = al_load_bitmap("./image/dog.png");
    // initial the geometric information of character
    chara.w = al_get_bitmap_width(chara.img_move);
    chara.h = al_get_bitmap_height(chara.img_move);
    chara.x = MIDDLE - chara.w/2;
    chara.y = 720 - chara.h/2;
    chara.dir = false;
}
void charater_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_KEY_DOWN )
        if( event.keyboard.keycode == ALLEGRO_KEY_P )
        {
            judge_next_window = true;
            next = SCENE_PAUSE;
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_A )
            A = true;
        else if( event.keyboard.keycode == ALLEGRO_KEY_D )
            D = true;
        else if( event.keyboard.keycode == ALLEGRO_KEY_J )
        {
            pause=!pause;
            if(pause)
            {
                al_stop_timer(fps);
                al_stop_sample_instance(sample_instance2);
            }
            else
            {
                al_start_timer(fps);
                al_play_sample_instance(sample_instance2);
            }
        }
}
void charater_update(){
    // use the idea of finite state machine to deal with different state
    if( A ){
        chara.dir = false;
        if(chara.x>LEFT - chara.w/2)chara.x -= 180;
        A = false;
    }
    else if( D ){
        chara.dir = true;
        if(chara.x<RIGHT - chara.w/2)chara.x += 180;
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
