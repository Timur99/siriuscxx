#include "linked_list.h"
using namespace std;

int main(int argc, char** argv)
{
    List list;

    ifstream f(argv[1]);
    int temp;
    while (!f.eof())
    {
        if (f.good())
        {
        f >> temp;
        list.addNode(temp);
        }
        else
        {
            cout << "Error" << endl;
            exit(-1);
        }
    }
   list.deleteElement(temp);
   list.printLinkedList();

    return 0;
}
