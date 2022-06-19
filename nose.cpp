#include "nose.h"
char ch[50];
int startstar;
int startbubble;
int min=0, max;

void nose_init()
{
    star=false;
    bubble=false;
    score = 0;
    srand( time(NULL) );
    for( int i=0; i<6; i++)
    {
        fire[i].img_move = al_load_bitmap("./image/fire.png");
        fire[i].w = al_get_bitmap_width(fire[i].img_move);
        fire[i].h = al_get_bitmap_height(fire[i].img_move);
        max = 2;
        fire[i].x = LEFT + 180*( rand() % (max - min + 1) + min) - fire[i].w/2;
        fire[i].y = 100 - fire[i].h/2;
        fire[i].v = 15;
        fire[i].hidden = true;
    }
    if(fire[4].x!=LEFT-fire[4].w/2)fire[5].x = LEFT-fire[5].w/2;
    else fire[5].x = MIDDLE-fire[5].w/2;

    for( int i=0; i<14; i++)
    {
        if(level==1)
        {
            max = 3;
            nose[i].type=rand() % (max - min + 1) + min;
            if(nose[i].type)nose[i].img_move = al_load_bitmap("./image/nose.png");
            else nose[i].img_move = al_load_bitmap("./image/coin.png");
            // initial the geometric information of character
            nose[i].w = al_get_bitmap_width(nose[i].img_move);
            nose[i].h = al_get_bitmap_height(nose[i].img_move);
            max = 2;
            nose[i].x = LEFT + 180*( rand() % (max - min + 1) + min) - nose[i].w/2;
            nose[i].y = 100 - nose[i].h/2;
            nose[i].v = 7.7;
            nose[i].hidden = true;
        }
        else if(level==2)
        {
            max = 7;
            nose[i].type=rand() % (max - min + 1) + min;
            if(nose[i].type==0)nose[i].img_move = al_load_bitmap("./image/coin.png");
            else if(nose[i].type==1)nose[i].img_move = al_load_bitmap("./image/star.png");
            else if(nose[i].type==2)nose[i].img_move = al_load_bitmap("./image/bubble.png");
            else nose[i].img_move = al_load_bitmap("./image/nose.png");
            // initial the geometric information of character
            nose[i].w = al_get_bitmap_width(nose[i].img_move);
            nose[i].h = al_get_bitmap_height(nose[i].img_move);
            max = 2;
            nose[i].x = LEFT + 180*( rand() % (max - min + 1) + min) - nose[i].w/2;
            nose[i].y = 100.1 - nose[i].h/2;
            nose[i].v = 7.9;
            nose[i].hidden = true;
        }
        else if(level==3)
        {
            max = 7;
            nose[i].type=rand() % (max - min + 1) + min;
            if(nose[i].type==0)nose[i].img_move = al_load_bitmap("./image/coin.png");
            else if(nose[i].type==1)nose[i].img_move = al_load_bitmap("./image/star.png");
            else if(nose[i].type==2)nose[i].img_move = al_load_bitmap("./image/bubble.png");
            else nose[i].img_move = al_load_bitmap("./image/nose.png");
            // initial the geometric information of character
            nose[i].w = al_get_bitmap_width(nose[i].img_move);
            nose[i].h = al_get_bitmap_height(nose[i].img_move);
            max = 2;
            nose[i].x = LEFT + 180*( rand() % (max - min + 1) + min) - nose[i].w/2;
            nose[i].y = 100 - nose[i].h/2;
            nose[i].v = 9;
            nose[i].hidden = true;
        }
    }
    nose[0].hidden = false;//first nose
}

void nose_update(){
    for(int i=0;i<14;i++)
    {
        if (!nose[i].hidden)
        {
            if(level==3)
            {
                if(i==2)fire[0].hidden=false;
                else if(i==5)fire[1].hidden=false;
                else if(i==8)fire[2].hidden=false;
                else if(i==10)fire[3].hidden=false;
                else if(i==12)fire[4].hidden=false,fire[5].hidden=false;
            }
            nose[i].y+=nose[i].v;
            if (nose[i].y>=285 && nose[i].y<=310)//next nose
             {
                nose[i+1].hidden=false;
                if(star && i == startstar + 4)star=false;
                if(bubble && i == startbubble + 3)bubble=false;
             }
            else if (nose[i].y>=550 && nose[i].y<=580)//same y position
            {
                if(chara.x+chara.w/2==nose[i].x+nose[i].w/2)//same x position
                {
                    nose[i].hidden = true;
                    if(level == 1)
                    {
                        score+=5;
                        if(nose[i].type==0)
                        {
                            al_play_sample_instance(sample_instancecoin);
                            coin+=3;
                        }
                        else al_play_sample_instance(sample_instancenose);
                    }
                    else if(level == 2 || level == 3)
                    {
                        if(bubble)
                        {
                            score-=5;
                            if(nose[i].type==0)coin+=3;
                        }
                        score+=5;
                        if(nose[i].type==0)
                        {
                            al_play_sample_instance(sample_instancecoin);
                            coin+=3;
                        }
                        else if(nose[i].type==1)
                        {
                            al_play_sample_instance(sample_instancestar);
                            star=true;
                            startstar=i;
                        }
                        else if(nose[i].type==2)
                        {
                            al_play_sample_instance(sample_instancebubble);
                            score-=5;
                            bubble=true;
                            startbubble=i;
                        }
                        else al_play_sample_instance(sample_instancenose);
                        if(star)
                        {
                            if(nose[i].type!=2)
                            {
                                score+=5;
                                if(nose[i].type==0)coin+=3;
                            }
                        }
                    }
                    if(score>=65)sprintf( ch, "./image/%d-%d-3.png", nowchar , nowitem );
                    else if(score>=40&&score<65)sprintf( ch, "./image/%d-%d-2.png", nowchar , nowitem );
                    else if(score>=20&&score<40)sprintf( ch, "./image/%d-%d-1.png", nowchar , nowitem );
                    else sprintf( ch, "./image/%d-%d-0.png", nowchar , nowitem );
                    chara.img_move = al_load_bitmap(ch);
                }
                if(i == 13)//last nose
                {
                    judge_next_window=true;
                    if(score >= 60)
                    {
                        if(level!=3)next = SCENE_LEVELUP,level++;
                        else next = SCENE_WIN,level=1;
                    }
                    else next = SCENE_LOSE;
                }
            }
        }
    }
    for(int i=0;i<6;i++)
        if (!fire[i].hidden)
        {
            fire[i].y+=fire[i].v;
            if (fire[i].y>=550 && fire[i].y<=570)//same y position
                if(chara.x+chara.w/2==fire[i].x+fire[i].w/2)//same x position
                {
                    al_play_sample_instance(sample_instancefire);
                    score-=10,coin-=10;
                }
        }
}

void nose_draw(){
    for(int i=0;i<14;i++)
        if (!nose[i].hidden)
            al_draw_bitmap(nose[i].img_move, nose[i].x, nose[i].y, 0);
    for( int i=0; i<6; i++)
        if (!fire[i].hidden)
            al_draw_bitmap(fire[i].img_move, fire[i].x, fire[i].y, 0);

    sprintf(s, "%d", score);
    sprintf(c, "%d", coin);
    sprintf(l, "%d", level);
    if(star)
    {
        al_draw_text(font, al_map_rgb(255,255,255), 350, 50, 0, s);
        al_draw_text(font, al_map_rgb(255,255,255), 520, 50, 0, c);
        al_draw_text(font, al_map_rgb(255,255,255), 200, 55, 0, l);
    }
    else{
        al_draw_text(font, al_map_rgb(0,0,0), 350, 50, 0, s);
        al_draw_text(font, al_map_rgb(0,0,0), 520, 50, 0, c);
        al_draw_text(font, al_map_rgb(0,0,0), 200, 55, 0, l);
    }

}

void nose_destory(){
    for(int i=0;i<50;i++)al_destroy_bitmap(nose[i].img_move);
    for(int i=0;i<6;i++)al_destroy_bitmap(fire[i].img_move);
}
