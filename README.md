# ZKP
cara running:
1. Buka terminal pada linux
2. masuk ke folder tempat project disimpan. misal project disimpan di document maka perintahnya -> cd /home/namauser/documen/zkp
3. setelah itu jalankan file register dengan cara mengetik pada terminal perintah ini -> ./register
4. setelah proses register selesai, jalankan file login. dengan cara yang sama dengan perintah 3 hanya beda nama file -> ./login
5. langkah selanjutnya adalah proses authorisasi dengan cara menjalankan perintah authorize. caranya -> ./authorize 

# cara compile file cpp
1. Register
    Pastikan terminal berada dalam folder dimana file yang akan dicompile berada. kemudian ketikkan perintah berikut ini:
    g++ registerDrone.cpp -o register bigInt/uint256_t.cpp bigInt/uint128_t.cpp HashLib/sha3.cpp
2. Login
    Pastikan terminal berada dalam folder dimana file yang akan dicompile berada. kemudian ketikkan perintah berikut ini:
    g++ login.cpp -o login bigInt/uint256_t.cpp bigInt/uint128_t.cpp HashLib/sha3.cpp
3. Authorize
    Pastikan terminal berada dalam folder dimana file yang akan dicompile berada. kemudian ketikkan perintah berikut ini:
    g++ authorize.cpp -o authorize bigInt/uint256_t.cpp bigInt/uint128_t.cpp HashLib/sha3.cpp