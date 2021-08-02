#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Fruit{

   private:
     int weight;
     string type;
     string shape;
     Fruit *right,*left;

   public:
       Fruit(){ // default Constructor
            weight = 0;
            right = left = NULL;
        }
        Fruit(int val){ // Constructor with parameters
            weight = val;
            right = left = NULL;
         }
        Fruit(int val,string t){ // Constructor with parameters
            weight = val;
            type = t;
            right = left = NULL;
         }
      virtual int get_weight(){
          return this->weight;
      }
      virtual void set_weight(int val){
          this->weight = val;
       }
      virtual string get_type(){
          return type;
       }
       virtual string get_shape(){
          return shape;
       }
      virtual Fruit* get_right(){
           return this->right;
       }
      virtual void set_right(Fruit* node){
          this->right = node;
       }
      virtual Fruit* get_left(){
           return this->left;
       }
      virtual void set_left(Fruit* node){
           this->left = node;
       }
};
/////////////////////////////////////////////////////////////////
class tiny : public virtual Fruit{
    public:
      string get_shape(){
        return "Tiny";
    }
};

class oval : public virtual Fruit{
    public:
      string get_shape(){
        return "Oval";
    }
};

class berry : public virtual Fruit{
    public:
      string get_shape(){
        return "Berry";
    }
};

class giant : public virtual Fruit{
    public:
      string get_shape(){
        return "Giant";
    }
};
/////////////////////////////////////////////////////////////////
class apple : public oval{
    public:
      string get_type(){
        return "Apple";
    }
};

class pear : public oval{
    public:
      string get_type(){
        return "Pear";
    }
};

class avocado : public oval{
    public:
      string get_type(){
        return "Avocado";
    }
};

class papaya : public oval{
    public:
      string get_type(){
        return "Papaya";
    }
};

class grapes : public tiny{
    public:
      string get_type(){
        return "Grapes";
    }
};

class gooseberries : public berry{
    public:
      string get_type(){
        return "Gooseberries";
    }
};

class mulberries : public berry{
    public:
      string get_type(){
        return "Mulberries";
    }
};

class cherry : public tiny , public berry {
  public:
     string get_type(){
        return "Cherry";
    }
      string get_shape(){
        return tiny::get_shape() + "+" + berry::get_shape();
    }
};

class raspberries : public tiny , public berry {
  public:
     string get_type(){
        return "Raspberries";
    }
      string get_shape(){
        return tiny::get_shape() + "+" + berry::get_shape();
    }
};

class blueberries : public tiny , public berry {
  public:
     string get_type(){
        return "Blueberries";
    }
      string get_shape(){
        return tiny::get_shape() + "+" + berry::get_shape();
    }
};

class watermelon : public giant{
    public:
      string get_type(){
        return "Watermelon";
    }
};
