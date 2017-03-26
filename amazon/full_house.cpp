// An optimal algorithm to check whether a hand of cards was a full house (in Poker) or not.  

#include <string>
#include <iostream>
using namespace std;

struct Card {
    int rank;
    string suit;
};

bool full_house(Card hand[5]) {

    int first_rank = hand[0].rank;
    int second_rank = -1;
    int first_rank_count = 1;
    int second_rank_count = 0;

    for (int i = 1; i < 5; i++) {
        if (hand[i].rank == first_rank)
        {
            first_rank_count++;
        } else if (second_rank < 0)
        {
            second_rank = hand[i].rank;
            second_rank_count++;
        } 
        else if (hand[i].rank == second_rank)
        {
            second_rank_count++;
        }
        else { // there are more than two different ranks in hand; cannot have a full house
            return false;
        }
    }

    //cout << first_rank_count << ", " << second_rank_count << endl;

    if ((first_rank_count == 3 && second_rank_count == 2) || (first_rank_count == 2 && second_rank_count == 1))
    {
        return true;
    }
    else { // wrong number of each suit for full house
        return false;
    }
}

int main()
{
    Card card1;
    card1.rank = 5;
    Card card2;
    card2.rank = 8;
    Card card3;
    card3.rank = 5;
    Card card4;
    card4.rank = 5;
    Card card5;
    card5.rank = 8;

    Card hand[] = {card1, card2, card3, card4, card5};

    cout << full_house(hand) << endl;

    return 0;
}
