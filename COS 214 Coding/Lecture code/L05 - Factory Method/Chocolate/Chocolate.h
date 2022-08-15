#ifndef CHOCOLATE_H
#define CHOCOLATE_H

//Interface for chocolates
class Chocolate {
  public:
    Chocolate();
    void wrap();
  protected:
    virtual void print() = 0;  
    int id_;
    static int total_;
};


class Barone : public Chocolate {
  protected:
    //override print method
    void print();
};

class Tex : public Chocolate {
  protected:
    //override print method
    void print();
};

class Creator {
  public:
    //anoperation
    Chocolate* produce();
  protected:
    //factory method
    virtual Chocolate* produceProduct() = 0;
};

class BaroneCreator : public Creator {
  protected:
    //factory method
    Chocolate* produceProduct();
};


class TexCreator : public Creator {
  protected:
    //factory method
    Chocolate* produceProduct();
};

#endif

// Remember to add the virtual destructors
