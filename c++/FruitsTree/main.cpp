#include <iostream>
#include <bits/stdc++.h>
#include "Fruits.h"
using namespace std;

class BST{

   private:
    Fruit* root = NULL;

    Fruit* Insert(Fruit* root,Fruit* node){

        if(!root) return node; // create the tree

        if(root->get_weight() < node->get_weight()){
            root->set_right(Insert(root->get_right(),node));
        }
        else{ // node->weight < root->weight
           root->set_left(Insert(root->get_left(),node));
        }
       return root;
    }

    void Inorder(Fruit* root,string Type, int Weight){

         if(root==NULL) return;

         Inorder(root->get_left(),Type,Weight);
         if((Type == " " || root->get_type() == Type)&&(Weight == -3 || root->get_weight() > Weight))
         print(root->get_type(),root->get_shape(),root->get_weight());
         Inorder(root->get_right(),Type,Weight);
    }

    void Update(Fruit* root,string Type, int Weight,queue<Fruit*> &nWeight){
         if(!root) return;
         Update(root->get_left(),Type,Weight,nWeight);
          if(root->get_type() == Type){
            root->set_weight(root->get_weight() + Weight);
         }
         nWeight.push(root);
         Update(root->get_right(),Type,Weight,nWeight);
    }

    Fruit* Max_Min(Fruit* root, bool check){
         if(!root) return NULL;
         if(check){
           if(root->get_right() == NULL) {
            return root;
          }else{
            return Max_Min(root->get_right(),check);
           }
         }
         else{
           if(root->get_left() == NULL) {
            return root;
          }else{
            return Max_Min(root->get_left(),check);
           }
         }
       }

   public:
       void InsertF(Fruit* node){
        if(!root)
            root=node;
        else
            Insert(root,node);
    }
       void print(string Type,string Shape,int Weight){
         cout << "{Fruit type: ";
         cout << Type;
         cout << " ,fruit shape: ";
         cout << Shape;
         cout << " ,fruit weight: ";
         cout << Weight;
         cout <<  "}" << endl;
    }

   //********************************

    void Iterate(){ //print the in-order traversal of the tree
        Inorder(root," ",-3);
    }

    void filterByType(string Type){ //print the nodes of a given fruit type ordered by weight
        Inorder(root,Type,-3);
    }

    void filterByWeight(int Weight){ //print the nodes that have weight larger than the given amount ordered by weight
        Inorder(root," ",Weight);
    }

    void magnifyByType(string Type, int Weight){ //increase the weight of the nodes of a given fruit type by the given amount

        queue<Fruit*> nWeight;
        Update(root,Type,Weight,nWeight);
        root = NULL; // create modified tree

         while(!nWeight.empty()){
             nWeight.front()->set_right(NULL);
             nWeight.front()->set_left(NULL);
             InsertF(nWeight.front());
             nWeight.pop(); // size--
        }
    }

    Fruit* findHeaviest(){ //find the node with the greatest weight in the tree
        return Max_Min(root,true);
    }

    Fruit* findLightest(){ //find the node with the least weight in the tree
        return Max_Min(root,false);
    }
};

int main()
{
    apple a1,a2;
    cherry c1,c2;
    pear pe1;
    grapes g1,g2;
    avocado avo1;
    mulberries m1;
    papaya pa1;
    gooseberries go1;
    raspberries r1;
    blueberries b1;
    watermelon w1;

    a1.set_weight(30);
    g1.set_weight(50);
    pa1.set_weight(15);
    c1.set_weight(20);
    g2.set_weight(10);
    go1.set_weight(40);
    m1.set_weight(60);
    c2.set_weight(35);
    w1.set_weight(90);
    r1.set_weight(25);
    a2.set_weight(75);
    pe1.set_weight(65);
    b1.set_weight(45);
    avo1.set_weight(80);

    BST FruitsTree;

    FruitsTree.InsertF(&a1);
    FruitsTree.InsertF(&g1);
    FruitsTree.InsertF(&pa1);
    FruitsTree.InsertF(&c1);
    FruitsTree.InsertF(&g2);
    FruitsTree.InsertF(&go1);
    FruitsTree.InsertF(&m1);
    FruitsTree.InsertF(&c2);
    FruitsTree.InsertF(&w1);
    FruitsTree.InsertF(&r1);
    FruitsTree.InsertF(&a2);
    FruitsTree.InsertF(&pe1);
    FruitsTree.InsertF(&b1);
    FruitsTree.InsertF(&avo1);


    cout << "\t\t\t\t***Test Iterate***" << endl;
    FruitsTree.Iterate();
    cout << "--------------------------------------------------------------------" << endl;

    cout << "\t\t\t\t***Test Filter By Type***" << endl;
    FruitsTree.filterByType("Apple");
    cout << "--------------------------------------------------------------------" << endl;

    cout << "\t\t\t\t***Test Filter By Weight***" << endl;
    FruitsTree.filterByWeight(40);
    cout << "--------------------------------------------------------------------" << endl;

    cout << "\t\t\t\t***Test Find Heaviest***" << endl;
    Fruit* f1 = FruitsTree.findHeaviest();
    FruitsTree.print(f1->get_type(),f1->get_shape(),f1->get_weight());
    cout << "--------------------------------------------------------------------" << endl;

    cout << "\t\t\t\t***Test Find Lightest***" << endl;
    Fruit* f2 = FruitsTree.findLightest();
    FruitsTree.print(f2->get_type(),f2->get_shape(),f2->get_weight());
    cout << "--------------------------------------------------------------------" << endl;

    cout << "\t\t\t\t***Test Magnify By Type***" << endl;
    FruitsTree.magnifyByType("Grapes",7);
    FruitsTree.Iterate();
    cout << "--------------------------------------------------------------------" << endl;

    return 0;
}
