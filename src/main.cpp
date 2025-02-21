#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <zlib.h>  // For compression (requires linking with -lz)
#include <openssl/aes.h>  // For encryption (requires OpenSSL)