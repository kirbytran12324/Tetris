#include "Stats.h"

Stats::Stats()
{
    Stats::mScore = 0;
    Stats::mLinesCleared = 0;
    Stats::mTetrises = 0;
}

void Stats::AddScore(int Lines)
{
    switch (Lines)
    {
    case 1:
        mScore += 40;
        break;
    case 2:
        mScore += 100;
        break;
    case 3:
        mScore += 300;
        break;
    case 4:
        mScore += 1200;
        mTetrises++;
        break;
    }
}

void Stats::UpdateLineClears(int Lines)
{
    mLinesCleared += Lines;
}

void Stats::UpdateTetrises(int Lines)
{
    if (Lines==4)
        mTetrises++;
}