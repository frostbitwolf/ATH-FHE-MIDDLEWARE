#ifndef CLOUD_SIMULATOR_H
#define CLOUD_SIMULATOR_H

#include <iostream>
#include <vector>
#include <string>
#include "openfhe.h"

using namespace lbcrypto;

class CloudSimulator {
public:
    CloudSimulator();
    
    // Simulate splitting and dispatching encrypted data to multi-cloud nodes (AWS & Azure)
    std::vector<double> simulateMultiCloudSplit(
        CryptoContext<DCRTPoly> cc, 
        Ciphertext<DCRTPoly> ciphertext, 
        PrivateKey<DCRTPoly> privateKey
    );

private:
    void sendToAWSNode(const std::string& nodeName, const std::vector<double>& chunkData);
    void sendToAzureNode(const std::string& nodeName, const std::vector<double>& chunkData);
};

#endif // CLOUD_SIMULATOR_H
