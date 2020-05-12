#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        virtual ~Player();

        void CallInput();
        void resetToSafePosition();

        int x, y;
        int lx, ly;

    protected:

    private:
};

#endif // PLAYER_H
