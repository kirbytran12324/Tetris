#ifndef _STATS_
#define _STATS_
class Stats 
{
private:
    int mScore;
    int mLinesCleared;
    int mTetrises;

public:
    Stats();
    void AddScore(int Lines);
    void UpdateLineClears(int Lines);
    void UpdateTetrises(int Lines);
};
#endif _STATS_
