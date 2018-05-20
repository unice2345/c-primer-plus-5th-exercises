/* pe14-6.c -- sports */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PLAYER_NUM 5
struct player {
    int number;
    char first_name[20];
    char last_name[20];
    int num_played;
    int num_strike;
    int num_base;
    int rbi;
    float success_rate;
};

void show_player(struct player *pplayer);
void calc_success_rate(struct player *pplayer);
int main(void)
{
    struct player players[PLAYER_NUM];
    struct player tmp_player;
    FILE* fp;
    int i;
    
    // Init 
    for (i = 0; i < PLAYER_NUM; i++) {
        players[i].number = i;
        players[i].num_played = 0;
        players[i].num_strike = 0;
        players[i].num_base = 0;
        players[i].rbi = 0;
        players[i].success_rate = 0.0f;
    }
    
    // Open file
    fp = fopen("player.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file.\n");
        exit(1);
    }
    
    // Read data
    while (fscanf(fp, "%d %s %s %d %d %d %d", &tmp_player.number, tmp_player.first_name, tmp_player.last_name, 
        &tmp_player.num_played, &tmp_player.num_strike, &tmp_player.num_base, &tmp_player.rbi) > 0) {
        //show_player(&tmp_player);
        
        int number = tmp_player.number;
        players[number].number = number;
        strcpy((players[number].first_name), (tmp_player.first_name));
        strcpy((players[number].last_name), (tmp_player.last_name));
        players[number].num_played += tmp_player.num_played;
        players[number].num_strike += tmp_player.num_strike;
        players[number].num_base += tmp_player.num_base;
        players[number].rbi += tmp_player.rbi;
        
        //show_player(&players[number]);
    }
    
    // Calculate success rate
    for (i = 0; i < PLAYER_NUM; i++)
        calc_success_rate(&players[i]);
        
    // Show info
    for (i = 0; i < PLAYER_NUM; i++)
        show_player(&players[i]);

    fclose(fp);
    return 0;
}

void show_player(struct player *pplayer)
{
    printf("%d %s %s %d %d %d %d %.2f\n",
        pplayer->number, pplayer->first_name, pplayer->last_name, pplayer->num_played, pplayer->num_strike, 
        pplayer->num_base, pplayer->rbi, pplayer->success_rate);
}

void calc_success_rate(struct player *pplayer)
{
    if (pplayer->num_played > 0)
        pplayer->success_rate = pplayer->num_strike * 1.0 / pplayer->num_played;
}