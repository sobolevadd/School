#include <iostream>
#include <list>
#include <typeinfo>
#include "go.h"

using namespace std;

char menu(){
    char c;
    cout << "Which type of object do you wish to draw: \n";
    cout << "(1) Point \n";
    cout << "(2) Line segment \n";
    cout << "(e) Nothing, end drawing \n \n";
    cout << " Your choice: ";
    cin >> c;
    return c;
}

void drawPicture(list<Go*> objects){
    Go *ptr;
    for(list<Go*>::iterator it=objects.begin(); it != objects.end(); ++it){
        ptr = *it;
        cout << typeid(*ptr).name() << endl;
        if(typeid(*ptr)==typeid(LineSegment)){
            cout << "yay, it's a line segment. Lenght; ";
            //ptr->lenght();
            LineSegment *lsp = static_cast<LineSegment*>(ptr);
            cout << lsp->lenght() << endl;
        }
        ptr->draw();
    }
}

void releaseObjects(list<Go*> &objects){
    for(list<Go*>::iterator it=objects.begin(); it != objects.end(); ++it){
        delete *it;
    }
    objects.clear();
}

int main()
{
    // Go g(0);
    list<Go*> objects; // list of graphic objects pointers
    Go *ptr;
    int ax, ay, bx, by, c; 
    while (true)
    {
        char choice = menu();
        if(choice == 'e' || choice =='E'){
            break;
        }
        cout << "Which color would you like to use?\n Color = ";
        cin >> c;
        switch(choice){
        case '1':
            cout << "Please, enter coordinates of point: ";
            cin >> ax >> ay;
            ptr = new Point (ax, ay, c);
            break;
        default:
            cout << "Please, enter start coordinates: ";
            cin >> ax >> ay;
            cout << "Please, enter end coordinates: ";
            cin >> bx >> by;
            ptr = new LineSegment(ax, ay, bx, by, c);
        }
        objects.push_back(ptr);
    }
    drawPicture(objects);
    releaseObjects(objects);
     
    //LineSegment ab(0, 0, 1, 1, 42);
    // ab.draw();
    return 0;
}