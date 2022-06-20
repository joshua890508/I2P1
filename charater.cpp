#include "charater.h"

char cha[50];
unsigned int position;
bool A=false,D=false;
ALLEGRO_BITMAP *spause = NULL;

void character_init(){
    // load character images
    sprintf( cha, "./image/%d-%d-0.png", nowchar , nowitem );
    chara.img_move = al_load_bitmap(cha);
    // initial the geometric information of character
    chara.w = al_get_bitmap_width(chara.img_move);
    chara.h = al_get_bitmap_height(chara.img_move);
    chara.x = MIDDLE - chara.w/2;
    if(nowchar == 1)chara.y = 419;
    else if(nowchar == 2)chara.y = 629;
    else if(nowchar == 3)chara.y = 395;
    else if(nowchar == 4)chara.y = 634;
    if(nowchar==1)chara.dir = true;
    else chara.dir = false;
}

void charater_process(ALLEGRO_EVENT event){

    if( event.type == ALLEGRO_EVENT_KEY_DOWN )
        if( event.keyboard.keycode == ALLEGRO_KEY_A && !bubble)
            A=true;
        else if( event.keyboard.keycode == ALLEGRO_KEY_D && !bubble)
            D=true;
        else if( event.keyboard.keycode == ALLEGRO_KEY_F)
        {
            judge_next_window = true;
            next=SCENE_PAUSE;
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_P )
        {
            spause = al_load_bitmap("./image/smallpause.png");
            al_draw_bitmap(spause, 32, 2, 0);
            al_flip_display();
            pause=!pause;
            if(pause)
            {
                if(level==1)
                {
                    position=al_get_sample_instance_position(sample_instance11);
                    al_stop_timer(fps);
                    al_stop_sample_instance(sample_instance11);
                }else if(level==2)
                {
                    position=al_get_sample_instance_position(sample_instance12);
                    al_stop_timer(fps);
                    al_stop_sample_instance(sample_instance12);
                }else if(level==3)
                {
                    position=al_get_sample_instance_position(sample_instance13);
                    al_stop_timer(fps);
                    al_stop_sample_instance(sample_instance13);
                }else if(level==4)
                {
                    position=al_get_sample_instance_position(sample_instance14);
                    al_stop_timer(fps);
                    al_stop_sample_instance(sample_instance14);
                }
            }
            else
            {
                if(level==1)
                {
                    al_set_sample_instance_position(sample_instance11,position);
                    al_start_timer(fps);
                    al_play_sample_instance(sample_instance11);
                }
                else if(level==2)
                {
                    al_set_sample_instance_position(sample_instance12,position);
                    al_start_timer(fps);
                    al_play_sample_instance(sample_instance12);
                }
                else if(level==3)
                {
                    al_set_sample_instance_position(sample_instance13,position);
                    al_start_timer(fps);
                    al_play_sample_instance(sample_instance13);
                }
                else if(level==4)
                {
                    al_set_sample_instance_position(sample_instance14,position);
                    al_start_timer(fps);
                    al_play_sample_instance(sample_instance14);
                }
            }
        }
}

void charater_update(){
    // use the idea of finite state machine to deal with different state
    if( A ){
        if(nowchar!=1)chara.dir = false;
        else chara.dir = true;
        if(chara.x>LEFT - chara.w/2)
            chara.x -= 180;
        A=false;
    }
    else if( D ){
        if(nowchar==1)chara.dir = false;
        else chara.dir = true;
        if(chara.x < RIGHT - chara.w/2)
            chara.x += 180;
        D=false;
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
    al_destroy_bitmap(spause);
}
