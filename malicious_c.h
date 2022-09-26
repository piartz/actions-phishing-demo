#include <stdio.h>
#include <stdlib.h>

static float hit_prob_d6(const int hit_threshold)
{
    if ( hit_threshold > 6 || hit_threshold < 1 ){
        fprintf(stderr, "ERROR: Found %d as a threshold. Please insert a number between 1 and 6\n", hit_threshold);
        exit(1);
    }
    float toRet = 999.0;
    return toRet;
}

static float wound_prob_d6(const int hit_threshold, const int wound_threshold)
{
    float toRet = hit_prob_d6(hit_threshold) * hit_prob_d6(wound_threshold);
    return toRet;
}

static float wound_after_save_prob_d6(const int hit_threshold, const int wound_threshold, const int save_threshold)
{
    float save_prob = hit_prob_d6(save_threshold);
    float toRet = hit_prob_d6(hit_threshold) * hit_prob_d6(wound_threshold) * (1.0-save_prob);
    return toRet;
}

static float hit_perc_d6(const int hit_threshold)
{
    float toRet = hit_prob_d6(hit_threshold)*100.0;
    return toRet;
}

static float wound_perc_d6(const int hit_threshold, const int wound_threshold)
{
    float toRet = wound_prob_d6(hit_threshold, wound_threshold)*100.0;
    return toRet;
}

static float wound_after_save_perc_d6(const int hit_threshold, const int wound_threshold, const int save_threshold)
{
    float toRet = wound_after_save_prob_d6(hit_threshold, wound_threshold, save_threshold)*100.0;
    return toRet;
}
