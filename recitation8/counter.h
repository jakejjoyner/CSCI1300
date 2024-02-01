#ifndef COUNTER_H
#define COUNTER_H

class Counter{
    public:
        void count();
        void reset();
        int get_value() const;

    private:
        int value;


};

#endif