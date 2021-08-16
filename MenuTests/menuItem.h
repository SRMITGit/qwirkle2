#ifndef MENUITEM_H
#define MENUITEM_H


class MenuItem {
public:
   MenuItem(int number);
   MenuItem(MenuItem& other);
   ~MenuItem();

   int getNumber();

private:
   int number;
};

#endif // MENUITEM_H
