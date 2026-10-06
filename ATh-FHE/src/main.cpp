#include <iostream>
#include <vector>
#include "CryptoManager.h"
#include "MiddlewareCore.h"
#include "CloudSimulator.h"

using namespace lbcrypto;

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "  ATh-FHE Zero-Trust Multi-Cloud Platform  " << std::endl;
    std::cout << "==========================================" << std::endl;

    // 1. Initialize Cryptographic Context (CKKS Scheme)
    CryptoManager cryptoMgr;
    cryptoMgr.setupContext();
    cryptoMgr.generateKeys();
    std::cout << "[+] CryptoContext and Keys Generated Successfully!" << std::endl;

    // 2. Setup Cloud Nodes Simulation
    CloudSimulator cloudA("CloudNode-AWS", cryptoMgr);
    CloudSimulator cloudB("CloudNode-Azure", cryptoMgr);

    // 3. Client Telemetry Data
    std::vector<double> dataA = {1.5, 2.5, 3.5, 4.5};
    std::vector<double> dataB = {10.0, 20.0, 30.0, 40.0};

    std::cout << "[+] Processing Telemetry Data across Multi-Cloud nodes..." << std::endl;
    
    // Clouds process and encrypt data independently (Zero-Trust edge simulation)
    Ciphertext<DCRTPoly> cipherA = cloudA.processCloudNodeData(dataA);
    Ciphertext<DCRTPoly> cipherB = cloudB.processCloudNodeData(dataB);

    // 4. Secure Homomorphic Analytics (Multi-Cloud Secure Aggregation)
    MiddlewareCore middleware(cryptoMgr);
    std::cout << "[+] Executing Secure Homomorphic Addition across Clouds..." << std::endl;
    Ciphertext<DCRTPoly> aggregatedCipher = middleware.executeSecureAnalytics(cipherA, cipherB);

    // 5. Client Decryption of Results
    std::cout << "[+] Decrypting Final Results on Client Side..." << std::endl;
    std::vector<double> finalResult = middleware.decryptResult(aggregatedCipher);

    // Print Results
    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "          RESULTS SUMMARY                 " << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Cloud A Data : [1.5, 2.5, 3.5, 4.5]" << std::endl;
    std::cout << "Cloud B Data : [10.0, 20.0, 30.0, 40.0]" << std::endl;
    std::cout << "Homomorphic Sum Result:" << std::endl;
    for (size_t i = 0; i < 4; ++i) {
        std::cout << "  Element [" << i << "] = " << finalResult[i] << std::endl;
    }
    std::cout << "==========================================" << std::endl;

    return 0;
}