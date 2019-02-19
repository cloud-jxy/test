#ifndef uTimeCounter_H
#define uTimeCounter_H

class uTimeCounter
{
public:
    uTimeCounter();
    ~uTimeCounter();
    
    void Enter();
    
    void Leave( char* file, int line );

private:

    double m_dff;
    double m_c1;
    double m_c2;
};

#endif
