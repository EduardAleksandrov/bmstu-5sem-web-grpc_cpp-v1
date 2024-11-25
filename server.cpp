#include <iostream>
#include <memory>

#include <grpcpp/grpcpp.h>
#include "example.grpc.pb.h"

class SimpleMathImpl final : public SimpleMath::Service {
    grpc::Status TimesTwo(grpc::ServerContext* context, const ReqType* req,
                  RespType* resp) override {
        resp->set_num(req->num() * 2);
        return grpc::Status::OK;
    }
};

int main() {

    SimpleMathImpl service;
    grpc::ServerBuilder builder;
    builder.AddListeningPort("localhost:54321", grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    server->Wait();
    return 0;
}