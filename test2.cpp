#include <iostream>
#include <hiredis/hiredis.h>
using namespace std;

int main() {
    redisContext* ctx = redisConnect("127.0.0.1", 6379);
    if (ctx == nullptr) {
        cout << "connect failed" << endl;
        return -1;
    }

    if (ctx->err) {
        cout << ctx->errstr << endl;
        redisFree(ctx);
        return -1;
    }

    cout << "connect success" << endl;

    redisReply* reply = (redisReply*)redisCommand(ctx, "PING");
    cout << reply->str << endl;

    freeReplyObject(reply);
    redisFree(ctx);

    return 0;
}