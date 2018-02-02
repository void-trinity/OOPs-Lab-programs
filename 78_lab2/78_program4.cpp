#include <iostream>
using namespace std;

enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, NOTHING};
enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES, NOTHING};

class Card
{
    Rank rank;
    Suit suit;

public:
    int GetRank()
    {
        return rank;
    }
    int GetSuit()
    {
        return suit;
    }
    void SetRank (Rank r)
    {
        rank = r;
    }
    void SetSuit (Suit s)
    {
        suit = s;
    }
};

class Deck_of_Cards
{
    Card cards[52];
    int n;
    Rank r;
public:
    void initialize()
    {
        int i, j;
        for(i = 0; i < 52; i++)
        {
            if(i < 13)
            {
                cards[i].SetSuit(CLUBS);
            }
            else if(i < 26)
            {
                cards[i].SetSuit(DIAMONDS);
            }
            else if(i < 39)
            {
                cards[i].SetSuit(HEARTS);
            }
            else
            {
                cards[i].SetSuit(SPADES);
            }
            switch(i%13)
            {
                case 0: r = TWO;
                    break;
                case 1: r = THREE;
                    break;
                case 2: r = FOUR;
                    break;
                case 3: r = FIVE;
                    break;
                case 4: r = SIX;
                    break;
                case 5: r = SEVEN;
                    break;
                case 6: r = EIGHT;
                    break;
                case 7: r = NINE;
                    break;
                case 8: r = TEN;
                    break;
                case 9: r = JACK;
                    break;
                case 10: r = QUEEN;
                    break;
                case 11: r = KING;
                    break;
                case 12: r = ACE;
                    break;
            }
            cards[i].SetRank(r);
        }
    }

    void shuffle()
    {

    }
};

int main()
{
    return 0;
}
