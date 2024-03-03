// BlackJack
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class Card
{
public:
    enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    // overloading << operator so can send Card object to standart output
    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);

    // returns the value of a card, 1-11
    int GetValue() const;

    // flips a card; if faces up, becomes face down and vice versa
    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}

int Card::GetValue() const
{
    // if a card is face down, its value is 0
    int value = 0;
    if (m_IsFaceUp)
    {
        // value is number showing on card
        value = m_Rank;
        // value is 10 for face cards
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}
void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

class Hand
{
public:
    Hand();
    virtual ~Hand();

    // adds a card to the hand
    void Add(Card* pCard);

    // clears hand of all cards
    void Clear();

    // gets hand total value, intelligently treats aces as 1 or 11
    int GetTotal() const;

protected:
    std::vector<Card*> m_Cards;
};

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    // iterate through vector, freeing all memory on the heap
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    // clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
    // if no cards in hand, return 0
    if (m_Cards.empty())
    {
        return 0;
    }
    // if a first card has value of 0, then card is face down; return 0
    if (m_Cards[0]->GetValue() == 0)
    {
        return 0;
    }
    // add up card values, treat each ace as 1
    int total = 0;
    std::vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        total += (*iter)->GetValue();
    }

    // determine if hand contains an ace
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        if ((*iter)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }
    // if hand contains ace and total is low enough, treat ace as 11
    if (containsAce && total <= 11)
    {
        // add only 10 since we've already added 1 for the ace
        total += 10;
    }
    return total;
}

class GenericPlayer : public Hand
{
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const std::string& name = "");
    virtual ~GenericPlayer();

    // indicates whether or not generic player wants to keep hitting
    virtual bool IsHitting() const = 0;

    // returns whether generic player has busted - has a total > 21
    bool IsBasted() const;

    // announces that the generic player busts
    void Bust() const;

protected:
    std::string m_Name;
};

GenericPlayer::GenericPlayer(const std::string& name) : m_Name(name) {}

GenericPlayer::~GenericPlayer() {}

bool GenericPlayer::IsBasted() const
{
    return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
    std::cout << m_Name << " busts.\n";
}

class Player : public GenericPlayer

{
public:
    Player(const std::string& name = "");

    virtual ~Player();

    // returns whether or not the player wants another hit
    virtual bool IsHitting() const;

    // announces that the player wins
    void Win() const;

    // announces that the player loses
    void Lose() const;

    // announces that the player pushes
    void Push() const;
};

Player::Player(const std::string& name) : GenericPlayer(name) {}

Player::~Player() {}

bool Player::IsHitting() const
{
    std::cout << m_Name << ", do you want a hit?(Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
    std::cout << m_Name << " wins.\n";
}

void Player::Lose() const
{
    std::cout << m_Name << " loses.\n";
}

void Player::Push() const
{
    std::cout << m_Name << " pushes.\n";
}

class House : public GenericPlayer
{
public:
    House(const std::string& name = "House");

    virtual ~House();

    // indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;

    // flips over first card
    void FlipFirstCard();
};

House::House(const std::string& name) : GenericPlayer(name) {}

House::~House() {}

bool House::IsHitting() const

{
    return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
    if (!(m_Cards.empty()))
    {
        m_Cards[0]->Flip();
    }
    else
    {
        std::cout << "No card to flip!\n";
    }
}

class Deck : public Hand
{
public:
    Deck();

    virtual ~Deck();

    // create a standart deck of 52 cards
    void Populate();

    // shuffle cards
    void Shuffle();

    // deal one card to a hand
    void Deal(Hand& aHand);

    // give additional cards to a generic player
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

Deck::Deck()
{
    m_Cards.reserve(52);
    Populate();
}

Deck::~Deck() {}

void Deck::Populate()
{
    Clear();
    // create standart deck
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }
}

void Deck::Shuffle() {}

int main()
{
    std::cout << "Temp message!\n\n\n";
    return 0;
}
std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    return os;
}