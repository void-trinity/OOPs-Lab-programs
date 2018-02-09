#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, NOTHING};
enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES, NOTHING1};

class Card
{
    Rank rank;
    Suit suit;

public:
    Rank GetRank()
    {
        return rank;
    }
    Suit GetSuit()
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

bool sort_fn(Card A, Card B)
{
    return A.GetRank() < B.GetRank();
}

class Deck_of_Cards
{
    Card cards[52];
    int n;
public:
    void initialize()
    {
        Rank r;
        n = 52;
        int i, j;
        for(i = 0; i < n; i++)
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
        shuffle();
    }

    void shuffle()
    {
        srand(time(NULL));
        for (int i = n - 1; i > 0; i--)
        {
            int j = rand()%(i+1);
            swap(i , j);
        }
    }

    void swap(int i, int j)
    {
        Card temp;
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    Card pick_a_card()
    {
        srand(time(NULL));
        int j = rand()%n;
        Card temp;
        temp = cards[j];
        for(int i = j; i < n - 1; i++)
            cards[i] = cards[i+1];
        n--;
        shuffle();
        return temp;
    }

    Card pick_a_card(Suit s, Rank r)
    {
        Card temp;
        temp.SetRank(NOTHING);
        temp.SetSuit(NOTHING1);
        int j = -1;
        for(int i = 0; i < n; i++)
        {
            if(cards[i].GetRank() == r && cards[i].GetSuit() == s)
            {
                j = i;
                temp.SetSuit(s);
                temp.SetRank(r);
                break;
            }
        }
        if(j != -1)
        {
            for(int i = j; i < n - 1; i++)
                cards[i] = cards[i+1];
            n--;
            shuffle();
        }
        return temp;
    }
};

class Player
{
    int PlayerID;
    string Name;
    Card holds[5];
    int total_holds;

    int check_same_suit()
    {
        int flag = 1;
        Suit s = holds[0].GetSuit();
        for(int i = 1; i < 5; i++)
        {
            if(holds[i].GetSuit() != s)
            {
                flag = 0;
                break;
            }
        }
        return flag;
    }

public:
    Player()
    {
        for (int i = 0; i < 5; i++)
        {
            holds[i].SetRank(NOTHING);
            holds[i].SetSuit(NOTHING1);
        }
    }

    Card *ShowCards()
    {
        return holds;
    }

    int how_many_cards()
    {
        return total_holds;
    }

    void pick_a_card(Deck_of_Cards &A)
    {
        holds[total_holds++] = A.pick_a_card();
    }

    void pick_a_card(Deck_of_Cards &A, Suit s, Rank r)
    {
        Card temp = A.pick_a_card(s, r);
        if (temp.GetSuit() != NOTHING1 && temp.GetRank() != NOTHING)
        {
            holds[total_holds++] = temp;
        }
        else
        {
            cout << endl << "The card is unavailable, you loose your turn.";
        }
    }

    void initialize()
    {
        total_holds = 0;
        for (int i = 0; i < 5; i++)
        {
            holds[i].SetSuit(NOTHING1);
            holds[i].SetRank(NOTHING);
        }
        cout << endl << "Enter player id: ";
        cin >> PlayerID;
        cout << endl << "Enter player name: ";
        cin >> Name;
    }

    int GetPlayerID()
    {
        return PlayerID;
    }

    string GetPlayerName()
    {
        return Name;
    }
    int check_royalflush()
    {
        sort(holds, holds + 5, sort_fn);
        if (check_same_suit() && holds[4].GetRank() == ACE)
            return 1;
        else
            return 0;
    }

    int check_straightflush()
    {
        int flag = 1;
        sort(holds, holds + 5, sort_fn);
        if(check_same_suit())
        {
            for(int i = 1; i < 5; i++)
                if(holds[i].GetRank()-holds[i-1].GetRank() != 1)
                {
                    flag = 0;
                    break;
                }

        }
        else
            flag = -1;

        if(flag != -1)
            return holds[4].GetRank();
        else
            return -1;
    }

    int check_fourofakind()
    {
        int flag = -1;
        sort(holds, holds + 5, sort_fn);
        for(int i = 0; i < 2; i++)
        {
            if(holds[i].GetRank() == holds[i+1].GetRank() &&
               holds[i].GetRank() == holds[i+2].GetRank() &&
               holds[i].GetRank() == holds[i+3].GetRank())
            {
                flag = holds[i].GetRank();
                break;
            }
        }
        return flag;
    }

    int check_fullhouse()
    {
        int flag = -1;
        sort(holds, holds + 5, sort_fn);

        if((holds[0].GetRank() == holds[1].GetRank() && holds[2].GetRank() == holds[3].GetRank() &&
            holds[4].GetRank() == holds[3].GetRank()) ||
           (holds[3].GetRank() == holds[4].GetRank() && holds[0].GetRank() == holds[1].GetRank() &&
            holds[1].GetRank() == holds[2].GetRank()))
            flag = holds[4].GetRank();
        return flag;
    }

    int check_flush()
    {
        if(check_same_suit())
            return holds[4].GetRank();
        else
            return -1;
    }

    int check_straight()
    {
        int flag = 1;
        sort(holds, holds + 5, sort_fn);
        for(int i = 1; i < 5; i++)
            if(holds[i].GetRank()-holds[i-1].GetRank() != 1)
            {
                flag = -1;
                break;
            }
        if(flag = -1)
            return flag;
        else
            return holds[4].GetRank();
    }

    int check_threeofakind()
    {
        int flag = -1;
        sort(holds, holds + 5, sort_fn);
        for(int i = 0; i < 3; i++)
        {
            if(holds[i].GetRank() == holds[i+1].GetRank() &&
               holds[i].GetRank() == holds[i+2].GetRank())
            {
                flag = 1;
                break;
            }
        }
        if(flag != -1)
            return holds[4].GetRank();
        else
            return -1;
    }

    int check_twopair()
    {
        sort(holds, holds+5, sort_fn);
        int flag = 0;
        for(int i = 0; i < 4; i++)
        {
            if(holds[i].GetRank() == holds[i+1].GetRank())
            {
                flag++;
                i++;
            }
        }
        if(flag > 1)
            holds[4].GetRank();
        else
            return -1;
    }

    int check_pair()
    {
        int flag = -1;
        sort(holds, holds + 5, sort_fn);
        for(int i = 0; i < 4; i++)
        {
            if(holds[i].GetRank() == holds[i+1].GetRank())
            {
                flag = holds[i].GetRank();
                break;
            }
        }
        return flag;
    }

    Rank check_highcard()
    {
        sort(holds, holds + 5, sort_fn);
        return holds[4].GetRank();
    }
};

class Game
{
    int N;
    Player *players;
    Deck_of_Cards A;

public:
    void start()
    {
        A.initialize();
        cout << endl << "Enter no. of players: ";
        cin >> N;
        players = new Player[N];
        for(int i = 0; i < N; i++)
            players[i].initialize();
        srand(time(NULL));
        for(int i = 0; i < N - 1; i++)
        {
            int j = rand()%(i+1);
            swap(i , j);
        }
        cout << endl << "Sequence of turns(by player id): ";
        for(int i = 0; i < N; i++)
        {
            cout << endl << i+1 << ": " << players[i].GetPlayerID();
        }
    }

    void swap(int i, int j)
    {
        Player temp;
        temp = players[i];
        players[i] = players[j];
        players[j] = temp;
    }

    void play1()
    {
        cout << endl << "Game 1, players get random cards to play" << endl;
        start();
        Card *cards;
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < N; j++)
                players[j].pick_a_card(A);
        for(int i = 0; i < N; i++)
        {
            cout << endl << "Cards of Player ID: " << players[i].GetPlayerID();
            for (int j = 0; j < 5; j++)
            {
                cards = players[i].ShowCards();
                cout << endl << endl << "Card " << j + 1 << ": "
                     << endl << "Suit: " << (cards + j)->GetSuit()
                     << endl << "Rank: " << (cards + j)->GetRank();
            }
        }
        decide_winner();
    }

    void play2()
    {
        cout << endl << endl << "Game 2, players get to choose their cards. But if the card "
             << "they select is already taken, they loose their turn" << endl;
        Card *cards;
        int flag = 1;
        int suit, rank;
        start();
        while(flag)
        {
            for(int i = 0; i < N; i++)
            {
                if(players[i].how_many_cards() != 5)
                {

                    cout << endl << "Player ID: " << players[i].GetPlayerID()
                         << endl << "Enter Suit: ";
                    cin >> suit;
                    cout << endl << "Enter Rank: ";
                    cin >> rank;
                    players[i].pick_a_card(A, (Suit)suit, (Rank)rank);
                }
                else
                    continue;
            }
            flag = 0;
            for(int i = 0; i < N; i++)
            {
                if(players[i].how_many_cards() != 5)
                {
                    flag = 1;
                    break;
                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            cout << endl << players[i].GetPlayerID();
            for (int j = 0; j < 5; j++)
            {
                cards = players[i].ShowCards();
                cout << endl << "Card " << j + 1 << ": "
                     << endl << "Suit: " << (cards + j)->GetSuit()
                     << endl << "Rank: " << (cards + j)->GetRank();
            }
        }
        decide_winner();
    }

    void decide_winner()
    {
        int royalflush = -1, straightflush = -1, fourofakind = -1, fullhouse = -1, flush = -1,
            straight = -1, threeofakind = -1, twopair = -1, pair = -1, highcard = -1, cond = 10;
        Player winner;
        for(int i = 0; i < N; i++)
        {
            if(players[i].check_royalflush())
            {
                winner = players[i];
                cond = 0;
                break;
            }
            if(straightflush < players[i].check_straightflush() && cond >= 1)
            {
                straightflush = players[i].check_straightflush();
                winner = players[i];
                cond = 1;
            }
            if(fourofakind < players[i].check_fourofakind() && cond >= 2)
            {
                fourofakind = players[i].check_fourofakind();
                winner = players[i];
                cond = 2;
            }
            if(fullhouse < players[i].check_fullhouse() && cond >= 3)
            {
                fullhouse = players[i].check_fullhouse();
                winner = players[i];
                cond = 3;
            }
            if(flush < players[i].check_flush() && cond >= 4)
            {
                flush = players[i].check_flush();
                winner = players[i];
                cond = 4;
            }
            if(straight < players[i].check_straight() && cond >= 5)
            {
                straight = players[i].check_straight();
                winner = players[i];
                cond = 5;
            }
            if(threeofakind < players[i].check_threeofakind() && cond >= 6)
            {
                threeofakind = players[i].check_threeofakind();
                winner = players[i];
                cond = 6;
            }
            if(twopair < players[i].check_twopair() && cond >= 7)
            {
                twopair = players[i].check_twopair();
                winner = players[i];
                cond = 7;
            }
            if(pair < players[i].check_pair() && cond >= 8)
            {
                pair = players[i].check_pair();
                winner = players[i];
                cond = 8;
            }
            if(highcard < players[i].check_highcard() && cond >= 9)
            {
                highcard = players[i].check_highcard();
                winner = players[i];
                cond = 9;
            }
        }
        cout << endl << endl << "Winner(";
        switch(cond)
        {
            case 0: cout << "by royal flush): ";
                break;
            case 1: cout << "by straight flush): ";
                break;
            case 2: cout << "by four of a kind flush): ";
                break;
            case 3: cout << "by fullhouse): ";
                break;
            case 4: cout << "by flush): ";
                break;
            case 5: cout << "by straight): ";
                break;
            case 6: cout << "by three of a kind): ";
                break;
            case 7: cout << "by two pair): ";
                break;
            case 8: cout << "by pair): ";
                break;
            case 9: cout << "by high card): ";
                break;
        }
        cout << endl << "Player ID: " << winner.GetPlayerID()
             << endl << "Name: " << winner.GetPlayerName();

    }

};

int main()
{
    Game game;
    game.play1();
    game.play2();
    return 0;
}
