#include <iostream>
#include <string>

class Player
{
    friend std::ostream &operator<<(std::ostream &os, const Player &aPlayer);

public:
    Player(const std::string &name = " ");
    std::string GetName() const;
    Player *GetNext() const;
    void SetNext(Player *next);

private:
    std::string m_Name;
    Player *m_pNext; // Pointer to next player in list
};

Player::Player(const std::string &name) : m_Name(name), m_pNext(0) {}

std::string Player::GetName() const
{
    return m_Name;
}

Player *Player::GetNext() const
{
    return m_pNext;
}

void Player::SetNext(Player *next)
{
    m_pNext = next;
}

std::ostream &operator<<(std::ostream &os, const Player &aPlayer)
{
    os << aPlayer.m_Name;
    return os;
}

class Lobby
{
    friend std::ostream &operator<<(std::ostream &os, const Lobby &aLobby);

public:
    Lobby();
    ~Lobby();
    void AddPlayer();
    void RemovePlayer();
    void Clear();

private:
    Player *m_pHead;
    Player *m_pTail;
};

Lobby::Lobby() : m_pHead(0), m_pTail(0) {}
Lobby::~Lobby()
{
    Clear();
}

void Lobby::AddPlayer()
{
    std::cout << "Please enter the name of the new player: ";
    std::string name;
    std::cin >> name;

    Player *pNewPlayer = new Player(name);
       // if the list is empty place new player to start of the list
    if (m_pHead == 0)
    {
        m_pHead = pNewPlayer;
        m_pTail = pNewPlayer;
    }
    // else find the end of the list and place player there
    else
    {
        m_pTail->SetNext(pNewPlayer);
        m_pTail = pNewPlayer;
    }

    // else
    // {
    //     Player *pIter = m_pHead;
    //     while (pIter->GetNext() != 0)
    //     {
    //         pIter = pIter->GetNext();
    //     }
    //     pIter->SetNext(pNewPlayer);
    // }
}

void Lobby::RemovePlayer()
{
    if (m_pHead == 0)
    {
        std::cout << "The game lobby is empty. No one to remove!\n";
    }
    else
    {
        Player *pTemp = m_pHead;
        m_pHead = m_pHead->GetNext();
        delete pTemp;
    }
}

void Lobby::Clear()
{
    while (m_pHead != 0)
    {
        RemovePlayer();
    }
}

std::ostream &operator<<(std::ostream &os, const Lobby &aLobby)
{
    Player *pIter = aLobby.m_pHead;
    os << "\nHere's who's in the game lobby:\n";
    if (pIter == 0)
    {
        os << "The lobby is empty.\n";
    }
    else
    {
        while (pIter != 0)
        {
            os << *pIter << std::endl;
            pIter = pIter->GetNext();
        }
    }
    return os;
}

int main()
{
    Lobby myLobby;
    int choice;
    do
    {
        std::cout << myLobby;
        std::cout << "\nGAME LOBBY\n";
        std::cout << "0 - Exit the program.\n";
        std::cout << "1 - Add player to the lobby.\n";
        std::cout << "2 - Remove a player from the lobby.\n";
        std::cout << "3 - Clear the lobby.\n";
        std::cout << std::endl
                  << "Enter choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << "Good-bye.\n";
            break;
        case 1:
            myLobby.AddPlayer();
            break;
        case 2:
            myLobby.RemovePlayer();
            break;
        case 3:
            myLobby.Clear();
            break;
        default:
            std::cout << "That was not a valid choice.\n";
        }

    } while (choice != 0);
    return 0;
}