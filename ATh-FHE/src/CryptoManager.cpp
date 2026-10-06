#include "CryptoManager.h"

CryptoManager::CryptoManager() {}

void CryptoManager::setupContext() {
    CCParams<CryptoContextCKKSRNS> parameters;
    parameters.SetMultiplicativeDepth(2);
    parameters.SetScalingModSize(50);
    parameters.SetBatchSize(8);

    CryptoContext<DCRTPoly> cc = GenCryptoContext(parameters);
    cc->Enable(PKE);
    cc->Enable(KEYSWITCH);
    cc->Enable(LEVELEDSHE);

    cryptoContext = cc;
}

void CryptoManager::generateKeys() {
    KeyPair<DCRTPoly> keyPair = cryptoContext->KeyGen();
    publicKey = keyPair.publicKey;
    privateKey = keyPair.secretKey;
}

CryptoContext<DCRTPoly> CryptoManager::getCryptoContext() const {
    return cryptoContext;
}

PublicKey<DCRTPoly> CryptoManager::getPublicKey() const {
    return publicKey;
}

PrivateKey<DCRTPoly> CryptoManager::getPrivateKey() const {
    return privateKey;
}