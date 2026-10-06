#ifndef CRYPTO_MANAGER_H
#define CRYPTO_MANAGER_H

#include "openfhe.h"

using namespace lbcrypto;

class CryptoManager {
public:
    CryptoManager();

    void setupContext();
    void generateKeys();

    CryptoContext<DCRTPoly> getCryptoContext() const;
    PublicKey<DCRTPoly> getPublicKey() const;
    PrivateKey<DCRTPoly> getPrivateKey() const;

private:
    CryptoContext<DCRTPoly> cryptoContext;
    PublicKey<DCRTPoly> publicKey;
    PrivateKey<DCRTPoly> privateKey;
};

#endif // CRYPTO_MANAGER_H