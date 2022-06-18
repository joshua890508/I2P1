#include "nose.h"

bool star=false;
int startstar;
int startbubble;
int min=0, max;

void nose_init()
{
    star=false;
    bubble=false;
    score = 0;
    srand( time(NULL) );
    for( int i=0; i<14; i++)
    {
        if(level==1)
        {
            max = 3;
            nose[i].type=rand() % (max - min + 1) + min;
            if(nose[i].type)nose[i].img_move = al_load_bitmap("./image/nose.png");
            else nose[i].img_move = al_load_bitmap("./image/coin.png");
        }
        else if(level==2)
        {
            max = 7;
            nose[i].type=rand() % (max - min + 1) + min;
            if(nose[i].type==0)nose[i].img_move = al_load_bitmap("./image/coin.png");
            else if(nose[i].type==1)nose[i].img_move = al_load_bitmap("./image/star.png");
            else if(nose[i].type==2)nose[i].img_move = al_load_bitmap("./image/bubble.png");
            else nose[i].img_move = al_load_bitmap("./image/nose.png");
        }
        // initial the geometric information of character
        nose[i].w = al_get_bitmap_width(nose[i].img_move);
        nose[i].h = al_get_bitmap_height(nose[i].img_move);
        max = 2;
        nose[i].x = LEFT + 180*( rand() % (max - min + 1) + min) - nose[i].w/2;
        nose[i].y = 100 - nose[i].h/2;
        nose[i].v = 8;
        nose[i].hidden = true;
    }
    nose[0].hidden = false;//first nose
}

void nose_update(){
    for(int i=0;i<16;i++)
    {
        if (!nose[i].hidden)
        {
            nose[i].y+=nose[i].v;
            if (nose[i].y>=WIDTH/2 && nose[i].y<=WIDTH/2+(chara.h+nose[i].h)/4)//next nose
             {
                nose[i+1].hidden=false;
                if(star && i == startstar+3)star=false;
                if(bubble && i == startbubble+3)bubble=false;
             }
            else if (nose[i].y>=chara.y - nose[i].h && nose[i].y<=chara.y+nose[i].h+(chara.h)/4)//same y position
            {
                if(chara.x+chara.w/2==nose[i].x+nose[i].w/2)//same x position
                {
                    nose[i].hidden = true;
                    if(level == 1)
                    {
                        score+=5;
                        if(nose[i].type==0)coin+=3;
                    }
                    else if(level == 2)
                    {
                        if(bubble)
                        {
                            score-=5;
                            if(nose[i].type==0)coin+=3;
                        }
                        score+=5;
                        if(nose[i].type==0)
                            coin+=3;
                        else if(nose[i].type==1)
                        {
                            star=true;
                            startstar=i;
                        }
                        else if(nose[i].type==2)
                        {
                            score-=5;
                            bubble=true;
                            startbubble=i;
                        }
                        if(star)
                        {
                            if(nose[i].type!=2)
                            {
                                score+=5;
                                if(nose[i].type==0)coin+=3;
                            }
                        }
                    }
                    /*if(score>=15)chara.img_move = al_load_bitmap("./image/longdog1.png");
                    if(score>=30)chara.img_move = al_load_bitmap("./image/longdog2.png");*/
                }
                if(i == 13)//last nose
                {
                    judge_next_window=true;
                    if(score >= 65)
                    {
                        level++;
                        next = SCENE_LEVELUP;
                    }
                    else next = SCENE_LOSE;
                }
            }
        }
    }

}

void nose_draw(){
    for(int i=0;i<14;i++)
        if (!nose[i].hidden)
            al_draw_bitmap(nose[i].img_move, nose[i].x, nose[i].y, 0);

    sprintf(s, "%d", score);
    sprintf(c, "%d", coin);
    sprintf(l, "%d", level);
    al_draw_text(font, al_map_rgb(0,0,0), 350, 50, 0, s);
    al_draw_text(font, al_map_rgb(0,0,0), 520, 50, 0, c);
    al_draw_text(font, al_map_rgb(0,0,0), 200, 55, 0, l);
}

void nose_destory(){
    for(int i=0;i<20;i++)al_destroy_bitmap(nose[i].img_move);
}
