#include <iostream>
#include <hiredis/hiredis.h>
using namespace std;

int main() {
    redisContext* c = redisConnect("127.0.0.1", 6379);
    if (c == nullptr || c->err) {
        cout << "connect failed" << endl;
        return -1;
    } else {
        cout << "connect success" << endl;
    }
    redisFree(c);
    return 0;
}