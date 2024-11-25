#include <iostream>
#include <memory>

#include <grpcpp/grpcpp.h>
#include "example.grpc.pb.h"

int main() {

    // Create the channel
    std::shared_ptr<grpc::Channel> ch = grpc::CreateChannel("localhost:54321", 
        grpc::InsecureChannelCredentials());

    // Create the stub
    std::unique_ptr<SimpleMath::Stub> stub = SimpleMath::NewStub(ch);

    // Create the client message
    ReqType request;
    request.set_num(7);

    // Invoke the method
    grpc::ClientContext ctx;
    RespType response;
    grpc::Status status = stub->TimesTwo(&ctx, request, &response);

    // Check status
    if (status.ok()) {
        std::cout << "The result is " << response.num() << std::endl;
    } else {
        std::cout << status.error_code() << ": " 
            << status.error_message() << std::endl;
    }
    return 0;
}