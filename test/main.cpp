#include <iostream>
#include "Person.pb.h"
using namespace std;

int main() {
    // 序列化
    Person p;
    p.set_id(10);
    p.set_age(32);
    p.set_sex("man");

    p.add_name();
    p.set_name(0, "Tom");

    p.add_name("Coco");
    p.add_name("Amy");
    p.mutable_addr()->set_addr("陕西省西安市");
    p.mutable_addr()->set_num(1001);
    p.set_color(Color::Blue);

    string output;
    p.SerializeToString(&output);

    // 反序列化
    Person pp;
    pp.ParseFromString(output);
    cout << pp.id() << endl;
    cout << pp.sex() << endl;
    cout << pp.age() << endl;
    cout << pp.addr().addr() << endl;
    cout << pp.addr().num() << endl;

    cout << endl;
    int size = pp.name_size();
    for (int i = 0; i < size; i++) {
        cout << pp.name(i) << endl;
    }

    cout << pp.color() << endl;
}