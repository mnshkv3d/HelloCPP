// Heap Data Member

#include <iostream>
#include <string>
using namespace std;

class Critter
{
public:
    Critter(const string &name = "", int age = 0);
    ~Critter();                                    // destructor prototype
    Critter(const Critter &c);                     // prototype of copy constructor
    Critter &operator=(const Critter &c); // overload operation
    void Gret() const;

private:
    string *m_pName;
    int m_Age;
};
Critter::Critter(const string &name, int age)
{
    cout << "Constructor called\n";
    m_pName = new string(name);
    m_Age = age;
}
Critter::~Critter()
{
    cout << "Destructor called\n";
    delete m_pName;
}
Critter::Critter(const Critter &c)
{
    cout << "Copy Constructor called\n";
    m_pName = new string(*(c.m_pName));
    m_Age = c.m_Age;
}
Critter &Critter::operator=(const Critter &c)
{
    cout << "Overloaded Assigment Operator called\n";
    if (this != &c)
    {
        delete m_pName;
        m_pName = new string(*(c.m_pName));
        m_Age = c.m_Age;
    }
    return *this;
}
void Critter::Gret() const
{
    cout << "I'm " << *m_pName << " and I'm " << m_Age << " years old.";
    cout << "&m_pName: " << &m_pName << endl;
}
void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssigmentOp();

int main()
{
    testDestructor();
    cout << endl;

    Critter crit("Poochie", 5);
    crit.Gret();
    testCopyConstructor(crit);
    crit.Gret();
    cout << endl;

    testAssigmentOp();
    return 0;
}

void testDestructor()
{
    Critter toDestroy("Rover", 3);
    toDestroy.Gret();
}
void testCopyConstructor(Critter aCopy)
{
    aCopy.Gret();
}
void testAssigmentOp()
{
    Critter crit1("crit1", 7);
    Critter crit2("crit2", 9);
    crit1 = crit2;
    crit1.Gret();
    crit2.Gret();

    cout << endl;

    Critter crit3("crit", 11);
    crit3 = crit3;
    crit3.Gret();
}